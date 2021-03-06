{
  /****************************************************************************
   * File: fullScan.C
   * Version: 1.0
   * Author: Ric Rodriguez
   * Function: Plots multiple channel's waveforms at one time
   * Example usage
   * ~bash$: root
   * root[0]: gSystem->Load("TCTAnalyse.sl");
   * root[1]: .x fullScan.C;
   ****************************************************************************/


	#define FILEPATH "../Downloads/sample.rtct"
	#define CHANNEL 3

  int i=0, j=0, k=0;
  char * file = (char *) FILEPATH;
  PSTCT * meas;
  meas = new PSTCT(file,0,2);
  meas->PrintInfo();

  TGraph2D * t2 = new TGraph2D(meas->Nx*meas->Ny);
  t2->SetNpy(meas->Ny);
  t2->SetNpx(meas->Nx);

  for(i=0;i<meas->Nx;i++){
    for(j=0;j<meas->Ny;j++){
      TH1F * t1;
      t1 = meas->GetHA(CHANNEL, i, j, 0);
      t2->SetPoint(k, meas->Nx-i-j/10., j, -1*t1->GetMinimum());
      k++;
    }
  }
  TCanvas *c1 = new TCanvas("c1", "FullScan", 0, 0, 1000, 1000);
  gStyle->SetPalette(kBird);
  t2->SetMarkerStyle(20);
  t2->GetHistogram()->GetXaxis()->SetTitle("X-Axis Position [um]");
  t2->GetHistogram()->GetYaxis()->SetTitle("Y-Axis Position [um]");
  t2->GetHistogram()->GetZaxis()->SetTitle("Signal Amplitude [mV]");
  t2->GetHistogram()->SetTitle("Detector: W4-AC2, 3 Pixels, Strip #2 connected, rest grounded. Reading Strip. Bias=200V. TCT Laser: 38% 1kHz");

  t2->Draw("COLZ"); // can also use "SURF2Z"

}
