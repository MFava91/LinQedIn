#ifndef INFO_H
#define INFO_H


#include<iostream>
using std::string;

class Info
{
private:
    string nome,cognome,email;
public:
    Info(const string&,const string&,const string&);
    string getnome() const;
    string getcognome() const;
    string getemail() const;
};

#endif // INFO_H
