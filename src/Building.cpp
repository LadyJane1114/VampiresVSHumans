#include "Building.h"


Building::Building(CrockettIsland* island, int x, int y) : Organism(island, x, y), occupied(false) {
    organismType = BUILDING_CH;
}

void Building::turn() {
    // Buildings do nothing (no movement, no breeding)
}
