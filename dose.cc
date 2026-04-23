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

// Incluimos la accion
#include "action.hh"

// Incluimos algunas librerias de goddess para prueba
#include "GODDeSS_Messenger.hh"
#include "ScintillatorTileConstructor.hh"
#include "G4ScintillatorTile.hh"



// Iniciando funcion main
int main(G4int argc, char** argv)
{
    // Creamos el corazon del programa
    G4RunManager *runManager = new G4RunManager();
    
    // Una vez creado el detector, lo definimos
    // pero aun no estamos listos para inciarlo
    runManager->SetUserInitialization(new MyDetectorConstruction());
    runManager->SetUserInitialization(new MyPhysicsList());
    runManager->SetUserInitialization(new MyActionInitialization());


    // Debemos iniciar el RunManager cuando tengamos definida la construccion
    runManager -> Initialize();

    // Creamos la User Interface
    G4UIExecutive *ui = new G4UIExecutive(argc, argv);
    G4UImanager *UIManager = G4UImanager::GetUIpointer();

    // Vizualisamos la interfaz
    G4VisManager *visManager = new G4VisExecutive();
    visManager -> Initialize();
    
    UIManager->ApplyCommand("/vis/open OGL"); // Abre la imagen del detector
    UIManager->ApplyCommand("/vis/viewer/set/viewpointVector 1 0.7 0.7"); // punto de observacion inicial
    UIManager->ApplyCommand("/vis/ogl/set/displayListLimit 50000");
    UIManager->ApplyCommand("/vis/drawVolume"); // Dibuja el volumen del detector
    UIManager->ApplyCommand("/vis/scene/add/axes 40 -40 -40 10 cm"); // Dibujando los ejes

    UIManager->ApplyCommand("/vis/viewer/set/autorefresh true"); // ver la trayectoria
    UIManager->ApplyCommand("/vis/scene/add/trajectories smooth"); // lineas suaves para B
    UIManager->ApplyCommand("/vis/scene/endOfEventAction accumulate 300"); // acumula eventos

    UIManager->ApplyCommand("/vis/modeling/trajectories/create/drawByParticleID");
    UIManager->ApplyCommand("/vis/modeling/trajectories/drawByParticleID-0/set e- blue");
    UIManager->ApplyCommand("/vis/modeling/trajectories/drawByParticleID-0/set mu- red");
    UIManager->ApplyCommand("/vis/modeling/trajectories/drawByParticleID-0/set mu+ red");
	UIManager->ApplyCommand("/vis/modeling/trajectories/drawByParticleID-0/set opticalphoton green");
    UIManager->ApplyCommand("/run/beamOn 100");
    
    // Inicia la sesion
    ui -> SessionStart();

    G4cout << "=========== Simulacion terminada :) ===========" << G4endl;

    delete ui;
    delete visManager;
    delete runManager;


    return 0;

}
