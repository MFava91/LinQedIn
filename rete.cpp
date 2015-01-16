#include "rete.h"

set<QString> Rete::getFollow() const{
    return follow;
}


void Rete::addFollow(Username u){
    follow.insert(u.getUsername());
}

void Rete::removeFollow(Username u){
    follow.erase(u.getUsername());
}

