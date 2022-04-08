//**************************************************
// \file CALICESiWTB.cc
// \brief: main() of CALICESiWTB project
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 17 February 2022
//**************************************************

//Includers from project files
//
#include "CaliceDetectorConstruction.hh" 
#include "CaliceActionInitialization.hh"
#include "CalicePrimaryGeneratorAction.hh" 
#include "CaliceRunAction.hh" 
#include "CaliceEventAction.hh" 
#include "CaliceTrackingAction.hh"
#include "CaliceSteppingAction.hh"

//Includers from Geant4 and C++
//
#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif 
#include "G4UImanager.hh" 
#include "G4UIterminal.hh" 
#include <cstring>
#include <climits>
#include <errno.h>
#include "G4SystemOfUnits.hh"
#include "G4ProcessManager.hh"
#include "G4PhysListFactory.hh"
#include "G4VModularPhysicsList.hh"
#include "G4GenericPhysicsList.hh"
#include "FTFP_BERT.hh"
#include "FTFP_BERT_HP.hh"
#include "QGSP_BERT.hh"
#include "QGSP_FTFP_BERT.hh"
#include "QBBC.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4GDMLParser.hh"
#include <fstream>

using namespace std;

namespace PrintUsageError {
    void UsageError() {
        G4cerr << " Usage: " << G4endl;
        G4cerr << " ./CALICESiWTB [macro] [physlist (default: FTFP_BERT)] [nthreads (default: 1)]" << G4endl;
    }
}

//main() of CALICESiWTB
//
int main( int argc, char** argv ) {
    
    //Set Random Seed Engine and intial seed
    //
    //CLHEP::HepRandomEngine* defaultEngine;
    //defaultEngine = new CLHEP::Ranlux64Engine(1234567,4);
    //CLHEP::HepRandom::setTheEngine( /*&*/defaultEngine );
    //G4long seed = time( NULL );
    //CLHEP::HepRandom::setTheSeed( seed );
    
    if ( argc>4 ){
        PrintUsageError::UsageError();
        return 1;
    }

    //Initializing RunManager
    //
    G4int nthreads = 2;
    if (argc == 4){
        nthreads = G4UIcommand::ConvertToInt(argv[3]);
    }
    #ifdef G4MULTITHREADED
    auto runManager = new G4MTRunManager;
    if ( nthreads > 0 ) { 
        runManager->SetNumberOfThreads(nthreads);
    }  
    #else
    auto runManager = new G4RunManager;
    #endif

    //Mandatory User Actions: 1- Detector
    //
    G4GDMLParser parser;
    parser.Read("myCaliceGeometry.gdml");
    runManager->SetUserInitialization( new CaliceDetectorConstruction(parser) );
    
    //Mandatory User Actions: 2- Physics List
    //
    G4String custom_pl = "FTFP_BERT"; //FTFP_BERT default PL
    if (argc == 3) {                  //argv[2] usage
        custom_pl = argv[2];
    }
    auto physListFactory = new G4PhysListFactory;
    auto physList = physListFactory->GetReferencePhysList( custom_pl );
    runManager->SetUserInitialization( physList );

    G4String outputname = "CALICESiWTBout.root";
    if (argc != 1){ 
        //argv[1] usage    
        G4String particleName = ((string)argv[1]).substr(4);
        particleName = particleName.substr(0,3);
        G4String particleEnergy = ((string)argv[1]).substr(8);
        particleEnergy = particleEnergy.substr(0,particleEnergy.find("GeV"));
        outputname = "Calice_" + custom_pl + "_" + particleName + "_" + particleEnergy + "GeV.root";  
    }

    //Mandatory User Action (for multi-threading): 3- ActionInitialization
    //
    auto actioninitialization = new CaliceActionInitialization( outputname );
    runManager->SetUserInitialization( actioninitialization );
    /* 
    //Mandatory User Actions: 3- PrimaryGeneratorAction
    //
    runManager->SetUserAction( new CalicePrimaryGeneratorAction );

    //Optional user actions
    //
    auto evtaction = new CaliceEventAction;
    runManager->SetUserAction( new CaliceRunAction(outputname, evtaction)  );
    runManager->SetUserAction( evtaction );
    //runManager->SetUserAction( new CaliceTrackingAction );
    runManager->SetUserAction( new CaliceSteppingAction() );
    */

    // Initialize run manager, not needed can be done in macros, to be removed
    //
    //runManager->Initialize();

    //Visualization
    //
    auto visManager = new G4VisExecutive;
    visManager->Initialize();

    //User Interface initialization
    //
    G4UImanager* UI = G4UImanager::GetUIpointer();

    if ( argc == 1 ) {    // Define UI session for interactive mode
        G4cout<<"-->CALICESiWTB: interactive mode"<<G4endl;
        G4UIExecutive* session = new G4UIExecutive(argc,argv);
	UI->ApplyCommand( "/control/execute CALICESiWTB_init_vis.mac" );
        if ( session->IsGUI() ) {
            UI->ApplyCommand( "/control/execute CALICESiWTB_gui.mac" );
        }
        session->SessionStart();
	delete session;
        delete UI;
    }    
    else {                // Batch mode (macros)
	G4String command = "/control/execute ";
        G4cout<<"-->CALICESiWTB: batch mode"<<G4endl;
	G4String fileName = argv[1];
	UI->ApplyCommand(command+fileName);
    }

    //Job termination
    //
    delete visManager;
    delete runManager;
    //delete defaultEngine;

}

//**************************************************
