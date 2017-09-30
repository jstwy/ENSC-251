/**
 * @file q1.cpp
 * @author Trevor Lee, Diane Wolf
 * @Date   9/28/2017
 * @version 1.0
 * @section DESCRIPTION
 * This program ...
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Trevor Lee, Diane Wolf ____      _____September 28, 2017_____________
//
// ____ tcl18 | 301320975, dawolf | 301305135 ______

#include <iostream>
#include <string>
using namespace std;

// class
    // >= 2 public member functions
        // returns zip code as integer (decoded zip code number)
        // returns zip code as string (barcode in 1s and 0s)
    // helper functions are private
class Postnet
{
    // how to store the zip code internally?
        // zip code integer?
        // barcode string?
    
    public:
// constructors and functions
    Postnet(int zipCodeInteger);
    // Initializes ...
    
    Postnet(string barcodeString);
    // Initializes ...
    
    void encode();
    // Precondition:
    // Postcondition:
    
    void decode();
    // Precondition:
    // Postcondition:
    
    private:
// variables
    int zipCode;
    string barcode;
    
// helper functions
}

// test program
int main()
{
    void checkBarcode(string barcodeString);
    // Precondition:
    // Postcondition:
    
    void checkZipCode(int zipCodeInteger);
    // Precondition:
    // Postcondition:
    
    return 0;
}