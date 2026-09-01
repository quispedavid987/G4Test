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
    G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");
    G4Material *alumiMat = nist->FindOrBuildMaterial("G4_Al");

    // Dandole forma al world
    // tres volumenes: solid(forma), logical(materiales), physical(magia)  
    
    G4double worldSize = 5. * cm;
    G4double alumiSize = worldSize * 1.; // tamaño proporcional
    G4double thickness = 0.5 * cm;
    // Solid:  
    // G4Box("name", x / 2, y / 2, z / 2);
    G4Box *solidWorld = new G4Box("solidWorld", worldSize / 2., worldSize / 2., worldSize / 2.);
    G4Box *solidAlumi = new G4Box("solidAlu", alumiSize / 2, alumiSize / 2, thickness / 2);

    // Logical: asignando lo materiales
    // G4LogicalVolume(solid, material, "name")
    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
    G4LogicalVolume *logicAlumi = new G4LogicalVolume(solidAlumi, alumiMat, "logicAlumi");

    // Agregando colores a los volumenes
    G4Colour gray50 = G4Colour::Gray();
    gray50.SetAlpha(0.5); // 50% de transparencia

    G4VisAttributes *visAlumi = new G4VisAttributes(gray50);
    visAlumi->SetVisibility(true);
    visAlumi->SetForceSolid(true);
    logicAlumi->SetVisAttributes(visAlumi);
    // Physical: Ubicación
    //G4PVPlacement(rotacion, ubicacion, logic a ubicar, "name", volumen madre (o 0))
    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicWorld, "physWorld", 0, false, 0, true);
    new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicAlumi, "physAlumi", logicWorld, false, 0, true);


    return physWorld;

}
