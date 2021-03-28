#include "DateManager.h"

DateManager::DateManager()
{
    date = year_month_day{ floor<days>(system_clock::now()) };
    presentYear = date.year();
    presentMonth = date.month();
}

string DateManager::getStringDate() const
{
    return AuxillaryMethods::conversionToString( date );
}

year_month_day DateManager::getDate() const
{
    return date;
}

year DateManager::getPresentYear() const
{
    return presentYear;
}

month DateManager::getPresentMonth() const
{
    return presentMonth;
}

void DateManager::setDate( string dateFromFile )
{
    isDateCorrect( dateFromFile );
}

void DateManager::setPresentDate()
{
    date = year_month_day{ floor<days>(system_clock::now()) };
}

void DateManager::setDate()
{
    string userInput;

    while (true)
    {
        cout << "Enter date (yyyy-mm-dd):";
        userInput = AuxillaryMethods::getInputLine();

        if (isDateFormatCorrect( userInput ))

            if (isDateCorrect( userInput ))

                if (isDatePeriodCorrect())
                    break;
                else
                    cout << "Date has to be between 2000/01/01 and last day of current month." << endl;
            else
                cout << "Entered date doesn't exist. Please enter correct date." << endl;
        else
            cout << "Incorrect date format, please enter only digits in format yyyy/mm/dd" << endl;
    }
}

bool DateManager::isDateFormatCorrect( string userInput ) const
{
    if (userInput.length() == 0)
        return false;
    else
    {
        for (unsigned int i = 0, endOfString = userInput.length(); i < endOfString ; i++)
        {
            if (!isdigit( userInput[i] ) && userInput[i] != '-')
                return false;
        }
    }
    return true;
}

bool DateManager::isDateCorrect( string userInput )
{
    int y,m,d;
    istringstream iss(userInput);

    getline(iss, userInput, '-' );
    y = stoi(userInput);
    getline(iss, userInput, '-' );
    m = stoi(userInput);
    getline(iss, userInput, '-' );
    d = stoi(userInput);

    date = year{y}/m/d;

    if (date.ok())
        return true;
    else
        return false;
}

bool DateManager::isDatePeriodCorrect() const
{
    auto earliestDate = 2000_y/01/01;
    auto latestDate = year{presentYear}/presentMonth/last;

    if (date >= earliestDate && date <= latestDate)
        return true;
    else
        return false;
}
