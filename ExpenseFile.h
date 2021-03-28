#ifndef EXPENSEFILE_H_INCLUDED
#define EXPENSEFILE_H_INCLUDED

#include "CashFlowFile.h"

class ExpenseFile : public CashFlowFile
{
public:
    ExpenseFile( string fileName );
    void addNewCashFlow() override;
};

#endif // EXPENSEFILE_H_INCLUDED
