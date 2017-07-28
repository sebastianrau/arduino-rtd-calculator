
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




class RTDcalc {


  private:
    double r0;
	double b;
	
	static double 	PTC_A,
					PTC_B,
					NTC_TN;
					
					
	inline double c_to_f(double c){
		return (c * 1.8) + 32;
	};
	inline double c_to_k(double c){
		return c + 273.15;
	}

  public:
  	RTDcalc();
	RTDcalc(double r0_value);
	RTDcalc(double r25_value, double b_value);
  
    inline void setR0(double r0_value){
      r0 = r0_value;  
    }
    
	
    double calcPTC_Celsius(float rx);
   	inline double calcPTC_Kelvin(float rx){
		return c_to_k(calcPTC_Celsius(rx));
	}
	inline double calcPTC_Fahrenheit(float rx){
		return c_to_f(calcPTC_Celsius(rx));
	}
	
	double calcNTC_Celsius(float rx);
   	inline double calcNTC_Kelvin(float rx){
		return c_to_k(calcNTC_Celsius(rx));
	}
	inline double calcNTC_Fahrenheit(float rx){
		return c_to_f(calcNTC_Celsius(rx));
	}
	
	
	
};

#endif
