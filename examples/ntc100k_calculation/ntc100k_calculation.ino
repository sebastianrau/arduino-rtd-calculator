
#include <RTDcalc.h>


double    mesurredResistance0 = 100000;   // 25 degree celsius
          

RTDcalc   ptcCalc0(100000,4850);            //Set NTC with 100000Ohm @ 25 Deg. Celsius and B=4850
         

double    temperature0;


void setup ( void ) {
  Serial.begin(115200);


  temperature0 = ptcCalc0.calcPTC_Celsius(mesurredResistance0);
  

  Serial.print("T0:\t");
  Serial.print(temperature0);
  Serial.println(" deg. celsius. (should be ~25)");
}

void loop ( void ) {
}



