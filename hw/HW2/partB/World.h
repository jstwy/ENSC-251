/**
 * @file World.cpp
 * @author Diane Wolf
 * @Date   10/26/2017
 * @version 1.0
 * @section DESCRIPTION
 * [HW2] [Part B] [World interface]
 * INCOMPLETE -- WILL NOT COMPILE
 * This source file is the interface for the class World.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Diane Wolf ____      _____October 26, 2017______________
//
// ____ dawolf | 301305135 ______
#ifndef WORLD_H
#define WORLD_H
#include "Organism.h"
const int DIMENSION = 20;       // X- and Y-dimensions of world grid
const int START_ANTS = 100;     // number of ants at initialization
const int START_BUGS = 5;       // number of doodlebugs at initialization
const int UNOCCUPIED = 0;       // value to represent unoccupied cell
const int ANT = 1;              // value to represent ant-occupied cell
const int BUG = 2;              // value to represent doodlebug-occupied cell

class World
{
public:
	World();
	// [precondition] none
	// [postcondition]
	~World();
	// [precondition] a non-empty World object exists
	// [postcondition] all pointers are deleted
	void place(Organism* org, int xCoordinate, int yCoordinate);
	// [precondition] the target cell is unoccupied
	// [postcondition] the target cell is occupied by designated organism
	void print();
	// [precondition] a World object exists
	// [postcondition] the World object is printed to the console
	void step();
	// [precondition] a World object exists
	// [postcondition] the simulation has progressed one time step
private:
	Organism* worldGrid[DIMENSION][DIMENSION]; // organism pointer to grid
};

#endif WORLD_H