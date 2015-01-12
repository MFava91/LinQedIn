#ifndef COMPETENZELAVORATIVE_H
#define COMPETENZELAVORATIVE_H
#include<lavoro.h>
#include<vector>
using std::vector;

class CompetenzeLavorative
{
private:
    vector<Lavoro> esperienze;
public:
    CompetenzeLavorative();
    CompetenzeLavorative(const Lavoro&);
    void AggiungiLavoro(const Lavoro&);

};

#endif // COMPETENZELAVORATIVE_H
