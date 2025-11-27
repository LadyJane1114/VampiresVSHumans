
#ifndef VAMPIRESVSHUMANS_ORGANISM_H
#define VAMPIRESVSHUMANS_ORGANISM_H

#include <iostream>

using namespace std;

class Island;
class Organism{
    protected:
        int x;
        int y;
        int size;
        bool moved;
        Island* island;

    public:
    Organism();
    Organism(Island *island, int size);
    virtual ~Organism();
    virtual void turn() = 0;

    friend ostream& operator<<(ostream &output, Organism &organism);
}; //end of Class organism




#endif //VAMPIRESVSHUMANS_ORGANISM_H