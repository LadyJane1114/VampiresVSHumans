#ifndef VAMPIRESVSHUMANS_ISLAND_H
#define VAMPIRESVSHUMANS_ISLAND_H

#include "Organism.h"
#include "Human.h"
#include "Vampire.h"
#include "GameSpecs.h"
#include <vector>
#include <iostream>

class Island {
private:
    Organism* grid[CROCKETT_ISLAND][CROCKETT_ISLAND];

public:
    Island();
    ~Island();

    void initialize(); // populate starting humans and vampires

    bool inBounds(int x, int y) const;
    bool isEmpty(int x, int y) const;
    bool isHuman(int x, int y) const;

    void addHuman(int x, int y);
    void addVampire(int x, int y);
    void removeOrganism(int x, int y);

    void moveOrganism(int oldX, int oldY, int newX, int newY);

    void resetMoves(); // set all moved flags to false
    void turnAll(); // call turn() for all organisms

    friend std::ostream& operator<<(std::ostream& os, const Island& isl);


};

#endif // VAMPIRESVSHUMANS_ISLAND_H
