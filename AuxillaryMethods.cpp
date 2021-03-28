#include "AuxillaryMethods.h"

string AuxillaryMethods::getInputLine()
{
    string userInput = "";
    getline(cin, userInput);
    return userInput;
}

char AuxillaryMethods::getInputChar()
{
    string userInput = "";
    char userChar  = {0};

    while (true)
    {
        getline(cin, userInput);

        if (userInput.length() == 1)
        {
            userChar = userInput[0];
            break;
        }
        cout << "This is not a single char. Enter single char:" << endl;
    }
    return userChar;
}

string AuxillaryMethods::changeFirstLetterToCapitalRestToLowercasse( string text )
{
    if (!text.empty())
    {
        transform( text.begin(), text.end(), text.begin(), ::tolower );
        text[0] = toupper(text[0]);
    }
    return text;
}

float AuxillaryMethods::roundToCorrectCashValue( float value )
{
    return round(value*100)/100;
}
