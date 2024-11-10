#include <TFile.h>
#include <TTree.h>
#include <TH2D.h>
#include <TCanvas.h>
#include "my_class.h"
#include <iostream>


void read(){
    
    TFile *file = TFile::Open("my_file.root", "READ");
    TTree *tree = (TTree*)file->Get("tree"); 

    // file->GetObject("tree", tree);

    if (!file || !tree) {
        std::cerr << "Error opening file or retrieving tree!" << std::endl;
        return;
    }
    

    momentum *obj = new momentum();
    tree->SetBranchAddress("objectbranch", &obj);
    

    Int_t N = tree->GetEntries();

    TCanvas *c1 = new TCanvas("c1", "px vs py", 800, 600);

    TH2D *hist_px_py = new TH2D("hist_px_py","title", 100, -0.1, 0.1, 100, -0.1, 0.1);
    

    for (Int_t i{0}; i<N; i++){
        tree->GetEntry(i);

        hist_px_py->Fill(obj->px, obj->py);
    }

    
    hist_px_py->Draw("COLZ");

    c1->Update();
    // c1->SaveAs("px_py_histogram.png");

    tree->Draw("px*py:pz", "sqrt(px*px + py*py + pz*pz) > 0.05", "COLZ");


    delete obj;
    file->Close();
    
}