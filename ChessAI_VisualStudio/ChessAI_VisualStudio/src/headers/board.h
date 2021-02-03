#pragma once
#include <stdio.h>
class Board
{
int turn = 0;
int movesChecked = 0;
Board* possibleMoves[500];
Board* gameHistory[300];
int board[8][8] = {
	{1,2,3,4,5,3,2,1},
	{6,6,6,6,6,6,6,6},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{12,12,12,12,12,12,12,12},
	{7,8,9,10,11,9,8,7} };

private:
	void movePiece(Board* currentBoard, int initialRow, int initialCol, int movedTooRow, int movedTooCol);
	bool moveCheck(int initRow, int initCol, int newRow, int newCol, bool white);
	void moveRook(int row, int col, bool white);
	void moveBishop(int row, int col, bool white);

public:

	Board();
	Board(Board* currentBoard, int initialRow, int initialCol, int movedTooRow, int movedTooCol);
	void getMoves(bool white);
	void addBoardToPossible(Board* possibleBoard);
	void submitTurn(Board* newBoard);
	char getPositionAsChar(int positionNumber);
	void printBoard();
	void printAllPossibleBoards();
};
