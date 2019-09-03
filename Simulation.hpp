/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 01/07/2019
 * Description: Simulation functions for Langton's Ant Simulation.
***************************************************************/
#ifndef SIMULATION_HPP
#define SIMULATION_HPP

void startSimulation(), getRows(int &), getCols(int &), getAntRow(int &, int), getAntCol(int &, int), getOrientation(int &), getSteps(int &), randomLocation(int &, int &, int, int);
bool integerInvalid(int), notInRange(int, int), stepsInvalid(int), orientationInvalid(int), answerInvalid(char character)
;


#endif
