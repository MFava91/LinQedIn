#ifndef RETE_H
#define RETE_H

#include"username.h"
#include<set>
using std::set;

class Rete{
private:
    set<QString> follow;
public:
    Rete();
    Rete(const set<QString>&);
    set<QString> getFollow() const;
    void addFollow(Username);
    void removeFollow(Username);
};

#endif // RETE_H
