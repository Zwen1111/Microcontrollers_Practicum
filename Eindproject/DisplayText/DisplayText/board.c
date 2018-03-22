/*
 * Board.c
 *
 * Created: 7-4-2016 12:16:43
 *  Author: remco
 */ 

 #include "ledmatrix.h"
 #include "board.h"

 void write_board_data(void); 
 void upOffset(void);

int board[17];
int offset = 0;

void upOffset(){
	offset++;
	if(offset > 17){
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
 }

 void setLed(int row,int column,int status)
 {
	
	if((row >= 0 && row < 8) && (column >= 0 && column < 8))
	{
		board[row] = status;
	}		
 }

 void show_A(void)
 {
	int letterA[8] = {0,0b01111111,0b11111111,0b11001100,0b11001100,0b11001100,0b11111111,0b01111111};
	int letterB[8] = {0,0b01111111,0b11111111,0b11001100,0b11001100,0b11001100,0b11111111,0b01111111};

	for(int row = 0; row < 8; row++)
	{
		board[row] = letterA[row];
	}
	
	
	board[8] = 0;
	
	for(int row = 9; row < 17; row++)
	{
		board[row] = letterB[row];
	}
	
	write_board_data();
 }

 void show_sadSmiley(void)
 {
	 int smiley[8][8] =
	{
		{0,0,1,1,1,1,0,0},
		{0,1,0,0,0,0,1,0},
		{1,0,1,0,0,1,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,1,1,0,0,1},
		{1,0,1,0,0,1,0,1},
		{0,1,0,0,0,0,1,0},
		{0,0,1,1,1,1,0,0}
	};

	 for(int row = 0; row < 8; row++)
	 {
		 for(int column = 0; column < 8; column++)
		 {
			 board[row] = smiley[row][column];
		 }
	 }
	 write_board_data();
 }

 void write_board_data(void)
 {
	char columnValue = 0;
	for(int row = 0; row < 8; row++)
	{
		columnValue = board[row + offset] >> 1;
		write_data(getRowAdress(row),columnValue);
	}
 }

