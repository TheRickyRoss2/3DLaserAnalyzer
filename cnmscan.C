{
  /****************************************************************************
   * File: fullScan.C
   * Version: 1.0
   * Author: Ric Rodriguez
   * Function: Plots multiple channel's waveforms at one time
   * Example usage
   * ~bash$: root
   * root[0]: gSystem->Load("TCTAnalyse.sl");
   * root[1]: .x fullScan.C;
   ****************************************************************************/


	#define FILEPATH "../Downloads/Run87_CNM6x6_KU_IR_BACK_V.rtct"

  int i=0, j=0, k=0;
  char * file = (char *) FILEPATH;
  PSTCT * meas;
  meas = new PSTCT(file,0,2);
  meas->PrintInfo();
  meas->Draw(0, 0, 1, 0, 0, 0, 0, 2000)->Draw("SURF2Z");
}
