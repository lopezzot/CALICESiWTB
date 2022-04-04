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
    fFirstInteractionLayer(-1),
    fnbhits(0)
    //felayer{},
    //fhitslayer{}
    {
}

//Deconstructor definition
//
CaliceEventAction::~CaliceEventAction() { }

//GetHitsCollection definition
//
CaliceHitsCollection* CaliceEventAction::GetHitsCollection(const G4String& hcName,
                                                           const G4Event* event) const {
    G4int hcID = G4SDManager::GetSDMpointer()->GetCollectionID(hcName);
    CaliceHitsCollection* hitsCollection
        = static_cast<CaliceHitsCollection*>(event->GetHCofThisEvent()->GetHC(hcID));

    if ( ! hitsCollection ) {
        //G4ExceptionDescription msg;
        //msg << "Cannot access hitsCollection ID " << hcID;
        //G4Exception("CaliceEventAction::GetHitsCollection()",
        //    "MyCode0003", FatalException, msg);
    }

    return hitsCollection;
}

//BeginOfEventAction definition
//
void CaliceEventAction::BeginOfEventAction(const G4Event* /*evt*/) {

    fnbhits = 0;
    fFirstInteractionLayer = -1;
    felayer.clear();
    for ( unsigned int i = 0; i<30; i++) { felayer.push_back(0.); }
    fhitslayer.clear();
    for ( unsigned int i = 0; i<30; i++) { fhitslayer.push_back(0); }

}

//EndOfEventAction definition
//
void CaliceEventAction::EndOfEventAction(const G4Event* evt) {

    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

    CaliceHitsCollection* caloHC = GetHitsCollection("CaloHitsCollection", evt);

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
        if ( (*caloHC)[i]->GetEdep() < 0.6 ) continue;
        felayer[layerNumber] += samplingFraction*(*caloHC)[i]->GetEdep();
        fhitslayer[layerNumber]++;
        fnbhits++;
        /*if ( i > 0 && (*caloHC)[i]->GetTrackID() != (*caloHC)[i-1]->GetTrackID() && 
             (*caloHC)[i]->GetLayerID() != (*caloHC)[i-1]->GetLayerID() ) {
            
            fhitslayer[layerNumber]++;
        }*/
    }
    analysisManager->FillNtupleIColumn(2, fnbhits );

    for ( int iLayer=0; iLayer<28; iLayer++) {
        //G4cout << "layer " << iLayer << "elayer[iLayer] " << felayer[iLayer] << G4endl;
        if ( felayer[iLayer] > 8 && felayer[iLayer+1] > 8 && felayer[iLayer+2] > 8 ) {
              fFirstInteractionLayer = iLayer;
              break; 
        }
    }
    if (fFirstInteractionLayer == -1){
        for ( int iLayer=2; iLayer<28; iLayer++) {
            if ( (felayer[iLayer]+felayer[iLayer+1])/(felayer[iLayer-1]+felayer[iLayer-2]) > 6
                      && (felayer[iLayer+1]+felayer[iLayer+2])/(felayer[iLayer-1]+felayer[iLayer-2]) > 6 ) {
                fFirstInteractionLayer = iLayer;
                break;
            }
        }
    }   
    analysisManager->FillNtupleIColumn(1, fFirstInteractionLayer); 
    
    analysisManager->FillNtupleDColumn(4, felayer[0]);
    analysisManager->FillNtupleDColumn(5, felayer[1]);
    analysisManager->FillNtupleDColumn(6, felayer[2]);
    analysisManager->FillNtupleDColumn(7, felayer[3]);
    analysisManager->FillNtupleDColumn(8, felayer[4]);
    analysisManager->FillNtupleDColumn(9, felayer[5]);
    analysisManager->FillNtupleDColumn(10, felayer[6]);
    analysisManager->FillNtupleDColumn(11, felayer[7]);
    analysisManager->FillNtupleDColumn(12, felayer[8]);
    analysisManager->FillNtupleDColumn(13, felayer[9]);
    analysisManager->FillNtupleDColumn(14, felayer[10]);
    analysisManager->FillNtupleDColumn(15, felayer[11]);
    analysisManager->FillNtupleDColumn(16, felayer[12]);
    analysisManager->FillNtupleDColumn(17, felayer[13]);
    analysisManager->FillNtupleDColumn(18, felayer[14]);
    analysisManager->FillNtupleDColumn(19, felayer[15]);
    analysisManager->FillNtupleDColumn(20, felayer[16]);
    analysisManager->FillNtupleDColumn(21, felayer[17]);
    analysisManager->FillNtupleDColumn(22, felayer[18]);
    analysisManager->FillNtupleDColumn(23, felayer[19]);
    analysisManager->FillNtupleDColumn(24, felayer[20]);
    analysisManager->FillNtupleDColumn(25, felayer[21]);
    analysisManager->FillNtupleDColumn(26, felayer[22]);
    analysisManager->FillNtupleDColumn(27, felayer[23]);
    analysisManager->FillNtupleDColumn(28, felayer[24]);
    analysisManager->FillNtupleDColumn(29, felayer[25]);
    analysisManager->FillNtupleDColumn(30, felayer[26]);
    analysisManager->FillNtupleDColumn(31, felayer[27]);
    analysisManager->FillNtupleDColumn(32, felayer[28]);
    analysisManager->FillNtupleDColumn(33, felayer[29]);
    
    //analysisManager->FillNtupleIColumn(4, fhitslayer);
    analysisManager->AddNtupleRow();

}

//**************************************************
