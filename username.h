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
    void setUsername(const QString&);
    QString getUsername() const;
};

#endif // USERNAME_H
