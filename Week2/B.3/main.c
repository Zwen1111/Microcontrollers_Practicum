/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** lookup.c
**
** Beschrijving:	Ledpatroon op PORTD dmv table lookup (scheiding logica en data)    
** Target:			AVR mcu
** Build:			avr-gcc -std=c99 -Wall -O3 -mmcu=atmega128 -D F_CPU=8000000UL -c switch.c
**					avr-gcc -g -mmcu=atmega128 -o lookup.elf lookup.o
**					avr-objcopy -O ihex lookup.elf lookup.hex 
**					or type 'make'
** Author: 			mawijnen2@avans.nl & ajerkele@avans.nl
** -------------------------------------------------------------------------*/

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int index;
int vect1;
int vect2;

typedef struct { 
	unsigned char data;
} PATTERN_STRUCT; 

// 7 seg
// PORTD dp G F E D C B A
//        y y y y x x x x

PATTERN_STRUCT pattern[] = {
	{0x3F}, // '0'
	{0x06}, // '1'
	{0x5B}, // '2'
	{0x4F}, // '3'
	{0x66}, // '4'
	{0x6D}, // '5'
	{0x7D}, // '6'
	{0x07}, // '7'
	{0x7F}, // '8'
	{0x6F}, // '9'
	{0x77}, // 'A'
	{0x7C}, // 'B'
	{0x39}, // 'C'
	{0x5E}, // 'D'
	{0x79}, // 'E'
	{0x71}, // 'F'
};

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
short:			ISR INT1
inputs:
outputs:
notes:			Sets the vect1 variable to 1
Version :    	Zwen van Erkelens & Thijs Wijnen, Initial code
*******************************************************************/
{
	vect1 = 1;
}

/******************************************************************/
ISR( INT2_vect )
/*
short:			ISR INT2
inputs:
outputs:
notes:			Sets the vect2 variable to 1
Version :    	Zwen van Erkelens & Thijs Wijnen, Initial code
*******************************************************************/
{
	vect2 = 1;
}


/******************************************************************/
int main( void )
/* 
short:			main() loop, entry point of executable
inputs:			
outputs:	
notes:			
Version :    	Zwen van Erkelens & Thijs Wijnen, Initial code
*******************************************************************/
{
	DDRD = 0xF0;
	DDRC = 0b11111111;					// PORTD all output 
	
	// Set index to begin of pattern array
	index = 0;
	
	// Init Interrupt hardware
	EICRA |= 0x2C;			// INT2 falling edge, INT1 rising edge
	EIMSK |= 0x06;			// Enable INT2 & INT1
	
	// Enable global interrupt system
	//SREG = 0x80;			// Of direct via SREG of via wrapper
	sei();
	
	PORTC = pattern[index].data;
	
	while (1==1)
	{
		if (vect1 == 1 && vect2 == 1)
		{
			index = 0;
			PORTC = pattern[index].data;
			vect1 = 0;
			vect2 = 0;
		}else if (vect1 == 1)
		{
			index--;
			if (index > 15 || index < 0)
			{
				PORTC = pattern[14].data;
				}else{
				PORTC = pattern[index].data;
			}
			vect1 = 0;
		}else if(vect2 == 1)
		{
			index++;
			if (index > 15 || index < 0)
			{
				PORTC = pattern[14].data;
				}else{
				PORTC = pattern[index].data;
			}
			vect2 = 0;
		}
		wait(200);
	}

	return 1;
}