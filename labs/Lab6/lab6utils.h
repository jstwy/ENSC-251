/**
 * @file lab6utils.h
 * @author Diane Wolf
 * @Date   11/16/2017
 * @version 1.0
 * @section This is the interface file for functions used in the main program
 *			(the "utilities"). The functions allow for ease in carrying out
 *			several actions.
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
#ifndef LAB6UTILS_H
#define LAB6UTILS_H
#include "Book.h"
#include <vector>
using std::vector;

//Precondition: The user needs to be prompted.
//Postcondition: The user is presented the menu and prompted to make a
//				 selection. After the user makes a selection, the selection
//				 is passed to the program. If invalid, then the selection is
//				 set to '0'.
char getUserChoice();
//////////////////////////////////////////////////////////////////////////////
//Precondition: The user has chosen to add a new book and a new book object
//				has been created.
//Postcondition: The user prompted to enter and set the book's title, author,
//				 and date of publication.
void setNewBookEntryInfo(Book& newBook);
//////////////////////////////////////////////////////////////////////////////
//Precondition: A data string needs to be checked for invalidity.
//Postcondition: The string is checked for presence of alphanumeric
//				 characters. The function returns true for an invalid string
//				 and false for a valid string.
bool hasNoContent(const string& uString);
//////////////////////////////////////////////////////////////////////////////
/*
* This function is derived from the code available at the following location:
* [http://forums.codeguru.com/showthread.php?366064-STL-Sorting-How-to-sort-a
* -std-vector-containing-classes-structures]
* The file has the following copyright from the original author:
* [ Marc G., CodeGuru.com. November 24, 2005. ]
**/
//Precondition: A new book has been created and its data has been set.
//Postcondition: The book is added to the library (vector holding all books)
//				 and the int keeping track of the number of book entries is
//				 incremented.
void addNewBookToLib(vector<Book>& libraryVector, const Book& bookToBeAdded,
					 int& libraryBookCounter);
//////////////////////////////////////////////////////////////////////////////
//Precondition: Vector elements need to be compared.
//Postcondition: This predicate is used to sort vector elements by author.
bool alphaByAuthor(const Book& firstBook, const Book& secondBook);
//////////////////////////////////////////////////////////////////////////////
//Precondition: A vector exists and needs to be sorted alphabetically by
//				author.
//Postcondition: The vector elements are sorted alphabetically by author and
//				 then printed to the console.
void sortAndPrint(vector<Book>& theLibrary);

#endif