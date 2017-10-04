/**
 * @file q1.cpp
 * @author Trevor Lee, Diane Wolf
 * @Date   9/28/2017
 * @version 1.0
 * @section DESCRIPTION
 * This program decodes barcodes entered in string format and encodes zip
 * codes entered in integer format based on the POSTNET format.
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
#include <string>   // string utilities
using namespace std;

class Postnet
{
public:
    // constructor for integer entry
    Postnet(int zipCodeInteger);
    // Initializes the zipcode in integer format.

    // constructor for string entry
    Postnet(string rawBarcodeString);
    // Initializes the zipcode in string/barcode format.

    // decoding function (barcode -> integer)
    void decode();
    // Precondition: Barcode entered by user is valid.
    // Postcondition: Barcode is printed to console as a zip code.
/*****************************************************************************
    // encoding function (integer -> barcode)
    void encode();
    // Precondition: Zip code entered by user is valid.
    // Postcondition: Zip code is printed to console as a barcode.
*****************************************************************************/
private:
    // variables
    string strippedBarcode; // barcode string without first and last digit
    string seg1; // numbers 0-4 of stripped barcode
    string seg2; // numbers 5-9 of stripped barcode
    string seg3; // numbers 10-14 of stripped barcode
    string seg4; // numbers 15-19 of stripped barcode
    string seg5; // numbers 20-24 of stripped barcode
    int zipDigits[5]; // array to hold all decoded zip code digits
    int decodedZipCode; // zip code as an integer

    // check that input is valid for barcodes
    bool checkBarcode(string rawBarcodeString);
    // Precondition: The barcode is entered as a string.
    // Postcondition: The barcode's validity has been determined.
/*
    // check that input is valid for zip codes
    void checkZipCode();
    // Precondition: The zip code is entered as an integer.
    // Postcondition: The zip code's validity has been determined.
*/
    // check for non-integer values in a string
    bool hasAlpha(string rawBarcodeString);
    // Precondition: The barcode is entered as a string.
    // Postcondition: The barcode is found to contain/not contain only ints.
    
    // check for legal number of ones per segment of 5 barcode digits
    bool checkDigitLegality(string rawBarcodeString);
    // Precondition: The barcode is entered as a string.
    // Postcondition: The barcode is determined to have exactly two ones in
    //                each group of five digits. Other numbers are illegal.

    // print an error message if constructor argument is invalid
    void error();
    // Precondition: The barcode is invalid.
    // Postcondition: The user is notified of a data entry error.

    // remove the first and last character from the barcode string
    string strip(string rawBarcodeString);
    // Precondition: The barcode string is 27 digits long.
    // Postcondition: The barcode's first and last 1s are removed.

    // split the stripped barcode string into 5 strings of 5 digits
    void segmentalize();
    // Precondition: The barcode is 25 digits long and is a string.
    // Postcondition: The barcode has been divided into 5 groups and stored
                    //in 5 integer arrays.

    // translate a segment into a zip code digit
    int flatten(string segment);
    // Precondition: The barcode is split into 5 different int arrays.
    // Postcondition: Each array has been converted to a zip code digit.
};

// test program/driver code
int main()
{
    // variables
    string barcodeCorrect; // legal barcode
    barcodeCorrect = "110100101000101011000010011";
    string barcodeShort; // illegal barcode that is too short
    barcodeShort = "1010010100010101100001001"; // missing first and last ones
    string barcodeLong; // illegal barcode that is too long
    barcodeLong = "1101001010001010110000100110"; // illegal, too long
    string barcodeAlpha; // illegal barcode containing a letter
    barcodeAlpha = "110100101000101011P00010011";
    string barcodeSymbol; // illegal barcode containing a symbol
    barcodeSymbol = "1101001010&0101011000010011";
    string barcodeOnesAbundance; // illegal barcode with >2 ones/segment
    barcodeOnesAbundance = "110100101111101011000010011";
    string barcodeZeroesAbundance; // illegal barcode with >3 zeroes/segment
    barcodeZeroesAbundance = "110100101000101000000010011";
/*    int zipCodeCorrect; // legal zip code
    int zipCodeShort; // illegal zip code that is too short
    int zipCodeLong; // illegal zip code that is too long
    string zipCodeAlpha; // illegal zip code that is not an integer
*/
    // introduction
    cout << "This is a driver program for testing program behaviour." << endl
         << "A legal value followed by several illegal values will be tested."
         << endl;

    // instantiate and test barcode objects
    cout << "Beginning testing..." << endl
         << "................................................................"
         << "..........." << endl;
    // test case 1: legal barcode
    cout << ">>> [TEST CASE 1] legal barcode: " << barcodeCorrect << endl;
    Postnet barcode1(barcodeCorrect);
    barcode1.decode();
    cout << "................................................................"
         << "..........." << endl;
    // test case 2: illegal short barcode
    cout << ">>> [TEST CASE 2] short barcode: " << barcodeShort << endl;
    Postnet barcode2(barcodeShort);
    barcode2.decode();
    cout << "................................................................"
         << "..........." << endl;
    // test case 3: illegal long barcode
    cout << ">>> [TEST CASE 3] long barcode: " << barcodeLong << endl;
    Postnet barcode3(barcodeLong);
    barcode3.decode();
    cout << "................................................................"
         << "..........." << endl;
    // test case 4: illegal alphabet-containing barcode
    cout << ">>> [TEST CASE 4] alphabetic barcode: " << barcodeAlpha << endl;
    Postnet barcode4(barcodeAlpha);
    barcode4.decode();
    cout << "................................................................"
         << "..........." << endl;
    // test case 5: illegal symbol barcode
    cout << ">>> [TEST CASE 5] symbol barcode: " << barcodeSymbol << endl;
    Postnet barcode5(barcodeSymbol);
    barcode5.decode();
    cout << "................................................................"
         << "..........." << endl;
    // test case 6: illegal ones barcode
    cout << ">>> [TEST CASE 6] ones barcode: "
         << barcodeOnesAbundance << endl;
    Postnet barcode6(barcodeOnesAbundance);
    barcode6.decode();
    cout << "................................................................"
         << "..........." << endl;
    // test case 7: illegal zeroes barcode
    cout << ">>> [TEST CASE ] zeroes barcode: "
         << barcodeZeroesAbundance << endl;
    Postnet barcode7(barcodeZeroesAbundance);
    barcode7.decode();
    cout << "................................................................"
         << "..........." << endl;

    //instantiate zip code object
    //Postnet zipCodePostnet(zipCode);
    //zipCode.encode(); // code not yet in existence

    return 0;
}


// class definitions
/**
 * @brief Constructor for zip code input
 *
 * @param zipCodeInteger from user
 * @return nothing
 *
 */
Postnet::Postnet(int zipCodeInteger)
{
    // this constructor is currently undergoing development/is useless
    cout << "zipCodeInteger constructor" << endl;
}

/**
 * @brief Constructor for barcode input
 *
 * @param rawBarcodeString from user
 * @return nothing
 *
 */
Postnet::Postnet(string rawBarcodeString)
{
    // variable
    bool okay; // tracking barcode validity
    okay = true;
    
    // check validity of barcode
    okay = checkBarcode(rawBarcodeString);
    
    if (okay == false)
    {
       error();
    }
    else
    {
        // strip padding and set as internal string representation of zip code
        strippedBarcode = strip(rawBarcodeString);

        // split into segments of five digits each
        segmentalize();
    }
}

/**
 * @brief This function decodes a barcode into a zip code
 *
 * @param nothing
 * @return nothing
 *
 */
void Postnet::decode()
{
    // flatten each segment of stripped barcode to integer and store in array
    zipDigits[0] = flatten(seg1);
    zipDigits[1] = flatten(seg2);
    zipDigits[2] = flatten(seg3);
    zipDigits[3] = flatten(seg4);
    zipDigits[4] = flatten(seg5);

    // convert array into integer by placing digits in correct position
    decodedZipCode = 10000 * zipDigits[0] // first digit in ten thousands pos.
                    + 1000 * zipDigits[1] // second digit in thousands pos.
                    + 100 * zipDigits[2] // third digit in hundreds position
                    + 10 * zipDigits[3] // fourth digit in tens position
                    + zipDigits[4]; // fifth digit in ones positions

    cout << "Zip code: " << decodedZipCode << endl;
}

 /**
 * @brief This function encodes a zip code into a barcode
 *
 * @param nothing
 * @return nothing
 *
 */
/*
void Postnet::encode()
{
    // add padding ones to front and end of string

}
*/
/**
 * @brief This function verifies that the barcode input is valid
 *
 * @param rawBarcodeString from user
 * @return a boolean: true for valid, false for invalid
 *
 */
bool Postnet::checkBarcode(string rawBarcodeString)
{
    // variable
    unsigned int barcodeLength; // length of barcode
    barcodeLength = 27;
    bool notAllInts; // tracks if string contains all numbers or not
    notAllInts = false;
    bool goodDigits; // tracks if string contains proper numbers or not
    goodDigits = false;
    
    // check string content
    notAllInts = hasAlpha(rawBarcodeString);
    goodDigits = checkDigitLegality(rawBarcodeString);

    // check for length and content errors
    if (rawBarcodeString.length() != barcodeLength)
    {
        return false; // string is too long/short
    }
    else if (notAllInts)
    {
        return false; // string contains non-numeric characters
    }
    else if (!goodDigits)
    {
        return false; // string contains incorrect numbers
    }
    else
    {
        return true; // string is legal and can be further processed
    }
}

/**
 * @brief This function verifies that the zip code input is valid
 *
 * @param nothing
 * @return nothing
 *
 */
/*void Postnet::checkZipCode()
{

}
*/

/**
 * @brief This function checks for any non-integer values in a string
 *
 * @param rawBarcodeString is user input
 * @return alpha - true if contains non-integer
 *
 */
bool Postnet::hasAlpha(string rawBarcodeString)
{
    bool alpha; // true if string contains non-integer
    alpha = false;
    
    for (int i = 0; i < 27; i++)
    {
        if (!isdigit(rawBarcodeString[i]))
        {
            alpha = true;
        }
        else
        {
            alpha = false;
        }
    }
    
    return alpha;
}

/**
 * @brief This function checks for the proper presence of ones and zeroes.
 *
 * @param rawBarcodeString is user input
 * @return isLegal - true if numerical content is legal
 *
 */
bool Postnet::checkDigitLegality(string rawBarcodeString)
{
    // variable
    bool isLegal; // is true if string contains exactly two ones/five digits
    isLegal = false;
    char one; // holds character/ASCII value of one
    one = '1';
    char zero; // holds character/ASCII value of zero
    zero = '0';
    int numOnes; // tracks number of ones
    numOnes = 0;
    int numZeroes; // tracks number of zeroes
    numZeroes = 0;

    // check first block of five digits for ones and zeroes
    for (int i = 1; i < 6; i++)
    {
        // count ones and zeroes; if digit is not one or zero, return false
        if (rawBarcodeString[i] == one)
        {
            numOnes++;
        }
        else if (rawBarcodeString[i] == zero)
        {
            numZeroes++;
        }
        else
        {
            return isLegal; // anything other than a one or zero is illegal
        }
    }
    
    // continue to next section of five digits if this one is legal
    if (numOnes == 2 && numZeroes == 3)
    {
        // reset counters for one and zero
        numOnes = 0;
        numZeroes = 0;
    }
    else
    {
        return isLegal; // illegal number of ones or zeroes
    }
    
    // check second block of five digits for ones and zeroes
    for (int i = 6; i < 11; i++)
    {
        // count ones and zeroes; if digit is not one or zero, return false
        if (rawBarcodeString[i] == one)
        {
            numOnes++;
        }
        else if (rawBarcodeString[i] == zero)
        {
            numZeroes++;
        }
        else
        {
            return isLegal; // anything other than a one or zero is illegal
        }
    }
    
    // continue to next section of five digits if this one is legal
    if (numOnes == 2 && numZeroes == 3)
    {
        // reset counters for one and zero
        numOnes = 0;
        numZeroes = 0;
    }
    else
    {
        return isLegal; // illegal number of ones or zeroes
    }
    
    // check third block of five digits for ones and zeroes
    for (int i = 11; i < 16; i++)
    {
        // count ones and zeroes; if digit is not one or zero, return false
        if (rawBarcodeString[i] == one)
        {
            numOnes++;
        }
        else if (rawBarcodeString[i] == zero)
        {
            numZeroes++;
        }
        else
        {
            return isLegal; // anything other than a one or zero is illegal
        }
    }
    
    // continue to next section of five digits if this one is legal
    if (numOnes == 2 && numZeroes == 3)
    {
        // reset counters for one and zero
        numOnes = 0;
        numZeroes = 0;
    }
    else
    {
        return isLegal; // illegal number of ones or zeroes
    }

    // check fourth block of five digits for ones and zeroes
    for (int i = 16; i < 21; i++)
    {
        // count ones and zeroes; if digit is not one or zero, return false
        if (rawBarcodeString[i] == one)
        {
            numOnes++;
        }
        else if (rawBarcodeString[i] == zero)
        {
            numZeroes++;
        }
        else
        {
            return isLegal; // anything other than a one or zero is illegal
        }
    }
    
    // continue to next section of five digits if this one is legal
    if (numOnes == 2 && numZeroes == 3)
    {
        // reset counters for one and zero
        numOnes = 0;
        numZeroes = 0;
    }
    else
    {
        return isLegal; // illegal number of ones or zeroes
    }

    // check last block of five digits for ones and zeroes
    for (int i = 21; i < 26; i++)
    {
        // count ones and zeroes; if digit is not one or zero, return false
        if (rawBarcodeString[i] == one)
        {
            numOnes++;
        }
        else if (rawBarcodeString[i] == zero)
        {
            numZeroes++;
        }
        else
        {
            return isLegal; // anything other than a one or zero is illegal
        }
    }
    
    // continue to next section of five digits if this one is legal
    if (numOnes == 2 && numZeroes == 3)
    {
        // reset counters for one and zero, return legal = true
        numOnes = 0;
        numZeroes = 0;
        isLegal = true;
        return isLegal;
    }
    else
    {
        return isLegal; // illegal number of ones or zeroes
    }
}

/**
 * @brief This function prints an error message for invalid barcodes
 *
 * @param nothing
 * @return nothing
 *
 */
void Postnet::error()
{
    cout << "The barcode entered is invalid. "
         << "Zip code generated is invalid as a result." << endl;
}

/**
 * @brief This function removes the ones at the start and end of the barcode
 *
 * @param rawBarcodeString is the barcode string entered by the user
 * @return strippedString is the string without the first and last one
 *
 */
string Postnet::strip(string rawBarcodeString)
{
    // variables
    string strippedString; // string to be manipulated and returned
    strippedString = rawBarcodeString; // copy raw string to manip string

    // delete padding ones from each end of string
    strippedString.erase(26,1); // delete last digit of raw string
    strippedString.erase(0,1); // delete first digit of raw string

    return strippedString; // string is now 25 characters long
}

/**
 * @brief This function breaks the stripped barcode into 5 segments
 *
 * @param nothing
 * @return nothing
 *
 */
void Postnet::segmentalize()
{
    // split the stripped barcode string into segments of 5
    seg1 = strippedBarcode.substr(0,5); // numbers 0-4 of stripped barcode
    seg2 = strippedBarcode.substr(5,5); // numbers 5-9 of stripped barcode
    seg3 = strippedBarcode.substr(10,5); // numbers 10-14 of stripped barcode
    seg4 = strippedBarcode.substr(15,5); // numbers 15-19 of stripped barcode
    seg5 = strippedBarcode.substr(20,5); // numbers 20-24 of stripped barcode
}

/**
 * @brief This function returns the number form of a barcode segment
 *
 * @param segment is a 5-character string to be translated
 * @return flattenedDigitSum is an int with the numerical value of a segment
 *
 */
int Postnet::flatten(string segment)
{
    // variables
    int flattenedDigitSum; // sum of multiplied segment parts
    flattenedDigitSum = 0;
    int charToIntHolder; // for char > ASCII > int conversion
    charToIntHolder= 0;
    int key[5] = {7, 4, 2, 1, 0}; // digit value mappings

    // flatten all segments and add running total to flattenedDigit
    for (int i = 0; i < 5; i++)
    {
        charToIntHolder = segment[i] - 48; // -48 to convert from ASCII to int
        flattenedDigitSum += charToIntHolder * key[i];
    }

    // check for sum of 11; convert to 0
    if (flattenedDigitSum == 11)
    {
        flattenedDigitSum = 0;
    }

    return flattenedDigitSum;
}