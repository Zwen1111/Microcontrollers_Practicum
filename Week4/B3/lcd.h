/*
 * segment.h
 *
 * Created: 8-3-2018 09:59:45
 *  Author: zwen1
 */ 


#ifndef LCD_H_
#define LCD_H_

#define true 1
#define false 1

#define F_CPU 8000000
#define BIT(x) (1 << (x))

#include <avr/io.h>
#include <util/delay.h>

void wait(int ms);

#ifndef LCD_H_
#define LCD_H_

void init();
void clr_display();
void display_text(char *str);
void set_cursor(int pos);
void set_display(int pos);

void lcd_command ( unsigned char dat );

#endif /* LCD_H_ */


#endif /* LCD_H_ */