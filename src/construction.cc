#include "construction.hh"

// Siempre ponemos primero el constructor y destructor
MyDetectorConstruction::MyDetectorConstruction() {}
MyDetectorConstruction::~MyDetectorConstruction() {}

// Ahora llamamos a la funcion de construccion
G4VPhysicalVolume *MyDetectorConstruction::Construct() {
    // Nuestro sistema estara construido con materiales,
    // entonces declaramos a Nist
    G4NistManager *nist = G4NistManager::Instance();

    // Hagamos el World de Aire
    G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

    // Dandole forma al world
    // tres volumenes: solid(forma), logical(materiales), physical(magia)
    
    // Solid: name, x/2, y/2, z/2, no olvidar unidades
    G4Box *solidWorld = new G4Box("solidWorld", 0.5*m, 0.5*m, 0.5*m);
    
    // Logical: asignando lo materiales
    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat,
    "logicWorld");

    // Physical: donde ocurre la magia
    G4VPhysicalVolume *physWorld = new G4PVPlacement(
        0, G4ThreeVector(0.,0.,0.), logicWorld, "physWorld", 0, false, 0, true
    );

    return physWorld;

}
