/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 01/07/2019
 * Description: Board class implementation file.
***************************************************************/
#include "Board.hpp"
#include "Ant.hpp"

#include <iostream>

//Constructor(s)
Board::Board(int rowsIn, int colsIn)
{
	setRows(rowsIn);
	setCols(colsIn);
	board = nullptr;
	board = new char*[rows];
	for (int i = 0; i < rows; ++i)
	{
		board[i] = new char[cols];
	}	
	
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{
			if (row == 0 || row == (rows - 1))
				board[row][col] = '-';
			else if (col == 0 || col == (cols - 1))
				board[row][col] = '|'; 
			else
				board[row][col] = ' ';
		}
	}
}

//Destructor
Board::~Board()
{
	for (int i = 0; i < rows; ++i)
		delete [] board[i];
	delete [] board;
	board = nullptr;
}

//Setters
void Board::setRows(int rowsIn)
{
	rows = rowsIn;
	rows += 2; //To accomodate the boarder 
}

void Board::setCols(int colsIn)
{
	cols = colsIn;
	cols += 2; //To accomodate the boarder
}

void Board::setSpaceColor(int rowIn, int colIn)
{
	spaceColor = board[rowIn][colIn];
}


//Getters
int Board::getRows()
{
	return rows;
}

int Board::getCols()
{
	return cols;
}

char Board::getSpaceColor()
{
	return spaceColor;
}

//Methods
/***************************************************************
 * Function Name: void printBoard
 * Parameters: None
 * Description: Prints current state of the board to the console.
***************************************************************/

void Board::printBoard()
{
	
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{
			std::cout << board[row][col];
		}
		std::cout << std::endl;
	}
}

/***************************************************************
 * Function Name: void putAnt
 * Parameters: int rowIn, int colIn
 * Description: Puts ant on board.
***************************************************************/

void Board::putAnt(int rowIn, int colIn)
{
	board[rowIn][colIn] = '*';
}


/***************************************************************
 * Function Name: void moveAnt
 * Parameters: int orientation, int rowIn, int colIn
 * Description: Moves the ant based on its orientation, row, and
 * 		column.
***************************************************************/

void Board::moveAnt(int orientation, int rowIn, int colIn)
{
	//Switch space color of current space
	switchSpaceColor(rowIn, colIn);

	int rowAdjusted = rows - 2,
	    colAdjusted = cols - 2;
	
	//If the ant is at an edge and moving into the boarder
	//In the first row, moving north, move to the last row, same column
	if (rowIn == 1 && orientation == 1)
	{
		setSpaceColor(rowAdjusted, colIn);
		putAnt(rowAdjusted, colIn);
	}
	//In the last row, moving south, move to the first row, same column
	else if (rowIn == rowAdjusted && orientation == 3)
	{
		setSpaceColor(1, colIn);
		putAnt(1, colIn);
	}
	//In the first column, moving west, move to the last column, same row
	else if (colIn == 1 && orientation == 4)
	{
		setSpaceColor(rowIn, colAdjusted);
		putAnt(rowIn, colAdjusted);
	}
	//In the last column, moving east, move to the first column, same row
	else if (colIn == colAdjusted && orientation == 2)
	{
		setSpaceColor(rowIn, 1);
		putAnt(rowIn, 1);
	}
	//Else, if the ant is not at an edge
	else 
	{
		if (orientation == 1)
		{
			setSpaceColor((rowIn - 1), colIn);
			putAnt((rowIn - 1), colIn);
		}
		else if (orientation == 2)
		{
			setSpaceColor(rowIn, (colIn + 1));
			putAnt(rowIn, (colIn + 1));
		}
		else if (orientation == 3)
		{
			setSpaceColor((rowIn + 1), colIn);
			putAnt((rowIn + 1), colIn);
		}
		else if (orientation == 4)
		{
			setSpaceColor(rowIn, (colIn - 1));
			putAnt(rowIn, (colIn - 1));
		}
	}
}

/***************************************************************
 * Function Name: void switchSpaceColor
 * Parameters: int rowIn, int colIn
 * Description: Switches spaceColor from white to black or from
 * 		black to white.
***************************************************************/

void Board::switchSpaceColor(int rowIn, int colIn)
{
	if (spaceColor == ' ')
		board[rowIn][colIn] = '#';
	else if (spaceColor == '#')
		board[rowIn][colIn] = ' ';

}
