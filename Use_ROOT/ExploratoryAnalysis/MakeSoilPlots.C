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
	
	TH1F *Hist_CoverTypeAll_vs_SoilTypeFixed = new TH1F(NewName.Data(),NewTitle.Data(),7,1,7);
		
	Hist_CoverTypeAll_vs_SoilTypeFixed->SetXTitle("Cover Type");
	Hist_CoverTypeAll_vs_SoilTypeFixed->SetYTitle("Number of Trees");
	
	return Hist_CoverTypeAll_vs_SoilTypeFixed;
	
}

TH1F* CoverTypeFixed_vs_SoilTypeAll(Int_t covertype){
	
	TString NewName="Cover";
	NewName+=covertype;
	NewName+="_vs_AllSoilTypes";
	
	TString NewTitle="Soil types that Tree";
	NewTitle+=covertype;
	NewTitle+=" Grows in";
	
	TH1F *Hist_CoverTypeFixed_vs_SoilTypeAll = new TH1F(NewName.Data(),NewTitle.Data(),40,1,40);
		
	Hist_CoverTypeFixed_vs_SoilTypeAll->SetXTitle("Soil Type");
	Hist_CoverTypeFixed_vs_SoilTypeAll->SetYTitle("Number of Trees of This Type");
	
	return Hist_CoverTypeFixed_vs_SoilTypeAll;
	
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

void MakeSoilPlots(){

	TFile *output = new TFile("SoilPlots.root","RECREATE");
	TChain *tree = new TChain("forest_cover");
	tree->Add("train.root");
	
	Int_t numsoils=40;
	TH1F *soilhists[numsoils];
	for (Int_t x=1; x<numsoils+1; x++) {
		soilhists[x] = CoverTypeAll_vs_SoilTypeFixed(x);
		Fill_CoverTypeAll_vs_SoilTypeFixed(tree, x);
	}
	
	Int_t numcovers=7;
	TH1F *coverhists[numcovers];
	for (Int_t y=1; y<numcovers+1; y++) {
		coverhists[y] = CoverTypeFixed_vs_SoilTypeAll(y);
		Fill_CoverTypeFixed_vs_SoilTypeAll(tree, y);
	}
	
	output->Write();
	output->Close();
	delete output;
	
	
}
