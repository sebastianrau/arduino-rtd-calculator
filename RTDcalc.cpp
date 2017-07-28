

#include "RTDcalc.h"




double RTDcalc::PTC_A = 3.9083e-3;
double RTDcalc::PTC_B = -5.775e-7;

double RTDcalc::NTC_TN = 298.15;		//25 celsius


RTDcalc::RTDcalc(){
	 r0 = 100.0;  
}

RTDcalc::RTDcalc(double r0_value){
	 r0 = r0_value;  
}

RTDcalc::RTDcalc(double r25_value, double b_value){
	r0 = r25_value;  
	b = b_value;
}


double RTDcalc::calcPTC_Celsius(float rx) {
  double  T = 0.0;
  T = -r0 * PTC_A + pow(((r0 * PTC_A) * (r0 * PTC_A)) - 4 * r0 * PTC_B * (r0 - rx), 0.5);
  T = T / (2 * r0 * PTC_B);
  return T;
}

//TODO
double RTDcalc::calcNTC_Celsius(float rx){
	//float T = 0; // Variable für gemessene Temperatur
	//T = (b*NTC_TN)/(b+(log(rx/r0)*NTC_TN)); // Berechnung der Temperatur
	
	//T = b/(log(rx/r0)+b/(NTC_TN)); 
	
	double steinhart;
	  steinhart = rx / r0;     			// (R/Ro)
	  steinhart = log(steinhart);       // ln(R/Ro)
	  steinhart /= b;                   // 1/B * ln(R/Ro)
	  steinhart += 1.0 / (NTC_TN); 		// + (1/To)
	  steinhart = 1.0 / steinhart;      // Invert
	  steinhart -= 273.15;              // convert to C
	
	
	return steinhart;
}





