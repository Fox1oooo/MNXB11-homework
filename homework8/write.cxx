#include "my_class.h"
#include <TTree.h>
#include <TFile.h>
#include <TRandom.h>

void write(){
   
    const Int_t nEvents = 1000;

    TFile *file = new TFile("my_file.root", "RECREATE"); 

    TTree *tree = new TTree("tree", "Tree with data");


    momentum *obj = new momentum();

    tree->Branch("tree","momentum", &obj);


    for (Int_t i{0}; i<nEvents; i++){

        Int_t px = gRandom->Gaus(0, 0.02);
        Int_t py = gRandom->Gaus(0, 0.02);
        Int_t pz = gRandom->Gaus(0, 0.02);

        delete obj;
        obj = new momentum();
        tree->Fill();
    }

    tree->Write();

    file->Close();

    delete obj;
    delete file;
    
}



//projects/hep/fs10/mnxb11/bin/startmnxb11container.sh bash
