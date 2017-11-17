/**
 * @file TimeFormatMistake.cpp
 * @author Diane Wolf
 * @Date   11/3/2017
 * @version 1.0
 * @section DESCRIPTION
 * This file contains function definitions for the exception class
 * TimeFormatMistake.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Diane Wolf ____      _____November 3, 2017______________
//
// ____ dawolf | 301305135 ______
#include "TimeFormatMistake.h"
#include <iostream>
#include <string>

/**
 * @brief This is the class constructor.
 *
 * @param string entered by user
 * @return void; sets badTime to user input string
 *
 */
TimeFormatMistake::TimeFormatMistake(std::string invalidTimeString):
                                                badTime(invalidTimeString)
{}

/**
 * @brief This function returns the input string.
 *
 * @param none
 * @return void; returns invalid input string
 *
 */
std::string TimeFormatMistake::getBadTime()
{
    return badTime;
}