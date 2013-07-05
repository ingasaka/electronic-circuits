/*
 * adc.h
 *
 * Created: 5. 5. 2013 20:02:07
 *  Author: asaka
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "main.h"

class Adc{
	
	public:
		Adc();
		unsigned char getAD(unsigned char);
	
	};



#endif /* ADC_H_ */