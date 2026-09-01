#include "action.hh"
#include "stepping.hh"

#include "Randomize.hh" // Generacion de numeros aleatorios

MyActionInitialization::MyActionInitialization() {}
MyActionInitialization::~MyActionInitialization() {}

void MyActionInitialization::Build() const {
    MyPrimaryGenerator *generator = new MyPrimaryGenerator();
    SetUserAction(generator);

    MySteppingAction *stepping = new MySteppingAction();
    SetUserAction(stepping);
}

MyPrimaryGenerator::MyPrimaryGenerator() {
    fParticleGun = new G4ParticleGun(1);
    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName = "gamma";
    G4ParticleDefinition *particle = particleTable->FindParticle(particleName);
    G4ThreeVector momdir(0., 0., -1.);
    G4double particleEnergy = 300. * keV;

    fParticleGun -> SetParticleMomentumDirection(momdir);
    fParticleGun -> SetParticleEnergy(particleEnergy);
    fParticleGun -> SetParticleDefinition(particle);


}

MyPrimaryGenerator::~MyPrimaryGenerator() {
delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent) {

    G4double envsizeXY = 5. * cm;
    G4double x0 = envsizeXY * (G4UniformRand() - 0.5);
    G4double y0 = envsizeXY * (G4UniformRand() - 0.5);
    G4double z0 = 2.5 * cm;
    fParticleGun -> SetParticlePosition(G4ThreeVector(x0, y0, z0));

    fParticleGun -> GeneratePrimaryVertex(anEvent);


}
