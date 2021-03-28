#include "CashFlowManager.h"

CashFlowManager::CashFlowManager( string incomeFileName, string expenseFileName, int loggedUserId )
    : INCOME_FILE_NAME( incomeFileName ), EXPENSE_FILE_NAME( expenseFileName ), LOGGED_USER_ID( loggedUserId )
{
    balanceManager = NULL;
    file = NULL;
}

CashFlowManager::~CashFlowManager()
{
    delete file;
    delete balanceManager;
    file = NULL;
    balanceManager = NULL;
}

void CashFlowManager::addNewIncome()
{
    char userInput;
    file = new CashFlowFile( INCOME_FILE_NAME );

    while (true)
    {
        findNewCashFlowData();
        file->addNewCashFlow( cashFlow );
        if (balanceManager != NULL)
            balanceManager->addNewIncome( cashFlow );
        cout << "Press y to make another transaction or any key to go back to user menu:";
        userInput = getch();
        cout << userInput << endl;

        if (userInput != 'y' && userInput != 'Y')
            break;
    }

    delete file;
    file = NULL;

}

void CashFlowManager::addNewExpense()
{
    char userInput;
    file = new CashFlowFile( EXPENSE_FILE_NAME );

    while (true)
    {
        findNewCashFlowData();
        cashFlow.setNegativeValue();
        file->addNewCashFlow( cashFlow );
        if (balanceManager != NULL)
            balanceManager->addNewExpense( cashFlow );
        cout << "Press y to make another transaction or any key to go back to user menu:";
        userInput = AuxillaryMethods::getInputChar();

        if (userInput != 'y' && userInput != 'Y')
            break;
    }

    delete file;
    file = NULL;
}

void CashFlowManager::findNewCashFlowData()
{
    char userInput;

    system("cls");
    cout << ">>>  ADDING NEW CASH TRANSACTION  <<<" << endl;
    cout << "Press y to select transaction date or any key to add transaction with present date:";
    userInput = AuxillaryMethods::getInputChar();

    if (userInput == 'y' || userInput == 'Y')
        cashFlow.setDate();
    else
        cashFlow.setPresentDate();

    cashFlow.setId( file->getLastIdFromFile() + 1 );
    cashFlow.setUserId( LOGGED_USER_ID );
    cashFlow.setDescription();
    cashFlow.setValue();
}

void CashFlowManager::displayCurrentMonthBalance()
{
    if (balanceManager == NULL)
        balanceManager = new BalanceManager( INCOME_FILE_NAME, EXPENSE_FILE_NAME, LOGGED_USER_ID );

    balanceManager->displayCurrentMonthBalance();
}

void CashFlowManager::displayPreviousMonthBalance()
{
    if (balanceManager == NULL)
        balanceManager = new BalanceManager( INCOME_FILE_NAME, EXPENSE_FILE_NAME, LOGGED_USER_ID );

    balanceManager->displayPreviousMonthBalance();
}

void CashFlowManager::displaySelectedMonthBalance()
{
    if (balanceManager == NULL)
        balanceManager = new BalanceManager( INCOME_FILE_NAME, EXPENSE_FILE_NAME, LOGGED_USER_ID );

    balanceManager->displaySelectedMonthBalance();
}
