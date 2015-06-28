#include "profilo.h"

Profilo::Profilo(){
}

Profilo::Profilo(const DatiAnagrafici & d, const TitoliStudio & s, const CompetenzeLavorative & c, const QString& t)
    :datiPersonali(d),studi(s),curriculum(c),tipoAccount(t){}

DatiAnagrafici Profilo::getDati() const {
    return datiPersonali;
}

TitoliStudio Profilo::getStudi() const{
    return studi;
}

CompetenzeLavorative Profilo::getLavori() const{
    return curriculum;
}

QString Profilo::getTipoAccount() const{
    return tipoAccount;
}

void Profilo::setDatiPersonali(const DatiAnagrafici& dati){
    datiPersonali=dati;
}

void Profilo::setTitoliStudio(const TitoliStudio & scuole){
    studi=scuole;
}

void Profilo::setLaurea(const QString& temp,const QString& l){
    studi.modificaLaurea(temp,l);
}

void Profilo::setCurriculum(const Lavoro& temp, const Lavoro& lavoro){
    curriculum.editEsperienze(temp,lavoro);
}

void Profilo::setNomeDatiPersonali(const QString &n){
    datiPersonali.setNome(n);
}

void Profilo::setCognomeDatiPersonali(const QString &c){
    datiPersonali.setCognome(c);
}

void Profilo::setTipoAccount(const QString &t){
    tipoAccount = t;
}

void Profilo::wipeLaurea(const QString& laurea){
    studi.removeLaurea(laurea);
}

void Profilo::wiperLavoro(const Lavoro& lavoro){
    curriculum.removeLavoro(lavoro);
}

void Profilo::aggiungiLaurea(const QString& laurea){
    studi.AggiungiLaurea(laurea);
}

void Profilo::aggiungiLavoro(const Lavoro& lavoro){
    curriculum.AggiungiLavoro(lavoro);
}

