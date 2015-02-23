#ifndef UTENTE_H
#define UTENTE_H
#include"rete.h"
#include"profilo.h"

class Utente
{
private:
    Username login;
    Profilo info;
    Rete rete;
public:
    Utente();
    Utente(const Username&);
    Username getLogin() const;
    Profilo getInfo() const;
    Rete getRete() const;
    //virtual ~Utente();
    //virtual void find(const QString& =" ", const QString& =" " ) =0;
};


#endif // UTENTE_H
