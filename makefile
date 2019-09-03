#Makefile for Langton's Ant Simulation

CXX = g++
CXXFLAGS = -Wall -g -std=c++0x

antSim: main.o Ant.o Board.o Menu.o Simulation.o
	$(CXX) $(CXXFLAGS) main.o Ant.o Board.o Menu.o Simulation.o -o antSim

main.o: main.cpp Ant.hpp Board.hpp Simulation.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Ant.o: Ant.hpp

Board.o: Board.hpp

Menu.o: Menu.hpp

Simulation.o: Simulation.hpp

clean:
	rm *.o antSim
