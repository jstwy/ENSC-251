/**
 * @file q2.cpp
 * @author Trevor Lee, Diane Wolf
 * @Date   9/28/2017
 * @version 1.0
 * @section DESCRIPTION
 * This program demonstrates a class that acts as a substitute for vectors.
 * It is defined for doubles.
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ Trevor Lee, Diane Wolf ____      _____September 28, 2017______________
//
// ____ tcl18 | 301320975, dawolf | 301305135 ______

#include "VectorDouble.h" // class header file
#include <iostream>
using namespace std;

int main()
{
    int customSize;
    customSize = 0;
    double input;
    input = 0.0;
    int accessPos;
    accessPos = 0;
    double value;
    value = 0.0;
    
    cout << "creating object..." << endl;
/*    
    VectorDouble test1;
    for (int i = 0; i < 5; i++)
    {
        cout << "new entry: ";
        cin >> input;
        test1.push_back(input);
        input = 0.0;
    }
    
    cout << "vector size is currently " << test1.size() << endl;
    
    for (int i = 0; i < 5; i++)
    {
        cout << "position to access: ";
        cin >> accessPos;
        value = test1.value_at(accessPos);
        cout << "value at " << accessPos << " is " << value << endl;
        value = 0.0;
        accessPos = 0;
    }
*/
    cout << "enter size of array >= 3: ";
    cin >> customSize;
    VectorDouble test2(customSize);
    for (int i = 0; i < 5; i++)
    {
        cout << "new entry: ";
        cin >> input;
        test2.push_back(input);
        input = 0.0;
    }
    for (int i = 0; i < (2 * customSize); i++)
    {
            cout << test2.value_at(i) << endl;
    }
    
    return 0;
}