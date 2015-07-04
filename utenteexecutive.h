#ifndef UTENTEEXECUTIVE_H
#define UTENTEEXECUTIVE_H

#include"utentebusiness.h"

class UtenteExecutive: public UtenteBusiness
{
public:
    UtenteExecutive(const QString&);
    UtenteExecutive(const QString &, const Profilo&, const Rete&);
    virtual map<QString,Utente*> find(const InfoSearch&, map<QString,Utente*>*);
    ~UtenteExecutive();
};

#endif // UTENTEEXECUTIVE_H

