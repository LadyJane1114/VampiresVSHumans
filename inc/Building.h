
#ifndef VAMPIRESVSHUMANS_BUILDING_H
#define VAMPIRESVSHUMANS_BUILDING_H


#include "Organism.h"
#include "GameSpecs.h"

class Building : public Organism {
private:
    bool occupied;
public:
    Building(CrockettIsland* island, int x, int y);

    virtual void turn() override; // empty turn (buildings don't do anything, they're buildings)


    //getter
    bool isOccupied() const {return occupied;};

    //setter
    void setOccupied(bool occ) {occupied = occ;};

};


#endif //VAMPIRESVSHUMANS_BUILDING_H