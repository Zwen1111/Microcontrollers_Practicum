/*
 * Opdracht B3
 *
 * Created: 7-3-2018 17:09:46
 * Author : Thijs van Wijnen & Zwen van Erkelens
 */

#define F_CPU 8000000

#include "lcd.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

void initAdc() {
	ADMUX = 0b11100010;			// AREF=2,56 V, result left adjusted, channel1 at pin PF1
	ADCSRA = 0b11100110;		// ADC-enable, no interrupt, no free running, division by 64
}


int main(void)
{
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0x00;	
	DDRF = 0x00;

	ADMUX	= 0b11100000;
	ADCSRA	= 0b11100110;
	
	initAdc();
	init();
	char temp[16];
	
	while (1)
	{
		PORTA = ADCH;
		PORTB = ADCL;
		
		clr_display();
		sprintf(temp, "Temp: %d", ADCH);
		display_text(temp);
		wait(500);
	}
	return 0;
}