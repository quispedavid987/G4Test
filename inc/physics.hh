#ifndef PHYSICS_HH
#define PHYSICS_HH

// Llamamos a los procesos fisicos involucrados en nuestra simulacion
#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4OpticalPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4DecayPhysics.hh"
#include "G4SystemOfUnits.hh"


class MyPhysicsList : public G4VModularPhysicsList
{
public:
    MyPhysicsList();
    virtual ~MyPhysicsList();

    virtual void SetCuts();
};

#endif