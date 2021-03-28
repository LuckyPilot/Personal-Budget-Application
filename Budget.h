#ifndef BUDGET_H_INCLUDED
#define BUDGET_H_INCLUDED

#include "UserManager.h"
#include "CashFlowManager.h"

class Budget
{
    char choice;
    UserManager userManager;
    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;
    CashFlowManager* cashFlowManager;

public:
    Budget( string usersFileName = "users.xml", string incomesFileName = "incomes.xml", string expensesFileName = "expenses.xml" );
    ~Budget();

    //getters
    char getChoice() const;

    void registerNewUser();
    void logInUser();
    void logOutUser();
    bool isUserLoggedIn();
    void changeUserPassword();
    void chooseOptionInMainMenu();
    void chooseOptionFromUserMenu();
    void addNewIncome();
    void addNewExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySelectedMonthBalance();
    void displayAllUsers();   // only auxillary function to remove after all
};

#endif // BUDGET_H_INCLUDED
