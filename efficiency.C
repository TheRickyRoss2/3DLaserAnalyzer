{
  #define PATH "Run14_HPK80D_KU_IR.rtct"
  #define PADLENGTH 3000
  #define METALLENGTH 1500
  #define MIPSPMAX 100
  char * file = (char *) PATH;


  PSTCT * meas;
  meas = new PSTCT(file,0,2);
  int i=0,j=0;
  double hitArea = (PADLENGTH*PADLENGTH)-(METALLENGTH*METALLENGTH)
  double expectedTotalVout= MIPSPMAX*hitArea;
  double totalVout=0;
  for(i=0;i<meas->Nx;i++){
    for(j=0;j<meas->Ny;j++){
      TH1F *t1;
      t1 = meas->GetHA(0, i, j, 0, 0);

      t1->GetXaxis()->SetRange(82*1024/200, 97*1024/200);
      double minVout;
      minVout = -1*t1->GetMinimum();
      if(minVout<50){
        totalVout+=0;
      }else if(minVout>100){
        totalVout+=100;
      }else{
        totalVout+=minVout;
      }
      t1 = meas->GetHA(1, i, j, 0, 0);
      t1->GetXaxis()->SetRange(82*1024/200, 97*1024/200);
      minVout = -1*t1->GetMinimum();
      if(minVout<50){
        totalVout+=0;
      }else if(minVout>100){
        totalVout+=100;
      }else{
        totalVout+=minVout;
      }
    }
  }
  cout <<"Efficiency: "<<(totalVout/expectedTotalVout)*100<<"%"<<endl;
}
