/**
 * @file Book.cpp
 * @author Diane Wolf
 * @Date   11/16/2017
 * @version 1.0
 * @section This is the implementation file fpr the Book class. It includes
 *			function for getting and setting book data.
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
#include <string>
using std::string;

// the book constructor; no initializations
Book::Book()
{
}
//////////////////////////////////////////////////////////////////////////////
/**
 * @brief This function returns the book's author name.
 *
 * @param none
 * @return string author
 *
 */
string Book::getAuthor()
const {
	return author;
}
//////////////////////////////////////////////////////////////////////////////
/**
 * @brief This function returns the book's publication date.
 *
 * @param none
 * @return string pubDate
 *
 */
string Book::getPubDate()
{
	return pubDate;
}
//////////////////////////////////////////////////////////////////////////////
/**
 * @brief This function returns the book's title.
 *
 * @param none
 * @return string title
 *
 */
string Book::getTitle()
{
	return title;
}
//////////////////////////////////////////////////////////////////////////////
/**
 * @brief This function sets the book's author name.
 *
 * @param strimg theAuthor is what the user is setting the author data to
 * @return void
 *
 */
void Book::setAuthor(string& theAuthor)
{
// resize the string to account for longer titles
	author.reserve(MAX_STRING_LEN);
	author = theAuthor;
}
//////////////////////////////////////////////////////////////////////////////
/**
 * @brief This function sets the book's author name.
 *
 * @param strimg thePubDate is what the user is setting the pub. date to
 * @return void
 *
 */
void Book::setPubDate(string& thePubDate)
{
	pubDate = thePubDate;
}
//////////////////////////////////////////////////////////////////////////////
/**
 * @brief This function sets the book's title.
 *
 * @param strimg theTitile is what the user is setting the title to
 * @return void
 *
 */
void Book::setTitle(string& theTitle)
{
// resize the string to account for longer names
	title.reserve(MAX_STRING_LEN);
	title = theTitle;
}