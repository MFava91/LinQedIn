#include "rete.h"

Rete::Rete() {};
Rete::Rete(const set<QString>& r):follow(r){}

set<QString> Rete::getFollow() const{
    return follow;
}


void Rete::addFollow(Username u){
    follow.insert(u.getUsername());
}

void Rete::removeFollow(Username u){
    follow.erase(u.getUsername());
}

