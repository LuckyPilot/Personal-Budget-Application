#include "UserManager.h"

UserManager::UserManager( string fileName )
    :file(fileName)
{
    loggedUserId = 0;
    file.loadUsersFromFile( &users );
}

int UserManager::getLoggedInUserId() const
{
    return loggedUserId;
}

void UserManager::registerNewUser()
{
    User newUser = enterNewUserData();
    users.push_back(newUser);
    file.addNewUser(newUser);
}

User UserManager::enterNewUserData()
{
    User newUser;

    newUser.setUserId( findNewUserId() );
    cout << "Insert your name:";
    newUser.setName( AuxillaryMethods::changeFirstLetterToCapitalRestToLowercasse( AuxillaryMethods::getInputLine() ) );
    cout << "Insert your surname:";
    newUser.setSurname( AuxillaryMethods::changeFirstLetterToCapitalRestToLowercasse( AuxillaryMethods::getInputLine() ) );

    do
    {
        cout << "Insert your login:";
        newUser.setLogin( AuxillaryMethods::getInputLine() );
    }while (isLoginExist( newUser.getLogin() ));

    cout << "Insert your password:";
    newUser.setPassword( AuxillaryMethods::getInputLine() );

    return newUser;
}

int UserManager::findNewUserId() const
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::isLoginExist( string newLogin ) const
{
    for (auto itr = users.begin(), endOfUsers = users.end(); itr != endOfUsers; ++itr)
    {
        if (newLogin == itr->getLogin())
        {
            cout << "Login's already exist please insert new login" << endl;
            return true;
        }
    }

    return false;
}

void UserManager::logInUser()
{
    string enteredLogin = "";

    cout << "Enter login: ";
    enteredLogin = AuxillaryMethods::getInputLine();

    for (auto itr = users.begin(), endOfUers = users.end(); itr != endOfUers; ++itr)
    {
        if (itr->getLogin() == enteredLogin)
        {
            if (checkUserPassword( itr->getPassword() ))
                loggedUserId = itr->getUserId();

            return;
        }
    }

    cout << "User with giving login doesn't exist!" << endl << endl;
    system("pause");
    loggedUserId = 0;
}

bool UserManager::checkUserPassword( string correctPassword ) const
{
    string enteredPassword = "";

    for (int attempts = 3; attempts > 0; attempts--)
    {
        cout << "Enter password. Left attempts: " << attempts << ": ";
        enteredPassword = AuxillaryMethods::getInputLine();
        if (enteredPassword == correctPassword)
        {
            cout << "Logging..." << endl;
            Sleep(1000);
            return true;
        }
        else
        {
            cout << "Incorrect Password!!!" << endl;
        }
    }

    cout << "You entered 3 times wrong password. Press any key to go back to main menu..." << endl;
    system("pause");
    return false;
}

void UserManager::logOutUser()
{
    loggedUserId = 0;
}

void UserManager::displayAllUsers()
{
    for (auto itr = users.begin(), endOfUsers = users.end(); itr != endOfUsers; ++itr)
    {
        cout << itr->getUserId() << endl;
        cout << itr->getName() << endl;
        cout << itr->getSurname() << endl;
        cout << itr->getLogin() << endl;
        cout << itr->getPassword() << endl;
    }
}

void UserManager::changeUserPassword()
{
    string newPassword = "";
    cout << "Enter new password: ";
    newPassword = AuxillaryMethods::getInputLine();

    for (auto itr = users.begin(), endOfUsers = users.end(); itr != endOfUsers; ++itr)
    {
        if (itr -> getUserId() == loggedUserId)
        {
            itr -> setPassword(newPassword);
            cout << "Password has changed." << endl << endl;
            system("pause");
        }
    }
    file.modifyUserPassword( newPassword, loggedUserId );
}
