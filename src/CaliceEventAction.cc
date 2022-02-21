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
#include "CaliceAnalysisManager.hh"
//#include "CaliceCalorimeterHit.hh"

//Includers from Geant4
//
#include "G4Event.hh"
#include "G4UnitsTable.hh"
#include "G4RunManager.hh"
#include "G4ThreeVector.hh"
#include "G4SystemOfUnits.hh"
#include "G4UImanager.hh"
#include "G4ios.hh"
#include "Randomize.hh"

//Constructor definition
//
CaliceEventAction::CaliceEventAction():
    printModulo(100),
    debugStarted(false) {
    
    UI = G4UImanager::GetUIpointer();
    //Get CaliceAnalysisManager (the one and only)
    //
    man = CaliceAnalysisManager::GetPointer();

}

//Deconstructor definition
//
CaliceEventAction::~CaliceEventAction() { }

/*
CaliceHitsCollection*
CaliceEventAction::GetHitsCollection(const G4String& hcName,
                                  const G4Event* event) const
{
  G4int hcID
    = G4SDManager::GetSDMpointer()->GetCollectionID(hcName);
  auto hitsCollection
    = static_cast<CaliceHitsCollection*>(
        event->GetHCofThisEvent()->GetHC(hcID));

  if ( ! hitsCollection ) {
    G4ExceptionDescription msg;
    msg << "Cannot access hitsCollection ID " << hcID;
    G4Exception("CaliceEventAction::GetHitsCollection()",
      "MyCode0003", FatalException, msg);
  }

  return hitsCollection;
}
*/

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

    //Initialize to 0 some variables in CaliceAnalysisManager
    //
    man->BeginOfEvent(); 
    /*  if(man->GetVerbose() > 0 || G4int(nEvt/printModulo)*printModulo == nEvt) {
        G4cout << "CaliceEventAction: Event # "
               << nEvt << " started" << G4endl;
    }*/
}

//EndOfEventAction definition
//
void CaliceEventAction::EndOfEventAction(const G4Event* evt) {

    //if (fCaloHCID == -1 ) fCaloHCID = G4SDManager::GetSDMpointer()->GetCollectionID("CaloHitsCollection");
    //auto caloHC = GetHitsCollection(fCaloHCID, evt);
    //auto caloHC = GetHitsCollection("CaloHitsCollection", evt);
    //auto caloHit = (*caloHC)[caloHC->entries()-1];

    auto eventID = evt->GetEventID();
    //Increment nevent in CaliceAnalysisManager and fill ROOT tree
    //
    man->EndOfEvent(); 
    
    //auto printModulo = G4RunManager::GetRunManager()->GetPrintProgress();

    if(debugStarted) {
        UI->ApplyCommand("/tracking/verbose  0");
        debugStarted = false;
    }

    if (!(evt->GetEventID()%1000) )  G4cout << "------>CALICESiWTB::CaliceEventAction: End of event #" << eventID  << G4endl;

}

//**************************************************
