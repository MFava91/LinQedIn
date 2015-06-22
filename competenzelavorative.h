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
    CompetenzeLavorative(const vector<Lavoro>&);
    void AggiungiLavoro(const Lavoro&);
    void removeLavoro(const Lavoro&);
    vector<Lavoro> getEsperienze() const;
};

#endif // COMPETENZELAVORATIVE_H
