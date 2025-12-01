#include <iostream>
#include <cstdlib>
#include <ctime>

#include "GameSpecs.h"
#include "Organism.h"
#include "Vampire.h"
#include "Human.h"
#include "Island.h"

using namespace std;


static int generation = 0;

//Constructor
Island::Island() {
    for (int r = 0; r < CROCKETT_ISLAND; r++) {
        for (int c = 0; c < CROCKETT_ISLAND; c++) {
            grid[r][c] = nullptr;
        }
    }

    srand(time(nullptr));
    initialize();
}

//Destructor
Island::~Island() {
    for (int r = 0; r < CROCKETT_ISLAND; r++) {
        for (int c = 0; c < CROCKETT_ISLAND; c++) {
            delete grid[r][c];
        }
    }
}

//Initialize population
void Island::initialize() {
    int placedHumans = 0;
    int placedVampires = 0;

    while (placedHumans<HUMAN_STARTCOUNT) {
        int x = rand() % CROCKETT_ISLAND;
        int y = rand() % CROCKETT_ISLAND;

        if (isEmpty(x,y)) {
            addHuman(x,y);
            placedHumans++;
        }
    }
    while (placedVampires < VAMPIRE_STARTCOUNT) {
        int x = rand() % CROCKETT_ISLAND;
        int y = rand() % CROCKETT_ISLAND;

        if (isEmpty(x, y)) {
            addVampire(x, y);
            placedVampires++;
        }
    }
}

//boundary and occupancy checks
bool Island::inBounds(int x, int y) const {
    return (x>=0 && x<CROCKETT_ISLAND && y>=0 && y<CROCKETT_ISLAND);
}

bool Island::isEmpty(int x, int y) const {
    return inBounds(x,y) && grid[x][y] == nullptr;
}

bool Island::isHuman(int x, int y) const {
    return grid[x][y] != nullptr && dynamic_cast<Human*>(grid[x][y]) != nullptr;
}

//add/remove organisms
void Island::addHuman(int x, int y) {
    grid[x][y] = new Human(this,x*CROCKETT_ISLAND + y);
}
void Island::addVampire(int x, int y) {
    grid[x][y] = new Vampire(this, x * CROCKETT_ISLAND + y);
}
void Island::removeOrganism(int x, int y) {
    if (inBounds(x, y)) {
        delete grid[x][y];
        grid[x][y] = nullptr;
    }
}

//move organism from one tile to another
void Island::moveOrganism(int oldX, int oldY, int newX, int newY) {
    if (grid[newX][newY] != nullptr) {
        delete grid[newX][newY]; // remove old organism safely
    }
    grid[newX][newY] = grid[oldX][oldY];
    grid[oldX][oldY] = nullptr;
    if (grid[newX][newY] != nullptr)
        grid[newX][newY]->setPosition(newX, newY);

}


//reset
void Island::resetMoves() {
    for (int r = 0; r < CROCKETT_ISLAND; r++) {
        for (int c = 0; c < CROCKETT_ISLAND; c++) {
            if (grid[r][c] != nullptr) {
                grid[r][c]->setMoved(false);
            }

        }
    }
}

//all organisms turn
void Island::turnAll() {
    generation++;
    for (int r=0; r<CROCKETT_ISLAND; r++) {
        for (int c=0; c<CROCKETT_ISLAND; c++) {
            if (grid[r][c] != nullptr && !grid[r][c]->hasMoved()) {
                grid[r][c]->turn();
            }

        }
    }
}

//count all orgs. of a specific type
void Island::countOrganisms(char organismChar) {
    //empty for now
}

//current gen number
int Island::getGeneration() const {
    return generation;
}

int Island::countType(char organismChar) const {
    int count = 0;

    for (int r = 0; r < CROCKETT_ISLAND; r++) {
        for (int c = 0; c < CROCKETT_ISLAND; c++) {
            if (grid[r][c] == nullptr) {
                continue;
            }
            if (organismChar == HUMAN_CH &&
                dynamic_cast<Human*>(grid[r][c]) != nullptr) {
                count++;
            }
            else if (organismChar == VAMPIRE_CH &&
                     dynamic_cast<Vampire*>(grid[r][c]) != nullptr) {
                count++;
            }
        }
    }
    return count;
}

bool Island::hasDiversity() {
    return (countType(HUMAN_CH) > 0 &&
            countType(VAMPIRE_CH) > 0);
}

std::ostream& operator<<(std::ostream& os, const Island& isl) {
    for (int r = 0; r < CROCKETT_ISLAND; r++) {
        for (int c = 0; c < CROCKETT_ISLAND; c++) {
            if (isl.grid[r][c] == nullptr) {
                os << SPACE_CH;
            }
            else if (dynamic_cast<Human*>(isl.grid[r][c])) {
                os << HUMAN_CH;
            }
            else if (dynamic_cast<Vampire*>(isl.grid[r][c])) {
                os << VAMPIRE_CH;
            }
        }
        os << "\n";
    }
    return os;
}


