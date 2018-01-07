{
  PSTCT *meas;
  meas = new PSTCT("../Downloads/vscan.rtct", 0, 2);
  float yvalues[120];
  float cur[120];
  int i = 0;
  for(;i<120;i++){
    yvalues[i]=i;
    cur[i]=meas->I1[i]*-1;
  }
  TGraph *t1;
  t1 = new TGraph(120, yvalues, cur);
  t1->SetLineColor(kRed);
  t1->Draw("ALP");



}
