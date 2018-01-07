{
  //gSystem->Load("TCTAnalyse.sl" );
 //char * file= (char *)"examples/testsensorrun.rtct";      // measurement file
 // char* file = (char *)  "~/Downloads/TCTAnalyse.V2.0/examples/NTypeDiode-300um-FocusFind-IR.rtct";
  //meas.PrintInfo();
  PSTCT * meas;
  meas = new PSTCT("/Users/Home/Downloads/vscan_good2.rtct", 0, 2);

  //gROOT->ProcessLine(".x GetFocus.C");
  meas->PrintInfo();
  //int size = meas.Nx * meas.Ny;
#define NO 106 
  Double_t ypos[NO];
  //ypos = new double[meas->NU1];
  Double_t ch1[NO];
  Double_t ch2[NO];

  int i=0;

  for(i=0;i<NO;i++){
    TH1F* t;

    ypos[i] = i*2;

    t = meas->GetHA(0, 0, 0, 0, i, 0);
    ch1[i]=t->GetMinimum()*-1;
    //ch1[i]= t->Integral(0.4*1024, 0.8*1024)/10.0/1000.0/(10e9);
   // ch1err[i] = sqrt((1/100)*ch1[i]>0?ch1[i]:-1*ch1[i]);

  }
  cout <<"gothere" <<endl;
  TGraph *t1[2];
  TMultiGraph *mg = new TMultiGraph();
  t1[0] = new TGraph(meas->NU1, ypos, ch1);
  t1[0]->SetLineColor(kRed);
  //t1[1] = new TGraph(meas->NU1, ypos, ch2);
  //t1[1]->SetLineColor(kBlue);
  //t1[2] = new TGraph(85, ypos, ch3);
  //t1[2]->SetLineColor(6);

  //t1[1]->SetTitle("Aasdf");
  mg->Add(t1[0]);//#mg->Add(t1[1]);
  //mg->Add(t1[2]);
  mg->Draw("AL");
  mg->GetXaxis()->SetTitle("Bias Voltage [V]");
  mg->GetYaxis()->SetTitle("Amplitude [mV]");
  mg->GetHistogram()->SetTitle("PMax vs Bias Voltage");
  mg->Draw("AL");


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