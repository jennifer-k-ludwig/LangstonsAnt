/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 01/07/2019
 * Description: Ant class header file for Langton's Ant Simulation.
***************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
	private:
		int row;
		int col;
		int orientation;

	public:
		//Constructor(s)
		Ant(int, int, int);
		//Setters
		void setRow(int);
		void setCol(int);
		void setOrientation(int);
		//Getters
		int getRow();
		int getCol();
		int getOrientation();	
		//Methods
		void printAntSettings();
		void changeOrientation(char);
		void updateLocation(int, int);
};
#endif
