#include "profilo.h"

Profilo::Profilo(){
}

Profilo::Profilo(const DatiAnagrafici & d, const TitoliStudio & s, const CompetenzeLavorative & c)
    :datiPersonali(d),studi(s),curriculum(c){}

DatiAnagrafici Profilo::getDati() const {
    return datiPersonali;
}

TitoliStudio Profilo::getStudi() const{
    return studi;
}

CompetenzeLavorative Profilo::getLavori() const{
    return curriculum;
}

void Profilo::setDatiPersonali(const DatiAnagrafici& dati){
    datiPersonali=dati;
}

void Profilo::setTitoliStudio(const TitoliStudio & scuole){
    studi=scuole;
}

void Profilo::setCurriculum(const Lavoro& temp, const Lavoro& lavoro){
    curriculum.editEsperienze(temp,lavoro);
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
