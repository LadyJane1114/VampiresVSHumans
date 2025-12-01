#include <vector>
#include <cstdlib>
#include <ctime>

#include "Vampire.h"
#include "Island.h"
#include "GameSpecs.h"

// Default
Vampire::Vampire() : Organism(), hunger(0) {}

// Main constructor
Vampire::Vampire(Island* island, int s) : Organism(island, s), hunger(0) {
    moved = false;
}

// Destructor
Vampire::~Vampire() {}

char Vampire::getType() const {
    return VAMPIRE_CH;  // or 'V'
}

//turn: move/eat, sire, starve

void Vampire::turn() {

    cout << "Vampire at (" << x << "," << y << ") taking turn\n";
    if (hasMoved()) return;

    std::vector<std::pair<int,int>> humanTargets;
    std::vector<std::pair<int,int>> emptySpaces;

    //check all 8 surrounding cells for available cells
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue; // skip current cell
            int nx = x + dx;
            int ny = y + dy;
            if (island->inBounds(nx, ny)) {
                if (island->isHuman(nx, ny))
                    humanTargets.push_back({nx, ny});
                else if (island->isEmpty(nx, ny))
                    emptySpaces.push_back({nx, ny});
            }
        }
    }

    //move/eat
    if (!humanTargets.empty()) {
        // Move to a random human and eat
        int idx = rand() % humanTargets.size();
        int newX = humanTargets[idx].first;
        int newY = humanTargets[idx].second;

        // Remove human and move vampire
        island->removeOrganism(newX, newY);
        island->moveOrganism(x, y, newX, newY);
        setPosition(newX, newY);

        hunger = 0; // reset hunger after eating
    } else if (!emptySpaces.empty()) {
        // Move to random empty space
        int idx = rand() % emptySpaces.size();
        int newX = emptySpaces[idx].first;
        int newY = emptySpaces[idx].second;

        island->moveOrganism(x, y, newX, newY);
        setPosition(newX, newY);

        hunger++; // increment hunger if didn't eat
    } else {
        // Couldn't move
        hunger++;
    }

    //sire
    static int sireCounter = 0;
    sireCounter++;

    if (sireCounter>= VAMPIRE_SIRE) {
        if (!humanTargets.empty()) {
            int idx = rand() % humanTargets.size();
            int newX = humanTargets[idx].first;
            int newY = humanTargets[idx].second;

            island->removeOrganism(newX, newY);
            island->addVampire(newX, newY);

            sireCounter = 0; // reset counter after breeding
        }
    }

    //starve
    if (hunger >= VAMPIRE_STARVE) {
        // Convert back to human
        island->removeOrganism(x, y);
        island->addHuman(x, y);
    }

    setMoved(true);
}