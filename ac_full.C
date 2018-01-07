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


	#define FILEPATH "../Downloads/Run138_CNM_AC_N_PAD.rtct"

  int i=0, j=0, k=0;
  char * file = (char *) FILEPATH;
  PSTCT * meas;
  meas = new PSTCT(file,0,2);
  meas->CorrectBaseLine(80);
  meas->PrintInfo();

  TGraph2D * t2 = new TGraph2D(meas->Nx*meas->Ny);
  t2->SetNpy(meas->Ny);
  t2->SetNpx(meas->Nx);

  for(i=0;i<meas->Nx;i++){
    for(j=0;j<meas->Ny;j++){
      TH1F * t1;
      t1 = meas->GetHA(0, i, j, 0, 0, 0);
      t1->GetXaxis()->SetRange(60*meas->NP/t1->GetXaxis()->GetXmax(), 140*meas->NP/t1->GetXaxis()->GetXmax());
      t2->SetPoint(k, i*meas->dx+meas->x0, meas->y0+meas->dy*j, t1->GetMaximum());
      /*
      if(point1>point2){
        t2->SetPoint(k, i*meas->dx+meas->x0, meas->y0+meas->dy*j, min1);
      }else{
        t2->SetPoint(k, i*meas->dx+meas->x0, meas->y0+meas->dy*j, min2);
      }
      */
      k++;
    }
  }
  TCanvas *c1 = new TCanvas("c1", "FullScan", 0, 0, 1000, 1000);
  gStyle->SetPalette(kBird);
  //t2->GetXaxis()->SetTitle("Scan-axis position [um]");
  //t2->GetYaxis()->SetTitle("Signal Amplitude [mV]");
  t2->Draw("COLZ");
  t2->GetHistogram()->SetTitle("Scan of detector voltage vs position; x-axis position [um]; y-axis position[um]; Signal Amplitude[mV]")

}
