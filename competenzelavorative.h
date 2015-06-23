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
    vector<Lavoro> getEsperienze() const;
    void editEsperienze(const Lavoro&,const Lavoro&);
    void AggiungiLavoro(const Lavoro&);
    void removeLavoro(const Lavoro&);
};

#endif // COMPETENZELAVORATIVE_H
