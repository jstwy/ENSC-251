/**
 * @file Book.h
 * @author Diane Wolf
 * @Date   11/16/2017
 * @version 1.0
 * @section This is the interface file for the Book class. A Book object holds
 *			three pieces of data: the title of the book, its author's name,
 *			and its date of publication.
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
#ifndef BOOK_H
#define BOOK_H
#include <string>
using std::string;

class Book
{
public:
	//Precondition: None.
	//Postcondition: A book object is instantiated.
	Book();
//////////////////////////////////////////////////////////////////////////////
	//Precondition: The author string has been initialized.
	//Postcondition: The author string is returned.
	string getAuthor() const;
//////////////////////////////////////////////////////////////////////////////
	//Precondition: The publication date string has been initialized.
	//Postcondition: The publication date string is returned.
	string getPubDate();
//////////////////////////////////////////////////////////////////////////////
	//Precondition: The title string has been initialized.
	//Postcondition: The title string is returned.
	string getTitle();
//////////////////////////////////////////////////////////////////////////////
	//Precondition: None.
	//Postcondition: The author string is set to the function argument.
	void setAuthor(string& theAuthor);
//////////////////////////////////////////////////////////////////////////////
	//Precondition: None.
	//Postcondition: The publication date string is set to the function
	//				 argument.
	void setPubDate(string& thePubDate);
//////////////////////////////////////////////////////////////////////////////
	//Precondition: None.
	//Postcondition: The title string is set to the function argument.
	void setTitle(string& theTitle);
//////////////////////////////////////////////////////////////////////////////
private:
	string author;	// book author
	string pubDate;	// book publication date
	string title;	// book title
};

#endif