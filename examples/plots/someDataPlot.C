{
	TString objName = "samplePlot";
	TH2* histo = dynamic_cast<TH2*>(gDirectory->FindObjectAny(objName));

	gPad->SetRightMargin(0.15);
	gStyle->SetOptStat(0);

	histo->GetXaxis()->SetRangeUser(0, 100);
	histo->GetYaxis()->SetRangeUser(0, 100);

	histo->GetXaxis()->SetTitle("Some funny measurement #alpha / m");
	histo->GetYaxis()->SetTitle("Another funny #beta measurement / ns");
	histo->GetXaxis()->SetLabelSize(0.05);
	histo->GetYaxis()->SetLabelSize(0.05);

	gPad->Modified();
	gPad->Update();

	// Force redrawing of palette.
	histo->GetListOfFunctions()->Delete("palette");

	gPad->SetLogz();
	histo->Draw("colz");
}
