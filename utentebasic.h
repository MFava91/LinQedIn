#ifndef UTENTEBASIC_H
#define UTENTEBASIC_H

#include"utente.h"

class UtenteBasic: public Utente
{
public:
    UtenteBasic(const QString&);
    UtenteBasic(const QString &, const Profilo&, const Rete&);
    virtual map<QString,Utente*> findUsername(const QString&);
    ~UtenteBasic();
};


#endif // UTENTEBASIC_H

