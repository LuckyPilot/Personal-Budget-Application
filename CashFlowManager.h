#ifndef CASHFLOWMANAGER_H_INCLUDED
#define CASHFLOWMANAGER_H_INCLUDED

#include "BalanceManager.h"
#include "AuxillaryMethods.h"

class CashFlowManager
{
    CashFlow cashFlow;
    CashFlowFile* file;
    BalanceManager* balanceManager;
    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;
    const int LOGGED_USER_ID;

    void findNewCashFlowData();

public:
    CashFlowManager( string incomeFileName, string expenseFileName, int loggedUserId  );
    ~CashFlowManager();
    void addNewIncome();
    void addNewExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySelectedMonthBalance();
};

#endif // CASHFLOWMANAGER_H_INCLUDED
