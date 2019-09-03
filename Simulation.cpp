/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 01/07/2019
 * Description: Simulation functions for Langton's Ant Simulation.
***************************************************************/
#include "Simulation.hpp"
#include "Menu.hpp"
#include "Board.hpp"
#include "Ant.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>

/***************************************************************
 * Function Name: void startSimulation
 * Parameters: None
 * Description: Main function for Langton's Ant Simulation.
***************************************************************/

void startSimulation()
{
	clearScreen();
	std::cout << "Choose the simulation parameters for the board and ant below." << std::endl;
	std::cout << std::endl;

	int rowsIn, colsIn, stepsIn, rowIn, colIn, orientationIn;
	
	//Board parameters
	std::cout << "Board:" << std::endl;
	getRows(rowsIn);
	getCols(colsIn);

	//Initialize board
	Board board(rowsIn, colsIn);
	std::cout << std::endl;
	
	//Ant parameters
	std::cout << "Ant:" << std::endl;
	getAntRow(rowIn, rowsIn);
	getAntCol(colIn, colsIn);
	getOrientation(orientationIn);

	//Initialize ant
	Ant ant(rowIn, colIn, orientationIn);
	std::cout << std::endl;
	
	//Get steps	
	getSteps(stepsIn);
	std::cin.ignore();
	std::cout << std::endl;

	//Store the space color of initial ant location
	board.setSpaceColor(ant.getRow(), ant.getCol());

	//Put ant on the board	
	board.putAnt(ant.getRow(), ant.getCol());

	do	
	{	//Print board and ant settings
		board.printBoard();
		ant.printAntSettings(); 
		
		//Change ant's orientation based on the space color its on
		ant.changeOrientation(board.getSpaceColor());

		//Move ant based on ant's new orientation
		board.moveAnt(ant.getOrientation(), ant.getRow(), ant.getCol());
		ant.updateLocation(board.getRows(), board.getCols());
		
		std::cout << "Remaining steps: " << stepsIn-- << std::endl;
		
		if (stepsIn == -1)
		{
			std::cout << std::endl;
			std::cout << "Simulation complete!" << std::endl;
		}

		std::cout << std::endl;
		std::cout << "Press Enter to continue..." << std::endl;
		std::cin.ignore();
//		clearScreen();
	} while (stepsIn > -1);

	continuousMenu(); 
}		

/***************************************************************
 * Function Name: bool integerInvalid
 * Parameters: int integer
 * Description: While input is invalid, calls invalidInput() 
 * 		from Menu and returns true. Otherwise returns
 * 		false.
***************************************************************/

bool integerInvalid(int integer)
{
	if (integer < 0 || integer > 100)
	{	invalidInput(); return true;}
	else if (std::cin.fail())
	{	invalidInput(); return true;}
	else
	{	return false;}
}

/***************************************************************
 * Function Name: void getRows
 * Parameters: int &rowsIn
 * Description: While input is invalid, asks user to enter 
 * 		the number of rows for the board.
***************************************************************/

void getRows(int &rowsIn)
{
	do
	{std::cout << "Number of rows (1-100): ";
	std::cin >> rowsIn;
	} while (integerInvalid(rowsIn));

}
	
/***************************************************************
 * Function Name: void getCols
 * Parameters: int &colsIn
 * Description: While input is invalid, asks user to enter 
 * 		the number of cols for the board.
***************************************************************/

void getCols(int &colsIn)
{
	do
	{std::cout << "Number of columns (1-100): ";
	std::cin >> colsIn;
	} while (integerInvalid(colsIn));
		
}	

/***************************************************************
 * Function Name: bool notInRange
 * Parameters: int numIn, int maxNum
 * Description: While input is invalid, calls invalidInput() 
 * 		from Menu and returns true. Otherwise returns
 * 		false.
***************************************************************/

bool notInRange(int numIn, int maxNum)
{
	if (numIn > maxNum || numIn < 1)
	{	invalidInput(); return true;}
	else if (std::cin.fail())
	{	invalidInput(); return true;}
	else
	{	return false;}
}	

/***************************************************************
 * Function Name: void getAntRow
 * Parameters: int &rowIn, int rowsIn
 * Description: While input is invalid, asks user to enter 
 * 		a starting row for ant that is in range of the
 * 		board.
***************************************************************/

void getAntRow(int &rowIn, int rowsIn)
{
	do
	{std::cout << "Start row (1-" << rowsIn << "): ";
	std::cin >> rowIn;}
	while (notInRange(rowIn, rowsIn));
}
	
/***************************************************************
 * Function Name: void getAntCol
 * Parameters: int &colIn, int colsIn
 * Description: While input is invalid, asks user to enter 
 * 		a starting col for ant that is in range of the
 * 		board.
***************************************************************/

void getAntCol(int &colIn, int colsIn)
{
	do
	{std::cout << "Start column (1-" << colsIn << "): ";
	std::cin >> colIn;}
	while (notInRange(colIn, colsIn));
}

/***************************************************************
 * Function Name: void getOrientation
 * Parameters: int &orientation
 * Description: While input is invalid, asks user to enter 
 * 		a starting orientation for ant.
***************************************************************/

void getOrientation(int &orientationIn)
{
	do
	{std::cout << "Start orientation (1: North, 2: East, 3: South, 4: West): ";
	std::cin >> orientationIn;
	} while (orientationInvalid(orientationIn));
}

/***************************************************************
 * Function Name: bool orientationInvalid
 * Parameters: int orientationIn
 * Description: While input is invalid, calls invalidInput() 
 * 		from Menu and returns true. Otherwise returns
 * 		false.
***************************************************************/

bool orientationInvalid(int orientationIn)
{
	if (orientationIn < 1 || orientationIn > 4)
	{	invalidInput(); return true;}
	else if (std::cin.fail())
	{	invalidInput(); return true;}
	else
	{	return false;}
}

/***************************************************************
 * Function Name: void stepsInvalid
 * Parameters: int stepsIn
 * Description: While input is invalid, calls invalidInput() 
 * 		from Menu and returns true. Otherwise returns
 * 		false.
***************************************************************/

bool stepsInvalid(int stepsIn)
{
	if (std::cin.fail())
	{	invalidInput(); return true;}
	else if (stepsIn < 1 || stepsIn > 1000)
	{	invalidInput(); return true;}
	else
	{	return false;}
}

/***************************************************************
 * Function Name: void getSteps
 * Parameters: int &stepsIn
 * Description: While input is invalid, asks user to enter 
 * 		a starting steps for ant.
***************************************************************/

void getSteps(int &stepsIn)
{
	do
	{std::cout << "Total number of steps (Max: 1000): ";
	std::cin >> stepsIn;
	} while (stepsInvalid(stepsIn));
}




