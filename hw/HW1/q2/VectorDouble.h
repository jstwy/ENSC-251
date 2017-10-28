/**
 * @file VectorDouble.h
 * @author Trevor Lee, Diane Wolf
 * @Date   10/3/2017
 * @version 1.0
 * @section DESCRIPTION
 * This source file is the interface for class VectorDouble.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Trevor Lee, Diane Wolf ____      _____October 3, 2017______________
//
// ____ tcl18 | 301320975, dawolf | 301305135 ______

#ifndef VECTORDOUBLE_H
#define VECTORDOUBLE_H

class VectorDouble
{
public:
    // default constructor; creates 50-element array
    VectorDouble();
    // constructor 2: creates n-element array based on input
    VectorDouble(int initialSizeOfArray);
    // constructor 3: copy constructor
//    VectorDouble(&);
    // destructor; deletes dynamic arrays created
    ~VectorDouble();
    void push_back(double newEntry);
    int capacity();
    int size();
//    reserve();
//    resize();
    double value_at(int position);
    // change_value_at(double value, int position);

private:
    double* doublesArray; // dynamic array
    double* upgradedArray; // array for when the original array is too small
    int max_count; // size of dynamic array
    int count; // number of entries held in array
    double newArrayEntry; // new vector entry
    void buildDefaultArray(double*& array);
    void buildCustomArray(double*& array, int initialSizeOfArray);
    void upgradeToNewArray(double*& upgradedArray); // makes array 2x original
    void success();
};

#endif