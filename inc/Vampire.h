
#ifndef VAMPIRESVSHUMANS_VAMPIRE_H
#define VAMPIRESVSHUMANS_VAMPIRE_H

#include "Organism.h"

class Vampire : public Organism {
    public:
    Vampire();
    Vampire(City *city, int size);
    virtual ~vampire();

    void turn();

}; //end of vampire


#endif //VAMPIRESVSHUMANS_VAMPIRE_H