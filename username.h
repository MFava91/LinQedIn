#ifndef USERNAME_H
#define USERNAME_H

#include<iostream>
#include<QString>

class Username
{
private:
    QString login;
public:
    Username();
    Username(const QString&);
    Username ModificaUsername(const QString&);
    QString getUsername();
};

#endif // USERNAME_H
