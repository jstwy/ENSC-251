/**
 * @file Doodlebug.h
 * @author Diane Wolf
 * @Date   10/26/2017
 * @version 1.0
 * @section DESCRIPTION
 * [HW2] [Part B] [Doodlebug interface]
 * INCOMPLETE -- WILL NOT COMPILE
 * This source file is the interface for the derived class Doodlebug.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Diane Wolf ____      _____October 26, 2017______________
//
// ____ dawolf | 301305135 ______
#ifndef DOODLEBUG_H
#define DOODLEBUG_H
#include "Organism.h"
#include "World.h"
class Doodlebug : public Organism
{
public:
	Doodlebug(World* worldSim, int xCoordinate, int yCoordinate);
	// [precondition] a World object exists
	// [postcondition] an Doodlebug is initialized on the grid
	int getOrgType();
	// [precondition] a World object exists
	// [postcondition] the type of Organism in a cell is returned
private:
};
#endif DOODLEBUG_H