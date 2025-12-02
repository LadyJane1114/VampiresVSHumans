#ifndef VAMPIRESVSHUMANS_VAMPIRE_H
#define VAMPIRESVSHUMANS_VAMPIRE_H

#include "Organism.h"

class Vampire : public Organism {
private:
    int convertCounter; // counts when a vampire can convert another vampire
    int hunger; // counts steps since last meal

public:
    Vampire(CrockettIsland* crockettIslandPtr, int xLocation, int yLocation);

    void turn() override; // move/eat, sire, starve
};

#endif // VAMPIRESVSHUMANS_VAMPIRE_H
