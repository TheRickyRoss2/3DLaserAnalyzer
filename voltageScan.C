{
  //gSystem->Load("TCTAnalyse.sl" );
 //char * file= (char *)"examples/testsensorrun.rtct";      // measurement file
 // char* file = (char *)  "~/Downloads/TCTAnalyse.V2.0/examples/NTypeDiode-300um-FocusFind-IR.rtct";
  //meas.PrintInfo();
  PSTCT * meas, *meas2;
  meas = new PSTCT("/Users/Home/Downloads/new_vscan.rtct", 0, 2);

  //gROOT->ProcessLine(".x GetFocus.C");
  meas->PrintInfo();
  //int size = meas.Nx * meas.Ny;
#define NO 100
  Double_t ypos[NO];
  //ypos = new double[meas->NU1];
  Double_t ch1[NO];
  Double_t ch2[NO];
  Double_t ch3[NO];
  Double_t ch4[NO];
  auto c1 = new TCanvas("c1", "c1", 600, 500);
  int i=0;
  cout << "Read in file " <<endl;
  TMultiGraph *mg = new TMultiGraph();
  gStyle->SetPalette(kBird);
  int c = 0;
  auto legend = new TLegend(0.1, 0.2, 0.4, 0.6);
  for(i=0;i<NO;i+=2){
    //TH1F* t;
    //ypos[i] = i*2;
    TGraph *tmp = new TGraph(meas->GetHA(0, 0, 0, 0, i));
    tmp->SetLineColor((c++)+2);
    mg->Add(tmp);
    stringstream ss;
    ss << i*2 <<"V";
    legend->AddEntry( tmp,ss.str().c_str(), "l");
    //ch1[i]=t->GetMinimum()*-1;
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
  //TGraph *t1[4];
  //t1[0] = new TGraph(NO, ypos, ch1);
  //t1[0]->SetLineColor(kRed);
  //t1[1] = new TGraph(NO, ypos, ch2);
  //t1[1]->SetLineColor(kBlue);
  //t1[2] = new TGraph(meas->NU1, ypos, ch3);
  //t1[2]->SetLineColor(6);
  //t1[3] = new TGraph(meas->NU1, ypos, ch4);
  //t1[3]->SetLineColor(12);

  //t1[1]->SetTitle("Aasdf");
 // mg->Add(t1[0]);
 // mg->Add(t1[1]);
  //mg->Add(t1[2]);
  //mg->Add(t1[3]);
  //hs->Draw("pfc ");/*
  mg->Draw("AL");
  mg->GetXaxis()->SetTitle("Time [ns]");
  mg->GetYaxis()->SetTitle("Amplitude [mV]");
  mg->GetHistogram()->SetTitle("Detectors CNM Run10478 S1 vs AC-2, TCT Laser: 39.7% 1kHz");
//mg->GetHistogram()->SetTitle("Detectors CNM Run10478 AC-2 Strip, TCT Laser: 39.7% 1kHz");
  mg->Draw("AL");
  legend->Draw();

}