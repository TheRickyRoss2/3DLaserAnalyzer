{
  /****************************************************************************
   * File: efficiency.C
   * Version: 1.0
   * Author: Ric Rodriguez
   * Function: Calculates the efficiency of a particle detector array
   * Example usage
   * ~bash$: root
   * root[0]: gSystem->Load("TCTAnalyse.sl");
   * root[1]: .x efficiency.C;
   ****************************************************************************/

  #define PATH "../Downloads/Run14_HPK80D_KU_IR.rtct"
  #define PAD_LENGTH 3000
  #define METAL_LENGTH 1500
  #define NO_PADS 2
  #define MIP_PMAX 100
  #define FOCAL_LENGTH 100

  char * file = (char *) PATH;

  PSTCT * meas;
  meas = new PSTCT(file,0,2);
  int i=0,j=0;
  double hitArea = (PAD_LENGTH/FOCAL_LENGTH*PAD_LENGTH/FOCAL_LENGTH)-(METAL_LENGTH/FOCAL_LENGTH*METAL_LENGTH/FOCAL_LENGTH);
  double expectedTotalVout= 2*MIP_PMAX*hitArea;
  double totalVout=0;

  for(i=0;i<meas->Nx;i++){
    for(j=0;j<meas->Ny;j++){

      TH1F *t1;
      t1 = meas->GetHA(0, i, j, 0, 0);
      //t1->GetXaxis()->SetRange(82*meas->NP/t1->GetXaxis()->GetXmax(), 97*meas->NP/t1->GetXaxis()->GetXmax());
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
      //t1->GetXaxis()->SetRange(82*meas->NP/t1->GetXaxis()->GetXmax(), 97*meas->NP/t1->GetXaxis()->GetXmax());
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
