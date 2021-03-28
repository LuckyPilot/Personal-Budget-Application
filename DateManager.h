#ifndef DATEMANAGER_H_INCLUDED
#define DATEMANAGER_H_INCLUDED

#include <iostream>
#include "Date.h"
#include "AuxillaryMethods.h"

using namespace std;
using namespace date;
using namespace std::chrono;

class DateManager
{
    year_month_day date;
    year presentYear;
    month presentMonth;

    bool isDateFormatCorrect( string userInput ) const;   // function is checking correct user format of input (yyyy-mm-dd) and digits only
    bool isDateCorrect( string userInput ); // function is checking whether inserted day exist in calendar
    bool isDatePeriodCorrect() const;    // function is checking whether date is inside specified period ( 2000/01/01 and last day current month)

public:
    DateManager();

    //setters
    void setDate();
    void setDate( string dateFromFile );
    void setPresentDate();

    //getters
    string getStringDate() const;
    year_month_day getDate() const;
    year getPresentYear() const;
    month getPresentMonth() const;


};

#endif // DATEMANAGER_H_INCLUDED
