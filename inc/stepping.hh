#ifndef STEPPING_HH
#define STEPPING_HH

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "G4SystemOfUnits.hh"

class MySteppingAction : public G4UserSteppingAction {
public:
    MySteppingAction();
    virtual ~MySteppingAction();

    // esto se ejecta cada vez que una particula da un paso
    virtual void UserSteppingAction(const G4Step*);

};

#endif //STEPPING_HH