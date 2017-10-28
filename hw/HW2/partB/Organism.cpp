/**
 * @file Organism.cpp
 * @author Diane Wolf
 * @Date   10/26/2017
 * @version 1.0
 * @section DESCRIPTION
 * [HW2] [Part B] [Organism implementation]
 * INCOMPLETE -- WILL NOT COMPILE
 * This source file is the implementation for the class Organism.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Diane Wolf ____      _____October 26, 2017______________
//
// ____ dawolf | 301305135 ______
#include "Organism.h"
#include "World.h"
#include <iostream>

/**
 * @brief This function is the default class constructor.
 *
 * @param nothing
 * @return nothing - INCOMPLETE
 *
 */
Organism::Organism()
{}

/**
 * @brief INCOMPLETE - This is a class constructor.
 *
 * @param a World object exists
 *
 * @return nothing, initilizes Organism
 *
 */
Organism::Organism(World* worldSim, int xCoordinate, int yCoordinate):
									xPos(yCoordinate), yPos(xCoordinate)
{
// place Organism in grid cell
	simulationGrid = worldSim;
	simulationGrid->place(xPos,yPos);

// initialize data
	breedCounter = 0;
	moveStatus = false;
}

/**
 * @brief INCOMPLETE - This function is the class destructor.
 *
 * @param an Organism object exists
 * @return nothing
 *
 */
Organism::~Organism()
{}