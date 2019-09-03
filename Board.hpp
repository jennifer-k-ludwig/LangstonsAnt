/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 01/07/2019
 * Description: Board class header file.
***************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
	private:
		int rows;
		int cols;
		char ** board;
		char spaceColor;
 
	public:
		//Constructor(s)
		Board(int, int);
		//Destructor
		~Board();
		//Setters
		void setRows(int);
		void setCols(int);
		void setSpaceColor(int, int);
		//Getters
		int getRows();
		int getCols();
		char getSpaceColor();
		//Methods
		void printBoard();
		void putAnt(int, int);
		void moveAnt(int, int, int);
		void switchSpaceColor(int, int);
};
#endif
