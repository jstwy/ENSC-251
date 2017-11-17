/**
 * @file TimeFormatMistake.h
 * @author Diane Wolf
 * @Date   11/3/2017
 * @version 1.0
 * @section DESCRIPTION
 * This is the interface file for the class TimeFormatMistake.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Diane Wolf ____      _____November 3, 2017______________
//
// ____ dawolf | 301305135 ______
#ifndef TIMEFORMATMISTAKE_H
#define TIMEFORMATMISTAKE_H
#include <string>

class TimeFormatMistake
{
public:
    TimeFormatMistake(std::string invalidTimeString);
	// Precondition: An exception is thrown.
	// Postcondition: An exception object is created.
    std::string getBadTime();
	// Precondition: A TimeFormatMistake object exists.
	// Postcondition: The invalid string is returned.
private:
    std::string badTime; // invalid string is stored here for later access
};

#endif