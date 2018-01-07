{
  /****************************************************************************
   * File: collectedCharge.C
   * Version: 1.0
   * Author: Ric Rodriguez
   * Function: Calculates the charge collected by a particle detector
   * Example usage
   * ~bash$: root
   * root[0]: gSystem->Load("TCTAnalyse.sl");
   * root[1]: .x collectedCharge.C;
   ****************************************************************************/


  double transimpedance = 30e3;
  double detector_gain = 30;
  char * file = (char *) "Run14_HPK80D_KU_IR.rtct";

  int i=0, j=0, k=0;
  PSTCT * meas;
  meas = new PSTCT(file,0,2);
  meas->PrintInfo();

  TGraph2D * t2 = new TGraph2D(meas->Nx*meas->Ny);
  t2->SetNpy(meas->Ny);
  t2->SetNpx(meas->Nx);

  double R = board_resistance * board_gain * detector_gain;

  for(i=0;i<meas->Nx;i++){
    for(j=0;j<meas->Ny;j++){
      TH1F * t1;
      t1 = meas->GetHA(1, i, j, 0, 0, 0);
      t1->GetXaxis()->SetRange(80*meas->NP/t1->GetXaxis()->GetXmax(), 110*meas->NP/t1->GetXaxis()->GetXmax());
      double min1 = -1*t1->Integral()/(1000*R);
      t1 = meas->GetHA(2, i, j, 0, 0, 0);
      t1->GetXaxis()->SetRange(82*meas->NP/t1->GetXaxis()->GetXmax(), 110*meas->NP/t1->GetXaxis()->GetXmax());
      double min2 = -1*t1->Integral()/(1000*R);
      if(min1>min2){
        t2->SetPoint(k, meas->dx*i, meas->dy*j, min1);
      }else{
        t2->SetPoint(k, meas->dx*i, meas->dy*j, min2);
      }
      k++;

    }
  }
  TCanvas *c1 = new TCanvas("c1", "Integral Scan", 0, 0, 1000, 1000);
  gStyle->SetPalette(1);
  t2->SetMarkerStyle(20);
  t2->Draw("COLZ");

}
