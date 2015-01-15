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

vector<Lavoro> CompetenzeLavorative::getEsperienze() const{
    return esperienze;
}
