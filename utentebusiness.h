#ifndef UTENTEBUSINESS_H
#define UTENTEBUSINESS_H

#include"utentebasic.h"


class UtenteBusiness: public UtenteBasic
{
public:
    UtenteBusiness(const QString&);
    UtenteBusiness(const QString &, const Profilo&, const Rete&);
    virtual map<QString,Utente*> findUsername(const QString&);
    ~UtenteBusiness();
};


#endif // UTENTEBUSINESS_H
