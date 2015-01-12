#ifndef UTENTE_H
#define UTENTE_H
#include"rete.h"
#include"profilo.h"

class Utente
{
private:
    QString login;
public:
    Utente(const Username&,const Profilo&);
    Profilo pf;
    Rete* rete;
    Username un;
    virtual ~Utente();
};

/*MEGA ONEROSA --> RICERCO SU TUTTO IL DATABASE, QUANDO ELIMINO UTENTE, CERCO SU TUTTE LE RETI
 * FOLLOWING FOLLOWER --> DUE RETI, UNA DOVE HO QUELLI CHE SEGUO E UNA DOVE HO QUELLI CHE MI SEGUONO, COSÌ SI VENGO ELIMINATO, HO LA LISTA DI TUTTI QUELLI CHE MI SEGUO E FACCIO PRESTO
 * ALLA FACEBOOK(CERY) --> AMICIZIE MUTUALI, IO TI SEGUO TU MI SEGUI, IO NON TI SEGUO PIU', TO MARE PUTANA
 *
 * LIST PER RETE
 *
 * COSA SALVARE NELL'XML, NON SI PUÒ SALVARE PUNTATORI
 * -O LOAD AL CARICAMENTO
 * -MI SALVO GLI USERNAME E CARICO SE SERVE
 *
 * LISTA PER COME SALVARE UTENTI (NO SMARTP) PROBABILMENTE LIST
 *
 * GERARCHIA DI CLASSI VERTICALI
 *
 *
 */

class UtenteBasic: public Utente {};
class UtenteBusiness: public UtenteBasic {};
class UtenteExecutive: public UtenteBusiness {};


/* DUBBI A RIGUARDO
class SmartUtente {
public:
    Utente* u; //puntatore polimorfo
};
*/

#endif // UTENTE_H
