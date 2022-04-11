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
        void EndOfEventAction(const G4Event*);

        std::vector<G4double>& Getelayer() { return felayer; };
        std::vector<G4int>& Gethitslayer() { return fhitslayer; };
        std::vector<G4double>& Getehits()  { return fehits; };

    private:

        CaliceHitsCollection* GetHitsCollection(const G4String& hcName,const G4Event* event) const;

        G4int fFirstInteractionLayer;
        G4int fnbhits;
        std::vector<G4double> felayer;
        std::vector<G4int> fhitslayer;
        std::vector<G4double> fehits;
        static const G4int numberOfCells = 9720; 

};

#endif

//**************************************************
