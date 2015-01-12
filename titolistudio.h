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
    TitoliStudio();
    TitoliStudio(const QString&);
    TitoliStudio(const QString& ="",const QString& ="");
    void AggiungiLaurea(const QString&);
    //elimina un elemento
    //distruttore di default
};

#endif // TITOLISTUDIO_H
