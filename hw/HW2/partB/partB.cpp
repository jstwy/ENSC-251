/**
 * @file partB.cpp
 * @author Diane Wolf
 * @Date   10/26/2017
 * @version 1.0
 * @section DESCRIPTION
 * [HW2] [Part B] [main program]
 * INCOMPLETE -- WILL NOT COMPILE
 * This program simulates a predator-prey situation involving doodlebugs
 * and ants. The doodlebugs and ants are class objects derived from a class
 * called Organism. The simulation takes place in a 20x20 grid world and
 * starts off with a population of 5 doodlebugs and 100 ants whose positions
 * are randomly generated at each launch of the program.
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
#include <iostream>
using namespace std;

int main()
{
// create 20x20 grid world with 100 & 5 randomly placed ants & bugs
	World simulation;
// print world to console
	simulation.print();

// prompt user to press Enter to proceed to next time step
	cout << "Press Enter to simulate next time step.\n"
		 << "Press any other key followed by Enter to exit.";
	while (1)
	{
	// simulate next time step and print to console
		if (cin.get() == '\n')
		{
	        simulation.step();
		    simulation.print();
		}
	// terminate program
		else
		{
		    break;
		}
	}

    return 0;
}