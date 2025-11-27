#ifndef VAMPIRESVSHUMANS_VAMPIRE_H
#define VAMPIRESVSHUMANS_VAMPIRE_H

#include "Organism.h"

class Vampire : public Organism {
public:
    Vampire();
    Vampire(Island* island, int size);
    virtual ~Vampire();

    void turn() override; // move/eat, breed, starve

    private:
    int hunger; // counts turns without eating
};

#endif // VAMPIRESVSHUMANS_VAMPIRE_H
