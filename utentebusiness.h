#ifndef UTENTEBUSINESS_H
#define UTENTEBUSINESS_H

#include"utentebasic.h"


class UtenteBusiness: public UtenteBasic
{
public:
    UtenteBusiness(const QString&);
    UtenteBusiness(const QString &, const Profilo&, const Rete&);
    virtual map<QString,Utente*> find(const InfoSearch&, map<QString,Utente*>*);
    ~UtenteBusiness();
};


#endif // UTENTEBUSINESS_H
