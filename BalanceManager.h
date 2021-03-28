#ifndef BALANCEMANAGER_H_INCLUDED
#define BALANCEMANAGER_H_INCLUDED

#include "CashFlowFile.h"
//#include "DateManager.h"

class BalanceManager
{
    CashFlowFile* file;
    DateManager dateManager;
    vector<CashFlow> incomes;
    vector<CashFlow> expenses;
    float sumOfIncomes;
    float sumOfExpenses;

    vector<CashFlow> findIncomesFromPeriod( year_month_day earliestDate, year_month_day latestDate );
    vector<CashFlow> findExpensesFromPeriod( year_month_day earliestDate, year_month_day latestDate );
    static bool sortCashFlows ( const CashFlow& element_1, const CashFlow& element_2 );
    void displayIncomes( vector<CashFlow>& incomesFromSelectedPeriod ) const;
    void displayExpenses( vector<CashFlow>& expensesFromSelectedPeriod ) const;
    void displaySummary() const;
    year_month_day setCorrectLatestDate( year_month_day earliestDate );

public:
    BalanceManager( string incomeFileName, string expenseFileName, int loggedUserId );
    ~BalanceManager();

    void addNewIncome( CashFlow income );
    void addNewExpense( CashFlow expense );
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySelectedMonthBalance();
};

#endif // BALANCEMANAGER_H_INCLUDED
