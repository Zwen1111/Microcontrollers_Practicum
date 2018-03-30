/*
 * Board.c
 *
 * Created: 22-3-2018 12:16:43
 *  Author: Thijs Wijnen & Zwen van Erkelens
 */ 

 #include <ctype.h>
 #include <string.h>
 #include <stdlib.h>
 #include "ledmatrix.h"
 #include "board.h"

void write_board_data_w(void);
void write_board_data(int*);
void upOffset(void);

int offset = 0;
int counter = 0;

/*
	upOffset()

	By changing the 'offset' variable the display will scroll
*/
void upOffset(void){
	offset++;
	if(offset > counter){
		offset = 0;
	}
}

/*
	initBoard()

	Calls the function 'clearBoard()' for clearing the board. This function will usually be called at start-up
*/
 void initBoard(void)
 {
	clearBoard();
 }

 /*
	clearBoard()

	This will clean the board
 */
 void clearBoard(void)
 {
	int board[8];

	for(int row = 0; row < 8; row++)
	{
		for(int column = 0; column < 8; column++)
		{
			board[row] = 0;
		}
	}
	write_board_data(board);
 }

 /*
	write_board_data(int* text)

	From the given array it writes data to the display
 */
 void write_board_data(int* text)
 {
	 char columnValue = 0;
	 int value = 8;
	 for(int row = 0; row < 8; row++)
	 {
		 columnValue = text[value + offset];
		 write_data(getRowAddress(row),columnValue);
		 value--;
	 }
 }
 
 /*
	show_text()

	For every character of the hardcoded character array it translates them into a int array that represents the character.
	It fills another int array with the arrays and from that it will write it on the display
 */
 void show_text(void){

	 int* text = malloc((38 * 8) * sizeof(int));
	 
	 // Letters
	 int letterA[5] = {0x3e, 0x09, 0x09, 0x09, 0x3e};
	 int letterB[5] = {0x3f, 0x25, 0x25, 0x25, 0x1a};
	 int letterC[5] = {0x1e, 0x21, 0x21, 0x21, 0x21};
	 int letterD[5] = {0x3f, 0x21, 0x21, 0x21, 0x1e};
	 int letterE[5] = {0x3f, 0x25, 0x25, 0x21, 0x21};
	 int letterF[5] = {0x3f, 0x05, 0x05, 0x05, 0x01};
	 int letterG[5] = {0x3f, 0x21, 0x25, 0x25, 0x3d};
	 int letterH[5] = {0x3f, 0x04, 0x04, 0x04, 0x3f};
	 int letterI[5] = {0x21, 0x21, 0x3f, 0x21, 0x21};
	 int letterJ[4] = {0x31, 0x21, 0x21, 0x3f};
	 int letterK[4] = {0x3f, 0x04, 0x0a, 0x31};
	 int letterL[4] = {0x3f, 0x20, 0x20, 0x20};
	 int letterM[5] = {0x3f, 0x01, 0x07, 0x01, 0x3f};
	 int letterN[5] = {0x3f, 0x02, 0x04, 0x08, 0x3f};
	 int letterO[5] = {0x3f, 0x21, 0x21, 0x21, 0x3f};
	 int letterP[5] = {0x3f, 0x09, 0x09, 0x09, 0x06};
	 int letterQ[5] = {0x06, 0x09, 0x09, 0x09, 0x3f};
	 int letterR[5] = {0x3f, 0x09, 0x19, 0x29, 0x06};
	 int letterS[5] = {0x16, 0x25, 0x25, 0x29, 0x1a};
	 int letterT[5] = {0x01, 0x01, 0x3f, 0x01, 0x01};
	 int letterU[5] = {0x0f, 0x10, 0x10, 0x08, 0x1f};
	 int letterV[5] = {0x07, 0x08, 0x10, 0x08, 0x07};
	 int letterW[5] = {0x1f, 0x20, 0x1c, 0x20, 0x1f};
	 int letterX[5] = {0x11, 0x0a, 0x04, 0x0a, 0x11};
	 int letterY[5] = {0x22, 0x14, 0x08, 0x04, 0x02};
	 int letterZ[6] = {0x41, 0x61, 0x51, 0x49, 0x45, 0x43};
	 
	 // Spaces
	 int emptySpace[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	 int space[1] = {0x00};
	 
	 for(int i = 0; i < 38; i++){
		memcpy(text + (i * 8), emptySpace, 8 * sizeof(int));
	 }
	 memcpy(text + 8, emptySpace, 8 * sizeof(int));
	 counter = 8;

	 char string[22] = "Nerds are the new cool";
	 
	 for(int i = 0; i < 22; i++){
		 char character = tolower(string[i]);
		 
		 switch(character){
			 case 'a':
				 memcpy(text + counter, letterA, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 'b':
				 memcpy(text + counter, letterB, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 'c':
				 memcpy(text + counter, letterC, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 'd':
				 memcpy(text + counter, letterD, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 'e':
				 memcpy(text + counter, letterE, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 'f':
				 memcpy(text + counter, letterF, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 'g':
				 memcpy(text + counter, letterG, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 'h':
				 memcpy(text + counter, letterH, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 'i':
				 memcpy(text + counter, letterI, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 'j':
				 memcpy(text + counter, letterJ, 4 * sizeof(int));
				 counter += 4;
				 break;
			 case 'k':
				 memcpy(text + counter, letterK, 4 * sizeof(int));
				 counter += 4;
				 break;
			 case 'l':
				 memcpy(text + counter, letterL, 4 * sizeof(int));
				 counter += 4;
				 break;
			 case 'm':
				 memcpy(text + counter, letterM, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 'n':
				 memcpy(text + counter, letterN, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 'o':
				 memcpy(text + counter, letterO, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 'p':
				 memcpy(text + counter, letterP, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 'q':
				 memcpy(text + counter, letterQ, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 'r':
				 memcpy(text + counter, letterR, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 's':
				 memcpy(text + counter, letterS, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 't':
				 memcpy(text + counter, letterT, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 'u':
				 memcpy(text + counter, letterU, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 'v':
				 memcpy(text + counter, letterV, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 'w':
				 memcpy(text + counter, letterW, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 'x':
				 memcpy(text + counter, letterX, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 'y':
				 memcpy(text + counter, letterY, 5 * sizeof(int));
				 counter += 5;
				 break;
			 case 'z':
				 memcpy(text + counter, letterZ, 6 * sizeof(int));
				 counter += 6;
				 break;
			 case ' ':
				 memcpy(text + counter, space, sizeof(int));
				 memcpy(text + counter, space, sizeof(int));
				 counter += 2;
				 break;
		}
	 
		memcpy(text + counter, space, sizeof(int));
		counter++;
	 }

	 write_board_data(text);
	 free(text);
 }

