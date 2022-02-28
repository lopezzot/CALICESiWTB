//**************************************************
// \file  CaliceEventAction.cc
// \brief: Implementation of 
//         CaliceEventAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 20 February 2021
//**************************************************

//Includers from project files
//
#include "CaliceEventAction.hh"
#include "CaliceEcalSD.hh"
#include "CaliceCalorimeterHit.hh"

//Includers from Geant4
//
#include "g4root.hh"
#include "G4Event.hh"
#include "G4UnitsTable.hh"
#include "G4RunManager.hh"
#include "G4ThreeVector.hh"
#include "G4SystemOfUnits.hh"
#include "G4UImanager.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "Randomize.hh"

//Constructor definition
//
CaliceEventAction::CaliceEventAction():
    printModulo(100),
    debugStarted(false),
    felayer{},
    fhitslayer{} {
    UI = G4UImanager::GetUIpointer();
}

//Deconstructor definition
//
CaliceEventAction::~CaliceEventAction() { }

//GetHitsCollection definition
//
CaliceHitsCollection* CaliceEventAction::GetHitsCollection(const G4String& hcName,
                                                           const G4Event* event) const {
    G4int hcID = G4SDManager::GetSDMpointer()->GetCollectionID(hcName);
    auto hitsCollection
        = static_cast<CaliceHitsCollection*>(event->GetHCofThisEvent()->GetHC(hcID));

    if ( ! hitsCollection ) {
        G4ExceptionDescription msg;
        msg << "Cannot access hitsCollection ID " << hcID;
        G4Exception("CaliceEventAction::GetHitsCollection()",
            "MyCode0003", FatalException, msg);
    }

    return hitsCollection;
}

//PrintEventStatistics method definition
//
void CaliceEventAction::PrintEventStatistics(G4double gapEdep, G4double gapTrackLength) const {
    G4cout
        << "        Calo: total energy: "
        << std::setw(7) << G4BestUnit(gapEdep, "Energy")
        << "       total track length: "
        << std::setw(7) << G4BestUnit(gapTrackLength, "Length")
        << G4endl;
}

//BeginOfEventAction definition
//
void CaliceEventAction::BeginOfEventAction(const G4Event* evt) {

    felayer.clear();
    for ( unsigned int i = 0; i<30; i++) { felayer.push_back(0.); }
    fhitslayer.clear();
    for ( unsigned int i = 0; i<30; i++) { fhitslayer.push_back(0.); }

}

//EndOfEventAction definition
//
void CaliceEventAction::EndOfEventAction(const G4Event* evt) {

    auto analysisManager = G4AnalysisManager::Instance();

    //if (fCaloHCID == -1 ) fCaloHCID = G4SDManager::GetSDMpointer()->GetCollectionID("CaloHitsCollection");
    //auto caloHC = GetHitsCollection(fCaloHCID, evt);
    auto caloHC = GetHitsCollection("CaloHitsCollection", evt);
    for(unsigned int i=0; i<caloHC->entries(); i++){
        analysisManager->FillNtupleIColumn(2, caloHC->entries() );
    }

    float samplingFraction = 1.0;
    int NbHits = caloHC->entries();
    for (G4int i=0;i<NbHits;i++) {

        int layerNumber = (*caloHC)[i]->GetLayerID();

        // to account for different amount of dead material preceding even
        // and odd layers + different sampling fraction in the modules
        if ( layerNumber < 10 ) {
            if ( layerNumber%2==0 ) samplingFraction = 1.;
            else samplingFraction = 1.072;
        } 
        else if ( layerNumber > 9 && layerNumber < 20 ) {
            //if ( layerNumber%2==0 ) samplingFraction = 2;
            if ( layerNumber%2==0 ) samplingFraction = 1;
            //else samplingFraction = 2.047;
            else samplingFraction = 1.047;
        }
        else {
            //if ( layerNumber%2==0 ) samplingFraction = 3;
            if ( layerNumber%2==0 ) samplingFraction = 1;
            //else samplingFraction = 3.047;
            else samplingFraction = 1.047;
        }
        if ( samplingFraction*(*caloHC)[i]->GetEdep() < 0.6 ) continue;
            felayer[layerNumber] += samplingFraction*(*caloHC)[i]->GetEdep();
            //theCaliceAnalysis->hitslayer[layerNumber]++;
            fhitslayer[layerNumber]++;
    }
    analysisManager->AddNtupleRow();

    auto eventID = evt->GetEventID();
    
    //auto printModulo = G4RunManager::GetRunManager()->GetPrintProgress();

    if(debugStarted) {
        UI->ApplyCommand("/tracking/verbose  0");
        debugStarted = false;
    }

    if (!(evt->GetEventID()%1000) )  G4cout << "------>CALICESiWTB::CaliceEventAction: End of event #" << eventID  << G4endl;

}

//**************************************************
