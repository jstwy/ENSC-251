/**
 * @file World.cpp
 * @author Diane Wolf
 * @Date   10/26/2017
 * @version 1.0
 * @section DESCRIPTION
 * [HW2] [Part B] [World implementation]
 * INCOMPLETE -- WILL NOT COMPILE
 * This source file is the implementation for the class World.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Diane Wolf ____      _____October 26, 2017______________
//
// ____ dawolf | 301305135 ______
#include "World.h"
#include "Organism.h"
#include "Ant.h"
#include "Doodlebug.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * @brief This function is the default class constructor.
 *
 * @param nothing
 * @return nothing, initializes world grid
 *
 */
World::World()
{
// seed the random number generator
	srand(time(NULL));
// initialize world to all null pointers
	for (int j = 0; j < DIMENSION; j++)
	{
		for (int i = 0; i < DIMENSION; i++)
		{
			worldGrid[j][i] = nullptr;
		}
	}
// randomly place ants
	for (int a = 0; a < START_ANTS; a++)
	{
		new Ant((rand() % DIMENSION),(rand() % DIMENSION));
	}
// randomly place doodlebugs
	for (int b = 0; b < START_BUGS; b++)
	{
		new Doodlebug((rand() % DIMENSION),(rand() % DIMENSION));
	}
}

/**
 * @brief This function is the class destructor.
 *
 * @param nothing
 * @return nothing, returns all dynanamically allocated memory to free store
 *
 */
World::~World()
{
// give memory back to free store; delete all pointers
	for (int j = 0; j < DIMENSION; j++)
	{
		for (int i = 0; i < DIMENSION; i++)
		{
			if (worldGrid[j][i] != nullptr)
			{
				delete worldGrid[j][i];
			}
		}
	}
}

/**
 * @brief This function places an Organism on the grid.
 *
 * @param Organism* org, int xCoordinate, int yCoordinate
 * @return nothing, has grid locationg point to Organism
 *
 */
void World::place(Organism* org, int xCoordinate, int yCoordinate)
{
// have a World grid pointer point to new Organism object
	worldGrid[yCoordinate][xCoordinate] = org;
}

/**
 * @brief This function prints the grid to the console.
 *
 * @param nothing
 * @return nothing, prints grid to console
 *
 */
void World::print()
{
// cycle through whole grid and print occupant type (./A/D)
	for (int j = 0; j < DIMENSION; j++)
	{
		for (int i = 0; i < DIMENSION; i++)
		{
			if (worldGrid[j][i] == nullptr)
			{
				std::cout << ".";
			}
			else if (worldGrid[j][i]->getOrgType() == ANT)
			{
				std::cout << "A";
			}
			else
			{
				std::cout << "D";
			}
		}
	}
}

/**
 * @brief INCOMPLETE - This function simulates the next time step.
 *
 * @param nothing
 * @return nothing, should iterate through all cells in grid and move
 *         Organisms as necessary
 *
 */
void World::step()
{}