#include "User.h"

User::User()
{
    userId = 0;
    login = "";
    password = "";
    name = "";
    surname = "";
}

void User::setUserId( int userId )
{
    this->userId = userId ;
}

void User::setUserId( string userId )
{
    this->userId = stoi( userId );
}

void User::setLogin( string login )
{
    this->login = login;
}

void User::setPassword( string password )
{
    this->password = password;
}

void User::setName( string name )
{
    this->name = name;
}

void User::setSurname( string surname )
{
    this->surname = surname;
}

int User::getUserId() const
{
    return userId;
}

string User::getName() const
{
    return name;
}

string User::getSurname() const
{
    return surname;
}

string User::getLogin() const
{
    return login;
}

string User::getPassword() const
{
    return password;
}
