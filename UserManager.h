#ifndef USERMANAGER_H_INCLUDED
#define USERMANAGER_H_INCLUDED

#include <windows.h>
#include "User.h"
#include "UserFile.h"
#include "AuxillaryMethods.h"

class UserManager
{
    int loggedUserId;
    vector<User> users;
    UserFile file;

    User enterNewUserData();
    int findNewUserId() const;
    bool isLoginExist( string newLogin ) const;
    bool checkUserPassword( string correctPassword ) const;

public:
    UserManager( string fileName );

    //getters
    int getLoggedInUserId() const;

    void registerNewUser();
    void logInUser();
    void logOutUser();
    void changeUserPassword();
    void displayAllUsers();   // only auxillary function to remove after all
};

#endif // USERMANAGER_H_INCLUDED
