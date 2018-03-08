/*
 * Opdracht B1
 *
 * Created: 7-3-2018 15:45:21
 * Author : Thijs van Wijnen & Zwen van Erkelens
 */

 #define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

void adcInit() {
	ADMUX = 0b11100001;			// AREF=2,56 V, result left adjusted, channel1 at pin PF1
	ADCSRA = 0b10000110;		// ADC-enable, no interrupt, no free running, division by 64
}

int main(void)
{
	DDRF = 0x00;					// set PORTF for input (ADC)
	DDRA = 0xFF;					// set PORTA for output
	adcInit();						// initialize ADC
	
    while (1) 
    {
		PORTA = ADCL;
		PORTB = ADCH;
		
		wait(100);
    }
}