#ifndef _ledmatrix_H
#define _ledmatrix_H

/*
 * ledmatrix.h
 *
 * Created: 22-3-2018 12:21:39
 *  Author: Thijs Wijnen & Zwen van Erkelens
 */ 


 #include <avr/io.h>
 
 void twi_start(void);
 void twi_stop(void);
 void twi_tx(unsigned char data);
 void twi_init(void);
 void write_data(unsigned char,unsigned char);
 char getRowAddress(int);

 #endif
