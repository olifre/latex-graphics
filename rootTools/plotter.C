void setBirdPalette() {
	#if ROOT_VERSION_CODE < ROOT_VERSION(6,04,99)
	Double_t stops[9] = { 0.0000, 0.1250, 0.2500, 0.3750, 0.5000, 0.6250, 0.7500, 0.8750, 1.0000};
	{
		Double_t red[9]   = { 0.2082, 0.0592, 0.0780, 0.0232, 0.1802, 0.5301, 0.8186, 0.9956, 0.9764};
		Double_t green[9] = { 0.1664, 0.3599, 0.5041, 0.6419, 0.7178, 0.7492, 0.7328, 0.7862, 0.9832};
		Double_t blue[9]  = { 0.5293, 0.8684, 0.8385, 0.7914, 0.6425, 0.4662, 0.3499, 0.1968, 0.0539};
		TColor::CreateGradientColorTable(9, stops, red, green, blue, 255, 1.0);
	}
	#else
	gStyle->SetPalette(kBird);
	#endif
	gStyle->SetNumberContours(99);
}

void plotter(TString macroName,
             TString outputName,
             int hasroot = 1,
             int width = 1000,
             int height = 600,
             TString styleFile = "Style_Example.C",
             TString styleName = "Example") {
	// gROOT->Reset();

	// Adjust this for style-selection
	gROOT->ProcessLine(".x " + styleFile);
	gROOT->SetStyle(styleName);

	setBirdPalette();
	gStyle->SetNumberContours(255);

	if (outputName.EndsWith(".svg")) {
		// Force font-precision 0, LaTeX will interpret everything!
		int FONT = 80;
		gStyle->SetTextFont(FONT);
		gStyle->SetLabelFont(FONT, "XYZ");
		gStyle->SetTitleFont(FONT, "XYZ");
		gStyle->SetTitleFont(FONT, "");
	}

	gROOT->ForceStyle();
	TCanvas *c1 = NULL;
	if (hasroot) {
		TString rfName = macroName + ".root";
		TFile *ff = TFile::Open(rfName.Data());
		std::cout << "Opened file: " << rfName.Data() << std::endl;
	}
	if (c1 == NULL) {
		/*
		  int width=1000;
		  int height=600;
		  TRegexp pattern("_[0-9]+x[0-9]+$");
		  Ssiz_t index=macroName.Index(pattern);
		  if (index>0) {
		    TSubString substr=macroName(pattern);
		//     cout << substr.Data() << endl;
		    sscanf(substr.Data(),"_%ix%i",&width,&height);
		//     cout << width << " " << height << endl;
		  }
		*/
		c1 = new TCanvas("c1", "", width, height);
	}
	TString execLine = ".x " + macroName + ".C";
	std::cout << "Running: " << execLine.Data() << std::endl;
	TInterpreter::EErrorCode interpreterError;
	gROOT->ProcessLine(execLine.Data(), (int*)(&interpreterError));
	if (interpreterError != TInterpreter::kNoError) {
		std::cerr << "Fatal failure executing " << execLine.Data() << "!" << std::endl;
	} else {
		c1->Update();
		c1->Print(outputName.Data());
	}
	gROOT->ProcessLine(".q");
}
