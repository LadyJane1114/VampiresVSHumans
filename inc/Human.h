
#ifndef VAMPIRESVSHUMANS_HUMAN_H
#define VAMPIRESVSHUMANS_HUMAN_H

#include "Building.h"
#include "Organism.h"

class Human : public Organism
{
private:
    int recruitCounter;

    // new building items
    bool isHiding;
    int hideTimer;
    Building* safeHouse;

public:
    Human( CrockettIsland *crockettIslandPtr, int xLocation, int yLocation);

    void turn() override; //all things a human may do on their turn. i.e. a move, and if allowed a recruitment

    // new building functions
    Building* buildingNearby();
    void startHiding(Building* b);
    void exitBuilding();
};

#endif //VAMPIRESVSHUMANS_HUMAN_H