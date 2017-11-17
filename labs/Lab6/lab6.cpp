/**
 * @file lab6.cpp
 * @author Diane Wolf
 * @Date   11/16/2017
 * @version 1.0
 * @section This is the main program. It allows for the user to store books in
 *			a library and list the books alphabetically by author.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ DIANE A. WOLF ____      _____NOVEMBER 16, 2017______________
//
// ____ 301305135 ______
//////////////////////////////////////////////////////////////////////////////
#include "lab6utils.h"
#include "Book.h"
#include "globalConst.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<Book> lib;			// vector of books - the "library"
	string entryString = "entry";	// base name for book objects
	int entryCount;					// number of books in library
	entryCount = 0;
	string bookEntry;				// object name ("entryX", X = entryCount)
	char sel;						// menu command from user's selection
	sel = '0';						// default command is invalid
    
// prompt user to select a menu option if invalid input is registered
// or until the user selects to exit the program
	do
	{
		sel = getUserChoice();

	// create a new book, set the data, and add it to the library
		if (sel == '1')
		{
		// make the book name "entry" + [books in library]
			bookEntry = entryString + std::to_string(entryCount);
			Book bookEntry;
		// set the data for the new book
			setNewBookEntryInfo(bookEntry);
		// add the new book to the library and update the library size
			addNewBookToLib(lib, bookEntry, entryCount);
		}
	// sort the library alphabetically by author name and print the
	// listings to the console
		else if (sel == '2')
		{
			sortAndPrint(lib);
		}
	} while (sel != '3'); // break loop and terminate when user enters '3'
    
    return 0;
}