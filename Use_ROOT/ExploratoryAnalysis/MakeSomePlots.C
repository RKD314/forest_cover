#include <TROOT.h>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TMath.h>
#include <TH1.h>
#include <TF1.h>
#include <TString.h>
#include <TCanvas.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;


TH1F* CoverTypeAll_vs_SoilTypeFixed(Int_t soiltype){
	
	TString NewName="Soil";
	NewName+=soiltype;
	NewName+="_vs_AllCoverTypes";
	
	TString NewTitle="Tree types growing in Soil";
	NewTitle+=soiltype;
	
	TH1F *Hist_CoverTypeAll_vs_SoilTypeFixed = new TH1F(NewName.Data(),NewTitle.Data(),7,1,8);
		
	Hist_CoverTypeAll_vs_SoilTypeFixed->SetXTitle("Cover Type");
	Hist_CoverTypeAll_vs_SoilTypeFixed->SetYTitle("Number of Trees");
	
	return Hist_CoverTypeAll_vs_SoilTypeFixed;
	
}

TH1F* CoverTypeAll_vs_AreaFixed(Int_t areatype){
	TString NewName="Wilderness_Area";
	NewName+=areatype;
	NewName+="_vs_AllCoverTypes";
	
	TString NewTitle="Tree types growing in Wilderness Area";
	NewTitle+=areatype;
	
	TH1F *Hist_CoverTypeAll_vs_AreaFixed = new TH1F(NewName.Data(),NewTitle.Data(),7,1,8);
	
	Hist_CoverTypeAll_vs_AreaFixed->SetXTitle("Cover Type");
	Hist_CoverTypeAll_vs_AreaFixed->SetYTitle("Number of Trees");
	
	return Hist_CoverTypeAll_vs_AreaFixed;
	
}

TH1F* CoverTypeFixed_vs_SoilTypeAll(Int_t covertype){
	
	TString NewName="Cover";
	NewName+=covertype;
	NewName+="_vs_AllSoilTypes";
	
	TString NewTitle="Soil types that Tree";
	NewTitle+=covertype;
	NewTitle+=" Grows in";
	
	TH1F *Hist_CoverTypeFixed_vs_SoilTypeAll = new TH1F(NewName.Data(),NewTitle.Data(),40,1,41);
		
	Hist_CoverTypeFixed_vs_SoilTypeAll->SetXTitle("Soil Type");
	Hist_CoverTypeFixed_vs_SoilTypeAll->SetYTitle("Number of Trees of This Type");
	
	Hist_CoverTypeFixed_vs_SoilTypeAll->SetLineWidth(2);
	
		if (covertype==1) 	Hist_CoverTypeFixed_vs_SoilTypeAll->SetLineColor(kBlack);	
		else if (covertype==2) 	Hist_CoverTypeFixed_vs_SoilTypeAll->SetLineColor(kRed);	
		else if (covertype==3) 	Hist_CoverTypeFixed_vs_SoilTypeAll->SetLineColor(kGreen);	
		else if (covertype==4) 	Hist_CoverTypeFixed_vs_SoilTypeAll->SetLineColor(kBlue);	
		else if (covertype==5) 	Hist_CoverTypeFixed_vs_SoilTypeAll->SetLineColor(kOrange);	
		else if (covertype==6) 	Hist_CoverTypeFixed_vs_SoilTypeAll->SetLineColor(kMagenta);	
		else  Hist_CoverTypeFixed_vs_SoilTypeAll->SetLineColor(kAzure+10);	
			
	Hist_CoverTypeFixed_vs_SoilTypeAll->SetStats(0);

	return Hist_CoverTypeFixed_vs_SoilTypeAll;
	
}

TH1F* CoverTypeFixed_vs_AreaTypeAll(Int_t covertype){
	
	TString NewName="Cover";
	NewName+=covertype;
	NewName+="_vs_AllAreaTypes";
	
	TString NewTitle="Wilderness areas that Tree";
	NewTitle+=covertype;
	NewTitle+=" Grows in";
	
	TH1F *Hist_CoverTypeFixed_vs_AreaTypeAll = new TH1F(NewName.Data(),NewTitle.Data(),4,1,5);
	
	Hist_CoverTypeFixed_vs_AreaTypeAll->SetXTitle("Wilderness Area");
	Hist_CoverTypeFixed_vs_AreaTypeAll->SetYTitle("Number of Trees of This Type");
	
	Hist_CoverTypeFixed_vs_AreaTypeAll->SetLineWidth(2);
	
		if (covertype==1) 	Hist_CoverTypeFixed_vs_AreaTypeAll->SetLineColor(kBlack);	
		else if (covertype==2) 	Hist_CoverTypeFixed_vs_AreaTypeAll->SetLineColor(kRed);	
		else if (covertype==3) 	Hist_CoverTypeFixed_vs_AreaTypeAll->SetLineColor(kGreen);	
		else if (covertype==4) 	Hist_CoverTypeFixed_vs_AreaTypeAll->SetLineColor(kBlue);	
		else if (covertype==5) 	Hist_CoverTypeFixed_vs_AreaTypeAll->SetLineColor(kOrange);	
		else if (covertype==6) 	Hist_CoverTypeFixed_vs_AreaTypeAll->SetLineColor(kMagenta);	
		else  Hist_CoverTypeFixed_vs_AreaTypeAll->SetLineColor(kAzure+10);	
			
	Hist_CoverTypeFixed_vs_AreaTypeAll->SetStats(0);

	return Hist_CoverTypeFixed_vs_AreaTypeAll;	
	
}

TH1F* CoverTypeFixed_vs_Variable(Int_t covertype, TString histname, Int_t low_bin, Int_t high_bin){
	TString NewName="CoverType";
	NewName+=covertype;
	NewName+="_vs_";
	NewName+=histname;
	
	TString NewTitle="";
	NewTitle+=histname;
	NewTitle+=" for tree type ";
	NewTitle+=covertype;
	
	Int_t bin_nums = high_bin-low_bin;
	if (bin_nums > 1000) bin_nums = bin_nums/100;
	else if (bin_nums > 100) bin_nums = bin_nums/10;
	
	TH1F *Hist_CoverTypeFixed_vs_Variable = new TH1F(NewName.Data(),NewTitle.Data(),bin_nums,low_bin,high_bin);
	
	Hist_CoverTypeFixed_vs_Variable->SetXTitle(histname.Data());
	Hist_CoverTypeFixed_vs_Variable->SetYTitle("Number of Trees of This Type");
	
	Hist_CoverTypeFixed_vs_Variable->SetLineWidth(2);
	
		if (covertype==1) 	Hist_CoverTypeFixed_vs_Variable->SetLineColor(kBlack);	
		else if (covertype==2) 	Hist_CoverTypeFixed_vs_Variable->SetLineColor(kRed);	
		else if (covertype==3) 	Hist_CoverTypeFixed_vs_Variable->SetLineColor(kGreen);	
		else if (covertype==4) 	Hist_CoverTypeFixed_vs_Variable->SetLineColor(kBlue);	
		else if (covertype==5) 	Hist_CoverTypeFixed_vs_Variable->SetLineColor(kOrange);	
		else if (covertype==6) 	Hist_CoverTypeFixed_vs_Variable->SetLineColor(kMagenta);	
		else  Hist_CoverTypeFixed_vs_Variable->SetLineColor(kAzure+10);	
			
	Hist_CoverTypeFixed_vs_Variable->SetStats(0);
	
	return Hist_CoverTypeFixed_vs_Variable;
	
}

void Fill_CoverTypeAll_vs_SoilTypeFixed(TChain *file_tree, Int_t soiltype){
	TString CutValue="Soil_Type";
	CutValue+=soiltype;
	CutValue+="==1";
	
	TString PlotValue="Cover_Type>>Soil";
	PlotValue+=soiltype;
	PlotValue+="_vs_AllCoverTypes";
	
	file_tree->Draw(PlotValue.Data(),CutValue.Data());
	
	return;
	
}

void Fill_CoverTypeAll_vs_AreaFixed(TChain *file_tree, Int_t areatype){
	TString CutValue="Wilderness_Area";
	CutValue+=areatype;
	CutValue+="==1";
	
	TString PlotValue="Cover_Type>>Wilderness_Area";
	PlotValue+=areatype;
	PlotValue+="_vs_AllCoverTypes";
	
	file_tree->Draw(PlotValue.Data(),CutValue.Data());
	
	return;
	
}

void Fill_CoverTypeFixed_vs_SoilTypeAll(TChain *file_tree, Int_t covertype){
	TString CutValue="";
	
	TString PlotValue="";

	for (Int_t soils=1; soils<41; soils++) {
		PlotValue="";
		PlotValue+=soils;
		if (soils==1) PlotValue+=">>Cover";
		else PlotValue+=">>+Cover";
		PlotValue+=covertype;
		PlotValue+="_vs_AllSoilTypes";
		
		CutValue="";
		CutValue="Cover_Type==";
		CutValue+=covertype;
		CutValue+="&&Soil_Type";
		CutValue+=soils;
		CutValue+="==1";
		
		file_tree->Draw(PlotValue.Data(),CutValue.Data());
	}
	
	return;
	
}

void Fill_CoverTypeFixed_vs_AreaTypeAll(TChain *file_tree, Int_t covertype){
	TString CutValue="";
	
	TString PlotValue="";

	for (Int_t areas=1; areas<5; areas++) {
		PlotValue="";
		PlotValue+=areas;
		if (areas==1) PlotValue+=">>Cover";
		else PlotValue+=">>+Cover";
		PlotValue+=covertype;
		PlotValue+="_vs_AllAreaTypes";
		
		CutValue="";
		CutValue="Cover_Type==";
		CutValue+=covertype;
		CutValue+="&&Wilderness_Area";
		CutValue+=areas;
		CutValue+="==1";
		
		file_tree->Draw(PlotValue.Data(),CutValue.Data());
	}
	
	return;
	
}	
	
void Fill_CoverTypeFixed_vs_Variable(TString variable, TChain *file_tree, Int_t covertype){
	TString CutValue="Cover_Type==";
	CutValue+=covertype;
	
	TString PlotValue="";
	PlotValue+=variable;
	PlotValue+=">>CoverType";
	PlotValue+=covertype;
	PlotValue+="_vs_";
	PlotValue+=variable;
	
	file_tree->Draw(PlotValue.Data(),CutValue.Data());
	
	return;
	
}

void MakeSomePlots(){

	TFile *output = new TFile("SomePlots.root","RECREATE");
	TChain *tree = new TChain("forest_cover");
	tree->Add("../train.root");
	
///Different variables for all cover types (vs cover types)

	//Histograms of cover type vs different soil types
	Int_t numsoils=40;
	TH1F *soilhists[numsoils];
	for (Int_t x=1; x<numsoils+1; x++) {
		soilhists[x] = CoverTypeAll_vs_SoilTypeFixed(x);
		Fill_CoverTypeAll_vs_SoilTypeFixed(tree, x);
	}
	
	//Histograms of cover type vs different wilderness areas
	Int_t numareas=4;
	TH1F *areahists[numareas];
	for (Int_t z=1; z<numareas+1; z++) {
		areahists[z] = CoverTypeAll_vs_AreaFixed(z);
		Fill_CoverTypeAll_vs_AreaFixed(tree, z);
	}
	
//Histograms of different variables for specific cover types
	Int_t numcovers=7;
	TH1F *elevation[numcovers];
	TH1F *aspect[numcovers];
	TH1F *slope[numcovers];
	TH1F *horizontal_dist_hydrology[numcovers];
	TH1F *vertical_dist_hydrology[numcovers];
	TH1F *horizontal_dist_roadways[numcovers];
	TH1F *hillshade_9am[numcovers];
	TH1F *hillshade_noon[numcovers];
	TH1F *hillshade_3pm[numcovers];
	TH1F *horizontal_dist_fire[numcovers];
	TH1F *wilderness_area[numcovers];
	TH1F *soil_type[numcovers];
	
	for (Int_t y=1; y<numcovers+1; y++) {

		//elevation for each tree type
		elevation[y] = CoverTypeFixed_vs_Variable(y,"Elevation",0,4000);	
		Fill_CoverTypeFixed_vs_Variable("Elevation",tree, y);	
	
		//aspect for each tree type
		aspect[y] = CoverTypeFixed_vs_Variable(y,"Aspect",0,360);	
		Fill_CoverTypeFixed_vs_Variable("Aspect",tree, y);	
	
		//slope for each tree type
		slope[y] = CoverTypeFixed_vs_Variable(y,"Slope",0,60);	
		Fill_CoverTypeFixed_vs_Variable("Slope",tree, y);	
	
		//horizontal distance to hydrology for each tree type
		horizontal_dist_hydrology[y] = CoverTypeFixed_vs_Variable(y,"Horizontal_Distance_To_Hydrology",0,1500);	
		Fill_CoverTypeFixed_vs_Variable("Horizontal_Distance_To_Hydrology",tree, y);	
		
		//vertical distance to hydrology for each tree type
		vertical_dist_hydrology[y] = CoverTypeFixed_vs_Variable(y,"Vertical_Distance_To_Hydrology",-210,650);	
		Fill_CoverTypeFixed_vs_Variable("Vertical_Distance_To_Hydrology",tree, y);	
	
		//horizontal distance to roadways for each tree type
		horizontal_dist_roadways[y] = CoverTypeFixed_vs_Variable(y,"Horizontal_Distance_To_Roadways",0,7500);	
		Fill_CoverTypeFixed_vs_Variable("Horizontal_Distance_To_Roadways",tree, y);	
	
		//hillshade at 9am for each tree type
		hillshade_9am[y] = CoverTypeFixed_vs_Variable(y,"Hillshade_9am",0,255);	
		Fill_CoverTypeFixed_vs_Variable("Hillshade_9am",tree, y);	

		//hillshade at noon for each tree type
		hillshade_noon[y] = CoverTypeFixed_vs_Variable(y,"Hillshade_Noon",0,255);	
		Fill_CoverTypeFixed_vs_Variable("Hillshade_Noon",tree, y);	

		//hillshade at 3pm for each tree type
		hillshade_3pm[y] = CoverTypeFixed_vs_Variable(y,"Hillshade_3pm",0,255);	
		Fill_CoverTypeFixed_vs_Variable("Hillshade_3pm",tree, y);	

		//horizontal distance to firepoints for each tree type
		horizontal_dist_fire[y] = CoverTypeFixed_vs_Variable(y,"Horizontal_Distance_To_Fire_Points",0,7500);	
		Fill_CoverTypeFixed_vs_Variable("Horizontal_Distance_To_Fire_Points",tree, y);	

		//wilderness area for each tree type
		wilderness_area[y] = CoverTypeFixed_vs_AreaTypeAll(y);
		Fill_CoverTypeFixed_vs_AreaTypeAll(tree, y);

		//types of soil for each tree type
		soil_type[y] = CoverTypeFixed_vs_SoilTypeAll(y);
		Fill_CoverTypeFixed_vs_SoilTypeAll(tree, y);	
	}
		
	output->Write();
	output->Close();
	delete output;
		
}
