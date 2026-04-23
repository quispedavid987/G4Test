#include "action.hh"
MyActionInitialization::MyActionInitialization() {}
MyActionInitialization::~MyActionInitialization() {}

void MyActionInitialization::Build() const {
MyPrimaryGenerator *generator = new MyPrimaryGenerator();
SetUserAction(generator);
}

MyPrimaryGenerator::MyPrimaryGenerator() {
fParticleGun = new G4ParticleGun(1);
}

MyPrimaryGenerator::~MyPrimaryGenerator() {
delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent) {
G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
G4String particleName = "proton";
G4ParticleDefinition *particle = particleTable->FindParticle(particleName);
G4ThreeVector pos(0., 0., 50. * cm);
G4ThreeVector momdir(0., 0., -1.);
G4double particleEnergy = 100.*GeV;
fParticleGun -> SetParticlePosition(pos);
fParticleGun -> SetParticleMomentumDirection(momdir);
fParticleGun -> SetParticleEnergy(particleEnergy);
fParticleGun -> SetParticleDefinition(particle);
fParticleGun -> GeneratePrimaryVertex(anEvent);
}
