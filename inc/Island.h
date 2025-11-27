
#ifndef VAMPIRESVSHUMANS_CITY_H
#define VAMPIRESVSHUMANS_CITY_H

#include <iostream>
#include "GameSpecs.h"

using namespace std;

class Organism;

class Island {
protected:
    Organism *grid[CROCKETT_ISLAND][CROCKETT_ISLAND];
    int generation;

public:
    Island();
    virtual ~Island();

    Organism *getOrganism(int x, int y);
    void setOrganism(Organism *organism, int x, int y);

    void step();
    void reset();
    int countType(char);
    friend ostream &operator<<(ostream &output, Island &island);

    void col(int c);

    bool hasDiversity();
}; //end of island


#endif //VAMPIRESVSHUMANS_CITY_H