/**
 * @file Doodlebug.cpp
 * @author Diane Wolf
 * @Date   10/26/2017
 * @version 1.0
 * @section DESCRIPTION
 * [HW2] [Part B] [Doodlebug implementation]
 * INCOMPLETE -- WILL NOT COMPILE
 * This source file is the implementation for the derived class Doodlebug.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Diane Wolf ____      _____October 26, 2017______________
//
// ____ dawolf | 301305135 ______
#include "Doodlebug.h"
#include "Organism.h"
#include "World.h"

/**
 * @brief This function places a Doodlebug on the grid.
 *
 * @param nothing
 * @return nothing, places an Doodlebug on the grid
 *
 */
Doodlebug::Doodlebug(World* worldSim, int xCoordinate, int yCoordinate):
								Organism(worldSim, xCoordinate, yCoordinate)
{}

/**
 * @brief This virtual function returns the type of Organism in a cell
 *
 * @param nothing
 * @return int orgType (0,1,2 corresponding to none,Ant,Doodlebug)
 *
 */
int Doodlebug::getOrgType()
{
	return orgType;
}