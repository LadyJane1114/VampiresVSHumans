#include "Organism.h"


Organism::Organism(CrockettIsland *crockettIslandPtr, int xLocation, int yLocation) {
    crockettIsland = crockettIslandPtr;
    x = xLocation;
    y = yLocation;
    moved = false;
    organismType = ' '; // default, will be overridden in subclasses
}


