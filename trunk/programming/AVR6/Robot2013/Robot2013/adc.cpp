/*
 * adc.c
 *
 * Created: 5. 5. 2013 20:05:44
 *  Author: asaka
 */ 
#include "adc.h"
#include <avr/io.h>

Adc::Adc(){
	// Set reference voltage
	// REFS[0..1] = low -> AREF
	L(ADMUX, REFS0);
	L(ADMUX, REFS1);

	// prescaler set
	// ADPS[0..2] =  / 128
	H(ADCSRA, ADPS0);
	H(ADCSRA, ADPS1);
	H(ADCSRA, ADPS2);


	// watch only 8bits from ADCH
	H(ADMUX, ADLAR);

	// enable ADC
	H(ADCSRA, ADEN);	
}

unsigned char Adc::getAD(unsigned char pin){
   // Clear register
   ADCH=0x00;
   
   // clear pin register
   ADMUX&=~0x07;
   
   //  set pin from 0 to 7 (function parameter);
   ADMUX|=pin;
   
   // start processing
   H(ADCSRA, ADSC);
   
   // wait for processing ends
   while(IS(ADCSRA, ADSC));
   
   // return 8-bit data
   return ADCH;
}	