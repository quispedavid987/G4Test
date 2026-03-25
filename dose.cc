// entrada y salida standard
#include <iostream> 

// G4runManager class
#include "G4RunManager.hh"

// User interface
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"

// Visualization
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"

// Incluimos el detector creado
#include "construction.hh"

// Incluimos la fisica
#include "physics.hh"

// Iniciando funcion main
int main(G4int argc, char** argv)
{
    // Creamos el corazon del programa
    G4RunManager *runManager = new G4RunManager();
    
    // Una vez creado el detector, lo definimos
    // pero aun no estamos listos para inciarlo
    runManager->SetUserInitialization(new MyDetectorConstruction());
    runManager->SetUserInitialization(new MyPhysicsList());


    // Debemos iniciar el RunManager cuando tengamos definida la construccion
    runManager -> Initialize();

    // Creamos la User Interface
    G4UIExecutive *ui = new G4UIExecutive(argc, argv);
    G4UImanager *UIManager = G4UImanager::GetUIpointer();

    // Vizualisamos la interfaz
    G4VisManager *visManager = new G4VisExecutive();
    visManager -> Initialize();

    UIManager->ApplyCommand("/vis/open OGL");
    UIManager->ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1");
    UIManager->ApplyCommand("/vis/ogl/set/displayListLimit 5000");
    UIManager->ApplyCommand("/vis/drawVolume");

    // Inicia la sesion
    ui -> SessionStart();

    G4cout << "=========== Simulacion terminada :) ===========" << G4endl;

    return 0;

}