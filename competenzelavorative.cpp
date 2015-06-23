#include "competenzelavorative.h"

CompetenzeLavorative::CompetenzeLavorative() {}

CompetenzeLavorative::CompetenzeLavorative(const vector<Lavoro> & vl){
    esperienze=vl;
}

CompetenzeLavorative::CompetenzeLavorative(const Lavoro& l){
    AggiungiLavoro(l);
}

void CompetenzeLavorative::AggiungiLavoro(const Lavoro& l){
    esperienze.push_back(l);
}

void CompetenzeLavorative::removeLavoro(const Lavoro &l){
    int size=esperienze.size();
    bool trovato=false;
    for(int i=0;i<size && trovato==false;i++){
        if(esperienze[i]==l)
        {
            esperienze.erase(esperienze.begin()+i);
            trovato==true;
        }
    }
}

vector<Lavoro> CompetenzeLavorative::getEsperienze() const{
    return esperienze;
}

void CompetenzeLavorative::editEsperienze(const Lavoro & temp, const Lavoro & l){
    int size=esperienze.size();
    bool trovato=false;
    for(int i=0;i<size && trovato==false;i++){
        if(esperienze[i]==temp)
        {
            esperienze[i]=l;
            trovato==true;
        }
    }
}
