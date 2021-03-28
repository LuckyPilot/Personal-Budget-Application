#ifndef INCOMEFILE_H_INCLUDED
#define INCOMEFILE_H_INCLUDED

#include "CashFlowFile.h"

class IncomeFile : public CashFlowFile
{
public:
    IncomeFile( string fileName );
    void addNewCashFlow() override;

};

#endif // INCOMEFILE_H_INCLUDED
