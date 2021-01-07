#include "TCanvas.h"
#include "TF2.h"
#include "TH2D.h"
#include "TFile.h"

void randomBlob() {
	auto c1 = new TCanvas ("c1", "c1", 1200, 800);
	TH2D *foo=new TH2D("samplePlot", "samplePlot", 100, 0, 100, 100, 0, 100);
	TF2 *xyg = new TF2("xyg","xygaus",0,100,0,100);
	xyg->SetParameters(42,50,20,50,20);
	foo->FillRandom("xyg");
	foo->Draw("colz");
	c1->SaveAs("randomBlob.pdf");
}
