import ROOT
import matplotlib.pyplot as plt
import numpy as np
import csv

plt.rcParams['text.usetex'] = True

# Constants
DATASETS='../datasets/'
GRID=True

# Open the ROOT file
root_file_name = input("Root file to read: ")
figure_name = input("Name of output figure: ")
root_file = ROOT.TFile.Open(root_file_name)

# Access the histogram
histogram = root_file.Get("phi_nu")
#weight = 1e-7
weight = 1

# Convert ROOT histogram to NumPy arrays
bin_centers = []
bin_contents = []
for i in range(1, histogram.GetNbinsX() + 1):
    bin_centers.append(histogram.GetBinCenter(i))
    bin_contents.append(histogram.GetBinContent(i) * weight)

bin_centers = np.array(bin_centers)
bin_contents = np.array(bin_contents)

# Open the CSV file and extract
with open(DATASETS+'DUNE_pi_hist.csv', 'r') as csv_file:
    csv_reader = csv.reader(csv_file)
    pi_x = []
    pi_y = []
    for row in csv_reader:
        pi_x.append(float(row[0]))
        pi_y.append(float(row[1]))

with open(DATASETS+'DUNE_kaon_hist.csv', 'r') as csv_file:
    csv_reader = csv.reader(csv_file)
    k_x = []
    k_y = []
    for row in csv_reader:
        k_x.append(float(row[0]))
        k_y.append(float(row[1]))

with open(DATASETS+'DUNE_numu_hist.csv', 'r') as csv_file:
    csv_reader = csv.reader(csv_file)
    phi_x = []
    phi_y = []
    for row in csv_reader:
        phi_x.append(float(row[0]))
        phi_y.append(float(row[1]))

# Get bin edges. This is based on a visual inspection of the DUNE plot.

# Define the bin widths and number of bins for each range
bin_widths = [5/24, 5/18, 5/14, 5/14]  # Corresponding to 0-5, 5-10, 10-15, 15-20
num_bins = [24, 18, 14, 14]

# Initialize an empty list to store bin edges
bin_edges = []

# Calculate the bin edges for each range and append them to the list
start_value = 0
for width, bins in zip(bin_widths, num_bins):
    end_value = start_value + width * bins
    edges = np.linspace(start_value, end_value, bins + 1)
    bin_edges.extend(edges[1:]) # This avoids double counting 5, 10, and 15
    start_value = end_value

# Convert the list of bin edges to a NumPy array
bin_edges = np.array(bin_edges)

np.savetxt('bin_edges.txt', bin_edges, delimiter=',', fmt='%f')

# Create the histogram plot
plt.hist(bin_centers, bins=len(bin_centers), weights=bin_contents, histtype='step', color='green', label='Geant4', linewidth=2)
plt.hist(phi_x, bins=bin_edges, weights=phi_y, histtype='step', label=r'DUNE $\nu$', color='black')
plt.hist(pi_x, bins=bin_edges, weights=pi_y, histtype='step', label=r'DUNE $\pi$', color='orange')
plt.hist(k_x, bins=bin_edges, weights=k_y, histtype='step', label=r'DUNE $K$', color='blue')
plt.xlabel("Energy (GeV)")
plt.ylabel(r'$\nu$ / Area / $\Delta$E / $10^7$')
plt.yscale("log")
plt.ylim(4.5e-11,6.5e-8)
plt.xlim(0, 20)
plt.title(r'$\frac{d\Phi_\nu}{dE} (K^\pm, \pi^\pm \to \nu_\mu)$', size=18, y=1.02)
plt.grid(visible=GRID, which='major', axis='both')    # which: major, minor, both; axis: both, x, y
plt.legend()

# Display or save the plot
#plt.show()  # Display the plot
plt.savefig("../plots/"+figure_name, dpi=600)  # Save as an image (optional)

# Close the ROOT file
root_file.Close()

