#include "BalanceManager.h"

BalanceManager::BalanceManager( string incomeFileName, string expenseFileName, int loggedUserId )
{
    sumOfIncomes = 0;
    sumOfExpenses = 0;
    file = new CashFlowFile(incomeFileName);
    file->loadCashFlows( &incomes, loggedUserId );
    delete file;
    file = new CashFlowFile( expenseFileName );
    file->loadCashFlows( &expenses, loggedUserId );
    delete file;
    file = NULL;
}

BalanceManager::~BalanceManager()
{
    delete file;
    file = NULL;
}

void BalanceManager::addNewIncome( CashFlow income )
{
    incomes.push_back( income );
}

void BalanceManager::addNewExpense( CashFlow expense )
{
    expenses.push_back( expense);
}

void BalanceManager::displayCurrentMonthBalance()
{
    year_month_day earliestDate = year{dateManager.getPresentYear()}/dateManager.getPresentMonth()/01;
    year_month_day latestDate = year{dateManager.getPresentYear()}/dateManager.getPresentMonth()/last;
    vector<CashFlow> currentMonthIncomes = findIncomesFromPeriod( earliestDate, latestDate );
    vector<CashFlow> currentMonthExpenes = findExpensesFromPeriod( earliestDate, latestDate );
    sort( currentMonthIncomes.begin(), currentMonthIncomes.end(), sortCashFlows );
    sort( currentMonthExpenes.begin(), currentMonthExpenes.end(), sortCashFlows );

    system("cls");
    cout << "   >>> BALANCE FROM PERIOD FROM: " << earliestDate << " TO: " << latestDate << " <<<" << endl << endl;
    displayIncomes( currentMonthIncomes );
    displayExpenses( currentMonthExpenes );
    displaySummary();

    sumOfIncomes = 0;
    sumOfExpenses = 0;
}

vector<CashFlow> BalanceManager::findIncomesFromPeriod( year_month_day earliestDate, year_month_day latestDate )
{
    vector<CashFlow> selectedPeriodIncomes;

    for (auto itr = incomes.begin(), endOfIncomes = incomes.end(); itr != endOfIncomes; ++itr)
    {
        if (itr->getDate() >= earliestDate && itr->getDate() <=latestDate)
        {
            sumOfIncomes += itr->getValue();
            selectedPeriodIncomes.push_back(*itr);
        }
    }

    return selectedPeriodIncomes;
}

vector<CashFlow> BalanceManager::findExpensesFromPeriod( year_month_day earliestDate, year_month_day latestDate )
{
    vector<CashFlow> selectedPeriodExpenses;

    for (auto itr = expenses.begin(), endOfExpenses = expenses.end(); itr != endOfExpenses; ++itr)
    {
        if (itr->getDate() >= earliestDate && itr->getDate() <=latestDate)
        {
            sumOfExpenses += itr->getValue();
            selectedPeriodExpenses.push_back(*itr);
        }
    }

    return selectedPeriodExpenses;
}

bool BalanceManager::sortCashFlows( const CashFlow& element_1, const CashFlow& element_2 )
{
     return (element_1.getDate() < element_2.getDate());
}

void BalanceManager::displayIncomes( vector<CashFlow>& incomesFromSelectedPeriod ) const
{
    cout << "   >>> YOUR INCOMES <<<" << endl;

    if (incomesFromSelectedPeriod.size() == 0)
        cout << "You don't have any incomes from selected period." << endl;

    for (auto itr = incomesFromSelectedPeriod.begin(), endOfIncomes = incomesFromSelectedPeriod.end(); itr != endOfIncomes; ++itr)
    {
        cout << endl << "Transaction ID: " << itr->getId() << endl;
        cout << "Date: " << itr->getDate() << endl;
        cout << "Value: " << itr->getValue() << endl;
        cout << "Description: " << itr->getDescription() << endl << endl;
    }
}

void BalanceManager::displayExpenses( vector<CashFlow>& expensesFromSelectedPeriod ) const
{
    cout << "   >>> YOUR EXPENSES <<<" << endl;

    if (expensesFromSelectedPeriod.size() == 0)
        cout << "You don't have any expenses from selected period." << endl;

    for (auto itr = expensesFromSelectedPeriod.begin(), endOfExpenses = expensesFromSelectedPeriod.end(); itr != endOfExpenses; ++itr)
    {
        cout << endl << "Transaction ID: " << itr->getId() << endl;
        cout << "Date: " << itr->getDate() << endl;
        cout << "Value: " << itr->getValue() << endl;
        cout << "Description: " << itr->getDescription() << endl << endl;
    }
}

void BalanceManager::displaySummary() const
{
    cout << "   >>> SUM OF INCOMES = " << sumOfIncomes << " <<<" << endl;
    cout << "   >>> SUM OF EXPENSES = " << sumOfExpenses << " <<<" <<endl;
    cout << "   >>> SALDO = " << sumOfIncomes + sumOfExpenses << " <<<" << endl;
}

void BalanceManager::displayPreviousMonthBalance()
{
    year_month_day earliestDate = year{dateManager.getPresentYear()}/(dateManager.getPresentMonth() - months{1})/01;
    year_month_day latestDate = year{dateManager.getPresentYear()}/(dateManager.getPresentMonth() - months{1})/last;
    vector<CashFlow> previousMonthIncomes = findIncomesFromPeriod( earliestDate, latestDate );
    vector<CashFlow> previousMonthExpenes = findExpensesFromPeriod( earliestDate, latestDate );
    sort( previousMonthIncomes.begin(), previousMonthIncomes.end(), sortCashFlows );
    sort( previousMonthExpenes.begin(), previousMonthExpenes.end(), sortCashFlows );

    system("cls");
    cout << "   >>> BALANCE FROM PERIOD FROM: " << earliestDate << " TO: " << latestDate << " <<<" << endl << endl;
    displayIncomes( previousMonthIncomes );
    displayExpenses( previousMonthExpenes );
    displaySummary();

    sumOfIncomes = 0;
    sumOfExpenses = 0;
}

void BalanceManager::displaySelectedMonthBalance()
{
    dateManager.setDate();
    year_month_day earliestDate = dateManager.getDate();
    year_month_day latestDate = setCorrectLatestDate( earliestDate );

    vector<CashFlow> previousMonthIncomes = findIncomesFromPeriod( earliestDate, latestDate );
    vector<CashFlow> previousMonthExpenes = findExpensesFromPeriod( earliestDate, latestDate );
    sort( previousMonthIncomes.begin(), previousMonthIncomes.end(), sortCashFlows );
    sort( previousMonthExpenes.begin(), previousMonthExpenes.end(), sortCashFlows );

    system("cls");
    cout << "   >>> BALANCE FROM PERIOD FROM: " << earliestDate << " TO: " << latestDate << " <<<" << endl << endl;
    displayIncomes( previousMonthIncomes );
    displayExpenses( previousMonthExpenes );
    displaySummary();

    sumOfIncomes = 0;
    sumOfExpenses = 0;
}

year_month_day BalanceManager::setCorrectLatestDate( year_month_day earliestDate )
{
    while (true)
    {
        dateManager.setDate();
        if (earliestDate < dateManager.getDate())
        {
            return dateManager.getDate();
        }
        else
        {
            cout << "Second date has to be after first date!!! Please enter correct second date!!!" << endl;
        }
    }
}
