#ifndef UTENTE_H
#define UTENTE_H
#include"rete.h"
#include"profilo.h"

class Utente
{
public:
    Utente();
    Profilo pf;
    Rete* rete;
    Username un;
    Utente(Username);
    virtual ~Utente() {}
};

class UtenteBasic: public Utente {};
class UtenteBusiness: public Utente {};
class UtenteExecutive: public Utente {};


/* DUBBI A RIGUARDO
class SmartUtente {
public:
    Utente* u; //puntatore polimorfo
};
*/

#endif // UTENTE_H
