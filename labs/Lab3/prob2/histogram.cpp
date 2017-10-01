/**
 * @file histogram.cpp
 * @author Diane Wolf
 * @Date   9/28/2017
 * @version 1.0
 * @section DESCRIPTION
 * This program takes student grades as integer inputs and outputs a histogram 
 * of the grades to the console.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Diane Wolf ____      _____September 28, 2017______________
//
// ____ dawolf | 301305135 ______

// necessary header files
#include <iostream>     // for standard i/o
#include <string>       // for string variables and .length()
#include <cstdlib>      // for atoi()
#include <vector>       // for vectors
#include <algorithm>    // for sorting
#include <set>          // for finding unique grades
using namespace std;

// function prototypes
void instructions();
void checkInput(string input, int& numberOfChars, int& numberOfInts);

// constants
const string KEYWORD = "-l"; // keyword for computing histogram generation

int main()
{
    // variables
    string entry; // stores user input; used to determine if it's an int value
    int numChars; // stores number of characters in user input string
    numChars = 0;
    int numInts; // stores number of integers in user entry
    numInts = 0;
    int grade; // stores grades entered by user
    grade = 0;
    int gradeType; // stores what different grades there are
    gradeType = 0;
    int gradeFreq; // stores frequency of each grade
    gradeFreq = 0;
    int *histogram; // dynamic array stores histogram
    vector<int> roster; // stores all grades in order entered by user
    bool loop; // used to keep while loop in action
    loop = 1;
    
    // provide user with instructions
    instructions();
    
    // get grades from user input; warn user of incorrect input
    while (loop)
    {
        cin >> entry;
        
        // check if input is '-l'; exit loop if it is
        if (entry == KEYWORD)
        {
            loop = 0;
            break;
        }
        
        numChars = entry.length();
        
        // check each character in user input and look for non-int values
        checkInput(entry,numChars,numInts);
        
        // store grade if input is determined to be all ints
        if (numInts == numChars)
        {
            grade = atoi(entry.c_str());
            roster.push_back(grade);
        }
        
        // reset int variables to prevent any leftover values
        numInts = 0;
        numChars = 0;
        grade = 0;
    }

    if (entry == KEYWORD && roster.empty())
    {
        cout << "No data was entered. Terminating program." << endl;
    }
    else
    {
        // sort raw data in roster
        sort(roster.begin(),roster.end()); 
        // find unique grades in roster
        gradeType = 2 * set<int>(roster.begin(),roster.end()).size();
        // create histogram array
        histogram = new int[gradeType];
        for (int i = 0; i < roster.size(); i++)
        {
            for (int j = 0; j < roster.size(); j++)
            {
                if (roster[i] == roster[j])
                {
                    gradeFreq += 1;
                    histogram[i * 2] = roster[i];
                    histogram[(i * 2) + 1] = gradeFreq;
                }
                else
                {
                    gradeFreq = 0;
                }
            }
        }
        for (int i = 0; i < gradeType; i += 2)
        {
            cout << "Number of " << histogram[i]
                 << "'s: " << histogram[i + 1] << endl;
        }
    }
    
    // following line triggers error "free(): invalid next size (fast):
        //0x0000000000c2bcb0 ***"
    //delete [] histogram;
    
    return 0;
}

// function definitions

/**
 * @brief This function prints user instructions to the console. It takes
 *         no arguments.
 *
 * @return void, prints message to console
 *
 */
void instructions()
{
    cout << "----------------------------------------------------------------"
         << "--------" << endl
         << "Please enter one grade per line - "
         << "press return after each entry is made." << endl
         << "Enter the command '-l' to generate histogram."
         << endl
         << "----------------------------------------------------------------"
         << "--------" << endl;
}

/**
 * @brief This function checks the user input for errors (non-int chars).
 *
 * @param input is the string entered by the user
 * @param numberOfChars is the length of the string
 * @param numberOfInts keeps track of the number of ints in the string
 * @return void, will print error message to console
 *
 */
void checkInput(string input, int& numberOfChars, int& numberOfInts)
{
    for (int i = 0; i < numberOfChars; i++)
    {
        // warn user of invalid input
        if (!(isdigit(input[i])))
        {
            cout << "Error: Please enter only integer values >=0 or '-l'."
                 << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            break;
        }
        // if character is an int, add to int counter
        else
        {
            numberOfInts++;
        }
    }
}