{
  TGraph *t1 = new TGraph(130000);
  ifstream myfile("9pads_Ch2.txt");
  string line;
  int k = 0;
  while(getline(myfile, line)){
    Double_t x = stod(line);
    getline(myfile, line);
    Double_t y = stod(line);
    t1->SetPoint(k++, x, y);
    if(k>130000)break;
  }
  TGraph *t2 = new TGraph(130000);
  ifstream otherfile("9pads_Ch1.txt");
  k=0;
  while(getline(otherfile, line)){
    Double_t x = stod(line);
    getline(otherfile, line);
    Double_t y = stod(line);
    t2->SetPoint(k++, x,y);
    if(k>130000)break;
  }
  t2->Draw("AC");
  t1->Draw("SAME");
/*
  char c;
  cin >> c;
  TF1 f1("f",[&](double *x, double *){return t1->Eval(x[0]);}, 0, 350, 0);
  TF1 f2("f",[&](double *x, double *){return t2->Eval(x[0]);}, 0,350, 0);
  f2.Draw("AC");
  f1.Draw("SAME");
*/

}
