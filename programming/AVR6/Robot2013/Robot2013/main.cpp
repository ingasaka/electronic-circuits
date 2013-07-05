/*
 * RobotSOSJR.c
 *
 * Created: 24. 4. 2013 11:51:46
 *  Author: Lukas Tatarka & Patrik Rodina as students
 *  Helper: Ing. Tomas Skvarenina as teacher
 */ 


/*	Atmega8 Robot connecting
 *  PIN01 -			PIN28 - I2C/display
 *  PIN02 -			PIN27 - I2C/display
 *  PIN03 -			PIN26 - 
 *  PIN04 -			PIN25 - 
 *  PIN05 -			PIN24 - AD black/white
 *  PIN06 -			PIN23 - AD black/white 
 *  PIN07 -			PIN22 - 
 *  PIN08 -			PIN21 - 
 *  PIN09 -			PIN20 - Direction motor 2B
 *  PIN10 -			PIN19 - Direction motor 2A
 *  PIN11 -			PIN18 - Direction motor 1B
 *  PIN12 -			PIN17 - Direction motor 1A
 *  PIN13 -			PIN16 - PWM Motor2
 *  PIN14 -			PIN15 - PWM Motor1
 */
#define F_CPU=1000000UL
#include "main.h"
#include "adc.h"
#include <util/delay.h>
#include<stdlib.h>
#include <avr/io.h>
#include <stdio.h>
#include "LiquidCrystal_I2C.h"




Adc *adc;

int main(void)
{
	
	char buff[16];
	
	adc = new Adc;
	unsigned char data = 0;

	 OSCCAL = 0xBF;
	 
	 LiquidCrystal_I2C lcd(0x27, 16, 2);
	 _delay_ms(50);
	 lcd.init();
	 lcd.backlight();
	 lcd.printstr("AD prevodnik");
	 lcd.setCursor(0,0);
	 _delay_ms(500);
	 lcd.clear();



	
	
    while(1)
    {
        //TODO:: Please write your application code 
		data = adc->getAD(1);
		lcd.setCursor(0,0);
		sprintf(buff,"S1:%5d",data);
		lcd.printstr(buff);
		_delay_ms(200);
		data = adc->getAD(1);
		lcd.setCursor(0,1);
		sprintf(buff,"S2:%5d",data);
		lcd.printstr(buff);
		_delay_ms(200);
		
    }
}