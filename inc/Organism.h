
#ifndef VAMPIRESVSHUMANS_ORGANISM_H
#define VAMPIRESVSHUMANS_ORGANISM_H

#include <iostream>

using namespace std;

class CrockettIsland;
class Organism{
    protected:
        int x; // x position on the grid <- ->
        int y; // y position on grid ^ v
        bool moved; // track if the organism has moved on this turn
        CrockettIsland* crockettIsland; // pointer to island Grid
        char organismType;

    public:
    Organism(CrockettIsland *crockettIslandPtr, int xLocation, int yLocation);
    virtual ~Organism() {};
    virtual void turn() = 0;

    // Getters
    char getType() const { return organismType; }
    bool hasMoved() const { return moved; }
    int getX() const { return x; }
    int getY() const { return y; }

    // Setters
    void setMoved(bool val) { moved = val; }
}; //end of Class organism




#endif //VAMPIRESVSHUMANS_ORGANISM_H