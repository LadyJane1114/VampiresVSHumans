#include <iostream>
#include <cstdlib>
#include <ctime>

#include "GameSpecs.h"
#include "Organism.h"
#include "Vampire.h"
#include "Human.h"
#include "CrockettIsland.h"

using namespace std;

#define HumanCyan "\033[36m"
#define VampRed "\033[31m"
#define IslandWhite "\033[37m"
#define AestheticYellow  "\033[33m"
#define ColorReset "\033[0m"



//Constructor
CrockettIsland::CrockettIsland() {
    generation = 0;
    humansTotal = HUMAN_STARTCOUNT;
    humansStart = HUMAN_STARTCOUNT;
    vampiresTotal = VAMPIRE_STARTCOUNT;
    vampiresStart = VAMPIRE_STARTCOUNT;

    //random
    srand(time(0));

    //empty grid
    for (int r = 0; r < ISLAND_GRID; r++) { // r for rows
        for (int c = 0; c < ISLAND_GRID; c++) { // c for columns
            grid[r][c] = nullptr;
        }
    }

    //place humans and vampires
    for (int o = 0; o < humansStart; o++) {
        int x, y;
        do {
            x = rand() % ISLAND_GRID;
            y = rand() % ISLAND_GRID;
        } while (grid[x][y] != nullptr);

        grid[x][y] = new Human(this,x,y);
    }

    for (int v = 0; v < vampiresStart; v++) {
        int x, y;
        do {
            x = rand() % ISLAND_GRID;
            y = rand() % ISLAND_GRID;
        } while (grid[x][y] != nullptr);

        grid[x][y] = new Vampire(this, x, y);
    }
}

//Destructor
CrockettIsland::~CrockettIsland() {
    for (int r = 0; r < ISLAND_GRID; r++) {
        for (int c = 0; c < ISLAND_GRID; c++) {
            if (grid[r][c] != nullptr) {
                delete grid[r][c];
                grid[r][c] = nullptr;
            }
        }
    }
}

bool CrockettIsland::runSimulation() {
    generation ++;

    //Pass 1: all organisms do everything they can on their turn.
    for (int r = 0; r < ISLAND_GRID; r++) {
        for (int c = 0; c < ISLAND_GRID; c++) {
            if (grid[r][c] != nullptr && grid[r][c]->getType() == VAMPIRE_CH) {
                grid[r][c]->turn();
            }
        }
    }

    for (int r = 0; r < ISLAND_GRID; r++) {
        for (int c = 0; c < ISLAND_GRID; c++) {
            if (grid[r][c] != nullptr && grid[r][c]->getType() == HUMAN_CH) {
                grid[r][c]->turn();
            }
        }
    }

    //Pass 2 - reset all movements to zero
    resetTurns();

    //Pass 3 - Count all organisms and check for extinction
    bool continueSim = countOrganisms();

    //Pass 4 - Display grid
    cout << *this;

    //decide whether to continue running the program
    return continueSim;
}


// Function to reset all turns
void CrockettIsland::resetTurns() {
    for (int r = 0; r < ISLAND_GRID; r++) {
        for (int c = 0; c < ISLAND_GRID; c++) {
            if (grid[r][c] != nullptr) {
                grid[r][c]->setMoved(false);
            }
        }
    }
}

bool CrockettIsland::countOrganisms() {
    humansTotal = 0;
    vampiresTotal = 0;

    for (int r = 0; r < ISLAND_GRID; r++) {
        for (int c = 0; c < ISLAND_GRID; c++) {
            if (grid[r][c] != nullptr) {
                if (grid[r][c]->getType()== HUMAN_CH) {
                    humansTotal++;
                        }else if (grid[r][c]->getType()== VAMPIRE_CH) {
                    vampiresTotal++;
                }
            }
        }
    }

    //Count displays
    cout << "\n\n\n\n\n\n\n\n\n" << AestheticYellow << "========================================" << ColorReset << endl;
    cout << "Generation: " << generation << endl;
    cout << "Humans: " << humansTotal << endl;
    cout << "Vampire: " << vampiresTotal << endl;
    cout << AestheticYellow << "========================================" << ColorReset << endl;

    //check for extinction level events
    if (humansTotal == 0) {
        cout << VampRed << "\n EXTINCTION EVENT: All humans have perished."<< ColorReset << endl;
        return false;
    }
    if (vampiresTotal == 0) {
        cout << HumanCyan << "\n EXTINCTION EVENT: All vampires have perished."<< ColorReset << endl;
        return false;
    }
    return true;
}

//get organism at position
Organism *CrockettIsland::getOrganism(int x, int y) {
    if (!isValidLocation(x,y))return nullptr;
    return grid[x][y];
}

//set organism at position
void CrockettIsland::setOrganism(int x, int y, Organism* org) {
    if (!isValidLocation(x, y)) return;
    grid[x][y] = org;
}

bool CrockettIsland::isValidLocation(int x, int y) {
    return (x>=0 && x < ISLAND_GRID && y >=0 && y < ISLAND_GRID);
}

// friend function
ostream& operator<<(std::ostream& os, const CrockettIsland& crockettIsland) {
    //border (idea borrowed from Adrian)
    os << AestheticYellow << " ";
    for (int r = 0; r < ISLAND_GRID; r++) {
        os << "==";
    }
    os << ColorReset <<endl;

    // Grid
    for (int c = 0; c < ISLAND_GRID; c++) {
        os << AestheticYellow << "| " << ColorReset; // left border

        for (int r = 0; r < ISLAND_GRID; r++) {
            if (crockettIsland.grid[r][c] != nullptr) {
                if (crockettIsland.grid[r][c]->getType() == HUMAN_CH) {
                    os << HumanCyan << HUMAN_CH << ColorReset;
                } else if (crockettIsland.grid[r][c]->getType() == VAMPIRE_CH) {
                    os << VampRed << VAMPIRE_CH << ColorReset;
                }
            } else {
                os << SPACE_CH;  // Empty cell
            }
            os << " ";
        }

        os << AestheticYellow << "|" << ColorReset << endl;  // Right border
    }
    // Print bottom border
    os << AestheticYellow << "  ";
    for (int r = 0; r < ISLAND_GRID; r++) {
        os << "==";
    }
    os << ColorReset << endl;

    return os;
}

