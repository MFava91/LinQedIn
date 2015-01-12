#include "titolistudio.h"

TitoliStudio::TitoliStudio() {} //usa construttore standard QString

TitoliStudio::TitoliStudio(const QString& d, const QString& l){
    if(d!="")
        diploma=d;
    if(l!="")
        AggiungiLaurea(l);
}

void TitoliStudio::AggiungiLaurea(const QString& l) {
    laurea.push_back(l);
}
