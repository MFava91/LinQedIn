#ifndef USERNAME_H
#define USERNAME_H

#include<iostream>
using std::string;

class Username
{
private:
    string login;
public:
    Username(string);
    Username ModificaUsername(Username);
};

#endif // USERNAME_H
