#ifndef PROFILO_H
#define PROFILO_H

#include"info.h"
#include"datianagrafici.h"
#include"titolistudio.h"
#include"competenzelavorative.h"

class Profilo
{
public:
    DatiAnagrafici datiPersonali;
    TitoliStudio studi;
    CompetenzeLavorative curriculum;
    //void modificaProfilo() {}
    //Info* visualizzaProfilo() const {return 0; }
};

#endif // PROFILO_H
