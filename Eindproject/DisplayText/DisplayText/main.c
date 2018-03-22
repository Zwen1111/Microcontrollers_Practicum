/*
 * DisplayText.c
 *
 * Created: 22-3-2018 12:28:11
 * Author : zwen1
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

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
	initMatrix();
	wait(500);
	
    /* Replace with your application code */
    while (1) 
    {
		clearBoard();
		show_A();
		write_board_data();
		upOffset();
		wait(1000);
    }
}

void initMatrix(){
	twi_init();
	initBoard();
	init_Lcd_4_bit_mode();
	
	DDRA = 0b11111111;

	EICRB |= 0b11000000; //set INT7 faling edge
	EIMSK |= 0b10000000; //enable INT&
	//enable global interrupt system
	sei();
}
