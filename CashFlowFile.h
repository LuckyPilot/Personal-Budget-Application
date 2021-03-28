#ifndef CASHFLOWFILE_H_INCLUDED
#define CASHFLOWFILE_H_INCLUDED

#include "XMLFile.h"
#include "CashFlow.h"

class CashFlowFile : public XMLFile
{
    int lastIdInFile;

    int fetchLastIdFromFile();
    CashFlow loadSingleCashFlow( int loggedUserId );

public:
    CashFlowFile( string fileName );

    //getters
    int getLastIdFromFile() const;

    void addNewCashFlow( CashFlow newCashFlow );
    void loadCashFlows( vector<CashFlow>* cashFlows, int loggedUserId );
};

#endif // CASHFLOWFILE_H_INCLUDED
