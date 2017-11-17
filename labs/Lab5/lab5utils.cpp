/**
 * @file lab5utils.cpp
 * @author Diane Wolf
 * @Date   11/3/2017
 * @version 1.0
 * @section DESCRIPTION
 * This file contains function definitions for functions used in lab5.cpp.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Diane Wolf ____      _____November 3, 2017______________
//
// ____ dawolf | 301305135 ______
#include "lab5utils.h"
#include "TimeFormatMistake.h"
#include <iostream>
#include <string>

/**
 * @brief This function prompts the user for the time they wish to concert.
 *
 * @param none
 * @return void; prints prompt to console
 *
 */
void printPrompt()
{
    std::cout << "Enter time in 24-hour notation:\n";
}

/**
 * @brief This function checks for proper time string size.
 *
 * @param string timeString
 * @return void; throws exception if string is too long or short
 *
 */
void validSize(std::string& timeString)
{
    if (timeString.size() < 4 || timeString.size() > 5)
    {
        throw TimeFormatMistake(timeString);
    }
}

/**
 * @brief This function checks that the string has only numbers and ':'.
 *
 * @param string timeString
 * @return void; throws exception if string contains non-digits
 *
 */
void validChars(std::string& timeString)
{
    bool hasColon;
    hasColon = false;
    for (unsigned int i = 0; i < timeString.size(); i++)
    {
        if (!isdigit(timeString.at(i)) && timeString.at(i) != ':')
        {
            throw TimeFormatMistake(timeString);
        }
        else if (timeString.at(i) == ':')
        {
            hasColon = true;
        }
    }
    if (hasColon == false)
    {
        throw TimeFormatMistake(timeString);
    }
}

/**
 * @brief This function checks whether the hours entered are valid.
 *
 * @param string timeString
 * @return void; throws exception if hours > 24
 *
 */
void validHours(std::string& timeString)
{
    int hour;
    
    if (timeString.size() == 4)
    {
        hour = std::stoi(timeString.substr(0,1));
    }
    else
    {
        hour = std::stoi(timeString.substr(0,2));
    }
    
    if (hour > 24)
    {
        throw TimeFormatMistake(timeString);
    }
}

/**
 * @brief This function checks whether the minutes are valid.
 *
 * @param string timeString
 * @return void; throws exception if minutes > 59
 *
 */
void validMins(std::string& timeString)
{
    int mins;
    
    if (timeString.size() == 4)
    {
        mins = std::stoi(timeString.substr(2,2));
    }
    else
    {
        mins = std::stoi(timeString.substr(3,2));
    }
    
    if (mins > 59)
    {
        throw TimeFormatMistake(timeString);
    }
}

/**
 * @brief This function prints the converted time.
 *
 * @param string timeString
 * @return void; prints converted time to console
 *
 */
void printConversion(std::string& timeString)
{
    std::cout << "That is the same as\n"
              << toTwelve(timeString)     // print converted time
              << "\n";   
}

/**
 * @brief This function prints an error message to the console.
 *
 * @param string timeString
 * @return void; prints error message to console
 *
 */
void printError(std::string timeString)
{
    std::cout << "There is no such time as "
              << timeString
              << "\n"
              << "Try again:\n";
}

/**
 * @brief This function converts 24-hour time to 12-hour time.
 *
 * @param string timeString
 * @return string; returns newly converted time
 *
 */
std::string toTwelve(std::string& timeString)
{
    int hoursInt;
    std::string hoursStr;
    std::string restOfTime;
    std::string convertedTime;
    
    if (timeString.size() == 4)
    {
        return (timeString + " AM");
    }
    else
    {
        restOfTime = timeString.substr(2,3);
        hoursInt = std::stoi(timeString.substr(0,2));
        if (hoursInt == 24)
        {
            hoursStr = std::to_string(hoursInt - 12);
            return ("00" + restOfTime + " AM");
        }
        else if (hoursInt < 12)
        {
            hoursStr = std::to_string(hoursInt);
            return (hoursStr + restOfTime + " AM");
        }
        else
        {
            hoursStr = std::to_string(hoursInt - 12);
            return (hoursStr + restOfTime + " PM");
        }
    }
}

/**
 * @brief This function controls the reuse of the conversion.
 *
 * @param bool errorRetry for detecting incorrect command entry
 * @return bool; continues or breaks do-while loop
 *
 */
bool onceMore(bool& errorRetry)
{
    std::string ans;
	char letter;
    
    if (errorRetry == true)
    {
        errorRetry = false;
        return true;
    }
    else
    {
		do
	    {
			std::cout << "Again? (y/n)\n";
		    std::cin >> ans;
			letter = ans.at(0);
			if (letter == 'n' || letter == 'N')
		    {
			    return false;
	        }
		    else if (letter == 'y' || letter == 'Y')
			{
				return true;
	        }
		    else
			{
	            std::cout << "Invalid command. Please try again...\n";
			}
		} while ((letter != 'n') ||
				 (letter != 'N') ||
				 (letter != 'y') ||
				 (letter != 'Y')
				);
    }
}

/**
 * @brief This function indicates program termination.
 *
 * @param none
 * @return void; prints message to console.
 *
 */
void endMessage()
{
    std::cout << "End of program\n";
}