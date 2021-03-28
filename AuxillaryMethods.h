#ifndef AUXILARYMETHODS_H_INCLUDED
#define AUXILARYMETHODS_H_INCLUDED

#include <iostream>
#include <algorithm>
#include <sstream>
#include <conio.h>
#include <math.h>

using namespace std;

class AuxillaryMethods
{
public:
    static string getInputLine();
    static char getInputChar();
    static string changeFirstLetterToCapitalRestToLowercasse( string text );
    static float roundToCorrectCashValue( float value );

    template <typename T>
    static string conversionToString(T number)
    {
        ostringstream ss;
        ss << number;
        return ss.str();
    }
};

#endif // AUXILARYMETHODS_H_INCLUDED
