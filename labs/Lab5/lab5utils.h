/**
 * @file lab5utils.h
 * @author Diane Wolf
 * @Date   11/3/2017
 * @version 1.0
 * @section DESCRIPTION
 * This file is the header file for the functions used in lab5.cpp.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Diane Wolf ____      _____November 3, 2017______________
//
// ____ dawolf | 301305135 ______
#ifndef LAB5UTILS_H
#define LAB5UTILS_H
#include <string>

void printPrompt();
// Precondition: None.
// Postcondition: A message prompting the user for input is printed to the
//				  console.
void validSize(std::string& timeString);
// Precondition: A string has been provided by the user.
// Postcondition: The size of the string is checked. An exception is thrown
//				  if the string is not 4 or 5 characters in length.
void validChars(std::string& timeString);
// Precondition: A string has been provided by the user.
// Postcondition: The characters in the string are checked. An exception is
//				  thrown when the characters are not a single ':'
//				  accompanied by 3 or 4 numbers.
void validHours(std::string& timeString);
// Precondition: A string has been provided by the user.
// Postcondition: The first or first two numbers in the string are
//				  checked. An exception is thrown when they are greater
//				  than 24.
void validMins(std::string& timeString);
// Precondition: A string has been provided by the user.
// Postcondition: The last two numbers in the string are checked. An
//				  exception is thrown if they form a number greater
//				  than 59.
void printConversion(std::string& timeString);
// Precondition: The string provided by the user has been converted to
//				 12-hour time.
// Postcondition: The converted time is printed to the console with "AM" or
//				  "PM" following it.
void printError(std::string timeString);
// Precondition: The string provided by the user has been deemed invalid.
// Postcondition: An erro message is printed to the console alerting the
//				  user of an error.
std::string toTwelve(std::string& timeString);
// Precondition: The string provided by the user has been deemed valid.
// Postcondition: The time in the string is conveted to 12-hour time.
bool onceMore(bool& errorRetry);
// Precondition: A conversion has been successfully converted or an invalid
//				 command has been entered by the user.
// Postcondition: The user is asked whether another conversion is desired.
void endMessage();
// Precondition: The user has selected to terminate the program.
// Postcondition: A message indicating program termination is printed to
//				  the console ("End of program").

#endif