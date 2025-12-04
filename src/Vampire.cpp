#include <vector>
#include <ctime>

#include "Vampire.h"
#include "CrockettIsland.h"
#include "GameSpecs.h"
#include "Human.h"

using namespace std;


Vampire::Vampire(CrockettIsland *crockettIslandPtr, int xLocation, int yLocation): Organism(crockettIslandPtr,xLocation,yLocation){
    organismType = VAMPIRE_CH;
    convertCounter = 0;
    hunger = 0;
}


//handles all the vampires turns (similar to human, only with a bit more spice)
void Vampire::turn() {
    if (moved) return;

    //HUNT - the vampire's Move/Eat action. Move to a square that has a human and drink their blood, or to a square that doesn't, if none are available.
    vector<pair<int,int>>humanLocations;
    vector<pair<int,int>>emptyLocations;

    // all adjacent cells (cardinal and diagonal)
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;  // Skip current position

            int newX = x + dx;
            int newY = y + dy;

            if (crockettIsland->isValidLocation(newX, newY)) {
                Organism* org = crockettIsland->getOrganism(newX, newY);
                if (org == nullptr) {
                    emptyLocations.push_back({newX, newY});
                }
                else if (org->getType() == HUMAN_CH) {
                    humanLocations.push_back({newX, newY});
                }

            }
        }
    }

    // if human -> feed
    if (!humanLocations.empty()) {
        // vampires are not picky
        int randomIndex = rand() % humanLocations.size();
        int targetX = humanLocations[randomIndex].first;
        int targetY = humanLocations[randomIndex].second;

        // kill the human
        delete crockettIsland->getOrganism(targetX, targetY);

        // vampire enters humans space
        crockettIsland->setOrganism(x,y,nullptr); // clear old position
        x = targetX;
        y = targetY;
        crockettIsland->setOrganism(x,y,this); // new position

        //reset hunger ( humans make a great meal)
        hunger = 0;
    }
    //if there aren't humans, vamps gotta keep hunting
    else if (!emptyLocations.empty()) {
        // Pick a random empty spot
        int randomIndex = rand() % emptyLocations.size();
        int newX = emptyLocations[randomIndex].first;
        int newY = emptyLocations[randomIndex].second;

        // Move to new position
        crockettIsland->setOrganism(x, y, nullptr);  // Clear old position
        x = newX;
        y = newY;
        crockettIsland->setOrganism(x, y, this);     // Set new position

        // Increment starve counter since we didn't eat
        hunger++;
    }
    //if they're trapped, they're still hungry
    else {
        hunger++;
    }
    moved = true;

    convertCounter++;

    // CONVERT: Convert the humans!! After 8 generations, a vampire may convert a human to their side.
    if (convertCounter >= VAMPIRE_CONVERT) {
        vector<pair<int, int>> humanSpots;

        // Check all 8 adjacent cells for humans
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;  // Skip current position

                int newX = x + dx;
                int newY = y + dy;

                if (crockettIsland->isValidLocation(newX, newY)) {
                    Organism* org = crockettIsland->getOrganism(newX, newY);
                    if (org != nullptr && org->getType() == HUMAN_CH) {
                        humanSpots.push_back(make_pair(newX, newY));
                    }
                }
            }
        }

        // If there are adjacent humans, convert one
        if (!humanSpots.empty()) {
            // Pick a random human to convert
            int randomIndex = rand() % humanSpots.size();
            int targetX = humanSpots[randomIndex].first;
            int targetY = humanSpots[randomIndex].second;

            // Delete the human
            delete crockettIsland->getOrganism(targetX, targetY);

            // Create a new vampire at that position
            Vampire* newVampire = new Vampire(crockettIsland, targetX, targetY);
            crockettIsland->setOrganism(targetX, targetY, newVampire);

            // Reset convert counter after successful conversion
            convertCounter = 0;
        }
        // Vampires do not lose their ability to convert humans if they miss their chance. They are persistent little buggers.
    }


    //STARVE: After 3 generations without eating, a vampire will starve, losing their vampire powers and becoming human again... for now.
    if (hunger >= VAMPIRE_STARVE) {
        crockettIsland->setOrganism(x, y, nullptr); // remove from grid first
        Human* newHuman = new Human(crockettIsland, x, y);
        crockettIsland->setOrganism(x, y, newHuman);
        delete this; // now safe, grid no longer points to this
        return;
    }
}