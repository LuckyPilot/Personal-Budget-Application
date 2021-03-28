#ifndef USERFILE_H_INCLUDED
#define USERFILE_H_INCLUDED

#include "User.h"
#include "XMLFile.h"
#include "AuxillaryMethods.h"

class UserFile : public XMLFile
{
    User loadSingleUser();

public:
    UserFile( string fileName );
    void addNewUser( User newUser );
    void loadUsersFromFile( vector<User>* usersFromFile );
    void modifyUserPassword( string newPassword, int userId );
};

#endif // USERFILE_H_INCLUDED
