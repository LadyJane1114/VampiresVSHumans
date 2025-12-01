#include <vector>
#include<cstdlib>
#include<ctime>

#include "Island.h"
#include "Human.h"
#include "GameSpecs.h"


//default
Human::Human() :Organism(){}

// main constructor
Human::Human(Island* island, int s) : Organism(island, s) {
    moved = false;
}

//destructor
Human::~Human() {}
// turn : move, recruit

void Human::turn() {
    if (moved)return; //already moved!

    std::vector<std::pair<int,int>>emptySpaces;

    // make sure space is valid
    if (island->inBounds(x-1, y) && island->isEmpty(x-1, y))
        emptySpaces.push_back({x-1, y});
    if (island->inBounds(x+1, y) && island->isEmpty(x+1, y))
        emptySpaces.push_back({x+1, y});
    if (island->inBounds(x, y-1) && island->isEmpty(x, y-1))
        emptySpaces.push_back({x, y-1});
    if (island->inBounds(x, y+1) && island->isEmpty(x, y+1))
        emptySpaces.push_back({x, y+1});

    //pick a random empty spot to move to
    if (!emptySpaces.empty()) {
        int idx = rand() % emptySpaces.size();
        int newX = emptySpaces[idx].first;
        int newY = emptySpaces[idx].second;

        island->moveOrganism(x, y, newX, newY);
        setPosition(newX, newY);
    }

    //recruit
    static int recruitCounter = 0;
    recruitCounter++;

    if (recruitCounter >= HUMAN_RECRUIT) {
        emptySpaces.clear();
        if (island->inBounds(x-1, y) && island->isEmpty(x-1, y))
            emptySpaces.push_back({x-1, y});
        if (island->inBounds(x+1, y) && island->isEmpty(x+1, y))
            emptySpaces.push_back({x+1, y});
        if (island->inBounds(x, y-1) && island->isEmpty(x, y-1))
            emptySpaces.push_back({x, y-1});
        if (island->inBounds(x, y+1) && island->isEmpty(x, y+1))
            emptySpaces.push_back({x, y+1});

        if (!emptySpaces.empty()) {
            int idx = rand() % emptySpaces.size();
            int newX = emptySpaces[idx].first;
            int newY = emptySpaces[idx].second;

            island->addHuman(newX, newY);
            recruitCounter = 0;
        }
    }
    setMoved(true);
}


