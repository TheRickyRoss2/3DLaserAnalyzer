{
  //gSystem->Load("TCTAnalyse.sl" );
 //char * file= (char *)"examples/testsensorrun.rtct";      // measurement file
 // char* file = (char *)  "~/Downloads/TCTAnalyse.V2.0/examples/NTypeDiode-300um-FocusFind-IR.rtct";
  //meas.PrintInfo();
  PSTCT * meas, *meas2;
  meas = new PSTCT("/Users/Home/Downloads/vscan_good2.rtct", 0, 2);
  meas2 = new PSTCT("/Users/Home/Downloads/vscan_back3.rtct", 0,2);

  //gROOT->ProcessLine(".x GetFocus.C");
  meas->PrintInfo();
  //int size = meas.Nx * meas.Ny;
#define NO 105
  Double_t ypos[NO];
  //ypos = new double[meas->NU1];
  Double_t ch1[NO];
  Double_t ch2[NO];
  Double_t ch3[NO];
  Double_t ch4[NO];

  int i=0;
  cout << "Read in file " <<endl;

  for(i=0;i<NO;i++){
    TH1F* t;
    ypos[i] = i*2;
    t = meas->GetHA(3, 0, 0, 0, i);
    ch1[i]=t->GetMinimum()*-1;
    //t = meas2->GetHA(0, 0, 0, 0, i);
    //ch2[i]=t->GetMinimum()*-1;
    //t = meas->GetHA(2, 0, 0, 0, i);
    //ch3[i]=t->GetMinimum()*-1;
    //t = meas->GetHA(3, 0, 0, 0, i);
    //ch4[i]=t->GetMinimum()*-1;
    //ch1[i]= t->Integral(0.4*1024, 0.8*1024)/10.0/1000.0/(10e9);
    //ch1err[i] = sqrt((1/100)*ch1[i]>0?ch1[i]:-1*ch1[i]);

  }
  cout <<"gothere" <<endl;
  TGraph *t1[4];
  TMultiGraph *mg = new TMultiGraph();
  t1[0] = new TGraph(NO, ypos, ch1);
  t1[0]->SetLineColor(kRed);
  t1[1] = new TGraph(NO, ypos, ch2);
  t1[1]->SetLineColor(kBlue);
  //t1[2] = new TGraph(meas->NU1, ypos, ch3);
  //t1[2]->SetLineColor(6);
  //t1[3] = new TGraph(meas->NU1, ypos, ch4);
  //t1[3]->SetLineColor(12);

  //t1[1]->SetTitle("Aasdf");
  mg->Add(t1[0]);
  //mg->Add(t1[1]);
  //mg->Add(t1[2]);
  //mg->Add(t1[3]);
  mg->Draw("AL");
  mg->GetXaxis()->SetTitle("Bias Voltage [V]");
  mg->GetYaxis()->SetTitle("Amplitude [mV]");
  mg->GetHistogram()->SetTitle("Detector CNM Run10478 S1, TCT Laser: 39.7% 1kHz, Laser from back");
  mg->Draw("AL");


}