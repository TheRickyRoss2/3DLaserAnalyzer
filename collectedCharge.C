{
  int i=0, j=0, k=0;
  char * file = (char *) "Run14_HPK80D_KU_IR.rtct";
  PSTCT * meas;
  meas = new PSTCT(file,0,2);
  meas->PrintInfo();

  TGraph2D * t2 = new TGraph2D(35*65);
  t2->SetNpy(65);
  t2->SetNpx(35);


  double R = 10e9;
  R = R*1000*30*680;
  for(i=0;i<35;i++){
    for(j=0;j<65;j++){
      TH1F * t1;
      t1 = meas->GetHA(0, i, j, 0, 0, 0);
      t1->GetXaxis()->SetRange(82*1024/200, 97*1024/200);
      double min1 = -1*t1->Integral()/R;
      t1 = meas->GetHA(1, i, j, 0, 0, 0);
      t1->GetXaxis()->SetRange(82*1024/200, 97*1024/200);
      double min2 = -1*t1->Integral()/R;
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
