/*
 * Lcd.h
 *
 * Created: 01-Mar-18 15:31:57
 *  Author: thijs
 */ 


#ifndef LCD_H_
#define LCD_H_

void init_Lcd_4_bit_mode(void);
void display_text(char *str);
void display_text_int(char *str,int number);
void display_int(int number);
void display_clear(void);
void set_cursor(int position);





#endif /* LCD_H_ */