#include "Riostream.h"
void convert_train_to_ROOT() {
//  Read data from an ascii file and create a root file with an histogram and an ntuple.
//   see a variant of this macro in basic2.C
//Author: Rene Brun
      
   TString filename="train.dat";
   printf("Using file: %s\n",filename.Data());

   ifstream in;
   in.open(Form(filename.Data()));
   
   Float_t Id, Elevation, Aspect, Slope, Horizontal_Distance_To_Hydrology, Vertical_Distance_To_Hydrology, Horizontal_Distance_To_Roadways, Hillshade_9am, Hillshade_Noon, Hillshade_3pm, Horizontal_Distance_To_Fire_Points, Wilderness_Area1, Wilderness_Area2, Wilderness_Area3, Wilderness_Area4, Soil_Type1, Soil_Type2, Soil_Type3, Soil_Type4, Soil_Type5, Soil_Type6, Soil_Type7, Soil_Type8, Soil_Type9, Soil_Type10, Soil_Type11, Soil_Type12, Soil_Type13, Soil_Type14, Soil_Type15, Soil_Type16, Soil_Type17, Soil_Type18, Soil_Type19, Soil_Type20, Soil_Type21, Soil_Type22, Soil_Type23, Soil_Type24, Soil_Type25, Soil_Type26, Soil_Type27, Soil_Type28, Soil_Type29, Soil_Type30, Soil_Type31, Soil_Type32, Soil_Type33, Soil_Type34, Soil_Type35, Soil_Type36, Soil_Type37, Soil_Type38, Soil_Type39, Soil_Type40, Cover_Type;

   Int_t nlines = 0;
   TFile *f = new TFile("train.root","RECREATE");
   TH1F *h_Elevation = new TH1F("h_Elevation","Elevation distribution",200,1850,3850);
   TTree *tree = new TTree("forest_cover","data from csv file");
   
   TBranch *b_Id 								= tree->Branch("Id",&Id);
   TBranch *b_Elevation							= tree->Branch("Elevation",&Elevation);
   TBranch *b_Aspect							= tree->Branch("Aspect",&Aspect);
   TBranch *b_Slope								= tree->Branch("Slope",&Slope);
   TBranch *b_Horizontal_Distance_To_Hydrology	= tree->Branch("Horizontal_Distance_To_Hydrology",&Horizontal_Distance_To_Hydrology);
   TBranch *b_Vertical_Distance_To_Hydrology	= tree->Branch("Vertical_Distance_To_Hydrology",&Vertical_Distance_To_Hydrology);
   TBranch *b_Horizontal_Distance_To_Roadways	= tree->Branch("Horizontal_Distance_To_Roadways",&Horizontal_Distance_To_Roadways);
   TBranch *b_Hillshade_9am						= tree->Branch("Hillshade_9am",&Hillshade_9am);
   TBranch *b_Hillshade_Noon					= tree->Branch("Hillshade_Noon",&Hillshade_Noon);
   TBranch *b_Hillshade_3pm						= tree->Branch("Hillshade_3pm",&Hillshade_3pm);
   TBranch *b_Horizontal_Distance_To_Fire_Points= tree->Branch("Horizontal_Distance_To_Fire_Points",&Horizontal_Distance_To_Fire_Points);
   TBranch *b_Wilderness_Area1					= tree->Branch("Wilderness_Area1",&Wilderness_Area1);
   TBranch *b_Wilderness_Area2					= tree->Branch("Wilderness_Area2",&Wilderness_Area2);
   TBranch *b_Wilderness_Area3					= tree->Branch("Wilderness_Area3",&Wilderness_Area3);
   TBranch *b_Wilderness_Area4					= tree->Branch("Wilderness_Area4",&Wilderness_Area4);
   TBranch *b_Soil_Type1						= tree->Branch("Soil_Type1",&Soil_Type1);
   TBranch *b_Soil_Type2						= tree->Branch("Soil_Type2",&Soil_Type2);
   TBranch *b_Soil_Type3						= tree->Branch("Soil_Type3",&Soil_Type3);
   TBranch *b_Soil_Type4						= tree->Branch("Soil_Type4",&Soil_Type4);
   TBranch *b_Soil_Type5						= tree->Branch("Soil_Type5",&Soil_Type5);
   TBranch *b_Soil_Type6						= tree->Branch("Soil_Type6",&Soil_Type6);
   TBranch *b_Soil_Type7						= tree->Branch("Soil_Type7",&Soil_Type7);
   TBranch *b_Soil_Type8						= tree->Branch("Soil_Type8",&Soil_Type8);
   TBranch *b_Soil_Type9						= tree->Branch("Soil_Type9",&Soil_Type9);
   TBranch *b_Soil_Type10						= tree->Branch("Soil_Type10",&Soil_Type10);
   TBranch *b_Soil_Type11						= tree->Branch("Soil_Type11",&Soil_Type11);
   TBranch *b_Soil_Type12						= tree->Branch("Soil_Type12",&Soil_Type12);
   TBranch *b_Soil_Type13						= tree->Branch("Soil_Type13",&Soil_Type13);
   TBranch *b_Soil_Type14						= tree->Branch("Soil_Type14",&Soil_Type14);
   TBranch *b_Soil_Type15						= tree->Branch("Soil_Type15",&Soil_Type15);
   TBranch *b_Soil_Type16						= tree->Branch("Soil_Type16",&Soil_Type16);
   TBranch *b_Soil_Type17						= tree->Branch("Soil_Type17",&Soil_Type17);
   TBranch *b_Soil_Type18						= tree->Branch("Soil_Type18",&Soil_Type18);
   TBranch *b_Soil_Type19						= tree->Branch("Soil_Type19",&Soil_Type19);
   TBranch *b_Soil_Type20						= tree->Branch("Soil_Type20",&Soil_Type20);
   TBranch *b_Soil_Type21						= tree->Branch("Soil_Type21",&Soil_Type21);
   TBranch *b_Soil_Type22						= tree->Branch("Soil_Type22",&Soil_Type22);
   TBranch *b_Soil_Type23						= tree->Branch("Soil_Type23",&Soil_Type23);
   TBranch *b_Soil_Type24						= tree->Branch("Soil_Type24",&Soil_Type24);
   TBranch *b_Soil_Type25						= tree->Branch("Soil_Type25",&Soil_Type25);
   TBranch *b_Soil_Type26						= tree->Branch("Soil_Type26",&Soil_Type26);
   TBranch *b_Soil_Type27						= tree->Branch("Soil_Type27",&Soil_Type27);
   TBranch *b_Soil_Type28						= tree->Branch("Soil_Type28",&Soil_Type28);
   TBranch *b_Soil_Type29						= tree->Branch("Soil_Type29",&Soil_Type29);
   TBranch *b_Soil_Type30						= tree->Branch("Soil_Type30",&Soil_Type30);
   TBranch *b_Soil_Type31						= tree->Branch("Soil_Type31",&Soil_Type31);
   TBranch *b_Soil_Type32						= tree->Branch("Soil_Type32",&Soil_Type32);
   TBranch *b_Soil_Type33						= tree->Branch("Soil_Type33",&Soil_Type33);
   TBranch *b_Soil_Type34						= tree->Branch("Soil_Type34",&Soil_Type34);
   TBranch *b_Soil_Type35						= tree->Branch("Soil_Type35",&Soil_Type35);
   TBranch *b_Soil_Type36						= tree->Branch("Soil_Type36",&Soil_Type36);
   TBranch *b_Soil_Type37						= tree->Branch("Soil_Type37",&Soil_Type37);
   TBranch *b_Soil_Type38						= tree->Branch("Soil_Type38",&Soil_Type38);
   TBranch *b_Soil_Type39						= tree->Branch("Soil_Type39",&Soil_Type39);
   TBranch *b_Soil_Type40						= tree->Branch("Soil_Type40",&Soil_Type40);
   TBranch *b_Cover_Type						= tree->Branch("Cover_Type",&Cover_Type);

   while (1) {
      in >> Id >> Elevation >> Aspect >> Slope >> Horizontal_Distance_To_Hydrology >> Vertical_Distance_To_Hydrology >> Horizontal_Distance_To_Roadways >> Hillshade_9am >> Hillshade_Noon >> Hillshade_3pm >> Horizontal_Distance_To_Fire_Points >> Wilderness_Area1 >> Wilderness_Area2 >> Wilderness_Area3 >> Wilderness_Area4 >> Soil_Type1 >> Soil_Type2 >> Soil_Type3 >> Soil_Type4 >> Soil_Type5 >> Soil_Type6 >> Soil_Type7 >> Soil_Type8 >> Soil_Type9 >> Soil_Type10 >> Soil_Type11 >> Soil_Type12 >> Soil_Type13 >> Soil_Type14 >> Soil_Type15 >> Soil_Type16 >> Soil_Type17 >> Soil_Type18 >> Soil_Type19 >> Soil_Type20 >> Soil_Type21 >> Soil_Type22 >> Soil_Type23 >> Soil_Type24 >> Soil_Type25 >> Soil_Type26 >> Soil_Type27 >> Soil_Type28 >> Soil_Type29 >> Soil_Type30 >> Soil_Type31 >> Soil_Type32 >> Soil_Type33 >> Soil_Type34 >> Soil_Type35 >> Soil_Type36 >> Soil_Type37 >> Soil_Type38 >> Soil_Type39 >> Soil_Type40 >> Cover_Type;
      if (!in.good()) break;
      h_Elevation->Fill(Elevation);
      tree->Fill();
      nlines++;
   }
   printf(" found %d points\n",nlines);

   in.close();

//   tree->Write();
   f->Write();
}
