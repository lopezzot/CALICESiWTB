/*
//**************************************************
// \file  CaliceAnalysisManager.hh
// \brief: Definition of 
//         CaliceAnalysisManager class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 20 February 2022
//**************************************************

//Prevent including headers multiple times
//
#ifndef CaliceAnalysisManager_h
#define CaliceAnalysisManager_h

//Includers from ROOT and Geant4
//
//#include "TSystem.h"
#include <TH1F.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TH3D.h>
#include <TH1I.h>
#include "globals.hh"
#include "G4Material.hh"
#include "G4Element.hh"
#include "G4SDManager.hh"
class G4Track;
class G4Step;
class G4ParticleDefinition;
class TTree;
class TFile;

//Includers from project files
//
#include "CaliceEcalSD.hh"
//#include "CaliceCalorimeterHit.hh"

#define numberOfLayers 30

using namespace std;

class CaliceAnalysisManager {
    
    public:
        //Singleton!
        static CaliceAnalysisManager* GetPointer();

    private:
        //Constructor
        CaliceAnalysisManager();

    public: 
        //Deconstructor
        ~CaliceAnalysisManager();

        void bookAnalysisTree();

        void BeginOfRun(G4String filename);
        void EndOfRun();
        void BeginOfEvent();
        void EndOfEvent();
        void Fill(G4int id, G4double x, G4double w);
        void SetOutputFile(G4String name);
        void SetPhysList(G4String listname);
        
        G4String fPhysListName; 
        G4String filename;
        G4String fParticleName;
        G4double fParticleEnergy;
        
        //void Write(std::vector<CaliceCalorimeterHit*>*);

        void SetVerbose(G4int val);        
        G4int GetVerbose() const;

        void SetBeamEnergy(G4double);

        TH1D* h_xProfile;
        TH1D* h_yProfile;
        TH1D* h_zProfile;
        TH1I* h_padXProfile;
        TH1I* h_padYProfile;
        TH1D* h_energyPerHit;
        TH1D* h_energyPerEvent;
        TH1I* h_longitudinalHits;
        TH1F* h_longitudinalE;

        G4int nLayers;
        G4int firstInteractionLayer;
        G4int MClayer;
        G4bool isInteraction;
 
        int nhits;
        float posx[20000];
        float posy[20000];
        float posz[20000];
        float energy[20000];
        int layer[20000];
        float elayer[numberOfLayers];
        int hitslayer[numberOfLayers];
        int numberOfMCparticles;
        double totEdep;
        //  vector<int>* hitPadX = 0;
        //  vector<int>* hitPadY = 0;

    private:
        static CaliceAnalysisManager* fManager;

        const G4ParticleDefinition* primaryDef;

        TTree* tree;
        TFile* fOutputFile;

        G4int numberOfEvents;

        G4int primaryParticleId;
        G4double beamEnergy;

        G4int verbose;

        G4int n_evt;

};

#endif

//**************************************************
*/
