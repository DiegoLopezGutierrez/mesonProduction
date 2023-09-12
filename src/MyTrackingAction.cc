#include "MyTrackingAction.hh"
#include "G4AnalysisManager.hh"

MyTrackingAction::MyTrackingAction()
{}

MyTrackingAction::~MyTrackingAction()
{}

void MyTrackingAction::PreUserTrackingAction(const G4Track* tr)
{
    auto analysisManager = G4AnalysisManager::Instance();

    if (tr->GetParticleDefinition()->GetParticleName() == "kaon+") {
        auto E = tr->GetTotalEnergy() / GeV;
	auto theta = tr->GetMomentumDirection().theta();
	
	if ((theta >= 0.01) and (theta <= 1.0))
	{
	    // Energy, Theta 2D Histogram     K+
	    analysisManager->FillH2(0, E, theta);

	    // Energy 1D Histogram            K+
	    analysisManager->FillH1(0, E);

	    // Phi_2 1D Histogram
	    analysisManager->FillH1(5, E);
	    analysisManager->FillH1(6, E, 3.0);
	    
	    // Phi_1 1D Histogram
	    if (E < 10*GeV)
	    {
	        analysisManager->FillH1(4, E);
		analysisManager->FillH1(6, E, 0.2);
	    }
	}
    }
    if (tr->GetParticleDefinition()->GetParticleName() == "kaon-") {
        auto E = tr->GetTotalEnergy() / GeV;
	auto theta = tr->GetMomentumDirection().theta();
	
	if ((theta >= 0.01) and (theta <= 1.0))
	{
	    // Energy, Theta 2D Histogram     K-
	    analysisManager->FillH2(1, E, theta);

	    // Energy 1D Histogram            K-
	    analysisManager->FillH1(1, E);

            // Phi_2 1D Histogram
	    analysisManager->FillH1(5, E);
	    analysisManager->FillH1(6, E, 3.0);
	    
	    // Phi_1 1D Histogram
	    if (E < 10*GeV)
	    {
	        analysisManager->FillH1(4, E);
		analysisManager->FillH1(6, E, 0.2);
	    }
 
	}
    }
    if (tr->GetParticleDefinition()->GetParticleName() == "pi+") {
        auto E = tr->GetTotalEnergy() / GeV;
	auto theta = tr->GetMomentumDirection().theta();

	if ((theta >= 0.01) and (theta <= 1.0))
	{	
	    // Energy, Theta 2D Histogram     Pi+
	    analysisManager->FillH2(2, E, theta);

	    // Energy 1D Histogram            Pi+
	    analysisManager->FillH1(2, E);
	
            // Phi_2 1D Histogram
	    analysisManager->FillH1(5, E);
	    analysisManager->FillH1(6, E, 3.0);
	    
	    // Phi_1 1D Histogram
	    if (E < 10*GeV)
	    {
	        analysisManager->FillH1(4, E);
		analysisManager->FillH1(6, E, 0.2);
	    }
  
	}
    }
    if (tr->GetParticleDefinition()->GetParticleName() == "pi-") {
        auto E = tr->GetTotalEnergy() / GeV;
	auto theta = tr->GetMomentumDirection().theta();
	
	if ((theta >= 0.01) and (theta <= 1.0))
	{
	    // Energy, Theta 2D Histogram     Pi-
	    analysisManager->FillH2(3, E, theta);

            // Energy 1D Histogram            Pi-
	    analysisManager->FillH1(3, E);
	
	    // Phi_2 1D Histogram
	    analysisManager->FillH1(5, E);
	    analysisManager->FillH1(6, E, 3.0);
	    
	    // Phi_1 1D Histogram
	    if (E < 10*GeV)
	    {
	        analysisManager->FillH1(4, E);
		analysisManager->FillH1(6, E, 0.2);
	    }
 
	}
    } 
}
