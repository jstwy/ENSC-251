/**
 * @file lab5.cpp
 * @author Diane Wolf
 * @Date   11/3/2017
 * @version 1.0
 * @section DESCRIPTION
 * This program converts 24-hour time to 12-hour time. It is an exercise
 * in exception handling.
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
#include "lab5utils.h"
#include <iostream>
#include <string>

int main()
{
    std::string userTime;	// string to hold user input
    bool tryAgain;			// bool keeps track of existance of a bad string
    tryAgain = false;
    
    do
    {
        printPrompt(); // prompt user to enter time
        try // try block
        {
        // test the string for errors, throw exceptions when necessary
            std::cin >> userTime;   // store time in user input var
            validSize(userTime);    // check for string of length 4 or 5 chars
            validChars(userTime);   // check for string with only ints and ':'
            validHours(userTime);   // check whether 0 <= hours <= 24
            validMins(userTime);    // check whether minutes < 60
        // convert valid time to 12-hour time
            printConversion(userTime);
        }
        catch(TimeFormatMistake e) // catch block
        {
            printError(e.getBadTime());	// print error message
            tryAgain = true;			// indicate a bad string
        }
    } while (onceMore(tryAgain)); // prompt until user enters something
                                        //other than 'y' 
    endMessage(); // print "End of program"
    
	return 0;
}