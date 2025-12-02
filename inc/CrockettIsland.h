#ifndef VAMPIRESVSHUMANS_ISLAND_H
#define VAMPIRESVSHUMANS_ISLAND_H

#include "Organism.h"
#include "GameSpecs.h"
#include <iostream>

class CrockettIsland {
private:
    Organism* grid[ISLAND_GRID][ISLAND_GRID];
    int generation;
    int humansTotal;
    int humansStart;
    int vampiresTotal;
    int vampiresStart;

public:
    CrockettIsland();
    ~CrockettIsland();

    bool runSimulation();
    void resetTurns();
    bool countOrganisms();

    Organism* getOrganism(int x, int y);
    void setOrganism(int x, int y, Organism* organism);
    bool isValidLocation(int x, int y);

    friend std::ostream& operator<<(std::ostream& os, const CrockettIsland& crockettIsland);
};

#endif // VAMPIRESVSHUMANS_ISLAND_H
