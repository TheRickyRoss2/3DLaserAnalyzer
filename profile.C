{
  //gSystem->Load("TCTAnalyse.sl" );
 //char * file= (char *)"examples/testsensorrun.rtct";      // measurement file
 // char* file = (char *)  "~/Downloads/TCTAnalyse.V2.0/examples/NTypeDiode-300um-FocusFind-IR.rtct";
  //meas.PrintInfo();
  PSTCT * meas;
  meas = new PSTCT("/Users/Home/Downloads/Run172_CNM_AC_VOLT.rtct", 0, 2);

  //gROOT->ProcessLine(".x GetFocus.C");
  meas->PrintInfo();
  meas->CorrectBaseLine(70);
#define NO 56
  TCanvas *c1 = new TCanvas("c", "c", 600, 400);
  //int size = meas.Nx * meas.Ny;
  Double_t ypos[NO];
  //ypos = new double[meas->NU1];
  Double_t ch1[NO];
  Double_t ch2[NO];
  Double_t ch3[NO];

  int i=0;
/*
  for(i=0;i<meas->Nx;i++){
    TH1F* t;

    ypos[i] = i*meas->dx+meas->x0;

    t = meas->GetHA(0, i, 0, 0);
    t->GetXaxis()->SetRange(60*meas->NP/t->GetXaxis()->GetXmax(), 140*meas->NP/t->GetXaxis()->GetXmax());
    ch1[i]= t->GetMaximum()>-1*t->GetMinimum()?t->GetMaximum():t->GetMinimum();
    t = meas->GetHA(1, i, 0, 0);
    t->GetXaxis()->SetRange(60*meas->NP/t->GetXaxis()->GetXmax(), 140*meas->NP/t->GetXaxis()->GetXmax());
    ch2[i]= t->GetMaximum()>-1*t->GetMinimum()?t->GetMaximum():t->GetMinimum();

  }
  */
  TGraph *t1[6];
  TMultiGraph *mg = new TMultiGraph();
  /*
  t1[0] = new TGraph(NO, ypos, ch1);
  t1[0]->SetLineColor(kRed);
  t1[1] = new TGraph(NO, ypos, ch2);
  t1[1]->SetLineColor(kBlue);
  t1[2] = new TGraph(NO, ypos, ch3);
  t1[2]->SetLineColor(kGreen);
  */
  TH1F *t;
#define xp 0 
#define ch 1
  t = meas->GetHA(ch, 0, 0, 0, 18, 0);
  cout <<"asdf"<<endl;
  t1[0] = new TGraph(t);
  t1[0]->SetLineColor(kRed);
  t = meas->GetHA(ch, 0, 0, 0, 19, 0);
  t1[1] = new TGraph(t);
  t1[1]->SetLineColor(kBlue);
  
  t = meas->GetHA(ch, 0, 0, 0, 20, 0);
  t1[2] = new TGraph(t);
  t1[2]->SetLineColor(kOrange);
  
  t = meas->GetHA(ch, 0, 0, 0, 21, 0);
  t1[3] = new TGraph(t);
  t1[3]->SetLineColor(kMagenta);

  t = meas->GetHA(ch, 0, 0, 0, 30, 0);
  cout << "asdf"<<endl;
  t1[4] = new TGraph(t);
  t1[4]->SetLineColor(kGreen+4);

  t = meas->GetHA(ch, 0, 0, 0, 40, 0);
  t1[5] = new TGraph(t);
  t1[5]->SetLineColor(kBlack);
  /*
  t = meas->GetHA(ch, xp, 1, 0);
  t1[3] = new TGraph(t);
  t1[3]->SetLineColor(kOrange);
  t = meas->GetHA(ch, xp, 0, 0);
  t1[4] = new TGraph(t);
  t1[4]->SetLineColor(kPink);
  */

  //t1[1]->SetTitle("Aasdf");
  mg->Add(t1[0]);
  mg->Add(t1[1]);
  mg->Add(t1[2]);
  mg->Add(t1[3]);
  mg->Add(t1[4]);
  mg->Add(t1[5]);
  
  //mg->Add(t1[2]);
  mg->Draw("AL");
  mg->GetXaxis()->SetTitle("Time [ns]");
  mg->GetYaxis()->SetTitle("Amplitude [mV]");
  mg->GetHistogram()->SetTitle("Amplitude vs Time");
  mg->Draw("AL");
  c1->BuildLegend()
  /*
  TGraphErrors *gr;
  gr = new TGraphErrors(86, ypos, ch1, yerr, ch1err);
  gr->SetTitle("Pmax vs Bias");
  gr->SetMarkerColor(4);
  gr->SetMarkerStyle(21);
  gr->SetMarkerSize(0.5);
  gr->Draw("AP");
  */

  //gr->GetHistogram()->SetTitle("Amplitude vs Bias Voltage (DAC=30.0%);Bias Voltage [V];Amplitude [mV]");
  /*
  TGraph * t1 =new TGraph(6000, ypos, amplitude);
  //t1->Draw("*");
  t1->GetYaxis()->SetTitle("Amplitude [mV]");
  t1->GetXaxis()->SetTitle("Y-Position [um]");
  t1->SetTitle("Scan over y-axis dy=100um");
*/
  //TCanvas * t1 = new TCanvas("c", "Example", 0,0, 1000, 1000);
  //TCanvas* c1 = new TCanvas();
  /*
  int i =0,j=0;
  double_t mins[10][10];
  for(i=0; i<1; i++){
    for(j=0; j<1; j++){
      gROOT->ProcessLine("stct.GetHA(1, i, 0, j, 0, 0)->Draw()");
      gROOT->ProcessLine("mdns[i][j] = c1->GetUymin()");
      cout << c1->GetUymin() <<endl;
      printf("Vmin[%d][%d]=%lf\n", i,j, mins[i][j]);
    }
  }
  //stct.GetHA(1,fsdfg 0, 0, 0, 0, 0)->Draw();
  //int i = c1.GetUymin();
	//stct.GetHA(1,0,0,0,0,0)->Draw();
  */
}