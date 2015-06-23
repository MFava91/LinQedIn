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
    TitoliStudio(const QString&,const vector<QString>&);
    TitoliStudio(const QString& ="",const QString& ="");
    TitoliStudio operator=(const TitoliStudio&);
    QString getDiploma();
    vector<QString> getLaurea();
    void AggiungiLaurea(const QString&);
    void removeLaurea(const QString&);
    //distruttore di default
};

#endif // TITOLISTUDIO_H
