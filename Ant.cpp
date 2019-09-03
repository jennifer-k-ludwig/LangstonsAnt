/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 01/07/2019
 * Description: Ant class implementation file.
***************************************************************/
#include "Ant.hpp"
#include "Board.hpp"
#include <iostream>

//Constructor(s)
Ant::Ant(int rowIn, int colIn, int orientationIn) 
{
	setRow(rowIn);
	setCol(colIn);
	setOrientation(orientationIn);
}

//Setters
void Ant::setRow(int rowIn)
{
	row = rowIn;
}

void Ant::setCol(int colIn)
{
	col = colIn;
}

void Ant::setOrientation(int orientationIn)
{
	orientation = orientationIn;
}

//Getters
int Ant::getRow()
{
	return row;	
}

int Ant::getCol()	
{
	return col;
}

int Ant::getOrientation()
{
	return orientation;
}

//Methods
/***************************************************************
 * Function Name: void printAntSettings
 * Parameters: None
 * Description: Prints ant's current row, column, and orientation
 * 		to console. 
***************************************************************/

void Ant::printAntSettings()
{
	std::cout << std::endl;
	std::cout << "Ant: " << std::endl;
	std::cout << "Row: " << row << std::endl;
	std::cout << "Column: " << col << std::endl;
	std::cout << "Orientation: " << orientation << std::endl;
}

/***************************************************************
 * Function Name: void changeOrientation
 * Parameters: char spaceColor
 * Description: If spaceColor is white (' '), changes orientation
 * 		90 deg to the right. If spaceColor is black ('#')
 * 		changes orientation 90 deg to the left.
***************************************************************/

void Ant::changeOrientation(char spaceColor)
{
	if (spaceColor == ' ')
	{if (orientation == 1) 
	{
		setOrientation(2);		
	}	
	else if (orientation == 2)
	{
		setOrientation(3);		
	}
	else if (orientation == 3)
	{
		setOrientation(4);		
	}
	else if (orientation == 4)
	{
		setOrientation(1);		
	}}	

	else if  (spaceColor == '#')
	{if (orientation == 1) 
	{
		setOrientation(4);		
	}	
	else if (orientation == 2)
	{
		setOrientation(1);		
	}
	else if (orientation == 3)
	{
		setOrientation(2);		
	}
	else if (orientation == 4)
	{
		setOrientation(3);		
	}}	
}

/***************************************************************
 * Function Name: void updateLocation
 * Parameters: int rowsIn, int colsIn
 * Description: Updates the location of the ant on the board.
***************************************************************/

void Ant::updateLocation(int rowsIn, int colsIn)
{
	int rowAdjusted = rowsIn - 2,
	    colAdjusted = colsIn - 2;

	if (row == 1 && orientation == 1)
	{
		row = rowAdjusted;
	}
	else if (row == rowAdjusted && orientation == 3)
	{
		row = 1;
	}
	else if (col == 1 && orientation == 4)
	{
		col = colAdjusted;
	}
	else if (col == colAdjusted && orientation == 2)
	{
		col = 1;
	}
	else
	{	
		if (orientation == 1)
		{	
			row -= 1;
		}
		else if (orientation == 2)
		{
			col += 1;
		}
		else if (orientation == 3)
		{
			row += 1;
		}
		else if (orientation == 4)
		{
			col -= 1;
		}
	}
}

