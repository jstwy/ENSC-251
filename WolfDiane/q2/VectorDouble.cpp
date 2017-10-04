/**
 * @file VectorDouble.cpp
 * @author Trevor Lee, Diane Wolf
 * @Date   10/3/2017
 * @version 1.0
 * @section DESCRIPTION
 * This source file is the implementation for class VectorDouble.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Trevor Lee, Diane Wolf ____      _____October 3, 2017______________
//
// ____ tcl18 | 301320975, dawolf | 301305135 ______

#include "VectorDouble.h"
#include <iostream>
using namespace std;

// FOR TEST PURPOSES -- USE INSTEAD OF COUT << BLAH BLAH, DELETE LATER--------
void VectorDouble::success()
{
    cout << "test of this function was successful" << endl;
}
//----------------------------------------------------------------------------

VectorDouble::VectorDouble() // COMPLETED
{
    buildDefaultArray(doublesArray); // build 50-element dynamic array
    count = 0; // set occupied positions to zero
}

VectorDouble::VectorDouble(int initialSizeOfArray) // COMPLETED
{
    buildCustomArray(doublesArray, initialSizeOfArray);
    count = 0; // set occupied positions to zero
}

/*
VectorDouble::VectorDouble(&)
{
    
}
*/

VectorDouble::~VectorDouble() // COMPLETED
{
    // check if there is a second array
    if (count > max_count)
    {
        delete [] upgradedArray; // delete second array
    }
    
    delete [] doublesArray; // delete dynamic array in any case
}

void VectorDouble::push_back(double userEntry) // COMPLETED
{
    newArrayEntry = userEntry; // store user's new entry internally
    count++; // increment number of elements
    
    if (count == max_count) // create new array once limit is reached
    {
        doublesArray[count - 1] = newArrayEntry;
        upgradeToNewArray(upgradedArray); // create new array
    }
    else if (count < max_count) // add to original array if under limit
    {
        doublesArray[count - 1] = newArrayEntry; // add new entry to array
    }
    else if (count > max_count) // add to new array if over limit
    {
        upgradedArray[count - 1] = newArrayEntry; // add to upgraded array
    }
}

int VectorDouble::capacity() // COMPLETED
{
    if (count > max_count)
    {
        return (2 * max_count);
    }
    else
    {
        return max_count;
    }
}

int VectorDouble::size() // COMPLETED
{
    return count;
}

/*
VectorDouble::reserve()
{
    
}
*/

/*
VectorDouble::resize()
{
    
}
*/

double VectorDouble::value_at(int position)
{
    // variable
    double valueAtPos; // stores value of double inside array position
    valueAtPos = 0.0;
    
    if (count > max_count)
    {
        valueAtPos = upgradedArray[position]; // get value from new array
    }
    else
    {
        valueAtPos = doublesArray[position]; // get value from old array
    }
    
    return valueAtPos;
}

void VectorDouble::buildDefaultArray(double*& array) // COMPLETED
{
    max_count = 50; // set capacity to 50 elements
    array = new double [max_count]; // create dynamic array
}

// COMPLETED
void VectorDouble::buildCustomArray(double*& array, int initialSizeOfArray)
{
    max_count = initialSizeOfArray; // set capacity to user specification
    array = new double [max_count]; // create dynamic array
}

void VectorDouble::upgradeToNewArray(double*& upgradedArray)
{
    upgradedArray = new double [2 * max_count]; // create array 2x as big
    
    // move old array elements to new one
    for (int i = 0; i < max_count; i++)
    {
        upgradedArray[i] = doublesArray[i];
    }
}