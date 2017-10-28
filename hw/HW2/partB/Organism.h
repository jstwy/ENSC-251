/**
 * @file Organism.h
 * @author Diane Wolf
 * @Date   10/26/2017
 * @version 1.0
 * @section DESCRIPTION
 * [HW2] [Part B] [Organism interface]
 * INCOMPLETE -- WILL NOT COMPILE
 * This source file is the interface for the class Organism.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Diane Wolf ____      _____October 26, 2017______________
//
// ____ dawolf | 301305135 ______
#ifndef ORGANISM_H
#define ORGANISM_H
class Organism
{
public:
	Organism();
	// [precondition] none
	// [postcondition] none
	Organism(World* worldSim, int xCoordinate, int yCoordinate);
	// [precondition] a World object exists
	// [postcondition] an Organism is initialized on the grid
	~Organism();
	// [precondition] an Organism object exists
	// [postcondition] memory is given back to the free store

protected:
	int orgType;        // holds 1 for Ant and 2 for Doodlebug
	int xPos;           // holds X-position of Organism
	int yPos;           // holds Y-positio of Organism
	int breedCounter;   // counts time steps since breeding
	bool moveStatus;    // status of whether to move or not
};
#endif