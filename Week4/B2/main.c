/*
 * Opdracht B2
 *
 * Created: 7-3-2018 16:17:57
 * Author : Thijs van Wijnen & Zwen van Erkelens
 */

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BIT(x)	(1 << (x))

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

void initAdc() {
	// ADC ref. spanning op internal 2.56V ref met external capacitor at AREF pin
	// 'hoge byte gevuld' en ADC0 aanzetten
	ADMUX = 0b11100000;
	
	// enable, start en zonder freerunning en /64
	ADCSRA = 0b10000110;
}

int main(void)
{
	// Alle poorten op F naar input voor de adc
	DDRF = 0x00;
	
	// A en B voor het aanzetten van lampjes, dus output van adc
	DDRA = 0xFF;   
	
	initAdc();
	
    while (1) 
    {
		ADCSRA |= BIT(6);
		while (ADCSRA & BIT(6));
		PORTA = ADCH;
		wait (500);
    }
}