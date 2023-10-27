# mesonProduction
Code for estimating the charged kaon and pion production in a DUNE-like proton beam on a graphite target to estimate differential neutrino fluxes.

The repo creates the kaons and pions and assumes they get perfectly collimated to the beamline if their polar angles fall within 0.01 and 1 rad. These collimated mesons are "propagated" following an exponential decay law with a randomly generated z-value, and they are weighted by this exponential. The differential neutrino fluxes are estimated as explained in [2304.02031](https://arxiv.org/pdf/2304.02031.pdf).
