//**************************************************
// \file  CaliceEventAction.hh
// \brief: Definition of 
//         CaliceEventAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 20 February 2022
//**************************************************

//Prevent including headers multple times
//
#ifndef CaliceEventAction_h
#define CaliceEventAction_h 

//Includers from project files
//
#include "CaliceCalorimeterHit.hh" 
//class CaliceAnalysisManager;

//Includers from Geant4
//
#include "G4UserEventAction.hh"
#include "globals.hh"
#include <vector>
class G4Event;
class G4UImanager;

class CaliceEventAction : public G4UserEventAction {
    
    public:
        //Constructor and deconstructor
        //
        CaliceEventAction();
        virtual ~CaliceEventAction();

        void BeginOfEventAction(const G4Event*);
        void   EndOfEventAction(const G4Event*);

        std::vector<G4double>& Getelayer() { return felayer; };
        std::vector<G4double>& Gethitslayer() { return fhitslayer; };

    private:

        CaliceHitsCollection* GetHitsCollection(const G4String& hcName,const G4Event* event) const;

        void PrintEventStatistics(G4double gapEdep, G4double gapTrackLength) const;
        
        G4UImanager*          UI;
        
        //CaliceAnalysisManager* man; //the one and only
        
        std::vector<G4int>    selectedEvents;
        G4int printModulo;
        G4bool debugStarted;
        
        std::vector<G4double> felayer;
        std::vector<G4double> fhitslayer;
};

#endif

//**************************************************
