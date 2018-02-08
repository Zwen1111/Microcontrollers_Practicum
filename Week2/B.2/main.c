/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** main.c
**
** Beschrijving:	ISR on PORTD demonstrattion  
** Target:			AVR mcu
** Build:			avr-gcc -std=c99 -Wall -O3 -mmcu=atmega128 -D F_CPU=8000000UL -c ioisr.c
**					avr-gcc -g -mmcu=atmega128 -o ioisr.elf ioisr.o
**					avr-objcopy -O ihex ioisr.elf ioisr.hex 
**					or type 'make'
** Author: 			zwen12@msn.com
** -------------------------------------------------------------------------*/

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int j;

/******************************************************************/
void wait( int ms )
/* 
short:			Busy wait number of millisecs
inputs:			int ms (Number of millisecs to busy wait)
outputs:	
notes:			Busy wait, not very accurate. Make sure (external)
				clock value is set. This is used by _delay_ms inside
				util/delay.h
Version :    	DMK, Initial code
*******************************************************************/
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

/******************************************************************/
ISR( INT1_vect )
/* 
short:			ISR INT0
inputs:			
outputs:	
notes:			Turns of the LED and turns on the next LED
Version :    	AJERKELE, Initial code
*******************************************************************/
{
	PORTC = 1<<j;
	++j;
	if(j>7){
		j = 0;
	}
	wait(250);
}

/******************************************************************/
ISR( INT2_vect )
/* 
short:			ISR INT2
inputs:			
outputs:	
notes:			Turns of the LED and turns on the next LED
Version :    	AJERKELE, Initial code
*******************************************************************/
{
	PORTC = 1<<j;
	++j;
	if(j>7){
		j = 0;
	}
	wait(250);
}

/******************************************************************/
int main( void )
/* 
short:			main() loop, entry point of executable
inputs:			
outputs:	
notes:			Slow background task after init ISR
Version :    	DMK, Initial code
*******************************************************************/
{
	// Init I/O
	DDRD = 0xF0;			// PORTD(7:4) output, PORTD(3:0) input	
	DDRC = 0xFF;			// PORTD(7:0) output

	// Init Interrupt hardware
	EICRA |= 0x2C;			// INT2 falling edge, INT1 rising edge
	EIMSK |= 0x06;			// Enable INT2 & INT1
	
	j = 0;
	PORTC = 1<<j;
	
	// Enable global interrupt system
	//SREG = 0x80;			// Of direct via SREG of via wrapper
	sei();

	while (1)
	{								
	}

	return 1;
}