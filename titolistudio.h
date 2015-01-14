#ifndef TITOLISTUDIO_H
#define TITOLISTUDIO_H

#include<QString>
#include <vector>
using std::vector;

class TitoliStudio
{
private:
    QString diploma;
    vector<QString> laurea;
public:
    //TitoliStudio();
    TitoliStudio(const QString&);
    TitoliStudio(const QString& ="",const QString& ="");
    TitoliStudio operator=(const TitoliStudio&);
    void AggiungiLaurea(const QString&);
    QString getDiploma();
    vector<QString> getLaurea();
    //elimina un elemento
    //distruttore di default
};

#endif // TITOLISTUDIO_H
