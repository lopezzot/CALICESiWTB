#include "AnalysisHelper.h"
#include <vector>

TString filename[5];
TString modelName;

//Event selection cuts
int minLayer = 7;
int maxLayer = 28;

void MyLongitudinalPlots()
{

  //set CALICE style
  int font = 43;
  int size = 40;
  int sizeLegend = 36;
  float offset = 1.5;

  gROOT->SetStyle("Plain");
  gStyle->SetPalette(1);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gStyle->SetLabelFont(font,"xyz");
  gStyle->SetLabelSize(size,"xyz");
  gStyle->SetTitleFont(font,"xyz");
  gStyle->SetTitleSize(size,"xyz");
  gStyle->SetTitleOffset(1.5,"xyz");
  gStyle->SetStatFont(font);
  
  gStyle->SetFrameFillColor(kWhite);
  gStyle->SetCanvasColor(kWhite);  
  gStyle->SetOptStat(0); /*don't show statistics box*/
  gStyle->SetTitleSize(size, "xyz"); 
  //gStyle->SetLegendBorderSize(1);
  gStyle->SetLegendBorderSize(0);
  
  gStyle->SetPadTopMargin(0.05);
  gStyle->SetPadBottomMargin(0.14);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetPadRightMargin(0.05);

  gROOT->ForceStyle();

  TLatex text;
  text.SetTextAlign(23);
  text.SetTextSize(size);
  text.SetTextFont(font);
  text.SetTextColor(kGray+2);

  //---------------------------------------------------------------------
  //Data arrays produced by macro "PrintLongitudinalDistributions.C"
  // Last changed 22/10/2014
  //---------------------------------------------------------------------
 
  modelName = "QGSP_BERT";

  //single pion QGSP_BERT
  //filename[0] = "../../build6/results/Calice_FTFP_BERT_pi-_2GeV.root";
  /*
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputQBBC/Calice_QBBC_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputQBBC/Calice_QBBC_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputQBBC/Calice_QBBC_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputQBBC/Calice_QBBC_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputQBBC/Calice_QBBC_pi-_10GeV.root";
  */
  /* 
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomput/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomput/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomput/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomput/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomput/Calice_FTFP_BERT_pi-_10GeV.root";
  */
  /* 
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputnewsamp/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputnewsamp/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputnewsamp/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputnewsamp/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputnewsamp/Calice_FTFP_BERT_pi-_10GeV.root";
  */
  /*
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2000mip240/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2000mip240/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2000mip240/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2000mip240/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2000mip240/Calice_FTFP_BERT_pi-_10GeV.root";
  */
  /* 
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2000mip300/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2000mip300/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2000mip300/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2000mip300/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2000mip300/Calice_FTFP_BERT_pi-_10GeV.root";
  */
  /*  
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2000mip300newcut/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2000mip300newcut/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2000mip300newcut/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2000mip300newcut/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2000mip300newcut/Calice_FTFP_BERT_pi-_10GeV.root";
  */
  /*   
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip300newcut/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip300newcut/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip300newcut/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip300newcut/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip300newcut/Calice_FTFP_BERT_pi-_10GeV.root";
  */
 /*  
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/pos0012mip300newcut/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/pos0012mip300newcut/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/pos0012mip300newcut/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/pos0012mip300newcut/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/pos0012mip300newcut/Calice_FTFP_BERT_pi-_10GeV.root";
  */
  /*  
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/pos0012mip155newcut/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/pos0012mip155newcut/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/pos0012mip155newcut/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/pos0012mip155newcut/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/pos0012mip155newcut/Calice_FTFP_BERT_pi-_10GeV.root";
 */ 
 /* 
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newcut/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newcut/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newcut/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newcut/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newcut/Calice_FTFP_BERT_pi-_10GeV.root";
  */
  /* 
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2000mip155newcut/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2000mip155newcut/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2000mip155newcut/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2000mip155newcut/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2000mip155newcut/Calice_FTFP_BERT_pi-_10GeV.root";
  */
  /* 
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2601mip155newcut/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2601mip155newcut/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2601mip155newcut/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2601mip155newcut/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2601mip155newcut/Calice_FTFP_BERT_pi-_10GeV.root";
  */
  //filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2601mip155newcut/Calice_QBBC_pi-_2GeV.root";
  //filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2601mip155newcut/Calice_QBBC_pi-_4GeV.root";
  //filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2601mip155newcut/Calice_QBBC_pi-_6GeV.root";
  //filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2601mip155newcut/Calice_QBBC_pi-_8GeV.root";
  //filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/pos2601mip155newcut/Calice_QBBC_pi-_10GeV.root";
  /*
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1001mip155newcut/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1001mip155newcut/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1001mip155newcut/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1001mip155newcut/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1001mip155newcut/Calice_FTFP_BERT_pi-_10GeV.root";
  */
  /*
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhits/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhits/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhits/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhits/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhits/Calice_FTFP_BERT_pi-_10GeV.root";
  */
  /*
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhitsnosamp/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhitsnosamp/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhitsnosamp/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhitsnosamp/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhitsnosamp/Calice_FTFP_BERT_pi-_10GeV.root";
  */
  /* 
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhitsnosamp2/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhitsnosamp2/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhitsnosamp2/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhitsnosamp2/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhitsnosamp2/Calice_FTFP_BERT_pi-_10GeV.root";
  */
  /*
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/pos0012mip155newhitsnosamp2/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/pos0012mip155newhitsnosamp2/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/pos0012mip155newhitsnosamp2/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/pos0012mip155newhitsnosamp2/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/pos0012mip155newhitsnosamp2/Calice_FTFP_BERT_pi-_10GeV.root";
  */
  /*
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/pos+0012mip155newhitsnosamp2/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/pos+0012mip155newhitsnosamp2/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/pos+0012mip155newhitsnosamp2/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/pos+0012mip155newhitsnosamp2/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/pos+0012mip155newhitsnosamp2/Calice_FTFP_BERT_pi-_10GeV.root";
  */
  /*
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhitnosamp2newlayer/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhitnosamp2newlayer/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhitnosamp2newlayer/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhitnosamp2newlayer/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhitnosamp2newlayer/Calice_FTFP_BERT_pi-_10GeV.root";
  */
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhitnosampnewlayer/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhitnosampnewlayer/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhitnosampnewlayer/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhitnosampnewlayer/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/pos1212mip155newhitnosampnewlayer/Calice_FTFP_BERT_pi-_10GeV.root";
  /*
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputcenter/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputcenter/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputcenter/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputcenter/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputcenter/Calice_FTFP_BERT_pi-_10GeV.root";
  */
  /*
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputx25y0/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputx25y0/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputx25y0/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputx25y0/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputx25y0/Calice_FTFP_BERT_pi-_10GeV.root";
  */
  /*
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputx25y12/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputx25y12/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputx25y12/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputx25y12/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputx25y12/Calice_FTFP_BERT_pi-_10GeV.root";
  */
  /*
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputnewpos/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputnewpos/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputnewpos/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputnewpos/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomputnewpos/Calice_FTFP_BERT_pi-_10GeV.root";
  */ 
  /* 
  filename[0] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomput10p4/Calice_FTFP_BERT_pi-_2GeV.root";
  filename[1] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomput10p4/Calice_FTFP_BERT_pi-_4GeV.root";
  filename[2] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomput10p4/Calice_FTFP_BERT_pi-_6GeV.root";
  filename[3] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomput10p4/Calice_FTFP_BERT_pi-_8GeV.root";
  filename[4] = "/Users/lorenzopezzotti/Desktop/calice/test/newcomput10p4/Calice_FTFP_BERT_pi-_10GeV.root";
  */
  //filename[1] = "../../build6/results/Calice_FTFP_BERT_pi-_4GeV.root";
  //filename[2] = "../../build6/results/Calice_FTFP_BERT_pi-_6GeV.root";
  //filename[3] = "../../build6/results/Calice_FTFP_BERT_pi-_8GeV.root";
  //filename[4] = "../../build6/results/Calice_FTFP_BERT_pi-_10GeV.root";
  
  /* express longitudinal shower shapes in terms of layer numbers (0..30) or pseudolayer numbers (0..60) to account for difference in absorber thickness (sampling) in modules */
  // will be normalised bin-by-bin with the number of entries (= events)
  TH1F* histZ[5];
  int binEntriesZ[5][30];
  double EnergyZ[5][30];
  for (int e = 0; e<5;e++)
        {
          int energy = 2*(e+1);
          TString titel = "Z_";
          titel+=modelName;
          titel+="_";
          titel+=energy;
          titel+="GeV";
          histZ[e]= new TH1F(titel,titel,30,-0.5,29.5);
          histZ[e]->Sumw2();
          for (int b=0;b<30;b++)
            {
              binEntriesZ[e][b] = 0;
              EnergyZ[e][b] = 0;
            }
        }

  //will be normalised overall with the number of hits (normalised to 1)
  TH1F* histZnorm[5];
  for (int e = 0; e<5;e++)
        {
          int energy = 2*(e+1);
          TString titel = "Znorm_";
          titel+=modelName;
          titel+="_";
          titel+=energy;
          titel+="GeV";
          histZnorm[e]= new TH1F(titel,titel,30,-0.5,29.5);
          histZnorm[e]->Sumw2();
        }
  // needed for the error calculation
  TH1F* histSquaredZ[5];
  for (int e = 0; e<5;e++)
        {
          int energy = 2*(e+1);
          TString titel = "SquaredZ_";
          titel+=modelName;
          titel+="_";
          titel+=energy;
          titel+="GeV";
          histSquaredZ[e]= new TH1F(titel,titel,30,-0.5,29.5);
          histSquaredZ[e]->Sumw2();
        }
  //Longitudinal profile (E vs z)
  // will be normalised bin-by-bin with the number of entries (= events)
  TH1F* histLongitudinalProfile[5];
  int binEntries[5][60];
  for (int e = 0; e<5;e++)
        {
          int energy = 2*(e+1);
          TString titel = "LongitudinalProfile_";
          titel+=modelName;
          titel+="_";
          titel+=energy;
          titel+="GeV";
          histLongitudinalProfile[e]= new TH1F(titel,titel,60,-0.5,59.5);
          histLongitudinalProfile[e]->Sumw2();
          for (int b=0;b<60;b++)
            {
              binEntries[e][b] = 0;
            }
        }
  //Longitudinal squared profile (E^2 vs z)
  // needed for the error calculation
  TH1F* histLongitudinalSquaredProfile[5];
  for (int e = 0; e<5;e++)
        {
          int energy = 2*(e+1);
          TString titel = "LongitudinalSquaredProfile_";
          titel+=modelName;
          titel+="_";
          titel+=energy;
          titel+="GeV";
          histLongitudinalSquaredProfile[e]= new TH1F(titel,titel,60,-0.5,59.5);
          histLongitudinalSquaredProfile[e]->Sumw2();
        }

  //Longitudinal profile (E vs z)
  // will be normalised bin-by-bin with the number of hits in that bin
  TH1F* histLongitudinalMeanHitEnergy[5];
  for (int e = 0; e<5;e++)
        {
          int energy = 2*(e+1);
          TString titel = "LongitudinalMeanHitEnergy_";
          titel+=modelName;
          titel+="_";
          titel+=energy;
          titel+="GeV";
          histLongitudinalMeanHitEnergy[e]= new TH1F(titel,titel,60,-0.5,59.5);
          histLongitudinalMeanHitEnergy[e]->Sumw2();
        }

  //--------------------------------------------------------------------
  //Reading the files, filling the histograms and printing the output
  //--------------------------------------------------------------------

  //redefine the layer numbers to express them as speudolayers
  int pseudoLayer[30] = {0,1,2,3,4,5,6,7,8,9,10,12,14,16,18,20,22,24,26,28,30,33,36,39,42,45,48,51,54,57} ;

  //Average values
  double meanZ[5];
  double meanZsquared[5];
  double sigmaZ[5];
  double sumOfZWeights[5];
  double meanEweightedZ[5];
  double meanEweightedZsquared[5];
  double sigmaEweightedZ[5];
  double sumOfWeights[5];
      for (int e=0;e<5;e++)
        {
          meanZ[e]=0.0;
          meanZsquared[e]=0.0;
          sigmaZ[e]=0.0;
          sumOfZWeights[e]=0.0;
          meanEweightedZ[e]=0.0;
          meanEweightedZsquared[e]=0.0;
          sigmaEweightedZ[e]=0.0;
          sumOfWeights[e]=0.0;
        }
 
  double e_mip = 0.0;
  int counter = 0;
  auto outputfile = new TFile( "HELPanalysis.root", "RECREATE" );
  TFile *inputFile;
      for (int file=0;file<5;file++)
        {
          int energy = (file+1)*2;
          inputFile = new TFile(filename[file]);

          TTree *tree = (TTree*)inputFile->Get("tree");
          //read the tree
          int isInteraction;
          tree->SetBranchAddress("isInteraction",&isInteraction);
          int reconstructedInteractionLayer;
          tree->SetBranchAddress("firstInteractionLayer",&reconstructedInteractionLayer);
          vector<double>* energyLayer = NULL;
          tree->SetBranchAddress("elayer", &energyLayer);
          vector<int>* hitsLayer = NULL;
          tree->SetBranchAddress("hitslayer", &hitsLayer);
          int nhits;
          tree->SetBranchAddress("nhits",&nhits);
          
          e_mip = 0.;
          //read the events
          int numberOfEvents =  tree->GetEntries();
          std::cout<<numberOfEvents<<std::endl;
          for ( int n =  0 ; n < numberOfEvents ; n++ )
            {
              tree->GetEntry(n);
              if ( nhits < 25 ) continue;
              //Last step of the event selection
              if (isInteraction==1 && reconstructedInteractionLayer >= minLayer && reconstructedInteractionLayer < maxLayer){
              //if (isInteraction)               {
                  counter = counter+1;
                  double energySum = 0.;
                  for (int layer = reconstructedInteractionLayer; layer < 30; layer++)
                    {
                      e_mip += energyLayer->at(layer);
                      int relativeLayer = pseudoLayer[layer]-pseudoLayer[reconstructedInteractionLayer];
                      int relativeLayerAbs = layer - reconstructedInteractionLayer;
                      histZ[file]->Fill(relativeLayerAbs,hitsLayer->at(layer));
                      EnergyZ[file][relativeLayerAbs] += energyLayer->at(layer);
                      histZnorm[file]->Fill(relativeLayerAbs,hitsLayer->at(layer));
                      histSquaredZ[file]->Fill(relativeLayerAbs,hitsLayer->at(layer)*hitsLayer->at(layer));
                      binEntriesZ[file][relativeLayerAbs]++;
                      meanZ[file] += hitsLayer->at(layer)*relativeLayerAbs;
                      meanZsquared[file] += hitsLayer->at(layer)*relativeLayerAbs*relativeLayerAbs;
                      sumOfZWeights[file] += hitsLayer->at(layer);
                      energySum += energyLayer->at(layer);
                      histLongitudinalMeanHitEnergy[file]->Fill(relativeLayerAbs, energyLayer->at(layer));
                      if (layer<10)
                        {
                          histLongitudinalProfile[file]->Fill(relativeLayer, energyLayer->at(layer));
                          histLongitudinalSquaredProfile[file]->Fill(relativeLayer, energyLayer->at(layer)*energyLayer->at(layer));
                          binEntries[file][relativeLayer]++;
                          meanEweightedZ[file] += energyLayer->at(layer)*relativeLayer;
                          meanEweightedZsquared[file] += energyLayer->at(layer)*relativeLayer*relativeLayer;
                          sumOfWeights[file] += energyLayer->at(layer);
                        }
                      else if (layer >= 10 && layer < 20)
                        {
                          double energy0 = 0.5*energyLayer->at(layer-1)+0.5*energyLayer->at(layer);
                          double energy1 = energyLayer->at(layer);
                          histLongitudinalProfile[file]->Fill(relativeLayer,energy0);
                          histLongitudinalProfile[file]->Fill(relativeLayer+1, energy1);
                          histLongitudinalSquaredProfile[file]->Fill(relativeLayer, energy0*energy0);
                          histLongitudinalSquaredProfile[file]->Fill(relativeLayer+1, energy1*energy1);
                          binEntries[file][relativeLayer]++;
                          binEntries[file][relativeLayer+1]++;
                          meanEweightedZ[file] += energy0*relativeLayer;
                          meanEweightedZ[file] += energy1*(relativeLayer+1);
                          meanEweightedZsquared[file] += energy0*relativeLayer*relativeLayer;
                          meanEweightedZsquared[file] += energy1*(relativeLayer+1)*(relativeLayer+1);
                          sumOfWeights[file] += energy0;
                          sumOfWeights[file] += energy1;
                        }
                      else if (layer >= 20)
                        {
                          double energy0 = (2./3.)*energyLayer->at(layer-1)+(1./3.)*energyLayer->at(layer);
                          double energy1 = (1./3.)*energyLayer->at(layer-1)+(2./3.)*energyLayer->at(layer);
                          double energy2 = energyLayer->at(layer);
                          histLongitudinalProfile[file]->Fill(relativeLayer, energy0);
                          histLongitudinalProfile[file]->Fill(relativeLayer+1, energy1);
                          histLongitudinalProfile[file]->Fill(relativeLayer+2, energy2);
                          histLongitudinalSquaredProfile[file]->Fill(relativeLayer, energy0*energy0);
                          histLongitudinalSquaredProfile[file]->Fill(relativeLayer+1, energy1*energy1);
                          histLongitudinalSquaredProfile[file]->Fill(relativeLayer+2, energy2*energy2);
                          binEntries[file][relativeLayer]++;
                          binEntries[file][relativeLayer+1]++;
                          binEntries[file][relativeLayer+2]++;
                          meanEweightedZ[file] += energy0*relativeLayer;
                          meanEweightedZ[file] += energy1*(relativeLayer+1);
                          meanEweightedZ[file] += energy2*(relativeLayer+2);
                          meanEweightedZsquared[file] += energy0*relativeLayer*relativeLayer;
                          meanEweightedZsquared[file] += energy1*(relativeLayer+1)*(relativeLayer+1);
                          meanEweightedZsquared[file] += energy2*(relativeLayer+2)*(relativeLayer+2);
                          sumOfWeights[file] += energy0;
                          sumOfWeights[file] += energy1;
                          sumOfWeights[file] += energy2;
                        }

                    }//loop over layers
                }//cut on reconstructed layer
            }//loop over events
          outputfile->cd();
          histZ[file]->Write();
          histLongitudinalProfile[file]->Write();
          meanZ[file] /= sumOfZWeights[file];
          meanZsquared[file] /= sumOfZWeights[file];
          sigmaZ[file] = sqrt(meanZsquared[file] - meanZ[file]*meanZ[file]);

          meanEweightedZ[file]/= sumOfWeights[file];
          meanEweightedZsquared[file]/= sumOfWeights[file];
          sigmaEweightedZ[file] = sqrt(meanEweightedZsquared[file] - meanEweightedZ[file]*meanEweightedZ[file]);

          //Normalise histZnorm to unity with sumOfZWeights
          histZnorm[file]->Scale(1/sumOfZWeights[file]);
          histLongitudinalMeanHitEnergy[file]->Scale(1/sumOfZWeights[file]);

          //Calculate the mean plus error for each bin in histZ
          //The error is sigma/sqrt(N)
          for (int bin=1;bin<31;bin++)
            {
              double meanN = 0.0;
              double error = 0.0;
              if (binEntriesZ[file][bin-1]!=0)
                {
                  meanN = histZ[file]->GetBinContent(bin)/(double)binEntriesZ[file][bin-1];
                  EnergyZ[file][bin-1] = EnergyZ[file][bin-1]/(double)binEntriesZ[file][bin-1];
                  //std::cout<<histZ[file]->GetBinContent(bin)<<" "<<(double)binEntriesZ[file][bin-1]<<std::endl;
                  //std::cout<<histZ[file]->GetBinContent(bin)/(double)binEntriesZ[file][bin-1]<<std::endl;
                  double meanN2 = histSquaredZ[file]->GetBinContent(bin)/(double)binEntriesZ[file][bin-1];
                  double sigma2 = meanN2 -meanN*meanN;
                  double sigma = 0.0;
                  if (sigma2 > 0.0) sigma = sqrt(sigma2);
                  error = sigma/sqrt(binEntriesZ[file][bin-1]);
                }
              histZ[file]->SetBinContent(bin,meanN);
              histZ[file]->SetBinError(bin,error);

            }
          //Now normalise to unity so the shower shape can be compared
          histZ[file]->Write();
          histZ[file]->Scale(1./histZ[file]->Integral());
          //histZ[model][file]->Draw();
          //Calculate the mean plus error for each bin in histLongitudinalProfile
          //The error is sigma/sqrt(N)
          for(int bin=1;bin<61;bin++){
              std::cout<<"bin: "<<bin<<" binentries: "<<binEntries[file][bin-1]<<" hist: "<<histLongitudinalProfile[file]->GetBinContent(bin)<<
                  " divided: "<<histLongitudinalProfile[file]->GetBinContent(bin)/binEntries[file][bin-1]<<std::endl;
          }
          for (int bin=1;bin<61;bin++)
            {
              double meanE = 0.0;
              double error = 0.0;
              if (binEntries[file][bin-1]!=0)
                {
                 meanE = histLongitudinalProfile[file]->GetBinContent(bin)/(double)binEntries[file][bin-1];
                 double meanE2 = histLongitudinalSquaredProfile[file]->GetBinContent(bin)/(double)binEntries[file][bin-1];
                 double sigma2 = meanE2 -meanE*meanE;
                 double sigma = 0.0;
                 if (sigma2 > 0.0) sigma = sqrt(sigma2);
                 error = sigma/sqrt(binEntries[file][bin-1]);
                }
              histLongitudinalProfile[file]->SetBinContent(bin,meanE);
              histLongitudinalProfile[file]->SetBinError(bin,error);
            }
            //histLongitudinalProfile[file]->Draw();
            e_mip = e_mip/binEntriesZ[file][0];
            std::cout<<"integral "<<histLongitudinalProfile[file]->Integral()<<std::endl;
            std::cout<<"energy "<<e_mip<<std::endl;
            //for(int i=0; i<30; i++){std::cout<<"Media energia: "<<EnergyZ[file][i]<<std::endl;}
            std::cout<<"counter: "<<counter<<std::endl;
            counter = 0;
        }//loop over energies
        
  //Arrays for the x-axis
  double x[60];
  double ex[60];
  double ex0[60];
  for (int i = 0; i<60; i++)
    { 
      x[i] = i;
      ex[i] = 0.5; 
      ex0[i] = 0.0;
    }
  int binsZ = 23;
  int binsLong = 53;

  double z_QGSP_BERT_2GeV[binsZ];
  double z_QGSP_BERT_4GeV[binsZ];
  double z_QGSP_BERT_6GeV[binsZ];
  double z_QGSP_BERT_8GeV[binsZ];
  double z_QGSP_BERT_10GeV[binsZ];

  double longitudinalProfile_QGSP_BERT_2GeV[binsLong];
  double longitudinalProfile_QGSP_BERT_4GeV[binsLong];
  double longitudinalProfile_QGSP_BERT_6GeV[binsLong];
  double longitudinalProfile_QGSP_BERT_8GeV[binsLong];
  double longitudinalProfile_QGSP_BERT_10GeV[binsLong];

  for(int iBin=0; iBin<binsZ; iBin++) {
 
      z_QGSP_BERT_2GeV[iBin] = histZ[0]->GetBinContent(iBin+1); // QGSP_BERT 
      if (iBin==0){
          histZ[0]->Write();
          histZ[1]->Write();
          histZ[2]->Write();
          histZ[3]->Write();
          histZ[4]->Write();
      }
      z_QGSP_BERT_4GeV[iBin] = histZ[1]->GetBinContent(iBin+1); 
      z_QGSP_BERT_6GeV[iBin] = histZ[2]->GetBinContent(iBin+1); 
      z_QGSP_BERT_8GeV[iBin] = histZ[3]->GetBinContent(iBin+1); 
      z_QGSP_BERT_10GeV[iBin] = histZ[4]->GetBinContent(iBin+1); 

  }

  for(int iBin=0; iBin<binsLong; iBin++) {
      longitudinalProfile_QGSP_BERT_2GeV[iBin] = histLongitudinalProfile[0]->GetBinContent(iBin+1);
      if (iBin==0){
          histLongitudinalProfile[0]->Write();
          histLongitudinalProfile[1]->Write();
          histLongitudinalProfile[2]->Write();
          histLongitudinalProfile[3]->Write();
          histLongitudinalProfile[4]->Write();
      }
      longitudinalProfile_QGSP_BERT_4GeV[iBin] = histLongitudinalProfile[1]->GetBinContent(iBin+1);
      longitudinalProfile_QGSP_BERT_6GeV[iBin] = histLongitudinalProfile[2]->GetBinContent(iBin+1);
      longitudinalProfile_QGSP_BERT_8GeV[iBin] = histLongitudinalProfile[3]->GetBinContent(iBin+1);
      longitudinalProfile_QGSP_BERT_10GeV[iBin] = histLongitudinalProfile[4]->GetBinContent(iBin+1);

}
  //---- Z distribution ----
  //Data
  double z_Data_2GeV[] = {0.106231, 0.13303, 0.113666, 0.0966606, 0.0787765, 0.068412, 0.0590184, 0.0494627, 0.0414201, 0.0347868, 0.029769, 0.0258555, 0.021765, 0.0188675, 0.0184092, 0.0157484, 0.0146379, 0.0124826, 0.01277, 0.0133686, 0.0119217, 0.012444, 0.0104963};
  
  double errorZ_Data_2GeV[] = {0.00135434, 0.00164353, 0.00140428, 0.00133177, 0.00126571, 0.00125878, 0.00116916, 0.0010933, 0.000984845, 0.00101956, 0.000893853, 0.000831928, 0.000884528, 0.000740615, 0.000832423, 0.000766643, 0.00105523, 0.000779462, 0.000877742, 0.00179325, 0.00130418, 0.00209768, 0.00207657};
  
  double z_Data_4GeV[] = {0.0720123, 0.0890166, 0.091949, 0.0881354, 0.0816472, 0.0746009, 0.0672669, 0.0587247, 0.0518808, 0.0452869, 0.0398821, 0.0343368, 0.0297697, 0.0258466, 0.0232445, 0.0209527, 0.0187104, 0.0170757, 0.0158545, 0.0147186, 0.0144488, 0.0132756, 0.0113632};
  
  double errorZ_Data_4GeV[] = {0.000264215, 0.000363426, 0.000288088, 0.000295284, 0.000308946, 0.000316582, 0.00031576, 0.000297676, 0.000296626, 0.000285061, 0.000278667, 0.000259426, 0.000249525, 0.000249533, 0.000245676, 0.000258308, 0.000230424, 0.000249657, 0.000260349, 0.00027178, 0.000339587, 0.000396072, 0.000524358};
  
  double z_Data_6GeV[] = {0.0510261, 0.0643616, 0.0748715, 0.0779886, 0.0785852, 0.0754118, 0.0704764, 0.0646847, 0.0584962, 0.0518605, 0.04659, 0.0407762, 0.0357238, 0.03144, 0.0279685, 0.0244907, 0.0225663, 0.0201331, 0.0187808, 0.0174499, 0.0170489, 0.0152462, 0.0140231};
  
  double errorZ_Data_6GeV[] = {0.000209029, 0.000259141, 0.000266568, 0.00027543, 0.000296389, 0.000305115, 0.000315303, 0.000314753, 0.000311915, 0.000303799, 0.000300464, 0.000289955, 0.000279333, 0.000268111, 0.000266994, 0.000249195, 0.000277581, 0.000273538, 0.00028131, 0.000311746, 0.000401006, 0.00043316, 0.00059779};
  
  double z_Data_8GeV[] = {0.04067, 0.0518501, 0.0631133, 0.0694785, 0.0726542, 0.0720509, 0.0698938, 0.0656186, 0.0610693, 0.0556832, 0.0510281, 0.0451191, 0.0403516, 0.0352828, 0.0318425, 0.0283854, 0.0258397, 0.0232749, 0.0217971, 0.0203835, 0.0196962, 0.0182067, 0.0167105};
  
  double errorZ_Data_8GeV[] = {0.000122474, 0.000143258, 0.000152621, 0.000162076, 0.000170555, 0.000178147, 0.000185781, 0.000187934, 0.000191937, 0.000193426, 0.000195641, 0.000183837, 0.0001802, 0.000170556, 0.00017028, 0.000170644, 0.000174943, 0.000178758, 0.000194549, 0.000221162, 0.000270319, 0.000318507, 0.0004402220};
  
  double z_Data_10GeV[] = {0.0338262, 0.0439685, 0.0553838, 0.0627901, 0.0681183, 0.0694448, 0.0691975, 0.0662489, 0.0628676, 0.0582296, 0.054035, 0.0486904, 0.0440303, 0.0390096, 0.0350832, 0.0312595, 0.0284568, 0.0256939, 0.0240602, 0.0220925, 0.0209349, 0.0192896, 0.0172886};

  double errorZ_Data_10GeV[] = {7.75864e-05, 9.42754e-05, 0.000102197, 0.000109158, 0.000117776, 0.000121699, 0.000128142, 0.000129802, 0.000134196, 0.000134362, 0.000136902, 0.00013287, 0.000132105, 0.000125501, 0.000125436, 0.000123344, 0.000126645, 0.000129022, 0.000142664, 0.000155447, 0.000196773, 0.000226918, 0.000316865};
 //---- Z energy distribution ----
 //Data
  double longitudinalProfile_Data_2GeV[] = {12.1831, 20.6881, 24.7609, 28.2626, 26.7509, 24.8565, 20.4649, 16.3522, 12.5738, 10.9694, 9.85384, 8.93861, 8.07006, 7.01244, 6.02041, 5.40701, 5.00597, 4.47801, 4.08983, 3.80375, 3.56816, 3.36495, 3.1483, 2.93507, 2.76002, 2.43988, 2.11799, 1.96422, 1.86829, 1.91166, 1.83301, 1.82387, 1.535, 1.50183, 1.45605, 1.34163, 1.22095, 1.15751, 1.09533, 1.09186, 0.973154, 0.987998, 0.953722, 0.990801, 1.04348, 1.17834, 1.29637, 1.45765, 1.52114, 1.73599, 1.82257, 1.22951, 0.724501};

  double errorLongitudinalProfile_Data_2GeV[] = {0.431405, 0.716619, 0.685444, 0.728628, 0.584018, 0.667515, 0.47395, 0.357916, 0.3006, 0.27905, 0.269465, 0.365928, 0.342542, 0.255684, 0.194218, 0.171933, 0.19875, 0.222906, 0.17727, 0.157236, 0.1655, 0.169956, 0.201122, 0.246784, 0.217653, 0.150492, 0.102914, 0.0973229, 0.115738, 0.153968, 0.198955, 0.255813, 0.148039, 0.145899, 0.15316, 0.133925, 0.143556, 0.182725, 0.14837, 0.119135, 0.0891381, 0.0869485, 0.0977944, 0.126839, 0.171714, 0.240377, 0.281187, 0.36472, 0.476468, 0.649249, 0.721735, 0.502929, 0.225555};

  double longitudinalProfile_Data_4GeV[] = {17.2855, 28.6117, 32.1055, 32.4963, 31.8687, 31.0009, 28.3589, 25.7234, 23.2689, 21.2988, 19.6772, 18.0672, 16.701, 15.3538, 14.0959, 13.0961, 12.0084, 10.9777, 10.1992, 9.40018, 8.71437, 8.11526, 7.52294, 6.94564, 6.48819, 5.98634, 5.54296, 5.22006, 4.90297, 4.61512, 4.40537, 4.15145, 3.90335, 3.62609, 3.41874, 3.22261, 3.12305, 2.95845, 2.91154, 2.79976, 2.75686, 2.67133, 2.57789, 2.43938, 2.3459, 2.23384, 2.2572, 2.20977, 2.10637, 1.93494, 1.8489, 1.78064, 1.50816};

  double errorLongitudinalProfile_Data_4GeV[] = {0.151063, 0.246971, 0.227289, 0.226968, 0.183101, 0.215326, 0.159596, 0.154361, 0.145076, 0.131379, 0.116623, 0.1299, 0.110582, 0.109789, 0.108214, 0.104487, 0.0935144, 0.0938008, 0.0893397, 0.0903546, 0.0909065, 0.0861476, 0.0839764, 0.0846903, 0.08011, 0.0730201, 0.0690694, 0.0674407, 0.0685017, 0.0699221, 0.0726633, 0.0774038, 0.0754426, 0.0713599, 0.0716385, 0.0662969, 0.0695684, 0.0715723, 0.0850256, 0.077855, 0.0793804, 0.0783469, 0.0743446, 0.0742959, 0.0707331, 0.0680123, 0.0931633, 0.106149, 0.102567, 0.0916018, 0.104289, 0.141551, 0.163674};

  double longitudinalProfile_Data_6GeV[] = {18.4121, 30.3165, 35.3306, 36.5766, 37.2406, 37.6638, 36.3763, 35.0623, 33.5264, 31.9362, 30.473, 28.9357, 27.48, 25.8159, 24.1825, 22.8283, 21.2668, 19.6762, 18.5545, 17.2246, 16.2256, 15.2371, 14.2719, 13.2486, 12.3359, 11.4364, 10.6898, 10.1271, 9.54122, 8.85384, 8.18976, 7.60768, 7.1609, 6.81262, 6.58923, 6.31926, 6.07743, 5.64747, 5.38586, 5.1249, 4.99859, 4.80884, 4.76417, 4.53276, 4.39328, 4.16256, 4.07447, 3.83332, 3.77704, 3.50987, 3.63644, 3.18747, 2.84687};

  double errorLongitudinalProfile_Data_6GeV[] = {0.190969, 0.298169, 0.293993, 0.295271, 0.24504, 0.297929, 0.227332, 0.229402, 0.218684, 0.209144, 0.189746, 0.205371, 0.179075, 0.181292, 0.175145, 0.173358, 0.155398, 0.154248, 0.147069, 0.145828, 0.151147, 0.143753, 0.141936, 0.140691, 0.13178, 0.124608, 0.125001, 0.131981, 0.132787, 0.123697, 0.117821, 0.120068, 0.121426, 0.127205, 0.143842, 0.154179, 0.143765, 0.12699, 0.127176, 0.143343, 0.136844, 0.121398, 0.131504, 0.129102, 0.130555, 0.130273, 0.143833, 0.136255, 0.151214, 0.146099, 0.220124, 0.225135, 0.275568};

  double longitudinalProfile_Data_8GeV[] = {18.7874, 31.1597, 36.8417, 38.7589, 40.3683, 41.7859, 41.9907, 41.9744, 41.3817, 40.1683, 38.9006, 37.5657, 36.3011, 34.7323, 33.1784, 31.6122, 29.921, 28.1784, 26.6825, 24.9237, 23.3956, 22.0615, 20.729, 19.3674, 18.2729, 17.0889, 16.0755, 15.131, 14.2164, 13.2656, 12.5283, 11.7196, 11.1282, 10.5606, 10.2104, 9.68298, 9.23923, 8.64035, 8.33708, 7.98253, 7.72387, 7.47099, 7.33097, 7.07918, 6.82802, 6.46862, 6.22796, 5.94531, 5.81127, 5.47219, 5.27103, 4.94309, 4.61886};

  double errorLongitudinalProfile_Data_8GeV[] = {0.130435, 0.211322, 0.207976, 0.211424, 0.178932, 0.213809, 0.171755, 0.180578, 0.177048, 0.164608, 0.147022, 0.159956, 0.143558, 0.145161, 0.14606, 0.141537, 0.133664, 0.137836, 0.128531, 0.122076, 0.123788, 0.120226, 0.11813, 0.118857, 0.116212, 0.114608, 0.112516, 0.109419, 0.107671, 0.105022, 0.105295, 0.105316, 0.0989054, 0.102236, 0.115753, 0.109177, 0.109592, 0.105657, 0.111266, 0.115756, 0.11789, 0.119903, 0.120227, 0.120184, 0.12447, 0.127674, 0.131388, 0.13282, 0.155549, 0.146148, 0.164248, 0.212696, 0.351896};

  double longitudinalProfile_Data_10GeV[] = {18.9946, 31.5913, 37.9013, 40.9131, 43.8902, 46.725, 48.0963, 49.3026, 49.7662, 49.3331, 48.7632, 47.9836, 46.9934, 45.4882, 43.8912, 42.1331, 40.1739, 38.0984, 36.481, 34.4937, 32.6172, 30.6913, 28.8606, 26.925, 25.4382, 23.6328, 22.1886, 20.9311, 19.78, 18.5332, 17.6253, 16.5005, 15.6057, 14.6837, 14.1156, 13.3398, 12.799, 11.97, 11.4112, 10.8136, 10.5811, 10.2233, 10.0689, 9.57463, 9.36366, 8.98514, 8.95923, 8.59975, 8.32033, 7.78256, 7.3601, 6.71799, 6.71121};

  double errorLongitudinalProfile_Data_10GeV[] = {0.0968501, 0.156512, 0.158083, 0.165784, 0.144519, 0.17615, 0.141549, 0.150091, 0.150697, 0.144885, 0.133663, 0.147469, 0.132596, 0.133448, 0.133712, 0.128786, 0.12177, 0.12621, 0.120498, 0.117713, 0.118963, 0.112512, 0.110071, 0.108978, 0.10418, 0.0986425, 0.0980296, 0.0989839, 0.0978708, 0.0954869, 0.0978137, 0.0980419, 0.0936939, 0.0933821, 0.0977084, 0.0955099, 0.101115, 0.100212, 0.0989616, 0.0964551, 0.106428, 0.106368, 0.111488, 0.108361, 0.114204, 0.117519, 0.134541, 0.133455, 0.146011, 0.153163, 0.184159, 0.187571, 0.415923}; 

  //---------------------------------------------------------------------
  // Correction factors to the data
  // From "CalculateSystematicError.C"
  // Last changed 24/10/2014
  //---------------------------------------------------------------------

  double corrFactor_Z_2GeV[] = {0.971633, 0.960669, 0.968973, 0.965842, 0.971563, 0.955553, 0.953326, 0.942517, 0.938088, 0.95235, 0.942504, 0.960796, 0.981133, 0.956223, 0.940402, 0.885661, 0.863285, 0.838569, 0.780188, 0.760841, 0.801144, 0.756929, 0.64895};

  double corrFactor_Z_4GeV[] = {0.978123, 0.976371, 0.976899, 0.978858, 0.984916, 0.985938, 0.985707, 0.992966, 0.992389, 0.984075, 0.976574, 0.970816, 0.969484, 0.964375, 0.96373, 0.958333, 0.956953, 0.945614, 0.942704, 0.922563, 0.916234, 0.908163, 0.91192};

  double corrFactor_Z_6GeV[] = {0.987192, 0.986785, 0.98727, 0.988533, 0.98881, 0.99144, 0.992621, 0.993995, 0.997194, 0.999505, 0.996971, 0.993648, 0.99222, 0.987051, 0.986423, 0.98101, 0.977399, 0.975833, 0.968623, 0.966741, 0.960403, 0.952273, 0.940526};

  double corrFactor_Z_8GeV[] = {0.978721, 0.976423, 0.977681, 0.979261, 0.980577, 0.983066, 0.984789, 0.988715, 0.993063, 0.998422, 0.998273, 0.994377, 0.989734, 0.983016, 0.974835, 0.969371, 0.964101, 0.95604, 0.950213, 0.94555, 0.943173, 0.940748, 0.916555};

  double corrFactor_Z_10GeV[] = {0.994399, 0.994144, 0.993, 0.99347, 0.993834, 0.994505, 0.994597, 0.99512, 0.995948, 0.997712, 0.998678, 0.999779, 0.99845, 0.996408, 0.994715, 0.990697, 0.990333, 0.98664, 0.985118, 0.979392, 0.976584, 0.976811, 0.988345};
  
  for (int i = 0; i<23; i++)
    {
      z_Data_2GeV[i] *= corrFactor_Z_2GeV[i];
      z_Data_4GeV[i] *= corrFactor_Z_4GeV[i];
      z_Data_6GeV[i] *= corrFactor_Z_6GeV[i];
      z_Data_8GeV[i] *= corrFactor_Z_8GeV[i];
      z_Data_10GeV[i] *= corrFactor_Z_10GeV[i];
      errorZ_Data_2GeV[i] *= corrFactor_Z_2GeV[i]; 
      errorZ_Data_4GeV[i] *= corrFactor_Z_4GeV[i]; 
      errorZ_Data_6GeV[i] *= corrFactor_Z_6GeV[i]; 
      errorZ_Data_8GeV[i] *= corrFactor_Z_8GeV[i]; 
      errorZ_Data_10GeV[i] *= corrFactor_Z_10GeV[i]; 
      }

  //Normalise to 1
  double integralZ_Data_2GeV = 0.0;
  double integralZ_Data_4GeV = 0.0;
  double integralZ_Data_6GeV = 0.0;
  double integralZ_Data_8GeV = 0.0;
  double integralZ_Data_10GeV = 0.0;
  for (int i = 0; i<23; i++)
    {
      integralZ_Data_2GeV += z_Data_2GeV[i];
      integralZ_Data_4GeV += z_Data_4GeV[i];
      integralZ_Data_6GeV += z_Data_6GeV[i];
      integralZ_Data_8GeV += z_Data_8GeV[i];
      integralZ_Data_10GeV += z_Data_10GeV[i];
    }

  for (int i = 0; i<23; i++)
    {
      z_Data_2GeV[i] /= integralZ_Data_2GeV;
      z_Data_4GeV[i] /= integralZ_Data_4GeV;
      z_Data_6GeV[i] /= integralZ_Data_6GeV;
      z_Data_8GeV[i] /= integralZ_Data_8GeV;
      z_Data_10GeV[i] /= integralZ_Data_10GeV;
      errorZ_Data_2GeV[i] /= integralZ_Data_2GeV; 
      errorZ_Data_4GeV[i] /= integralZ_Data_4GeV; 
      errorZ_Data_6GeV[i] /= integralZ_Data_6GeV; 
      errorZ_Data_8GeV[i] /= integralZ_Data_8GeV; 
      errorZ_Data_10GeV[i] /= integralZ_Data_10GeV; 
    }

  //idem for MC
  //Normalise to 1
  double integralZ_QGSP_BERT_2GeV = 0.0;
  double integralZ_QGSP_BERT_4GeV = 0.0;
  double integralZ_QGSP_BERT_6GeV = 0.0;
  double integralZ_QGSP_BERT_8GeV = 0.0;
  double integralZ_QGSP_BERT_10GeV = 0.0;
  for (int i = 0; i<23; i++)
    {
      integralZ_QGSP_BERT_2GeV += z_QGSP_BERT_2GeV[i];
      integralZ_QGSP_BERT_4GeV += z_QGSP_BERT_4GeV[i];
      integralZ_QGSP_BERT_6GeV += z_QGSP_BERT_6GeV[i];
      integralZ_QGSP_BERT_8GeV += z_QGSP_BERT_8GeV[i];
      integralZ_QGSP_BERT_10GeV += z_QGSP_BERT_10GeV[i];
    }
  for (int i = 0; i<23; i++)
    {
      z_QGSP_BERT_2GeV[i] /= integralZ_QGSP_BERT_2GeV;
      z_QGSP_BERT_4GeV[i] /= integralZ_QGSP_BERT_4GeV;
      z_QGSP_BERT_6GeV[i] /= integralZ_QGSP_BERT_6GeV;
      z_QGSP_BERT_8GeV[i] /= integralZ_QGSP_BERT_8GeV;
      z_QGSP_BERT_10GeV[i] /= integralZ_QGSP_BERT_10GeV;
    }

  double corrFactor_LongitudinalProfile_2GeV[] = {0.968968, 0.968916, 0.986983, 0.982569, 0.986389, 0.985317, 0.992704, 0.991558, 0.978885, 0.975471, 0.963643, 0.951649, 0.952297, 0.957115, 0.95935, 0.954196, 0.966207, 0.944524, 0.952282, 0.958507, 0.946462, 0.931624, 0.93457, 0.948294, 0.963897, 0.963828, 0.951536, 0.920635, 0.881572, 0.864616, 0.896177, 0.933397, 0.946063, 0.943383, 0.922123, 0.879507, 0.831729, 0.79808, 0.799775, 0.824563, 0.820506, 0.804538, 0.78168, 0.807945, 0.837585, 0.841698, 0.788518, 0.80189, 0.805799, 0.788282, 0.706347, 0.561623, 0.604098};

  double corrFactor_LongitudinalProfile_4GeV[] = {0.995554, 0.996712, 0.99631, 0.996974, 0.997859, 0.997012, 0.995668, 0.994841, 0.991215, 0.985523, 0.985129, 0.983468, 0.980566, 0.977352, 0.973557, 0.973034, 0.974579, 0.974963, 0.971811, 0.969154, 0.96537, 0.962062, 0.959782, 0.959061, 0.954771, 0.949505, 0.939061, 0.933604, 0.929697, 0.932818, 0.931943, 0.93253, 0.925015, 0.922504, 0.919246, 0.919225, 0.919214, 0.921094, 0.916918, 0.916435, 0.910792, 0.912432, 0.91185, 0.919008, 0.917568, 0.910392, 0.903576, 0.896671, 0.865328, 0.863696, 0.86203, 0.866028, 0.869268};

  double corrFactor_LongitudinalProfile_6GeV[] = {0.998189, 0.996571, 0.994819, 0.994053, 0.997813, 0.996018, 0.997642, 0.998651, 0.997968, 0.99632, 0.994679, 0.993033, 0.991508, 0.99015, 0.99009, 0.989681, 0.988285, 0.986441, 0.984939, 0.9838, 0.982762, 0.980719, 0.979784, 0.976022, 0.973806, 0.973417, 0.97353, 0.972379, 0.970217, 0.970095, 0.968274, 0.967146, 0.963963, 0.959747, 0.955253, 0.956076, 0.959491, 0.960622, 0.963349, 0.963172, 0.961778, 0.956752, 0.947343, 0.945525, 0.955079, 0.952421, 0.941122, 0.933236, 0.929256, 0.927699, 0.923769, 0.923583, 0.907221};
  
  double corrFactor_LongitudinalProfile_8GeV[] = {0.996635, 0.997647, 0.996303, 0.998313, 0.9993, 0.997638, 0.997569, 0.997681, 0.996465, 0.994623, 0.993552, 0.99241, 0.989413, 0.9858, 0.983755, 0.982198, 0.980975, 0.978936, 0.977276, 0.976433, 0.975392, 0.974174, 0.972582, 0.968627, 0.963636, 0.959278, 0.955774, 0.953172, 0.950163, 0.947626, 0.943876, 0.941331, 0.93711, 0.935912, 0.932939, 0.9304, 0.925595, 0.923961, 0.921175, 0.920056, 0.913936, 0.910311, 0.908549, 0.906012, 0.900285, 0.901659, 0.892931, 0.892385, 0.878603, 0.876906, 0.861881, 0.857679, 0.807869 };
 
  double corrFactor_LongitudinalProfile_10GeV[] = {0.998993, 0.997992, 0.998181, 0.999264, 0.999739, 0.999034, 0.99896, 0.998855, 0.99908, 0.998233, 0.997941, 0.99792, 0.998182, 0.998361, 0.997756, 0.997112, 0.995974, 0.995179, 0.995351, 0.994818, 0.994078, 0.993755, 0.993695, 0.992941, 0.991865, 0.990016, 0.988181, 0.986092, 0.984801, 0.984221, 0.983537, 0.983202, 0.982963, 0.982889, 0.98194, 0.980773, 0.978624, 0.977189, 0.976373, 0.975026, 0.970854, 0.970702, 0.972755, 0.972065, 0.970732, 0.967908, 0.968739, 0.968948, 0.970247, 0.970134, 0.971354, 0.976567, 0.975379};
    
  for (int i = 0; i<53; i++)
    {
      longitudinalProfile_Data_2GeV[i] *= corrFactor_LongitudinalProfile_2GeV[i];
      errorLongitudinalProfile_Data_2GeV[i] *= corrFactor_LongitudinalProfile_2GeV[i]; 
      longitudinalProfile_Data_4GeV[i] *= corrFactor_LongitudinalProfile_4GeV[i];
      errorLongitudinalProfile_Data_4GeV[i] *= corrFactor_LongitudinalProfile_4GeV[i]; 
      longitudinalProfile_Data_6GeV[i] *= corrFactor_LongitudinalProfile_6GeV[i];
      errorLongitudinalProfile_Data_6GeV[i] *= corrFactor_LongitudinalProfile_6GeV[i]; 
      longitudinalProfile_Data_8GeV[i] *= corrFactor_LongitudinalProfile_8GeV[i];
      errorLongitudinalProfile_Data_8GeV[i] *= corrFactor_LongitudinalProfile_8GeV[i]; 
      longitudinalProfile_Data_10GeV[i] *= corrFactor_LongitudinalProfile_10GeV[i];
      errorLongitudinalProfile_Data_10GeV[i] *= corrFactor_LongitudinalProfile_10GeV[i]; 
    }


  //---------------------------------------------------------------------
  //Systematic error on the data
  //Estimated from FTFP_BERT using "CalculateSystematicError.C"
  //Last changed 24/10/2014
  //---------------------------------------------------------------------
  double sysError_Z_2GeV[] = {0.0614481, 0.0507045, 0.0601248, 0.0618481, 0.0457919, 0.0265975, 0.0297765, 0.0104991, 0.0171821, 0.022538, 0.0263854, 0.0547584, 0.06315, 0.0959444, 0.123643, 0.139554, 0.129274, 0.18583, 0.21469, 0.203747, 0.231691, 0.283134, 0.542381};
  
  double sysError_Z_4GeV[] = {0.0316955, 0.043565, 0.0317612, 0.022952, 0.0162371, 0.0138018, 0.0144336, 0.0160444, 0.0212015, 0.0214005, 0.0246628, 0.0334586, 0.0353972, 0.0338037, 0.038646, 0.0408692, 0.0502933, 0.048549, 0.0558336, 0.0660009, 0.0730764, 0.0669543, 0.086413};
  
  double sysError_Z_6GeV[] = {0.0425185, 0.0447, 0.0332638, 0.0222071, 0.0117411, 0.00691521, 0.0076961, 0.0126817, 0.0165922, 0.018366, 0.0211791, 0.0244286, 0.0246645, 0.0239947, 0.0286501, 0.0276474, 0.0268756, 0.0298857, 0.0308047, 0.0364215, 0.0376613, 0.038433, 0.047401};
  
  double sysError_Z_8GeV[] = {0.042577, 0.0444756, 0.035726, 0.0263782, 0.0149724, 0.00854354, 0.00401643, 0.0068495, 0.0108444, 0.0124455, 0.0178193, 0.019273, 0.022698, 0.0235529, 0.0259854, 0.0273032, 0.0242195, 0.0262226, 0.02498, 0.024507, 0.0287066, 0.0282443, 0.0353177};
  
  double sysError_Z_10GeV[] = {0.0414185, 0.0447892, 0.0359881, 0.0280388, 0.0182029, 0.011913, 0.00483946, 0.00263663, 0.0067721, 0.00998876, 0.0136957, 0.0163807, 0.0206071, 0.0218279, 0.0232222, 0.0243188, 0.024965, 0.0253187, 0.0253993, 0.0220921, 0.01794, 0.0216232, 0.0286523};
  
  for (int i=0;i<23;i++) 
    { 
      sysError_Z_2GeV[i] = sysError_Z_2GeV[i]*z_Data_2GeV[i]; 
      sysError_Z_4GeV[i] = sysError_Z_4GeV[i]*z_Data_4GeV[i];
      sysError_Z_6GeV[i] = sysError_Z_6GeV[i]*z_Data_6GeV[i];
      sysError_Z_8GeV[i] = sysError_Z_8GeV[i]*z_Data_8GeV[i];
      sysError_Z_10GeV[i] = sysError_Z_10GeV[i]*z_Data_10GeV[i];
    }
  

  double sysError_LongitudinalProfile_2GeV[] = {0.0825848, 0.0790301, 0.08605, 0.114797, 0.112439, 0.109372, 0.0970629, 0.08706, 0.0822022, 0.077725, 0.0696827, 0.0624276, 0.0586791, 0.0526439, 0.0423009, 0.0331923, 0.0179538, 0.0221897, 0.0252533, 0.0320474, 0.0428552, 0.0449079, 0.0487056, 0.0565071, 0.0603677, 0.0521002, 0.0508782, 0.0629792, 0.0663277, 0.088278, 0.0790154, 0.0961704, 0.0845312, 0.0968867, 0.118667, 0.140337, 0.1239, 0.122954, 0.100566, 0.141626, 0.173106, 0.211058, 0.126697, 0.129318, 0.174288, 0.167862, 0.189414, 0.202191, 0.22526, 0.204798, 0.178397, 0.180408, 0.421587};

  double sysError_LongitudinalProfile_4GeV[] = {0.0676656, 0.0669821, 0.0704994, 0.0830439, 0.0704209, 0.0579389, 0.0477848, 0.0403347, 0.0377226, 0.0406436, 0.043083, 0.047028, 0.0472691, 0.0463077, 0.0467408, 0.045209, 0.0430118, 0.0419689, 0.045032, 0.0477205, 0.0476315, 0.0471792, 0.0451002, 0.0430851, 0.0422614, 0.0401708, 0.0400963, 0.0420711, 0.0447172, 0.0454159, 0.0421863, 0.0413748, 0.0411222, 0.0402734, 0.0403629, 0.0368283, 0.0353876, 0.0319338, 0.0283588, 0.0213147, 0.01884, 0.0300137, 0.044217, 0.046443, 0.0329801, 0.0354572, 0.0381942, 0.0431069, 0.0706544, 0.0823095, 0.0772339, 0.0872396, 0.0892618};

  double sysError_LongitudinalProfile_6GeV[] = {0.0749263, 0.0732934, 0.0686896, 0.0639875, 0.0528183, 0.0428846, 0.0338174, 0.0278991, 0.0275169, 0.0308016, 0.0315934, 0.0324996, 0.0350075, 0.0359571, 0.0380381, 0.0393525, 0.0403183, 0.0402792, 0.0407246, 0.039937, 0.0399349, 0.0439204, 0.0453613, 0.0455139, 0.0458858, 0.0454367, 0.0448188, 0.0430644, 0.0408713, 0.0398636, 0.0386385, 0.0397607, 0.0417749, 0.0437256, 0.0465028, 0.0470742, 0.0463533, 0.0416976, 0.0386443, 0.0348898, 0.0372981, 0.0343401, 0.0351554, 0.0365575, 0.0422434, 0.0475519, 0.0541883, 0.0597699, 0.0443394, 0.0468545, 0.0658813, 0.0461439, 0.0599275};

  double sysError_LongitudinalProfile_8GeV[] = {0.0788959, 0.0759517, 0.0697631, 0.0622683, 0.0527425, 0.0441903, 0.0366726, 0.030909, 0.0273547, 0.0289433, 0.0291798, 0.0296867, 0.0309168, 0.0311996, 0.0320635, 0.0330194, 0.033499, 0.0345222, 0.0360162, 0.0368087, 0.0378351, 0.038844, 0.0401916, 0.0411938, 0.0429512, 0.0419907, 0.0409604, 0.040733, 0.0399389, 0.0391947, 0.0391032, 0.0412661, 0.0454603, 0.046166, 0.0430372, 0.0383953, 0.0372349, 0.0368956, 0.0389512, 0.0381096, 0.0403858, 0.0380232, 0.0382133, 0.0353895, 0.032281, 0.0335276, 0.037277, 0.0359512, 0.0307304, 0.0230656, 0.0197217, 0.0339121, 0.0709372};

  double sysError_LongitudinalProfile_10GeV[] = {0.0824893, 0.0792877, 0.0732209, 0.0646446, 0.0540509, 0.0446597, 0.0379284, 0.0326091, 0.0285863, 0.0289042, 0.0278239, 0.0269944, 0.0278356, 0.0279719, 0.0287593, 0.029336, 0.029728, 0.0300499, 0.0313878, 0.0324964, 0.0335474, 0.0344219, 0.0351777, 0.0365154, 0.0382988, 0.0388606, 0.0385186, 0.0377221, 0.0374381, 0.0375026, 0.0402029, 0.0408894, 0.040575, 0.0412056, 0.0419266, 0.0414732, 0.0414248, 0.0409618, 0.0400707, 0.0377432, 0.0387161, 0.0384777, 0.0337955, 0.0303512, 0.0315256, 0.0276468, 0.0257659, 0.0248326, 0.0204012, 0.0200022, 0.0237253, 0.0384519, 0.0476407};

  for (int i=0;i<53;i++) 
    { 
      sysError_LongitudinalProfile_2GeV[i] = sysError_LongitudinalProfile_2GeV[i]*longitudinalProfile_Data_2GeV[i]; 
      sysError_LongitudinalProfile_4GeV[i] = sysError_LongitudinalProfile_4GeV[i]*longitudinalProfile_Data_4GeV[i];
      sysError_LongitudinalProfile_6GeV[i] = sysError_LongitudinalProfile_6GeV[i]*longitudinalProfile_Data_6GeV[i];
      sysError_LongitudinalProfile_8GeV[i] = sysError_LongitudinalProfile_8GeV[i]*longitudinalProfile_Data_8GeV[i];
      sysError_LongitudinalProfile_10GeV[i] = sysError_LongitudinalProfile_10GeV[i]*longitudinalProfile_Data_10GeV[i];
    }

  //---------------------------------------------------------------------
  //Sum of the statistical and systematic error added in quadrature
  //---------------------------------------------------------------------
  double totError_Z_2GeV[23];
  double totError_Z_4GeV[23];
  double totError_Z_6GeV[23];
  double totError_Z_8GeV[23];
  double totError_Z_10GeV[23];
  double totError_LongitudinalProfile_2GeV[53];
  double totError_LongitudinalProfile_4GeV[53];
  double totError_LongitudinalProfile_6GeV[53];
  double totError_LongitudinalProfile_8GeV[53];
  double totError_LongitudinalProfile_10GeV[53];

  for (int i=0;i<23;i++) { 
    totError_Z_2GeV[i] = sysError_Z_2GeV[i]*sysError_Z_2GeV[i] + errorZ_Data_2GeV[i]*errorZ_Data_2GeV[i];
    totError_Z_2GeV[i] = sqrt(totError_Z_2GeV[i]);

    totError_Z_4GeV[i] = sysError_Z_4GeV[i]*sysError_Z_4GeV[i] + errorZ_Data_4GeV[i]*errorZ_Data_4GeV[i];
    totError_Z_4GeV[i] = sqrt(totError_Z_4GeV[i]);
    
    totError_Z_6GeV[i] = sysError_Z_6GeV[i]*sysError_Z_6GeV[i] + errorZ_Data_6GeV[i]*errorZ_Data_6GeV[i];
    totError_Z_6GeV[i] = sqrt(totError_Z_6GeV[i]);
    
    totError_Z_8GeV[i] = sysError_Z_8GeV[i]*sysError_Z_8GeV[i] + errorZ_Data_8GeV[i]*errorZ_Data_8GeV[i];
    totError_Z_8GeV[i] = sqrt(totError_Z_8GeV[i]);
    
    totError_Z_10GeV[i] = sysError_Z_10GeV[i]*sysError_Z_10GeV[i] + errorZ_Data_10GeV[i]*errorZ_Data_10GeV[i];
    totError_Z_10GeV[i] = sqrt(totError_Z_10GeV[i]);
  }

  for (int i=0;i<53;i++) { 
    totError_LongitudinalProfile_2GeV[i] = sysError_LongitudinalProfile_2GeV[i]*sysError_LongitudinalProfile_2GeV[i] 
      + errorLongitudinalProfile_Data_2GeV[i]*errorLongitudinalProfile_Data_2GeV[i];
    totError_LongitudinalProfile_2GeV[i] = sqrt(totError_LongitudinalProfile_2GeV[i]);

    totError_LongitudinalProfile_4GeV[i] = sysError_LongitudinalProfile_4GeV[i]*sysError_LongitudinalProfile_4GeV[i] 
      + errorLongitudinalProfile_Data_4GeV[i]*errorLongitudinalProfile_Data_4GeV[i];
    totError_LongitudinalProfile_4GeV[i] = sqrt(totError_LongitudinalProfile_4GeV[i]);
    
    totError_LongitudinalProfile_6GeV[i] = sysError_LongitudinalProfile_6GeV[i]*sysError_LongitudinalProfile_6GeV[i] 
      + errorLongitudinalProfile_Data_6GeV[i]*errorLongitudinalProfile_Data_6GeV[i];
    totError_LongitudinalProfile_6GeV[i] = sqrt(totError_LongitudinalProfile_6GeV[i]);
    
    totError_LongitudinalProfile_8GeV[i] = sysError_LongitudinalProfile_8GeV[i]*sysError_LongitudinalProfile_8GeV[i] 
      + errorLongitudinalProfile_Data_8GeV[i]*errorLongitudinalProfile_Data_8GeV[i];
    totError_LongitudinalProfile_8GeV[i] = sqrt(totError_LongitudinalProfile_8GeV[i]);
    
    totError_LongitudinalProfile_10GeV[i] = sysError_LongitudinalProfile_10GeV[i]*sysError_LongitudinalProfile_10GeV[i] 
      + errorLongitudinalProfile_Data_10GeV[i]*errorLongitudinalProfile_Data_10GeV[i];
    totError_LongitudinalProfile_10GeV[i] = sqrt(totError_LongitudinalProfile_10GeV[i]);
  }

  //---------------------------------------------------------------------
  //Define TGraphs for Data and MC
  //---------------------------------------------------------------------
  int nBins = 53;
  int nBinsZ = 23;
  
  //Data
  TGraphErrors* gZ_Data_2GeV = new TGraphErrors(nBinsZ,x,z_Data_2GeV,ex0,errorZ_Data_2GeV);
  myGraphSetUp(gZ_Data_2GeV, kRed,1);
  gZ_Data_2GeV->SetLineWidth(1);
  TGraphErrors* gZ_Data_2GeV_tot = new TGraphErrors(nBinsZ,x,z_Data_2GeV, ex0, totError_Z_2GeV);
  myGraphSetUp(gZ_Data_2GeV_tot, kRed+2,1);
  gZ_Data_2GeV_tot->SetLineWidth(1);
  gZ_Data_2GeV_tot->SetFillColor(kRed-7);
  gZ_Data_2GeV_tot->SetFillStyle(3002);

  TGraphErrors* gZ_Data_4GeV = new TGraphErrors(nBinsZ,x,z_Data_4GeV,ex0,errorZ_Data_4GeV);
  myGraphSetUp(gZ_Data_4GeV, kRed,1);
  gZ_Data_4GeV->SetLineWidth(1);
  TGraphErrors* gZ_Data_4GeV_tot = new TGraphErrors(nBinsZ,x,z_Data_4GeV, ex0, totError_Z_4GeV);
  myGraphSetUp(gZ_Data_4GeV_tot, kRed+2,1);
  gZ_Data_4GeV_tot->SetLineWidth(1);
  gZ_Data_4GeV_tot->SetFillColor(kRed-7);
  gZ_Data_4GeV_tot->SetFillStyle(3002);

  TGraphErrors* gZ_Data_6GeV = new TGraphErrors(nBinsZ,x,z_Data_6GeV,ex0,errorZ_Data_6GeV);
  myGraphSetUp(gZ_Data_6GeV, kRed,1);
  gZ_Data_6GeV->SetLineWidth(1);
  TGraphErrors* gZ_Data_6GeV_tot = new TGraphErrors(nBinsZ,x,z_Data_6GeV, ex0, totError_Z_6GeV);
  myGraphSetUp(gZ_Data_6GeV_tot, kRed+2,1);
  gZ_Data_6GeV_tot->SetLineWidth(1);
  gZ_Data_6GeV_tot->SetFillColor(kRed-7);
  gZ_Data_6GeV_tot->SetFillStyle(3002);

  TGraphErrors* gZ_Data_8GeV = new TGraphErrors(nBinsZ,x,z_Data_8GeV,ex0,errorZ_Data_8GeV);
  myGraphSetUp(gZ_Data_8GeV, kRed,1);
  gZ_Data_8GeV->SetLineWidth(1);
  TGraphErrors* gZ_Data_8GeV_tot = new TGraphErrors(nBinsZ,x,z_Data_8GeV, ex0, totError_Z_8GeV);
  myGraphSetUp(gZ_Data_8GeV_tot, kRed+2,1);
  gZ_Data_8GeV_tot->SetLineWidth(1);
  gZ_Data_8GeV_tot->SetFillColor(kRed-7);
  gZ_Data_8GeV_tot->SetFillStyle(3002);

  TGraphErrors* gZ_Data_10GeV = new TGraphErrors(nBinsZ,x,z_Data_10GeV,ex0,errorZ_Data_10GeV);
  myGraphSetUp(gZ_Data_10GeV, kRed,1);
  gZ_Data_10GeV->SetLineWidth(1);
  TGraphErrors* gZ_Data_10GeV_tot = new TGraphErrors(nBinsZ,x,z_Data_10GeV, ex0, totError_Z_10GeV);
  myGraphSetUp(gZ_Data_10GeV_tot, kRed+2,1);
  gZ_Data_10GeV_tot->SetLineWidth(1);
  gZ_Data_10GeV_tot->SetFillColor(kRed-7);
  gZ_Data_10GeV_tot->SetFillStyle(3002);

  //QGSP_BERT
  TGraph* gZ_QGSP_BERT_2GeV = new TGraph(nBinsZ,x,z_QGSP_BERT_2GeV);
  myGraphSetUp(gZ_QGSP_BERT_2GeV, kMagenta+4,1);

  TGraph* gZ_QGSP_BERT_4GeV = new TGraph(nBinsZ,x,z_QGSP_BERT_4GeV);
  myGraphSetUp(gZ_QGSP_BERT_4GeV, kMagenta+4,1);

  TGraph* gZ_QGSP_BERT_6GeV = new TGraph(nBinsZ,x,z_QGSP_BERT_6GeV);
  myGraphSetUp(gZ_QGSP_BERT_6GeV, kMagenta+4,1);

  TGraph* gZ_QGSP_BERT_8GeV = new TGraph(nBinsZ,x,z_QGSP_BERT_8GeV);
  myGraphSetUp(gZ_QGSP_BERT_8GeV, kMagenta+4,1);

  TGraph* gZ_QGSP_BERT_10GeV = new TGraph(nBinsZ,x,z_QGSP_BERT_10GeV);
  myGraphSetUp(gZ_QGSP_BERT_10GeV, kMagenta+4,1);
  
  //Define histograms for the axis
  TH1F* histoZ = new TH1F("Z","Z",nBinsZ,-0.5,22.5);
  histoZ->SetTitle(";Shower depth [layer];Entries (normalised to unity)");
  histoZ->SetAxisRange(0.0,0.15,"Y");

  //2 GeV
  TCanvas* canvasZ2 = new TCanvas("Z2GeV", "layer (z) of hits in the shower at 2 GeV",0,0,1000,900);
  histoZ->Draw();
  gZ_Data_2GeV_tot->Draw("p3");
  gZ_QGSP_BERT_2GeV->Draw("l");
  gZ_Data_2GeV->Draw("p");
  TLegend *legendZ2 = new TLegend(0.57,0.61,0.93,0.92,NULL,"brNDC");
  legendZ2->SetFillColor(kWhite);
  legendZ2->SetTextFont(font);
  legendZ2->SetTextSize(sizeLegend);
  legendZ2->SetHeader("2 GeV");
  legendZ2->AddEntry(gZ_Data_2GeV,"#pi^{-} FNAL 2008","p");
  legendZ2->AddEntry(gZ_QGSP_BERT_2GeV,"QGSP_BERT","l");
  legendZ2->Draw();
  text.DrawLatex(5.4,0.14,"#splitline{CALICE}{Si-W ECAL}");
  canvasZ2->Write();

  //4 GeV
  TCanvas* canvasZ4 = new TCanvas("Z4GeV", "layer (z) of hits in the shower at 4 GeV",0,0,1000,900);
  histoZ->Draw();
  gZ_Data_4GeV_tot->Draw("p3");
  gZ_QGSP_BERT_4GeV->Draw("l");
  gZ_Data_4GeV->Draw("p");
  TLegend *legendZ4 = new TLegend(0.57,0.61,0.93,0.92,NULL,"brNDC");
  legendZ4->SetFillColor(kWhite);
  legendZ4->SetTextFont(font);
  legendZ4->SetTextSize(sizeLegend);
  legendZ4->SetHeader("4 GeV");
  legendZ4->AddEntry(gZ_Data_4GeV,"#pi^{-} FNAL 2008","p");
  legendZ4->AddEntry(gZ_QGSP_BERT_2GeV,"QGSP_BERT","l");
  legendZ4->Draw();
  text.DrawLatex(3.9,0.14,"#splitline{CALICE}{Si-W ECAL}");
  canvasZ4->Write();

  //6 GeV
  TCanvas* canvasZ6 = new TCanvas("Z6GeV", "layer (z) of hits in the shower at 6 GeV",0,0,1000,900);
  histoZ->Draw();
  gZ_Data_6GeV_tot->Draw("p3");
  gZ_QGSP_BERT_6GeV->Draw("l");
  gZ_Data_6GeV->Draw("p");
  TLegend *legendZ6 = new TLegend(0.57,0.61,0.93,0.92,NULL,"brNDC");
  legendZ6->SetFillColor(kWhite);
  legendZ6->SetTextFont(font);
  legendZ6->SetTextSize(sizeLegend);
  legendZ6->SetHeader("6 GeV");
  legendZ6->AddEntry(gZ_Data_6GeV,"#pi^{-} FNAL 2008","p");
  legendZ6->AddEntry(gZ_QGSP_BERT_2GeV,"QGSP_BERT","l");
  legendZ6->Draw();
  text.DrawLatex(3.9,0.14,"#splitline{CALICE}{Si-W ECAL}");
  canvasZ6->Write();

  //8 GeV
  TCanvas* canvasZ8 = new TCanvas("Z8GeV", "layer (z) of hits in the shower at 8 GeV",0,0,1000,900);
  histoZ->Draw();
  gZ_Data_8GeV_tot->Draw("p3");
  gZ_QGSP_BERT_8GeV->Draw("l");
  gZ_Data_8GeV->Draw("p");
  TLegend *legendZ8 = new TLegend(0.57,0.61,0.93,0.92,NULL,"brNDC");
  legendZ8->SetFillColor(kWhite);
  legendZ8->SetTextFont(font);
  legendZ8->SetTextSize(sizeLegend);
  legendZ8->SetHeader("8 GeV");
  legendZ8->AddEntry(gZ_Data_8GeV,"#pi^{-} FNAL 2008","p");
  legendZ8->AddEntry(gZ_QGSP_BERT_2GeV,"QGSP_BERT","l");
  legendZ8->Draw();
  text.DrawLatex(3.9,0.14,"#splitline{CALICE}{Si-W ECAL}");
  canvasZ8->Write();
  
  //10 GeV
  TCanvas* canvasZ10 = new TCanvas("Z10GeV", "layer (z) of hits in the shower at 10 GeV",0,0,1000,900);
  histoZ->Draw();
  gZ_Data_10GeV_tot->Draw("p3");
  gZ_QGSP_BERT_10GeV->Draw("l");
  gZ_Data_10GeV->Draw("p");
  TLegend *legendZ10 = new TLegend(0.57,0.61,0.93,0.92,NULL,"brNDC");
  legendZ10->SetFillColor(kWhite);
  legendZ10->SetTextFont(font);
  legendZ10->SetTextSize(sizeLegend);
  legendZ10->SetHeader("10 GeV");
  legendZ10->AddEntry(gZ_Data_10GeV,"#pi^{-} FNAL 2008","p");
  legendZ10->AddEntry(gZ_QGSP_BERT_2GeV,"QGSP_BERT","l");
  legendZ10->Draw();
  text.DrawLatex(3.9,0.14,"#splitline{CALICE}{Si-W ECAL}");
  canvasZ10->Write();

  //Longitudinal Profile
  //Data
  TGraphErrors* gLongitudinalProfile_Data_2GeV = new TGraphErrors(nBins,x,longitudinalProfile_Data_2GeV,ex0,errorZ_Data_2GeV);
  myGraphSetUp(gLongitudinalProfile_Data_2GeV, kRed,1);
  gLongitudinalProfile_Data_2GeV->SetLineWidth(1);
  TGraphErrors* gLongitudinalProfile_Data_2GeV_tot = new TGraphErrors(nBins,x,longitudinalProfile_Data_2GeV, ex0, totError_LongitudinalProfile_2GeV);
  myGraphSetUp(gLongitudinalProfile_Data_2GeV_tot, kRed+2,1);
  gLongitudinalProfile_Data_2GeV_tot->SetLineWidth(1);
  gLongitudinalProfile_Data_2GeV_tot->SetFillStyle(3002);
  gLongitudinalProfile_Data_2GeV_tot->SetFillColor(kRed-7);
   
  TGraphErrors* gLongitudinalProfile_Data_4GeV = new TGraphErrors(nBins,x,longitudinalProfile_Data_4GeV,ex0,errorZ_Data_4GeV);
  myGraphSetUp(gLongitudinalProfile_Data_4GeV, kRed,1);
  gLongitudinalProfile_Data_4GeV->SetLineWidth(1);
  TGraphErrors* gLongitudinalProfile_Data_4GeV_tot = new TGraphErrors(nBins,x,longitudinalProfile_Data_4GeV, ex0, totError_LongitudinalProfile_4GeV);
  myGraphSetUp(gLongitudinalProfile_Data_4GeV_tot, kRed+2,1);
  gLongitudinalProfile_Data_4GeV_tot->SetLineWidth(1);
  gLongitudinalProfile_Data_4GeV_tot->SetFillStyle(3002);
  gLongitudinalProfile_Data_4GeV_tot->SetFillColor(kRed-7);

  TGraphErrors* gLongitudinalProfile_Data_6GeV = new TGraphErrors(nBins,x,longitudinalProfile_Data_6GeV,ex0,errorZ_Data_6GeV);
  myGraphSetUp(gLongitudinalProfile_Data_6GeV, kRed,1);
  gLongitudinalProfile_Data_6GeV->SetLineWidth(1);
  TGraphErrors* gLongitudinalProfile_Data_6GeV_tot = new TGraphErrors(nBins,x,longitudinalProfile_Data_6GeV, ex0, totError_LongitudinalProfile_6GeV);
  myGraphSetUp(gLongitudinalProfile_Data_6GeV_tot, kRed+2,1);
  gLongitudinalProfile_Data_6GeV_tot->SetLineWidth(1);
  gLongitudinalProfile_Data_6GeV_tot->SetFillStyle(3002);
  gLongitudinalProfile_Data_6GeV_tot->SetFillColor(kRed-7);

  TGraphErrors* gLongitudinalProfile_Data_8GeV = new TGraphErrors(nBins,x,longitudinalProfile_Data_8GeV,ex0,errorZ_Data_8GeV);
  myGraphSetUp(gLongitudinalProfile_Data_8GeV, kRed,1);
  gLongitudinalProfile_Data_8GeV->SetLineWidth(1);
  TGraphErrors* gLongitudinalProfile_Data_8GeV_tot = new TGraphErrors(nBins,x,longitudinalProfile_Data_8GeV, ex0, totError_LongitudinalProfile_8GeV);
  myGraphSetUp(gLongitudinalProfile_Data_8GeV_tot, kRed+2,1);
  gLongitudinalProfile_Data_8GeV_tot->SetLineWidth(1);
  gLongitudinalProfile_Data_8GeV_tot->SetFillStyle(3002);
  gLongitudinalProfile_Data_8GeV_tot->SetFillColor(kRed-7);

  TGraphErrors* gLongitudinalProfile_Data_10GeV = new TGraphErrors(nBins,x,longitudinalProfile_Data_10GeV,ex0,errorZ_Data_10GeV);
  myGraphSetUp(gLongitudinalProfile_Data_10GeV, kRed,1);
  gLongitudinalProfile_Data_10GeV->SetLineWidth(1);
  TGraphErrors* gLongitudinalProfile_Data_10GeV_tot = new TGraphErrors(nBins,x,longitudinalProfile_Data_10GeV, ex0, totError_LongitudinalProfile_10GeV);
  myGraphSetUp(gLongitudinalProfile_Data_10GeV_tot, kRed+2,1);
  gLongitudinalProfile_Data_10GeV_tot->SetLineWidth(1);
  gLongitudinalProfile_Data_10GeV_tot->SetFillColor(kRed-7);
  gLongitudinalProfile_Data_10GeV_tot->SetFillStyle(3002);

  //QGSP_BERT
  TGraph* gLongitudinalProfile_QGSP_BERT_2GeV = new TGraph(nBins,x,longitudinalProfile_QGSP_BERT_2GeV);
  myGraphSetUp(gLongitudinalProfile_QGSP_BERT_2GeV, kMagenta+4,1);
  
  TGraph* gLongitudinalProfile_QGSP_BERT_4GeV = new TGraph(nBins,x,longitudinalProfile_QGSP_BERT_4GeV);
  myGraphSetUp(gLongitudinalProfile_QGSP_BERT_4GeV, kMagenta+4,1);
  
  TGraph* gLongitudinalProfile_QGSP_BERT_6GeV = new TGraph(nBins,x,longitudinalProfile_QGSP_BERT_6GeV);
  myGraphSetUp(gLongitudinalProfile_QGSP_BERT_6GeV, kMagenta+4,1);
  
  TGraph* gLongitudinalProfile_QGSP_BERT_8GeV = new TGraph(nBins,x,longitudinalProfile_QGSP_BERT_8GeV);
  myGraphSetUp(gLongitudinalProfile_QGSP_BERT_8GeV, kMagenta+4,1);
  
  TGraph* gLongitudinalProfile_QGSP_BERT_10GeV = new TGraph(nBins,x,longitudinalProfile_QGSP_BERT_10GeV);
  myGraphSetUp(gLongitudinalProfile_QGSP_BERT_10GeV, kMagenta+4,1);

  //Define histograms for the axis
  TH1F* histoLongitudinalProfile = new TH1F("LongitudinalProfile","LongitudinalProfile",nBins-8,-0.5,51.5);
  histoLongitudinalProfile->SetTitle(";Shower depth [pseudolayer];#LTE_{rec}#GT/pseudolayer [MIP]");
  histoLongitudinalProfile->SetAxisRange(0.0,52.0,"Y");

  //2 GeV
  TCanvas* canvasLongitudinalProfile2 = new TCanvas("LongitudinalProfile2GeV","Longitudinal profile of hits at 2 GeV",0,0,1000,900);
  histoLongitudinalProfile->Draw();
  gLongitudinalProfile_Data_2GeV_tot->Draw("p3");
  gLongitudinalProfile_QGSP_BERT_2GeV->Draw("l");
  gLongitudinalProfile_Data_2GeV->Draw("p");
  legendZ2->Draw();
  text.DrawLatex(9.4,49.3,"#splitline{CALICE}{Si-W ECAL}");
  canvasLongitudinalProfile2->Write();
  //4 GeV
  TCanvas* canvasLongitudinalProfile4 = new TCanvas("LongitudinalProfile4GeV","Longitudinal profile of hits at 4 GeV",0,0,1000,900);
  histoLongitudinalProfile->Draw();
  gLongitudinalProfile_Data_4GeV_tot->Draw("p3");
  gLongitudinalProfile_QGSP_BERT_4GeV->Draw("l");
  gLongitudinalProfile_Data_4GeV->Draw("p");
  legendZ4->Draw();
  text.DrawLatex(9.4,49.3,"#splitline{CALICE}{Si-W ECAL}");
  canvasLongitudinalProfile4->Write();
  //6 GeV
  TCanvas* canvasLongitudinalProfile6 = new TCanvas("LongitudinalProfile6GeV","Longitudinal profile of hits at 6 GeV",0,0,1000,900);
  histoLongitudinalProfile->Draw();
  gLongitudinalProfile_Data_6GeV_tot->Draw("p3");
  gLongitudinalProfile_QGSP_BERT_6GeV->Draw("l");
  gLongitudinalProfile_Data_6GeV->Draw("p");
  legendZ6->Draw();
  text.DrawLatex(9.4,49.3,"#splitline{CALICE}{Si-W ECAL}");
  canvasLongitudinalProfile6->Write();
  //8 GeV
  TCanvas* canvasLongitudinalProfile8 = new TCanvas("LongitudinalProfile8GeV","Longitudinal profile of hits at 8 GeV",0,0,1000,900);
  histoLongitudinalProfile->Draw();
  gLongitudinalProfile_Data_8GeV_tot->Draw("p3");
  gLongitudinalProfile_QGSP_BERT_8GeV->Draw("l");
  gLongitudinalProfile_Data_8GeV->Draw("p");
  legendZ8->Draw();
  text.DrawLatex(9.4,7.5,"#splitline{CALICE}{Si-W ECAL}");
  canvasLongitudinalProfile8->Write();

  //10 GeV
  TCanvas* canvasLongitudinalProfile10 = new TCanvas("LongitudinalProfile10GeV","Longitudinal profile of hits at 10 GeV",0,0,1000,900);
  histoLongitudinalProfile->Draw();
  gLongitudinalProfile_Data_10GeV_tot->Draw("p3");
  gLongitudinalProfile_QGSP_BERT_10GeV->Draw("l");
  gLongitudinalProfile_Data_10GeV->Draw("p");
  legendZ10->Draw();
  text.DrawLatex(9.4,7.5,"#splitline{CALICE}{Si-W ECAL}");
  canvasLongitudinalProfile10->Write();

}
