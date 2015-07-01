#ifndef UTENTE_H
#define UTENTE_H
#include<map>
#include"rete.h"
#include"profilo.h"

using std::map;

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
    virtual map<QString,Utente*> findUsername(const QString& ="") =0;
    virtual ~Utente();
};


#endif // UTENTE_H
