#ifndef VAMPIRESVSHUMANS_BUILDING_H
#define VAMPIRESVSHUMANS_BUILDING_H

#include "GameSpecs.h"
#include "Organism.h"

class Building : public Organism {
public:
    Building(Island* isl = nullptr, int x = -1, int y = -1)
        : Organism(isl, x, y) {}

    virtual ~Building() override = default;

    virtual void turn() override {
        // Buildings do nothing
    }

    virtual char getType() const override { return '#'; }

    virtual const char* getDisplay() const override {
        return BUILDING_CH;  // your ANSI code
    }
};

#endif

