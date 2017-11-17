/**
 * @file lab6utils.cpp
 * @author Diane Wolf
 * @Date   11/16/2017
 * @version 1.0
 * @section This is the implementation file for the "utility" functions. It
 *			includes functions that handle all of the user I/O.
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
#include "Book.h"
#include "globalConst.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::vector;

/**
 * @brief This function prompts the user for input.
 *
 * @param none
 * @return char uChoice
 *
 */
char getUserChoice()
{
		std::string uInput;	// user input
		char uChoice;		// user's choice extracted from uInput[0]
	
	// present the menu to the user and collect input
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
			 << "Select from the following choices:\n"
             << "1. Add new book\n"
             << "2. Print listing sorted by author\n"
             << "3. Quit\n->";
        cin >> uInput;
	// first character of string entered by user is treated as choice
		uChoice = uInput.at(0);
	
	// if the choice is invalid, return '0' for "invalid choice" code
		if (uChoice != '1' && uChoice != '2' && uChoice != '3')
		{
			return '0';
		}
	// if the choice is valid, return the choice code
		else
		{
			return uChoice;
		}
}
//////////////////////////////////////////////////////////////////////////////
/**
 * @brief This function checks for invalid content in the user's data entry.
 *
 * @param string uString is the user's input for the date/author/title
 * @return bool noAlpha - if true, then the input is invalid
 *
 */
bool hasNoContent(const string& uString)
{
	char currentChar;
	bool noAlpha;
	noAlpha = true;

// check each character of uString for at least one letter or one number -
// this allows for a wide range of titles, but not entries such as pure
// whitespace or only symbols
	for (int i = 0; i < uString.length(); i++)
	{
		currentChar = uString.at(i);
		if (isalpha(currentChar) || isdigit(currentChar))
		{
		// false means the string is valid
			noAlpha = false;
		}
	}

// if no letters/numbers were found, the function returns true for invalidity
	return noAlpha;
}
//////////////////////////////////////////////////////////////////////////////
/**
 * @brief This function allows the user to set the book data.
 *
 * @param Book newBook
 * @return void
 *
 */
void setNewBookEntryInfo(Book& newBook)
{
	string tit;		// user entry for title
	string auth;	// user entry for author
	string pdate;	// user entry for publication date

// clear the stream of previous input/flags
	cin.clear();
	cin.ignore(10000,'\n');

// prompt user to set data; if incorrect, prompt again
	do
	{
	// set the string length to 100 to accommodate for long titles
		tit.reserve(MAX_STRING_LEN);
		cout << "Enter title:\n";
	// get the prospective title and check validity
		std::getline(cin,tit);
	} while (hasNoContent(tit));
// set title data
	newBook.setTitle(tit);

	do
	{
	// set the string length to 100 to accommodate for long titles
		auth.reserve(MAX_STRING_LEN);
		cout << "Enter author:\n";
	// get the prospective author name and check validity
		std::getline(cin,auth);
	} while (hasNoContent(auth));
// capitalize first letter of author name for uniformity
	auth.at(0) = toupper(auth.at(0));
// set author data
	newBook.setAuthor(auth);

	do
	{
	// the date string can be left at default capacity
		cout << "Enter date:\n";
	// get the prospective title and check validity
		std::getline(cin,pdate);
	} while (hasNoContent(pdate));
// set publication date data
	newBook.setPubDate(pdate);
}
//////////////////////////////////////////////////////////////////////////////
/**
 * @brief This function adds a Book object to the library and increments a
 *		  counter that keeps track of the number of books in the library.
 *
 * @param vector<Book> libraryVector, Book bookToBeAdded, int
 *		  libraryBookCounter
 * @return void
 *
 */
void addNewBookToLib(vector<Book>& libraryVector, const Book& bookToBeAdded,
					 int& libraryBookCounter)
{
	libraryVector.push_back(bookToBeAdded);
	libraryBookCounter++;
}
//////////////////////////////////////////////////////////////////////////////
/*
* This function is derived from the code available at the following location:
* [ http://forums.codeguru.com/showthread.php?366064-STL-Sorting-How-to-sort-a
* -std-vector-containing-classes-structures ]
* The file has the following copyright from the original author:
* [ Marc G., CodeGuru.com. November 24, 2005. ]
**/
/**
 * @brief This function redefines the [<] operator.
 *
 * @param Book firstBook and Book secondBook
 * @return bool for comparing the two author names
 *
 */
bool alphaByAuthor(const Book& firstBook, const Book& secondBook)
{
// get the author names
	string author1;
	author1 = firstBook.getAuthor();
	string author2;
	author2 = secondBook.getAuthor();

// compare the names
	return (author1 < author2);
}
//////////////////////////////////////////////////////////////////////////////
/**
 * @brief This function sorts the library vector and prints the sorted
 *		  listings to the console.
 *
 * @param vector<Book> theLibrary
 * @return void
 *
 */
void sortAndPrint(vector<Book>& theLibrary)
{
// sort the library book listings
	std::sort(theLibrary.begin(), theLibrary.end(), alphaByAuthor);
	// iterate through and print the listings to the console
		cout << "The books entered so far, "
			 << "sorted alphabetically by author are:\n";
		for (vector<Book>::iterator i = theLibrary.begin();
											i != theLibrary.end(); i++)
		{
		// format output: [TAB][AUTHOR NAME]. [TITLE]. [PUBLICATION DATE].[\N]
			cout << "\t"
				 << (*i).getAuthor() << ". "
				 << (*i).getTitle() << ". "
				 << (*i).getPubDate() << ".\n";
		}
}