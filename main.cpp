/*
 * @author Brendan Warnick
 * @version CIS 263 Winter 2018
 * used https://www.geeksforgeeks.org/backtracking-set-7-suduku/ for reference
 */
#include <stdio.h>

bool emptySpot(int board[9][9], int &row, int &col);
bool isSafe(int board[9][9], int row, int col, int num);

//searches for spots still assigned 0, returns true if one is found
bool emptySpot(int board[9][9], int &row, int &col){
	//loop that searches for 0
	for (row = 0; row < 9; row++)
		for (col = 0; col < 9; col++)
			if (board[row][col] == 0)
				return true;
	return false;
}

//checks if a given number x is used in this row
bool usedRow(int board[9][9], int row, int x){
	for (int col = 0; col < 9; col++)
		if (board[row][col] == x)
			return true;
	return false;
}

//checks if given number x is used in this column
bool usedCol(int board[9][9], int col, int x){
	for (int row = 0; row < 9; row++)
		if (board[row][col] == x)
			return true;
	return false;
}

//checks if given number x is used in this 3 by 3 box
bool usedBox(int board[9][9], int boxStartRow, int boxStartCol, int x){
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (board[row+boxStartRow][col+boxStartCol] == x)
				return true;
	return false;
}

//returns true if x is able to be placed in this area after checking row, column, and box
bool isClear(int board[9][9], int row, int col, int x){
	return !usedRow(board, row, x) &&
		!usedCol(board, col, x) &&
		!usedBox(board, row - row%3 , col - col%3, x);
}

//solvesBoard
bool solve(int board[9][9]){
	int row;
	int col;
	if (!emptySpot(board, row, col))
	return true;

	for (int num = 1; num <= 9; num++) {
		if (isClear(board, row, col, num)) {
			board[row][col] = num;
			if (solve(board))
				return true;
				
			board[row][col] = 0;
		}
	}
	return false;
}

//prints board
void printBoard(int board[9][9])
{
	for (int row = 0; row < 9; row++)
	{
	for (int col = 0; col < 9; col++)
			printf("%2d", board[row][col]);
		printf("\n");
	}
}


int main(){
	int board[9][9] = {{ 0, 3, 0, 0, 0, 0, 0, 2, 0 },
                   { 0, 9, 0, 0, 0, 0, 0, 8, 5 },
                   { 5, 0, 0, 0, 8, 0, 4, 0, 0 },
                   { 4, 0, 7, 2, 0, 6, 8, 9, 0 },
                   { 0, 1, 0, 8, 0, 9, 0, 4, 0 },
                   { 0, 8, 9, 5, 0, 1, 3, 0, 2 },
                   { 0, 0, 3, 0, 1, 0, 0, 0, 9 },
                   { 9, 4, 0, 0, 0, 0, 0, 1, 0 },
                   { 0, 7, 0, 0, 0, 0, 0, 3, 0 }
        };
	if (solve(board) == true)
		printBoard(board);
	else
		printf("No solution exists");
	return 0;
}

