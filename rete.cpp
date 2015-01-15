#include "rete.h"


void Rete::addFollow(Username u){
    follow.insert(u.getUsername());
}

void Rete::addFollower(Username u){
    follower.insert(u.getUsername());
}

void Rete::removeFollow(Username u){
    follow.erase(u.getUsername());
}

void Rete::removeFollower(Username u){
    follower.erase(u.getUsername());
}
