{
  PSTCT * meas;
  meas = new PSTCT("/Users/Home/Downloads/sample.rtct", 0, 2);

  meas->PrintInfo();
  //meas->CorrectBaseLine(5);
#define NO 100
  TCanvas *c1 = new TCanvas("c", "c", 600, 400);
  Double_t ypos[NO];
  Double_t ch1[NO];
  Double_t ch2[NO];


  int i=0, j=0;

  for(i=0;i<NO;i++)
    ch1[i]=0;

  for(i=0;i<NO;i++){
    for(j=44;j<=50;j++){
    TH1F* t;

    ypos[i] = i*meas->dx+meas->x0;

    t = meas->GetHA(0, meas->Nx-i-1, j, 0);
    ch1[i]= t->GetMinimum()*-1;
    ch1[i] += meas->GetHA(1, meas->Nx-i-1, j, 0)->GetMinimum()*-1;
    ch1[i] += meas->GetHA(2, meas->Nx-i-1, j, 0)->GetMinimum()*-1;
    ch1[i] += meas->GetHA(3, meas->Nx-i-1, j, 0)->GetMinimum()*-1;

    //if(ch2[i]>12) ch2[i] = ch2[i-1];
    //t = meas->GetHA(2, i, 0, 0);
    //t->GetXaxis()->SetRange(85*meas->NP/t->GetXaxis()->GetXmax(), 105*meas->NP/t->GetXaxis()->GetXmax());
    //ch3[i]= t->GetMaximum();
    //if(ch3[i]>12) ch3[i] = ch3[i-1];
    //total[i] = ch1[i]+ch2[i]+ch3[i];
    }
  }
  //for(i=0;i<NO;i++)
  // ch1[i] = ch1[i]/(double) NO;

  TGraph *t1[4];
  TMultiGraph *mg = new TMultiGraph();
  
  t1[0] = new TGraph(NO, ypos, ch1);
  t1[0]->SetLineColor(kRed);
  //t1[1] = new TGraph(NO, ypos, ch2);
  //t1[1]->SetLineColor(kBlue);
  //t1[2] = new TGraph(NO, ypos, ch3);
  //t1[2]->SetLineColor(kPurple);
  //t1[3] = new TGraph(NO, ypos, total);
  mg->Add(t1[0]);
  //mg->Add(t1[1]);
  //mg->Add(t1[2]);
  //mg->Add(t1[3]);
  mg->Draw("AL");
  mg->GetXaxis()->SetTitle("X-Position [um]");
  mg->GetYaxis()->SetTitle("Amplitude [mV]");
  mg->GetHistogram()->SetTitle("Amplitude vs X-Position (38% DAC, 50kHz, 200V, W4-AC2, Avg over pixel)");
  mg->Draw("AL");
}