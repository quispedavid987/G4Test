#include "construction.hh"

// Enlazamos este codigo con la cabecera
MyDetectorConstruction::MyDetectorConstruction() {}
MyDetectorConstruction::~MyDetectorConstruction() {}

// Devuelve un puntero hacia un objeto del tipo G4VPhysicalVolume
G4VPhysicalVolume *MyDetectorConstruction::Construct() {
    // Nuestro sistema estara construido con materiales,
    // entonces declaramos a Nist
    G4NistManager *nist = G4NistManager::Instance();

    // Hagamos el World de Aire
    G4Material *worldMat = nist->FindOrBuildMaterial("G4_Al");

    // Dandole forma al world
    // tres volumenes: solid(forma), logical(materiales), physical(magia)  
    
    // Solid: 
    // G4Box("name", x / 2, y / 2, z / 2);
    G4Box *solidWorld = new G4Box("solidWorld", 0.5 * m, 0.5 * m, 0.5 * m);

    // Logical: asignando lo materiales
    // G4LogicalVolume(solid, material, "name")
    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
    												  
     // Physical: Ubicación
    //G4PVPlacement(rotacion, ubicacion, logic a ubicar, "name", volumen madre (o 0))
    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicWorld, "physWorld", 0, false, 0, true);


    return physWorld;

}
