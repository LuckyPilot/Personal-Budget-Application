#include "CashFlow.h"

CashFlow::CashFlow()
{
    id = 0; userId = 0; value = 0;
    description = "";
}

int CashFlow::getId() const
{
    return id;
}

int CashFlow::getUserId() const
{
    return userId;
}
string CashFlow::getStringValue() const
{
    return AuxillaryMethods::conversionToString( value );
}

float CashFlow::getValue() const
{
    return value;
}

string CashFlow::getDescription() const
{
    return description;
}

string CashFlow::getStringDate() const
{
    return date.getStringDate();
}

year_month_day CashFlow::getDate() const
{
    return date.getDate();
}

void CashFlow::setId( int id )
{
    this->id = id;
}

void CashFlow::setUserId( int userId )
{
    this->userId = userId;
}

void CashFlow::setDate()
{
    date.setDate();
}

void CashFlow::setDate( string date )
{
    this->date.setDate( date );
}

void CashFlow::setPresentDate()
{
    date.setPresentDate();
}

void CashFlow::setDescription( string description )
{
    this->description = description;
}

void CashFlow::setDescription()
{
    cout << "Enter transaction's description:";
    this->description = AuxillaryMethods::getInputLine();
}

void CashFlow::setValue( float value )
{
    this->value = value;
}

void CashFlow::setNegativeValue()
{
    this->value = -value;
}

void CashFlow::setValue()
{
    string userInput;
    while (true)
    {
        cout << "Enter value (e.g. 126,25):";
        userInput = AuxillaryMethods::getInputLine();

        if (isValueDecimalDigit( userInput ))
        {
            userInput = changeDecimalToDot( userInput );
            value = stof(userInput);
            value = AuxillaryMethods::roundToCorrectCashValue( value );
            break;
        }
        else
            cout << "Value has to be decimal number. Please enter correct value!!!" << endl;
        }
}

bool CashFlow::isValueDecimalDigit( string userInput ) const
{
    if (userInput.length() == 0)
        return false;
    else
    {
        for (unsigned int i = 0, endOfString = userInput.length(); i < endOfString ; i++)
        {
            if (!isdigit( userInput[i] ) && userInput[i] != '.' && userInput[i] != ',')
                return false;
        }
    }
    return true;
}

string CashFlow::changeDecimalToDot( string userInput ) const
{
    for (unsigned int i = 0, endOfString = userInput.length(); i < endOfString ; i++)
    {
        if (userInput[i] == ',')
            userInput[i] = '.';
    }

    return userInput;
}
