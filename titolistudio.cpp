 #include "titolistudio.h"

//TitoliStudio::TitoliStudio() {} //Usa costruttore standard del vector e del QString

TitoliStudio::TitoliStudio(const QString& d, const QString& l){
    if(d!="")
        diploma=d;
    if(l!="")
        AggiungiLaurea(l);
}

TitoliStudio::TitoliStudio(const QString& d,const vector<QString>& v){
    diploma=d;
    laurea=v;
}

TitoliStudio TitoliStudio::operator=(const TitoliStudio& a){
    diploma=a.diploma;
    laurea=a.laurea;
    return *this;
}

void TitoliStudio::AggiungiLaurea(const QString& l) {
    laurea.push_back(l);
}

QString TitoliStudio::getDiploma(){
    return diploma;
}

vector<QString> TitoliStudio::getLaurea(){
    return laurea;
}

void TitoliStudio::removeLaurea(const QString& l){
    int size=laurea.size();
    bool trovato=false;
    for(int i=0;i<size && trovato==false;i++){
        if(laurea[i]==l)
        {
            laurea.erase(laurea.begin()+i);
            trovato=true;
        }
    }
}

void TitoliStudio::modificaLaurea(const QString& temp, const QString& l){
    int size=laurea.size();
    bool trovato=false;
    for(int i=0;i<size && trovato==false;i++){
        if(laurea[i]==temp)
        {
            laurea[i]=l;
            trovato=true;
        }
    }
}
