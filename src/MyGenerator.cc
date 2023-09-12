#include "MyGenerator.hh"

Generator::Generator()
{
    fParticleGun = new G4ParticleGun(1);
}

Generator::~Generator()
{
    delete fParticleGun;
}

void Generator::GeneratePrimaries(G4Event *event)
{
    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition *particle = particleTable->FindParticle("proton");

    G4ThreeVector pos(0., 0., -4*m);
    G4ThreeVector mom(0., 0., 1.);

    fParticleGun->SetParticlePosition(pos);
    fParticleGun->SetParticleMomentumDirection(mom);
    fParticleGun->SetParticleMomentum(120.*GeV);
    fParticleGun->SetParticleDefinition(particle);

    fParticleGun->GeneratePrimaryVertex(event);
}
