#include "physics.hh"

// Creamos el constructor
MyPhysicsList::MyPhysicsList(){
RegisterPhysics (new G4EmStandardPhysics_option4());
//RegisterPhysics (new G4OpticalPhysics());
}

// Creamos el destructor
MyPhysicsList::~MyPhysicsList() {}


void MyPhysicsList::SetCuts() {
    SetDefaultCutValue(0.001 * mm);
}