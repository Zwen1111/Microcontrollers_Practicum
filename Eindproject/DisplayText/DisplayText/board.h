#ifndef _board_H
#define _board_H

/*
 * board.h
 *
 * Created: 22-3-2018 12:25:41
 *  Author: Thijs Wijnen & Zwen van Erkelens
 */ 
 
 #define Led_On 1
 #define Led_Off 0

 void initBoard(void);
 void clearBoard(void);
 void upOffset(void);
 void write_board_data_w(void);
 void write_board_data(int*);
 void show_text();
 #endif
