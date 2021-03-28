#include "Budget.h"

Budget::Budget( string usersFileName, string incomesFileName, string expensesFileName )
    :userManager(usersFileName), INCOME_FILE_NAME(incomesFileName), EXPENSE_FILE_NAME(expensesFileName)
{
    choice = '0';
    cashFlowManager = NULL;
}

Budget::~Budget()
{
    delete cashFlowManager;
    cashFlowManager = NULL;
}

char Budget::getChoice() const
{
    return choice;
}

void Budget::registerNewUser()
{
    userManager.registerNewUser();
}

void Budget::logInUser()
{
    userManager.logInUser();
    if (isUserLoggedIn())
    {
        cashFlowManager = new CashFlowManager( INCOME_FILE_NAME, EXPENSE_FILE_NAME, userManager.getLoggedInUserId() );
    }
}

void Budget::logOutUser()
{
    userManager.logOutUser();
    delete cashFlowManager;
    cashFlowManager = NULL;
}

bool Budget::isUserLoggedIn()
{
    if ( userManager.getLoggedInUserId() != 0 )
        return true;
    else
        return false;
}

void Budget::changeUserPassword()
{
    userManager.changeUserPassword();
}

void Budget::displayAllUsers()   // only auxillary function to remove after all
{
    userManager.displayAllUsers();
}

void Budget::chooseOptionInMainMenu()
{
    system("cls");
    cout << "    >>>  MAIN MENU  <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register" << endl;
    cout << "2. Log in" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxillaryMethods::getInputChar();
}

void Budget::chooseOptionFromUserMenu()
{
    system("cls");
    cout << " >>>  USER MENU  <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Display current month balance" << endl;
    cout << "4. Display previous month balance" << endl;
    cout << "5. Display selected period balance" << endl;
    cout << "---------------------------" << endl;
    cout << "8. Change password" << endl;
    cout << "9. Logout" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxillaryMethods::getInputChar();
}

void Budget::addNewIncome()
{
    cashFlowManager->addNewIncome();
}

void Budget::addNewExpense()
{
    cashFlowManager->addNewExpense();
}

void Budget::displayCurrentMonthBalance()
{
    cashFlowManager->displayCurrentMonthBalance();
}

void Budget::displayPreviousMonthBalance()
{
    cashFlowManager->displayPreviousMonthBalance();
}

void Budget::displaySelectedMonthBalance()
{
    cashFlowManager->displaySelectedMonthBalance();
}
