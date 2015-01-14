#include "username.h"

Username::Username() {}

Username::Username(const QString& s):login(s) {}

void Username::setUsername(const QString& u){
    login=u;
}

QString Username::getUsername(){
    return login;
}


