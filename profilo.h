#ifndef PROFILO_H
#define PROFILO_H

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
    QString getTipoAccount() const;
    void setDatiPersonali(const DatiAnagrafici&);
    void setTitoliStudio(const TitoliStudio&);
    void setLaurea(const QString&, const QString&);
    void setCurriculum(const Lavoro&, const Lavoro&);
    void setNomeDatiPersonali(const QString&);
    void setCognomeDatiPersonali(const QString&);
    void setTipoAccount(const QString&);
    void wipeLaurea(const QString&);
    void wiperLavoro(const Lavoro&);
    void aggiungiLaurea(const QString&);
    void aggiungiLavoro(const Lavoro&);
    bool searchLaurea(const QString&);
};

#endif // PROFILO_H
