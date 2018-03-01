/*
 * LCD.c
 *
 * Created: 01-Mar-18 15:26:13
 * Author : thijs
 */ 

#include <avr/io.h>

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Lcd.h"


 int main(void)
 {
	 init_Lcd_4_bit_mode();
	 display_text("Are you a yedi?");
	 set_cursor(15);
	 while (1)
	 {
		 
	 }
 }

