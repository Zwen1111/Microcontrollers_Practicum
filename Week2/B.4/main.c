/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** lookup.c
**
** Beschrijving:	Ledpatroon op PORTC dmv table lookup (scheiding logica en data)    
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

typedef struct { 
	unsigned char data;
	unsigned int delay ;
} PATTERN_STRUCT;

PATTERN_STRUCT pattern[] = { 
	{0x02, 150}, {0x06, 150}, 
	{0x0E, 150}, {0x1E, 150},
	{0x3E, 150}, {0x3F, 150},
	
	{0x3D, 150}, {0x39, 150},
	{0x31, 150}, {0x21, 150},
	{0x01, 150}, {0x00, 0},
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
int main( void )
/* 
short:			main() loop, entry point of executable
inputs:			
outputs:	
notes:			
Version :    	Zwen van Erkelens & Thijs Wijnen, Initial code
*******************************************************************/
{
	DDRC = 0b11111111;					// PORTD all output
	int delay = 0;
	
	while (1==1)
	{
		// Set index to begin of pattern array
		int index = 0;
		if ((150-delay)*0.1 < 1)
		{
			delay = 0;
		}else{
			delay += (150-delay)*0.1;
		}
		
		// as long as delay has meaningful content
		while( pattern[index].delay != 0 ) {
			// Write data to PORTD	
			PORTC = pattern[index].data;
			// wait
			if (pattern[index].delay != 0)
			{
				wait(pattern[index].delay - delay);
			}else{
				wait(pattern[index].delay);
			}
			// increment for next round
			index++;
		}
	}

	return 1;
}