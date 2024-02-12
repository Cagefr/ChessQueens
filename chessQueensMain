#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <string>

using namespace std;

#include "StackNode_chess.h"
#include "simpleStackClass.h"

const int MAX=9;
const int MIN=4;

int getBoardSize();
void createBoard(int board[][MAX], int nrows, int ncols);
void showBoard(int board[][MAX], int nrows, int ncols);
void finalBoard(int board[][MAX], int nrows, int ncols);
bool guarded(int board[][MAX],int row, int col, int boardSize);

int main()
{
	int i,j,k;
	int row, col;
	int nrows, ncols;
	int boardSize;
	Stack *qStack;
	StackNode *node;

	int board[MAX][MAX];

	qStack = createStack();

	boardSize  = getBoardSize();
	nrows = boardSize;
	ncols = boardSize;

	createBoard(board, nrows, ncols);
	showBoard(board, nrows, ncols);

	row = 1;
	col = 0;

	while(row <= boardSize){
		while(col <= boardSize && row <= boardSize){

			col++;
			if(!guarded(board,row,col,boardSize)){

				node = createNode(row,col);
				qStack->push(node);

				board[row][col] = 1;
				row++;
				col = 0;
			} //if(!guarded)

			//Remove Previous Queen:
			while(col >= boardSize){
						
				node = qStack->pop();
				row  = node->getRow();
				col  = node->getCol();
				board[row][col] = 0;

			} // while(col > size)

		} //while(col && row < size)

	} //while(row < size)
	
	//showBoard(board, nrows, ncols);
	finalBoard(board, nrows, ncols);

	return 0;
}

int getBoardSize()
{
	int size;
	

	size = 0;
	while(size < MIN || size > MAX-1){
		cout << "\n\n\n\t\t\tWelcome to Chess Queens Attack Program." <<endl;
		cout << "\t\t\tChess Board Size Ranges Between : " << MIN << " - " << MAX-1 << endl;
		cout << "\t\t\tPlease Enter the Chessboard Size: " ;
		cin >> size;
	} 

	cout << "\n\n\t\t\tSelected Board Size is: " << size <<endl;

	return size;
}

void createBoard(int board[][MAX], int nrows, int ncols)
{
	int i,j;

	for(i=1;i<=nrows;i++)
		for(j=1;j<=ncols;j++)
			board[i][j] = 0;

	return;
}

void finalBoard(int board[][MAX], int nrows, int ncols)
{
	int i,j;
	char symbol;

	cout <<"\n\n\n";
	for(i=1;i<=nrows;i++){
		cout << "\t\t\t";
		for(j=1;j<=ncols;j++){

			if(board[i][j]==0)
				symbol = 'X';
			else
				symbol = 'Q';

			cout << setw(3) << symbol;
		}
	
		cout << "\n";
	}
	cout <<"\n\n\n";

	return;
}


void showBoard(int board[][MAX], int nrows, int ncols)
{
	int i,j;

	cout <<"\n\n\n";
	for(i=1;i<=nrows;i++){
		cout << "\t\t\t";
		for(j=1;j<=ncols;j++){
			cout << setw(3) << board[i][j];
		}
	
		cout << "\n";
	}
	cout <<"\n\n\n";

	return;
}

bool guarded(int board[][MAX],int nrow, int ncol, int boardSize)
{
	int row, col;

	//Scan all Rows overlapping the column:
	col = ncol;
	for(row=1;row<=nrow;row++){
		if(board[row][col]==1){
			cout <<"\n\n\t\t\tPosition: [" << row << "," << col <<"]" << " is guarded!!!" << endl;
			return true;
		}
	}
	
	//Check along Left Diagonal Upwards:
	row = nrow-1;
	col = ncol-1;
	while(row > 0 && col > 0){
		if(board[row][col]==1){
			cout <<"\n\n\t\t\tPosition: [" << row << "," << col <<"]" << " is guarded!!!" << endl;
			return true;
		}
	
		row--;
		col--;
	} //while(row && col > 0)

	row = nrow-1;
	col = ncol+1;
	while(row > 0 && col <= boardSize){
		if(board[row][col]==1){
			cout <<"\n\n\t\t\tPosition: [" << row << "," << col <<"]" << " is guarded!!!" << endl;
			return true;
		}
	
		row--;
		col++;
	} //while(row && col <=size)

	return false;
}
