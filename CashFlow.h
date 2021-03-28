#ifndef CASHFLOW_H_INCLUDED
#define CASHFLOW_H_INCLUDED

#include "DateManager.h"

class CashFlow
{
public:  // only for test
    int id, userId;
    float value;
    string description;
    DateManager date;

    bool isValueDecimalDigit( string userInput ) const;
    string changeDecimalToDot( string userInput ) const;

public:
    CashFlow();

    //setters
    void setId( int id );
    void setUserId( int userId );
    void setDate();
    void setDate( string date );
    void setPresentDate();
    void setValue();
    void setValue( float value );
    void setNegativeValue();
    void setDescription();
    void setDescription( string description );

    //getters
    int getId() const;
    int getUserId() const;
    string getStringValue() const;
    float getValue() const;
    string getDescription() const;
    string getStringDate() const;
    year_month_day getDate() const;
};

#endif // CASHFLOW_H_INCLUDED
