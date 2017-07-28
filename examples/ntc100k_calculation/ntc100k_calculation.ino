
#include <PTCcalc.h>


double    mesurredResistance0 = 109.73,   // 25 degree celsius
          mesurredResistance1 = 1077.94;  // 20 degree celsius

RTDcalc   ptcCalc0,             //Set as default: PT100
          ptcCalc1(R0_PT100);   //Set explicit as PT100

double    temperature0,
          temperature1;


void setup ( void ) {
  Serial.begin(115200);

  
  ptcCalc1.setR0(R0_PT1000);    //Use constructor or this set Method.

  temperature0 = ptcCalc0.calcPTC_Celsius(mesurredResistance0);
  temperature1 = ptcCalc1.calcPTC_Celsius(mesurredResistance1);

  Serial.print("T0:\t");
  Serial.print(temperature0);
  Serial.println(" deg. celsius. (should be ~25)");
  Serial.print("T1:\t");
  Serial.print(temperature1);
  Serial.println(" deg. celsius. (should be ~20)");
}

void loop ( void ) {
}



