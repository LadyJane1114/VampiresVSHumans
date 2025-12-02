#include <vector>
#include<cstdlib>

#include "CrockettIsland.h"
#include "Human.h"
#include "GameSpecs.h"

using namespace std;

//constructor
Human::Human(CrockettIsland *crockettIslandPtr, int xLocation, int yLocation) : Organism(crockettIslandPtr,xLocation,yLocation){
    organismType = HUMAN_CH;
    recruitCounter = 0;
}

//turn, all human turn actions
void Human::turn() {
    // act only if you haven't moved
    if (moved) return;

    // Move: Try to move locations randomly in one of the 4 cardinal directions
    //N:0 S:1 E:2 W:3
    vector<int> validLocations;

    if (crockettIsland->isValidLocation(x,y -1) && crockettIsland->getOrganism(x,y - 1) == nullptr) {
        validLocations.push_back(0); // up
    }
    if (crockettIsland->isValidLocation(x, y + 1) && crockettIsland->getOrganism(x, y + 1) == nullptr) {
        validLocations.push_back(1); // Down
    }
    if (crockettIsland->isValidLocation(x - 1, y) && crockettIsland->getOrganism(x - 1, y) == nullptr) {
        validLocations.push_back(2); // Left
    }
    if (crockettIsland->isValidLocation(x + 1, y) && crockettIsland->getOrganism(x + 1, y) == nullptr) {
        validLocations.push_back(3); // Right
    }

    // if there is more than one valid location, pick one randomly
    if (!validLocations.empty()) {
        int randomChoice = validLocations[rand() % validLocations.size()];
        int newX = x;
        int newY = y;

        // determine new location
        if (randomChoice == 0) newY--;      // Up
        else if (randomChoice == 1) newY++; // Down
        else if (randomChoice == 2) newX--; // Left
        else if (randomChoice == 3) newX++; // Right

        // move to new location
        crockettIsland->setOrganism(x, y, nullptr);
        x = newX;
        y = newY;
        crockettIsland->setOrganism(x, y, this);     // Set new position
    }

    moved = true;

    recruitCounter++;
    if (recruitCounter >= HUMAN_RECRUIT) {
        vector<pair<int, int>> validSpots;

        // Check all 4 adjacent cardinal cells
        if (crockettIsland->isValidLocation(x, y - 1) && crockettIsland->getOrganism(x, y - 1) == nullptr) {
            validSpots.push_back(make_pair(x, y - 1)); // Up
        }
        if (crockettIsland->isValidLocation(x, y + 1) && crockettIsland->getOrganism(x, y + 1) == nullptr) {
            validSpots.push_back(make_pair(x, y + 1)); // Down
        }
        if (crockettIsland->isValidLocation(x - 1, y) && crockettIsland->getOrganism(x - 1, y) == nullptr) {
            validSpots.push_back(make_pair(x - 1, y)); // Left
        }
        if (crockettIsland->isValidLocation(x + 1, y) && crockettIsland->getOrganism(x + 1, y) == nullptr) {
            validSpots.push_back(make_pair(x + 1, y)); // Right
        }

        // If valid spots exist, recruit a new human
        if (!validSpots.empty()) {
            // Pick a random spot
            int randomIndex = rand() % validSpots.size();
            int newX = validSpots[randomIndex].first;
            int newY = validSpots[randomIndex].second;

            // Create new human at that spot
            Human* newHuman = new Human(crockettIsland, newX, newY);
            crockettIsland->setOrganism(newX, newY, newHuman);

            // Reset counter after successful recruit
            recruitCounter = 0;
        } else {
            // If unable to recruit, reset counter to 0 as per requirements
            recruitCounter = 0;
        }
    }

}

