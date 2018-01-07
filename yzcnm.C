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


	#define FILEPATH "../Downloads/Run171_CNM_AC_FOCUS.rtct"

  int i=0, j=0, k=0;
  char * file = (char *) FILEPATH;
  PSTCT * meas;
  meas = new PSTCT(file,0,2);
  meas->PrintInfo();
  meas->CorrectBaseLine(60);

  TGraph2D * t2 = new TGraph2D(meas->Nx*meas->Nz);
  t2->SetNpy(meas->Nx);
  t2->SetNpx(meas->Nz);

  for(i=0;i<meas->Nx;i++){
    for(j=0;j<meas->Nz;j++){
      TH1F * t1;
      t1 = meas->GetHA(1, i, 0, j);
      t1->GetXaxis()->SetRange(60*meas->NP/t1->GetXaxis()->GetXmax(), 140*meas->NP/t1->GetXaxis()->GetXmax());
      float min2 = t1->GetMaximum();
      //int max = t1->GetMaximum();
        t2->SetPoint(k, i*meas->dx+meas->x0, meas->z0+meas->dz*j, min2>0.1?min2:0.0001);
      k++;
    }
  }
  TCanvas *c1 = new TCanvas("c1", "FullScan", 0, 0, 1000, 1000);
  gStyle->SetPalette(kBird);
  t2->SetMarkerStyle(20);
  //t2->GetXaxis()->SetTitle("Scan-axis position [um]");
  //t2->GetYaxis()->SetTitle("Signal Amplitude [mV]");
  t2->Draw("SURF2Z");
  t2->GetHistogram()->SetTitle("Scan of detector voltage vs position; x-axis position [um]; y-axis position[um]; Signal Amplitude[mV]")

}
