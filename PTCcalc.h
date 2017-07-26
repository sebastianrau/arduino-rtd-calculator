
#ifndef __PTC_CALC_BOARD_H__
#define __PTC_CALC_BOARD_H__

#include "Arduino.h"


#define R0_PT25		10.0f
#define R0_PT10		25.0f
#define R0_PT100	100.0f
#define R0_PT200	200.0f
#define R0_PT500	500.0f
#define R0_PT1000	1000.0f
#define R0_PT3000	3000.0f
#define R0_PT6000	6000.0f
#define R0_PT9000	9000.0f




class PTCcalc {


  private:
    double r0;
	static double A;
    static double B;

  public:
  	PTCcalc();
	PTCcalc(double r0_value);
  
    inline void setR0(double r0_value){
      r0 = r0_value;  
    }
    
    double calcTemperatureCelsius(float rx);
    double calcTemperatureKelvin(float rx);
	double calcTemperatureFahrenheit(float rx);
    
};

#endif
