/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 01/07/2019
 * Description: Menu functions for Langton's Ant Simulation.
***************************************************************/
#include "Menu.hpp"
#include "Simulation.hpp"

#include <iostream>
#include <string>

/***************************************************************
 * Function Name: void clearScreen
 * Parameters: None
 * Description: Clears screen by inserting 100 lines.
***************************************************************/

void clearScreen()
{
	std::cout << std::string(100, '\n');
}

/***************************************************************
 * Function Name: void invalidInput 
 * Parameters: None
 * Description: Clears buffer, ignores 100 char until '\n' and
 * 		prints "Invalid input!" to screen.
***************************************************************/

void invalidInput()
{
	std::cin.clear();
	std::cin.ignore(100, '\n');
	std::cout << "Invalid input!" << std::endl;
}

/***************************************************************
 * Function Name: int menuInput 
 * Parameters: None
 * Description: Asks user for menu number, validates the input,
 * 		then directs to simulation or quit functions.
***************************************************************/

int menuInput()
{	
	int menuNum = 0;
	bool menuNumInvalid = true;
	while (menuNumInvalid)
	{
		std::cout << "\nPlease enter a number from the menu above: ";
		std::cin >> menuNum;
		
		if (menuNum == 1 || menuNum == 2)
		{
			switch(menuNum)
			{
				case 1: startSimulation(); 
					break;
				case 2: return 0;
					break;
				default: std::cout << "Default" << std::endl;
			}
			menuNumInvalid = false;
		}	


		else if (std::cin.fail())
			invalidInput();
		else
			invalidInput();
 	}
	return 0;
}

/***************************************************************
 * Function Name: void startMenu 
 * Parameters: None
 * Description: Shows start menu and calls menuInput function.
***************************************************************/

void startMenu()
{
	clearScreen();
	std::cout << std::endl;
	std::cout << "::Menu::" << std::endl;
	std::cout << std::endl;
	std::cout << "1. Start Langton's Ant Simulation" << std::endl;
	std::cout << "2. Quit" << std::endl;
	menuInput();
}

/***************************************************************
 * Function Name: void continuousMenu 
 * Parameters: None
 * Description: Shows continuous menu and calls menuInput
 * 		function.
***************************************************************/

void continuousMenu()
{
	clearScreen();
	bool keepGoing = true;
	while (keepGoing)
	{
		std::cout << std::endl;
		std::cout << "::Menu::" << std::endl;
		std::cout << std::endl;
		std::cout << "1. Play again" << std::endl;
		std::cout << "2. Quit" << std::endl;
		keepGoing = menuInput();
	}
}

		
