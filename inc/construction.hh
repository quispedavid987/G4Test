#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

// Agregando sistema de unidades y constantes fisicas
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"

// Agregando la clase Nist para materiales standard
#include "G4NistManager.hh"

// Agregando la clase para construccion de detectores
#include "G4VUserDetectorConstruction.hh"

// Agregando las clases de volumenes
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

// Agregando algunas formas standard
#include "G4Box.hh"
//#include "G4Sphere.hh"

// Escogiendo el nombre de la clase
class MyDetectorConstruction : public G4VUserDetectorConstruction {
// El constructor y destructor son siempre publicos
public:
    MyDetectorConstruction();
    ~MyDetectorConstruction();

    G4VPhysicalVolume *Construct();

};

#endif