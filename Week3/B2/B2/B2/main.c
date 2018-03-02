/*
 * B2.c
 *
 * Created: 01-Mar-18 16:13:25
 * Author : thijs
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#define Bit(x)(1<<x)

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "Lcd.h"

int count = 0;

void init(void)
{
	init_Lcd_4_bit_mode();
	 
	DDRD &= ~Bit(7); //portd7 op input
	 
	OCR2 = 3;
	TIMSK |= Bit(7);
	sei();
	TCCR2 = 0b00011111;
}

ISR(TIMER2_COMP_vect)
{
	count++;
}

int main(void)
{
	init();
	display_text("Counting: ");		//zet tekst op het display
	while (1)
	{
		set_cursor(10);
		display_int(count);
	}
}

