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


	#define FILEPATH "../Downloads/Run127_CNM_AC_SCAN.rtct"

  int i=0, j=0, k=0;
  char * file = (char *) FILEPATH;
  PSTCT * meas;
  meas = new PSTCT(file,0,2);
  meas->CorrectBaseLine(60);
  meas->PrintInfo();

  TGraph2D * t2 = new TGraph2D(300*meas->Ny);
  t2->SetNpy(meas->Ny);
  t2->SetNpx(meas->Nx);

  for(i=0;i<meas->Nx;i++){
    for(j=0;j<meas->Ny;j++){
      TH1F * t1;
      t1 = meas->GetHA(0, i, j, 0, 0, 0);
      t1->GetXaxis()->SetRange(60*meas->NP/t1->GetXaxis()->GetXmax(), 140*meas->NP/t1->GetXaxis()->GetXmax());
      int max1 = t1->GetMaximum();
      int min1 = t1->GetMinimum();
      //int max = t1->GetMaximum();
      int point1 = max1>min1*-1?max1:min1;
      t1 = meas->GetHA(1, i, j, 0, 0, 0);
      t1->GetXaxis()->SetRange(60*meas->NP/t1->GetXaxis()->GetXmax(), 140*meas->NP/t1->GetXaxis()->GetXmax());
      int max2 = t1->GetMaximum();
      int min2 = t1->GetMinimum();
      int point2 = max2>min2*-1?max2:min2;
      //int max = t1->GetMaximum();
      if(j == 0){
        t2->SetPoint(k, i*meas->dx+meas->x0, meas->y0+meas->dy*j, point1);
      }else if(j==1){

        t2->SetPoint(k, i*meas->dx+meas->x0+150, meas->y0+meas->dy*j, point1);
      }else if(j==2){

        t2->SetPoint(k, i*meas->dx+meas->x0, meas->y0+meas->dy*j, point1);
      }else if(j==3){

        t2->SetPoint(k, i*meas->dx+meas->x0+175, meas->y0+meas->dy*j, point1);
      }else if(j==4){

        t2->SetPoint(k, i*meas->dx+meas->x0-50, meas->y0+meas->dy*j, point1);
      }
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
  t2->SetMarkerStyle(20);
  //t2->GetXaxis()->SetTitle("Scan-axis position [um]");
  //t2->GetYaxis()->SetTitle("Signal Amplitude [mV]");
  t2->Draw("COLZ");
  t2->GetHistogram()->SetTitle("Scan of detector voltage vs position; x-axis position [um]; y-axis position[um]; Signal Amplitude[mV]")

}
