#include "profilo.h"

DatiAnagrafici Profilo::getDati() const {
    return datiPersonali;
}

TitoliStudio Profilo::getStudi() const{
    return studi;
}

CompetenzeLavorative Profilo::getLavori() const{
    return curriculum;
}

