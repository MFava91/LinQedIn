#include "competenzelavorative.h"

CompetenzeLavorative::CompetenzeLavorative() {}

CompetenzeLavorative::CompetenzeLavorative(const Lavoro& l){
    AggiungiLavoro(l);
}

void CompetenzeLavorative::AggiungiLavoro(const Lavoro& l){
    esperienze.push_back(l);
}

