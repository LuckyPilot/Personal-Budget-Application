#include "UserFile.h"

UserFile::UserFile( string fileName )
    : XMLFile(fileName)
{}

void UserFile::addNewUser( User newUser )
{
    xmlFile.AddElem("User");
    xmlFile.AddChildElem("UserId", newUser.getUserId());
    xmlFile.AddChildElem("Name", newUser.getName());
    xmlFile.AddChildElem("Surname", newUser.getSurname());
    xmlFile.AddChildElem("Login", newUser.getLogin());
    xmlFile.AddChildElem("Password", newUser.getPassword());

    xmlFile.Save(FILE_NAME);
}

void UserFile::loadUsersFromFile( vector<User>* usersFromFile )
{
    xmlFile.ResetMainPos();
    xmlFile.FindElem();
    xmlFile.IntoElem();

    while (xmlFile.FindElem("User"))
    {
        usersFromFile->push_back( loadSingleUser() );
    }
}

User UserFile::loadSingleUser()
{
    User user;

    xmlFile.FindChildElem();
    user.setUserId( xmlFile.GetChildData() );
    xmlFile.FindChildElem();
    user.setName( xmlFile.GetChildData() );
    xmlFile.FindChildElem();
    user.setSurname( xmlFile.GetChildData() );
    xmlFile.FindChildElem();
    user.setLogin( xmlFile.GetChildData() );
    xmlFile.FindChildElem();
    user.setPassword( xmlFile.GetChildData() );

    return user;
}

void UserFile::modifyUserPassword( string newPassword, int userId )
{
    xmlFile.ResetMainPos();

    while (xmlFile.FindElem("User"))
    {
        xmlFile.FindChildElem("UserId");
        if (xmlFile.GetChildData() == AuxillaryMethods::conversionToString<int>( userId ))
        {
            xmlFile.FindChildElem("Password");
            xmlFile.SetChildData(newPassword);
        }
    }

    xmlFile.Save(FILE_NAME);
}
