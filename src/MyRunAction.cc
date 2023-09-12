#include "G4AnalysisManager.hh"
#include "G4SystemOfUnits.hh"
#include "MyRunAction.hh"

#include "helper.hh"

#include <iostream>

MyRunAction::MyRunAction()
{}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run* run)
{
    // Create/get analysis manager
    auto analysisManager = G4AnalysisManager::Instance();
    G4cout << "Using " << analysisManager->GetType() << G4endl;
    analysisManager->SetVerboseLevel(1);

    // Open output file
    G4int numberOfEvents = run->GetNumberOfEventToBeProcessed();
    std::string timestamp = GetCurrentTimestamp();

    std::stringstream strEvents;
    strEvents << numberOfEvents;

    G4String fileName = "../histograms/" + strEvents.str() + "Events_" + timestamp + ".root";
    analysisManager->OpenFile(fileName);

    // Create 2D Energy, Theta Histograms
    analysisManager->CreateH2("kp", "k+ E (up to 120 GeV) Theta (0.01 rad to 1 rad)", 1e3, 0, 120, 1e3, 0.01*rad, 1*rad);    // ID: 0
    analysisManager->CreateH2("km", "k- E (up to 120 GeV) Theta (0.01 rad to 1 rad)", 1e3, 0, 120, 1e3, 0.01*rad, 1*rad);    // ID: 1
    analysisManager->CreateH2("pip", "pi+ E (up to 120 GeV) Theta (0.01 rad to 1 rad)", 1e3, 0, 120, 1e3, 0.01*rad, 1*rad);  // ID: 2
    analysisManager->CreateH2("pim", "pi- E (up to 120 GeV) Theta (0.01 rad to 1 rad)", 1e3, 0, 120, 1e3, 0.01*rad, 1*rad);  // ID: 3

    for (G4int i = 0; i < 4; i++)
    {
        analysisManager->SetH2XAxisTitle(i, "E (GeV)");
	analysisManager->SetH2YAxisTitle(i, "theta (rad)");
	analysisManager->SetH2ZAxisTitle(i, "Count");
    }

    // Create 1D Energy Histograms    
    analysisManager->CreateH1("kp", "k+ E (up to 120 GeV)", 1e3, 0, 120);    // ID: 0
    analysisManager->CreateH1("km", "k- E (up to 120 GeV)", 1e3, 0, 120);    // ID: 1
    analysisManager->CreateH1("pip", "pi+ E (up to 120 GeV)", 1e3, 0, 120);  // ID: 2
    analysisManager->CreateH1("pim", "pi- E (up to 120 GeV)", 1e3, 0, 120);  // ID: 3

    // Create Differential Neutrino Fluxes
    analysisManager->CreateH1("phi1", "phi_1 (E up to 10 GeV)", 1e3, 0, 10);            // ID: 4
    analysisManager->CreateH1("phi2", "phi_2 (E up to 120 GeV)", 1e3, 0, 120);          // ID: 5
    analysisManager->CreateH1("phi_nu", "phi_nuv = 3*phi_1 + 0.2*phi_2", 1e3, 0, 20);   // ID: 6; Note: upper limit set to 20 GeV for easier comparison with arXiv:2002.03005

    for (G4int i = 0; i < 7; i++)
    {
        analysisManager->SetH1XAxisTitle(i, "E (GeV)");
	analysisManager->SetH1YAxisTitle(i, "Count");
    } 
}

void MyRunAction::EndOfRunAction(const G4Run* run)
{
    // Get analysis manager
    auto analysisManager = G4AnalysisManager::Instance();

    // Write and close the output file
    analysisManager->Write();
    analysisManager->CloseFile();
}
