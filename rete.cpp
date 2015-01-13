#include "rete.h"

Rete::Rete()
{
}

void Rete::addFollow(Username u){
    follow.insert(u.getUsername());
}

void Rete::removeFollow(Username u){
    follow.erase(u.getUsername());
}
