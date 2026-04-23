#include "physics.hh"

// Creamos el constructor
MyPhysicsList::MyPhysicsList(){
RegisterPhysics (new G4EmStandardPhysics());
//RegisterPhysics (new G4OpticalPhysics());
}

// Creamos el destructor
MyPhysicsList::~MyPhysicsList() {}
