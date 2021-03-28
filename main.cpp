#include <iostream>
#include "Budget.h"

int main()
{
    Budget PersonalBudger;

    while (true)
    {
        if (!PersonalBudger.isUserLoggedIn())
        {
            PersonalBudger.chooseOptionInMainMenu();

            switch (PersonalBudger.getChoice())
            {
            case '1':
                PersonalBudger.registerNewUser();
                break;
            case '2':
                PersonalBudger.logInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << "This option doesn't exist in menu... Press any key to make another choice." << endl;
                getch();
                break;
            }
        }
        else
        {
            PersonalBudger.chooseOptionFromUserMenu();

            switch (PersonalBudger.getChoice())
            {
            case '1':
                PersonalBudger.addNewIncome();
                break;
            case '2':
                PersonalBudger.addNewExpense();
                break;
            case '3':
                PersonalBudger.displayCurrentMonthBalance();
                getch();
                break;
            case '4':
                PersonalBudger.displayPreviousMonthBalance();
                getch();
                break;
            case '5':
                PersonalBudger.displaySelectedMonthBalance();
                getch();
                break;
            case '8':
                PersonalBudger.changeUserPassword();
                break;
            case '9':
                PersonalBudger.logOutUser();
                break;
            default:
                cout << "This option doesn't exist in menu... Press any key to make another choice." << endl;
                getch();
                break;
            }
        }
    }

    return 0;
}
