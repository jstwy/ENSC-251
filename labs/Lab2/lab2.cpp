/**
 * @file lab2.cpp
 * @author Diane Wolf
 * @Date   9/22/2017
 * @version 1.0
 * @section DESCRIPTION
 * This program takes the user's first and last name as input and returns their
 * name in Pig Latin.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Diane Wolf ____      _____September 22, 2017______________
//
// ____ dawolf | 301305135 ______

#include <iostream>
#include <string>
#include <cctype>
using namespace std; 

// pig latin translator function
string translate(string word, int length);
	
int main()
{
	// variables
	string first, last; // Strings to hold first and last name.
	string newFirst, newLast; // Translated first and last name.
	string result; // Whole translated name.
	int lenFirst = 0; // Length of first name.
	int lenLast = 0; // Length of last name.
	bool loopFirst = 1; // Loop for checking name validity.
	bool loopLast = 1; // Loop for cheking name validity.

	// Prompt for first name.
	// Check for input errors; make sure input is only letters.
	// Re-prompt for information if input values are invalid.
	while (loopFirst)
	{
		loopFirst = 0; /* Set looping boolean to false in order to exit if valid
						  entry is made. */
		
		cout << "Enter your first name: ";
		cin >> first; // Store name in first name string holder.
		lenFirst = first.length(); // Get and store name length.

		for (int i = 0; i < lenFirst; i++) // Check for invalid characters.
		{
			if (!isalpha(first[i]))
			{
				loopFirst = 1; /* If string contains non-alphabetical character,
								  repeat. */
				cout << "That entry is not valid... please try again with " <<
							"letters only" << endl;
				break;
			}
			else
			{
				first[i] = tolower(first[i]); /* If no errors are detected,
												 change string to lowercase. */
			}
		}

	}

	/*	
		Prompt for last name.
		Check for input errors; make sure input is only letters.
		Re-prompt for information if input values are invalid.
	*/
	while (loopLast)
	{
		loopLast = 0; /* Set looping boolean to false in order to exit if valid
						 entry is made. */
		
		cout << "Enter your last name: ";
		cin >> last; // Store name in last name string holder.
		lenLast = last.length(); // Get and store name length.

		for (int i = 0; i < lenLast; i++) // Check for invalid characters.
		{
			if (!isalpha(last[i]))
			{
				loopLast = 1; /* If string contains non-alphabetical character,
								  repeat. */
				cout << "That entry is not valid... please try again with " <<
							"letters only" << endl;
				break;
			}
			else
			{
				last[i] = tolower(last[i]); /* If no errors are detected,
												 change string to lowercase. */
			}
		}

	}

	newFirst = translate(first, lenFirst); // Translate first name to pig latin.
	newLast = translate(last, lenLast); // Translate last name to pig latin.
	result.append(newFirst); // Store translated first name into result string.
	result.append(" ");
	result.append(newLast); // Append translated last name to result string.

	cout << result << endl; // Print converted name string.

	return 0;
}

/**
 * @brief This function returns the Pig Latin translation of a string.
 *
 * @param word is the name to be translated
 * @param length is the length of the name
 * @return string
 *
 */

string translate(string word, int length)
{
	string translation; // For storing the translated name.
	string addWay = "way"; // String to append if name starts with vowel.
	string addAy = "ay"; // String to append if name starts with consonant.
	char temp = ' '; // Temporary holder for letter to be moved.
	char vowels[5] = {'a', 'e', 'i', 'o', 'u'}; // Array for vowel comparison.
	
	/*
		If the name starts with a vowel, append "way" to name.
		If the name starts with a consonant, append "ay" to name, put first
		letter into temporary holder and shift letters over to left.
	*/
	if (word[0] == vowels[0] || word[0] == vowels[1] || word[0] == vowels[2] ||
		word[0] == vowels[3] || word[0] == vowels[4])
	{
		word.append(addWay);
	}
	else
	{
		word.append(addAy);
		temp = word[0];
		for (int i = 1; i < length; i++)
		{
			word[(i - 1)] = word[i];
		}
		word[(length - 1)] = temp;
	}

	// Capitalize name.
	word[0] = toupper(word[0]);
	translation = word;

	return translation;
}