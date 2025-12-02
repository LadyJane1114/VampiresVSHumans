
#ifndef VAMPIRESVSHUMANS_HUMAN_H
#define VAMPIRESVSHUMANS_HUMAN_H

#include "Organism.h"

class Human : public Organism
{
private:
    int recruitCounter;
public:
    Human( CrockettIsland *crockettIslandPtr, int xLocation, int yLocation);

    void turn() override; //all things a human may do on their turn. i.e. a move, and if allowed a recruitment


};

#endif //VAMPIRESVSHUMANS_HUMAN_H