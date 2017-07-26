

#include "PTCcalc.h"




double PTCcalc::A = 3.9083e-3;
double PTCcalc::B = -5.775e-7;


PTCcalc::PTCcalc(){
	 r0 = 100.0;  
}

PTCcalc::PTCcalc(double r0_value){
	 r0 = r0_value;  
}

double PTCcalc::calcTemperatureCelsius(float rx) {
  double  T = 0.0;
  T = -r0 * A + pow(((r0 * A) * (r0 * A)) - 4 * r0 * B * (r0 - rx), 0.5);
  T = T / (2 * r0 * B);
  return T;
}


double PTCcalc::calcTemperatureKelvin(float rx){
	return calcTemperatureCelsius(rx) + 273.15;
}

double PTCcalc::calcTemperatureFahrenheit(float rx){
	return (calcTemperatureCelsius(rx) * 1.8) + 32;
}


