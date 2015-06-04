#ifndef PROFILO_H
#define PROFILO_H

#include"info.h"
#include"datianagrafici.h"
#include"titolistudio.h"
#include"competenzelavorative.h"

class Profilo
{
private:
    DatiAnagrafici datiPersonali;
    TitoliStudio studi;
    CompetenzeLavorative curriculum;
public:
    Profilo();
    Profilo(const DatiAnagrafici&, const TitoliStudio&, const CompetenzeLavorative&);
    DatiAnagrafici getDati() const;
    TitoliStudio getStudi() const;
    CompetenzeLavorative getLavori() const;
    //void modificaProfilo() {}
    //Info* visualizzaProfilo() const {return 0; }
};

#endif // PROFILO_H
