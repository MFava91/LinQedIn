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
    Utente(const Username&, const Profilo&, const Rete&);
    Username getLogin() const;
    //vedere se è il caso di fare così o meno
    Profilo& getInfo();
    Rete getRete() const;
    //virtual ~Utente();
    //virtual void find(const QString& =" ", const QString& =" " ) =0;
};


#endif // UTENTE_H
