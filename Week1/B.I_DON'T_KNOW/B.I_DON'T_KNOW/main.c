/*
 * Week1.c
 *
 * Created: 1-2-2018 15:26:09
 * Author : zwen1
 */

 #define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

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

int main(void)
{
    /* Replace with your application code */
    DDRD = 0b11111111;			// All pins PORTD are set to output
    
    while (1)
    {
	    PORTD = 0b10000000;
	    wait(500);
	    PORTD = 0b01000000;
	    wait(500);
    }

    return 1;
}

