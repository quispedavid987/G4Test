#include "stepping.hh"

#include "G4VVisManager.hh"
#include "G4Polyline.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"
#include "G4VProcess.hh"
#include "G4TrackStatus.hh"

MySteppingAction::MySteppingAction() {}
MySteppingAction::~MySteppingAction() {}

void MySteppingAction::UserSteppingAction(const G4Step* step) {
    G4VVisManager *visManager = G4VVisManager::GetConcreteInstance();
    if (!visManager) return;

    // vemos que proceso fisico acaba de ocurrir
    const G4VProcess *process = step->GetPostStepPoint()->GetProcessDefinedStep();
    if (!process) return;

    if (process->GetProcessName() == "compt") {
        G4cout << "¡¡¡INTERACCIÓN COMPTON DETECTADA!!! " << G4endl;
        // obtenemos el vertice de colision
        G4ThreeVector vertex = step->GetPostStepPoint()->GetPosition();
        
        // obtenemos las lineas
        G4ThreeVector gammaDir = step->GetPostStepPoint()->GetMomentumDirection();
        G4ThreeVector gammaEnd = vertex + gammaDir * 1.0 * cm;

        G4Polyline gammaLine;
        gammaLine.push_back(vertex);
        gammaLine.push_back(gammaEnd);
        gammaLine.SetVisAttributes(G4VisAttributes(G4Colour::Red()));
        visManager->Draw(gammaLine);

        // ahora dibujamos la linea del electron
        const std::vector<const G4Track*>* secondaries = step->GetSecondaryInCurrentStep();
        for (size_t i = 0; i < secondaries->size(); ++i) {
            const G4Track* secTrack = (*secondaries)[i];
            if (secTrack->GetDefinition()->GetParticleName() == "e-") {
                G4ThreeVector eDir = secTrack->GetMomentumDirection();
                G4ThreeVector eEnd = vertex + eDir * 1.0 * cm;

                G4Polyline eLine;
                eLine.push_back(vertex);
                eLine.push_back(eEnd);
                eLine.SetVisAttributes(G4VisAttributes(G4Colour::Yellow()));
                visManager->Draw(eLine);
            }
        }
        
        // matamos la particula para que no siga interactuando co nel material
        step->GetTrack()->SetTrackStatus(fStopAndKill);


    }
}