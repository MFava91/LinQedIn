#include "username.h"

Username::Username() {}

Username::Username(const QString& s):login(s) {}

Username Username::ModificaUsername(const QString& u){
    login=u;
}

QString Username::getUsername(){
    return login;
}



