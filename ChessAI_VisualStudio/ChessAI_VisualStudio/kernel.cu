
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>


class Board {
private:
    int turn = 0;
    int movesChecked = 0;
    Board* possibleMoves[1000];
    Board* gameHistory[300];

    //Move a piece and create a new board
    void movePiece(Board* currentBoard, int initialRow, int initialCol, int movedTooRow, int movedTooCol) {
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                //Remove the piece from its inital square
                if (row == initialRow && col == initialCol) {
                    board[row][col] = 0;
                }
                //Move the piece to new square
                else if (row == movedTooRow && col == movedTooCol) {
                    board[row][col] = currentBoard->board[initialRow][initialCol];
                }

                //Copy the rest of the board
                else {
                    board[row][col] = currentBoard->board[row][col];
                    //(board[row]) + col = (currentBoard->board[row]) + col;
                }
            }
        }
    }

    bool moveCheck(int initRow, int initCol, int newRow, int newCol, bool white) {
        //Toggle between checking valid white and black moves
        int lowerBound;
        int upperBound;
        if (!white) {
            lowerBound = 1;
            upperBound = 6;
        }
        else {
            lowerBound = 7;
            upperBound = 12;
        }

        if (newCol >= 0 && newCol < 8) {
            if (board[newRow][newCol] == 0) {
                Board* move1 = new Board(this, initRow, initCol, newRow, newCol);
                return true;
            }
            else if (board[newRow][newCol] >= lowerBound && board[newRow][newCol] <= upperBound) {
                Board* move1 = new Board(this, initRow, initCol, newRow, newCol);
                return false;
            }

            else {
                return false;
            }
        }
    }

    void moveRook(int row, int col, bool white) {
        bool up = true;
        bool down = true;
        bool left = true;
        bool right = true;

        //Check Right
        for (int newCol = col + 1; newCol < 8; newCol++) {
            if (right) {
                right = moveCheck(row, col, row, newCol, white);
            }
            else {
                break;
            }
        }
        //Check Left
        for (int newCol = col - 1; newCol >= 0; newCol--) {
            if (left) {
                left = moveCheck(row, col, row, newCol, white);
            }
            else {
                break;
            }
        }

        //Check Down
        for (int newRow = row - 1; newRow >= 0; newRow--) {
            if (down) {
                down = moveCheck(row, col, newRow, col, white);
            }
            else {
                break;
            }
        }

        //Check Up
        for (int newRow = row + 1; newRow < 8; newRow++) {
            if (up) {
                up = moveCheck(row, col, newRow, col, white);
            }
            else {
                break;
            }
        }
    }

    void moveBishop(int row, int col, bool white) {
        bool upRight = true;
        bool upLeft = true;
        bool downRight = true;
        bool downLeft = true;

        //Check rows above current
        for (int newRow = row + 1; newRow < 8; newRow++) {

            int moveUpRightCol = col + (newRow - row);
            int moveUpLeftCol = col - (newRow - row);

            //UpRight
            if (upRight) {
                upRight = moveCheck(row, col, newRow, moveUpRightCol, white);
            }

            if (upLeft) {
                upLeft = moveCheck(row, col, newRow, moveUpLeftCol, white);
            }

        }

        //Check rows below current
        for (int newRow = row - 1; newRow >= 0; newRow--) {

            int moveDownRightCol = col + (row - newRow);
            int moveDownLeftCol = col - (row - newRow);

            //UpRight
            if (downRight) {
                downRight = moveCheck(row, col, newRow, moveDownRightCol, white);
            }

            if (downLeft) {
                downLeft = moveCheck(row, col, newRow, moveDownLeftCol, white);
            }

        }
    }


public:
    int board[8][8] = {
        {1,2,3,4,5,3,2,1},
        {6,6,6,6,6,6,6,6},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {7,8,9,10,11,0,0,0},
        {12,12,12,12,12,12,12,12},
        {7,8,9,10,11,9,8,7} };

    Board() {
        printBoard();
    }

    //Validate move and generate new board if valid
    Board(Board* currentBoard, int initialRow, int initialCol, int movedTooRow, int movedTooCol) {
        //Check if proposed move exists
        if ((movedTooRow >= 8 || movedTooRow < 0) || (movedTooCol >= 8 || movedTooCol < 0)) {
            delete this;
        }
        else {
            //Check if move is possible for white
            if (currentBoard->board[initialRow][initialCol] < 7) {
                //Check if a white piece is trying to move to the position of another white piece
                if (currentBoard->board[movedTooRow][movedTooCol] < 7 && currentBoard->board[movedTooRow][movedTooCol] > 0) {
                    delete this;
                }
                else {
                    movePiece(currentBoard, initialRow, initialCol, movedTooRow, movedTooCol);
                    currentBoard->addBoardToPossible(this);
                }
            }
            //Check for black
            else {
                //Check if black piece if moving to the position of another black piece
                if (currentBoard->board[movedTooRow][movedTooCol] >= 7 && currentBoard->board[movedTooRow][movedTooCol] <= 12) {
                    delete this;
                }
                else {
                    movePiece(currentBoard, initialRow, initialCol, movedTooRow, movedTooCol);
                    currentBoard->addBoardToPossible(this);
                }
            }
        }
    }

    void getMoves(bool white) {
        //White Moves
        if (white) {
            for (int row = 0; row < 8; row++) {
                for (int col = 0; col < 8; col++) {
                    //Pawn
                    if (getPositionAsChar(board[row][col]) == 'P' && row == 1 && board[row + 1][col] == 0) {
                        Board* move1 = new Board(this, row, col, row + 1, col);
                        Board* move2 = new Board(this, row, col, row + 2, col);
                    }
                    else if (getPositionAsChar(board[row][col]) == 'P') {
                        Board* move1 = new Board(this, row, col, row + 1, col);
                    }

                    //Knight
                    else if (getPositionAsChar(board[row][col]) == 'N') {
                        moveCheck(row, col, row + 2, col - 1, white );
                        moveCheck(row, col, row + 2, col + 1, white );
                        moveCheck(row, col, row - 1, col + 2, white );
                        moveCheck(row, col, row + 1, col + 2, white );
                        moveCheck(row, col, row - 2, col - 1, white );
                        moveCheck(row, col, row - 2, col + 1, white );
                        moveCheck(row, col, row - 1, col - 2, white );
                        moveCheck(row, col, row + 1, col - 2, white );
                    }

                    //Bishop
                    else if (getPositionAsChar(board[row][col]) == 'B') {
                        moveBishop(row, col, white);
                    }

                    //Rook
                    else if (getPositionAsChar(board[row][col]) == 'R') {
                        moveRook(row, col, white);
                    }

                    //Queen
                    else if (getPositionAsChar(board[row][col]) == 'Q') {
                        moveRook(row, col, white);
                        moveBishop(row, col, white);
                    }

                    //King
                    else if (getPositionAsChar(board[row][col]) == 'K') {
                        moveCheck(row, col, row + 1, col, white);
                        moveCheck(row, col, row + 1, col, white);
                        moveCheck(row, col, row - 1, col, white);
                        moveCheck(row, col, row, col+1, white);
                        moveCheck(row, col, row, col-1, white);
                        moveCheck(row, col, row + 1, col+1, white);
                        moveCheck(row, col, row - 1, col+1, white);
                        moveCheck(row, col, row + 1, col - 1, white);
                        moveCheck(row, col, row - 1, col - 1, white);
                    }
                }

            }
        }
            //Black moves
        else {
            for (int row = 0; row < 8; row++) {
                for (int col = 0; col < 8; col++) {
                    //Pawn
                    if (getPositionAsChar(board[row][col]) == 'p' && row == 6 && board[row - 1][col] == 0) {
                        Board* move1 = new Board(this, row, col, row - 1, col);
                        Board* move2 = new Board(this, row, col, row - 2, col);
                    }
                    else if (getPositionAsChar(board[row][col]) == 'p') {
                        Board* move1 = new Board(this, row, col, row - 1, col);
                    }

                    //Knight
                    else if (getPositionAsChar(board[row][col]) == 'n') {
                        moveCheck(row, col, row + 2, col - 1, white);
                        moveCheck(row, col, row + 2, col + 1, white);
                        moveCheck(row, col, row - 1, col + 2, white);
                        moveCheck(row, col, row + 1, col + 2, white);
                        moveCheck(row, col, row - 2, col - 1, white);
                        moveCheck(row, col, row - 2, col + 1, white);
                        moveCheck(row, col, row - 1, col - 2, white);
                        moveCheck(row, col, row + 1, col - 2, white);
                    }

                    //Bishop
                    else if (getPositionAsChar(board[row][col]) == 'b') {
                        moveBishop(row, col, white);
                    }

                    //Rook
                    else if (getPositionAsChar(board[row][col]) == 'r') {
                        moveRook(row, col, white);
                    }

                    //Queen
                    else if (getPositionAsChar(board[row][col]) == 'q') {
                        moveRook(row, col, white);
                        moveBishop(row, col, white);
                    }

                    //King
                    else if (getPositionAsChar(board[row][col]) == 'k') {
                        moveCheck(row, col, row + 1, col, white);
                        moveCheck(row, col, row + 1, col, white);
                        moveCheck(row, col, row - 1, col, white);
                        moveCheck(row, col, row, col + 1, white);
                        moveCheck(row, col, row, col - 1, white);
                        moveCheck(row, col, row + 1, col + 1, white);
                        moveCheck(row, col, row - 1, col + 1, white);
                        moveCheck(row, col, row + 1, col - 1, white);
                        moveCheck(row, col, row - 1, col - 1, white);
                    }
                }
            }
        }
        
    }

        void addBoardToPossible(Board * possibleBoard) {
            for (int row = 0; row < 8; row++) {
                for (int col = 0; col < 8; col++) {
                    this->possibleMoves[movesChecked] = possibleBoard;
                }
            }
            movesChecked++;
        }

        void submitTurn(Board * newBoard) {
            for (int row = 0; row < 8; row++) {
                for (int col = 0; col < 8; col++) {
                    this->gameHistory[turn]->board[row][col] = this->board[row][col];
                    this->board[row][col] = newBoard->board[row][col];
                }
            }
            turn++;
        }

        char getPositionAsChar(int positionNumber) {
            if (positionNumber == 0) {
                return ' ';
            }
            else if (positionNumber == 1) {
                return 'R';
            }
            else if (positionNumber == 2) {
                return 'N';
            }
            else if (positionNumber == 3) {
                return 'B';
            }
            else if (positionNumber == 4) {
                return 'Q';
            }
            else if (positionNumber == 5) {
                return 'K';
            }
            else if (positionNumber == 6) {
                return 'P';
            }
            else if (positionNumber == 7) {
                return 'r';
            }
            else if (positionNumber == 8) {
                return 'n';
            }
            else if (positionNumber == 9) {
                return 'b';
            }
            else if (positionNumber == 10) {
                return 'q';
            }
            else if (positionNumber == 11) {
                return 'k';
            }
            else if (positionNumber == 12) {
                return 'p';
            }
            else {
                return '!';
            }
        }

        void printBoard() {
            int tmp;
            char output[17];
            output[16] = '\0';
            for (int row = 7; row >= 0; row--) {
                for (int col = 0; col < 16; col += 2) {
                    tmp = board[row][col / 2];
                    output[col] = getPositionAsChar(tmp);
                    output[col + 1] = '|';
                }
                printf("%s", output);
                printf("\n----------------\n");
            }
            printf("\n\n");
        }

        void printAllPossibleBoards() {
            for (int boardNo = 0; boardNo < movesChecked; boardNo++) {
                possibleMoves[boardNo]->printBoard();
            }
        }
    };

    int main()
    {
        Board* board = new Board();
        board->getMoves(true);
        board->printAllPossibleBoards();

        return 0;
    }
