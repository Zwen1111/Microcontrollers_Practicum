/*
 * Board.c
 *
 * Created: 22-3-2018 12:16:43
 *  Author: Thijs Wijnen & Zwen van Erkelens
 */ 

 #include "ledmatrix.h"
 #include "board.h"
 #include <string.h>
 #include <stdlib.h>

void write_board_data_w(void);
void write_board_data(int*);
void upOffset(void);

int board[8];
int offset = 0;

void upOffset(){
	offset++;
	if(offset > 135){
		offset = 0;
	}
}

 void initBoard(void)
 {
	clearBoard();
 }

 void clearBoard(void)
 {
	for(int row = 0; row < 8; row++)
	{
		for(int column = 0; column < 8; column++)
		{
			board[row] = 0;
		}
	}
	write_board_data_w();
 }

 void write_board_data(int* text)
 {
	 char columnValue = 0;
	 int value = 8;
	 for(int row = 0; row < 8; row++)
	 {
		 columnValue = text[value + offset];
		 write_data(getRowAdress(row),columnValue);
		 value--;
	 }
 }

 void write_board_data_w()
 {
	 char columnValue = 0;
	 int value = 8;
	 for(int row = 0; row < 8; row++)
	 {
		 columnValue = board[value + offset];
		 write_data(getRowAdress(row),columnValue);
		 value--;
	 }
 }
 
 void show_text(){
	 int* text = malloc((2 * 8) * sizeof(int));
	 
	 int letterA[8] = {0,0,0b00111111,0b10000100,0b10000100,0b10000100,0b00111111,0};
	 int letterB[8] = {0,0,0b10111111,0b10100100,0b10100100,0b10100100,0b00011011,0};
	 int letterC[8] = {0x00, 0x1e, 0x21, 0x21, 0x21, 0x21, 0x00, 0x00};
	 int letterD[8] = {0x00, 0x3f, 0x21, 0x21, 0x21, 0x1e, 0x00, 0x00};
	 int letterE[8] = {0x00, 0x3f, 0x25, 0x25, 0x21, 0x21, 0x00, 0x00};
	 int letterF[8] = {0x00, 0x3f, 0x05, 0x05, 0x05, 0x01, 0x00, 0x00};
	 int letterG[8] = {0x00, 0x3f, 0x21, 0x25, 0x25, 0x3d, 0x00, 0x00};
	 int letterH[8] = {0x00, 0x3f, 0x04, 0x04, 0x04, 0x3f, 0x00, 0x00};
	 int letterI[8] = {0x00, 0x21, 0x21, 0x3f, 0x21, 0x21, 0x00, 0x00};
	 int letterJ[8] = {0x00, 0x00, 0x31, 0x21, 0x21, 0x3f, 0x00, 0x00};
	 int letterK[8] = {0x00, 0x3f, 0x04, 0x0a, 0x31, 0x00, 0x00, 0x00};
	 int letterL[8] = {0x00, 0x3f, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00};
	 int letterM[8] = {0x00, 0x3f, 0x01, 0x07, 0x01, 0x3f, 0x00, 0x00};
	 int letterN[8] = {0x00, 0x3f, 0x02, 0x04, 0x08, 0x3f, 0x00, 0x00};
	 int letterO[8] = {0x00, 0x3f, 0x21, 0x21, 0x21, 0x3f, 0x00, 0x00};
	 int letterP[8] = {0x00, 0x3f, 0x09, 0x09, 0x09, 0x06, 0x00, 0x00};
	 int letterQ[8] = {0x00, 0x06, 0x09, 0x09, 0x09, 0x3f, 0x00, 0x00};
	 int letterR[8] = {0x00, 0x3f, 0x09, 0x19, 0x29, 0x06, 0x00, 0x00};
	 int letterS[8] = {0x00, 0x16, 0x25, 0x25, 0x29, 0x1a, 0x00, 0x00};
	 int letterT[8] = {0x00, 0x00, 0x01, 0x01, 0x1f, 0x01, 0x01, 0x00};
	 int letterU[8] = {0x00, 0x00, 0x0f, 0x10, 0x10, 0x08, 0x1f, 0x00};
	 int letterV[8] = {0x00, 0x00, 0x07, 0x08, 0x10, 0x08, 0x07, 0x00};
	 int letterW[8] = {0x00, 0x00, 0x0f, 0x10, 0x0c, 0x10, 0x0f, 0x00};
	 int letterX[8] = {0x00, 0x00, 0x11, 0x0a, 0x04, 0x0a, 0x11, 0x00};
	 int letterY[8] = {0x00, 0x00, 0x22, 0x14, 0x08, 0x04, 0x02, 0x00};
	 int letterZ[8] = {0x00, 0x41, 0x61, 0x51, 0x49, 0x45, 0x43, 0x00};
	 
	 char string[22] = "nerdsarethenewcool";
	 
	 for(int i = 0; i < 22; i++){
		 char character = string[i];
		 
		 switch(character){
			 case 'a':
				 memcpy(text + (i * 8), letterA, 8 * sizeof(int));
				 break;
			 case 'b':
				 memcpy(text + (i * 8), letterB, 8 * sizeof(int));
				 break;
			 case 'c':
				 memcpy(text + (i * 8), letterC, 8 * sizeof(int));
				 break;
			 case 'd':
				 memcpy(text + (i * 8), letterD, 8 * sizeof(int));
				 break;
			 case 'e':
				 memcpy(text + (i * 8), letterE, 8 * sizeof(int));
				 break;
			 case 'f':
				 memcpy(text + (i * 8), letterF, 8 * sizeof(int));
				 break;
			 case 'g':
				 memcpy(text + (i * 8), letterG, 8 * sizeof(int));
				 break;
			 case 'h':
				 memcpy(text + (i * 8), letterH, 8 * sizeof(int));
				 break;
			 case 'i':
				 memcpy(text + (i * 8), letterI, 8 * sizeof(int));
				 break;
			 case 'j':
				 memcpy(text + (i * 8), letterJ, 8 * sizeof(int));
				 break;
			 case 'k':
				 memcpy(text + (i * 8), letterK, 8 * sizeof(int));
				 break;
			 case 'l':
				 memcpy(text + (i * 8), letterL, 8 * sizeof(int));
				 break;
			 case 'm':
				 memcpy(text + (i * 8), letterM, 8 * sizeof(int));
				 break;
			 case 'n':
				 memcpy(text + (i * 8), letterN, 8 * sizeof(int));
				 break;
			 case 'o':
				 memcpy(text + (i * 8), letterO, 8 * sizeof(int));
				 break;
			 case 'p':
				 memcpy(text + (i * 8), letterP, 8 * sizeof(int));
				 break;
			 case 'q':
				 memcpy(text + (i * 8), letterQ, 8 * sizeof(int));
				 break;
			 case 'r':
				 memcpy(text + (i * 8), letterR, 8 * sizeof(int));
				 break;
			 case 's':
				 memcpy(text + (i * 8), letterS, 8 * sizeof(int));
				 break;
			 case 't':
				 memcpy(text + (i * 8), letterT, 8 * sizeof(int));
				 break;
			 case 'u':
				 memcpy(text + (i * 8), letterU, 8 * sizeof(int));
				 break;
			 case 'v':
				 memcpy(text + (i * 8), letterV, 8 * sizeof(int));
				 break;
			 case 'w':
				 memcpy(text + (i * 8), letterW, 8 * sizeof(int));
				 break;
			 case 'x':
				 memcpy(text + (i * 8), letterX, 8 * sizeof(int));
				 break;
			 case 'y':
				 memcpy(text + (i * 8), letterY, 8 * sizeof(int));
				 break;
			 case 'z':
				 memcpy(text + (i * 8), letterZ, 8 * sizeof(int));
				 break;
			 case ' ':
				 break;
		 }
	 }
	 
	 write_board_data(text);
	 free(text);
 }

