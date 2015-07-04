#ifndef UTENTEBASIC_H
#define UTENTEBASIC_H

#include"utente.h"
using std::map;

class UtenteBasic : public Utente
{
public:
    UtenteBasic(const QString&);
    UtenteBasic(const QString &, const Profilo&, const Rete&);
    map<QString,Utente*> find(const InfoSearch&,map<QString,Utente*>*);
    ~UtenteBasic();
};


#endif // UTENTEBASIC_H

