{
  int i=0, j=0, k=0;
  char * file = (char *) "Run25_HPK80D_KU_IR.rtct";
  PSTCT * meas;
  meas = new PSTCT(file,0,2);
  meas->PrintInfo();

  TGraph2D * t2 = new TGraph2D(meas->Nx*meas->Ny);
  t2->SetNpy(meas->Ny);
  t2->SetNpx(meas->Nx);

  for(i=0;i<meas->Nx;i++){
    for(j=0;j<meas->Ny;j++){
      TH1F * t1;
      t1 = meas->GetHA(0, i, j, 0, 0, 0);
      //t1->GetXaxis()->SetRange(0*1024/200, 20*1024/200);
      int min1 = t1->GetMinimum();
      t1 = meas->GetHA(1, i, j, 0, 0, 0);
      //t1->GetXaxis()->SetRange(0*1024/200, 20*1024/200);
      int min2 = t1->GetMinimum();
      if(min1<min2){
        t2->SetPoint(k, meas->dx*i, meas->dy*j, min1);
      }else{
        t2->SetPoint(k, meas->dx*i, meas->dy*j, min2);
      }
      k++;
    }
  }
  TCanvas *c1 = new TCanvas("c1", "FullScan", 0, 0, 1000, 1000);
  gStyle->SetPalette(kDarkBodyRadiator);
  t2->SetMarkerStyle(20);
  t2->Draw("COLZ");

}