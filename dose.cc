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

    // Vizualisamos la interfaz
    G4VisManager *visManager = new G4VisExecutive();
    visManager -> Initialize();
    G4UImanager *UIManager = G4UImanager::GetUIpointer();

    
    if (argc == 1) {
        G4UIExecutive *ui = new G4UIExecutive(argc, argv);

        UIManager -> ApplyCommand("/control/execute ../vis.mac");
        ui -> SessionStart();

        delete ui;
    }
    else {
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UIManager -> ApplyCommand(command + "../" + fileName);
    }

    G4cout << "=========== Simulacion terminada :) ===========" << G4endl;

    delete visManager;
    delete runManager;


    return 0;

}
