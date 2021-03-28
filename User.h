#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <iostream>

using namespace std;

class User
{
    int userId;
    string login,password,name,surname;

public:
   User();

   //setters
   void setUserId( int userId );
   void setUserId( string userId );
   void setLogin( string login );
   void setPassword( string password );
   void setName( string name );
   void setSurname( string surname );

   //getters
   int getUserId() const;
   string getName() const;
   string getSurname() const;
   string getLogin() const;
   string getPassword() const;
};

#endif // USER_H_INCLUDED
