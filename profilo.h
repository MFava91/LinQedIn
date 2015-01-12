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
    CompetenzeLavorative esperienze;
public:
    Profilo(const DatiAnagrafici&,const TitoliStudio&,const CompetenzeLavorative&);
    //void modificaProfilo() {}
    //Info* visualizzaProfilo() const {return 0; }
};

#endif // PROFILO_H
