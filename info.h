#ifndef INFO_H
#define INFO_H


#include<iostream>
#include<QString>
using std::string;

class Info
{
private:
    QString nome,cognome,email;
    int telefono;
public:
    Info(const QString&,const QString&,const QString&,const int&);
    QString getnome() const;
    QString getcognome() const;
    QString getemail() const;
    int gettelefono() const;

};

#endif // INFO_H
