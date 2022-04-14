#include "StepperMulti.h"
#include <MsTimer2.h>

StepperMulti step_R(200, 4, 6, 5, 7);
StepperMulti step_L(200, 8, 10, 9, 11);
int n = 0;


//적외선 핀 번호
int sencer1 = A1;//재확인 좌
int sencer2 = A0;//재확인 우



void sta ()
{
  int sen1 = analogRead(sencer1);
  int sen2 = analogRead(sencer2);

  //  if (n == 200) n = 0; // ++일때
  //  else (n == 0) n = 200; // -- 일떄



  if (sen1 >= 750 && sen2 >= 750)
  {
    step_L.moveStep(-1);  // 왼쪽 직진
    step_R.moveStep(1); // 오른쪽 직진
  }
  else if (sen1 <= 750 && sen2 >= 750) // 우측좁아질때
  {
    step_R.moveStep(1);
    if (n == 0) n = 200;
    n--;
    if (n % 2) step_L.moveStep(-1);
  }

  else if (sen1 >= 750 && sen2 <= 750) // 좌측좁아질때
  {
    step_L.moveStep(-1);
    if (n == 200) n = 0;
    n++;
    if (n % 2) step_R.moveStep(1);
  }
}



void setup() {
  MsTimer2::set(10, sta);
  MsTimer2::start();

}





void loop() {
  // put your main code here, to run repeatedly:

}
