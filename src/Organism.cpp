#include "Organism.h"
#include "Island.h"

//default constructor
Organism::Organism() :x(0),y(0), moved(false), island(nullptr){}

//main constructor
Organism::Organism(Island *island, int size) :x(0),y(0), moved(false), island(nullptr){}

//virtual constructor
Organism::~Organism(){}


void Organism::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}
void Organism::setMoved(bool m) {
    moved = m;
}
bool Organism::hasMoved() const {
    return moved;
}


ostream& operator<<(ostream& output, Organism& organism)
{
    output << organism.getType();
    return output;
}
