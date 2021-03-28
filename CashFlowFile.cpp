#include "CashFlowFile.h"

CashFlowFile::CashFlowFile( string fileName )
    : XMLFile(fileName)
{
    lastIdInFile = fetchLastIdFromFile();
}

int CashFlowFile::getLastIdFromFile() const
{
    return lastIdInFile;
}

void CashFlowFile::addNewCashFlow( CashFlow newCashFlow )
{
    lastIdInFile++;

    xmlFile.ResetPos();
    xmlFile.FindElem();
    xmlFile.IntoElem();

    xmlFile.AddElem("CashFlow");
    xmlFile.AddChildElem("UserId", newCashFlow.getUserId());
    xmlFile.AddChildElem("Id", newCashFlow.getId());
    xmlFile.AddChildElem("Date", newCashFlow.getStringDate());
    xmlFile.AddChildElem("Decription", newCashFlow.getDescription());
    xmlFile.AddChildElem("Value", newCashFlow.getValue());
    xmlFile.OutOfElem();

    cout << "Transaction was added successfully." << endl;

    xmlFile.Save(FILE_NAME);
}

int CashFlowFile::fetchLastIdFromFile()
{
    int lastId = 0;

    xmlFile.ResetPos();
    xmlFile.FindElem();
    xmlFile.IntoElem();

    while (xmlFile.FindElem("CashFlow"))
    {}

    xmlFile.FindChildElem("Id");

    if ( xmlFile.GetChildData() != "" )
        lastId = stoi( xmlFile.GetChildData() );

    return lastId;
}

void CashFlowFile::loadCashFlows( vector<CashFlow>* cashFlows, int loggedUserId )
{
    xmlFile.ResetMainPos();

    while (xmlFile.FindElem("CashFlow"))
    {
        xmlFile.FindChildElem();

        if ( stoi( xmlFile.GetChildData() ) == loggedUserId)
            cashFlows->push_back( loadSingleCashFlow( loggedUserId ) );
    }
}

CashFlow CashFlowFile::loadSingleCashFlow( int loggedUserId )
{
    CashFlow singleCashFlow;

    singleCashFlow.setUserId( stoi( xmlFile.GetChildData() ) );
    xmlFile.FindChildElem();
    singleCashFlow.setId( stoi( xmlFile.GetChildData() ) );
    xmlFile.FindChildElem();
    singleCashFlow.setDate( xmlFile.GetChildData() );
    xmlFile.FindChildElem();
    singleCashFlow.setDescription( xmlFile.GetChildData() );
    xmlFile.FindChildElem();
    singleCashFlow.setValue( stof( xmlFile.GetChildData() ) );

    return singleCashFlow;
}
