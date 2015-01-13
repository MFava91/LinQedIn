#ifndef RETE_H
#define RETE_H

#include"username.h"
#include<set>

using std::set;
class Rete{
private:
    //Following
    set<QString> follow;
    //Follower
    set<QString> follower;
public:
    Rete();

    void addFollow(Username);
    void removeFollow(Username);
};

#endif // RETE_H
