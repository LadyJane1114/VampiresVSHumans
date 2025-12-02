#include <iostream>
#include <chrono>
#include <thread>
#include "CrockettIsland.h"

using namespace std;



int main() {
    bool shouldContinue;
    // Create the city
    CrockettIsland crockettIsland;

    cout << "\n===========================================\n";
    cout << "        Welcome to Crockett Island!\n";
    cout << "===========================================\n";
    cout << "\nLegend:\n";
    cout << "  O = Human (Cyan)\n";
    cout << "  V = Vampire (Red)\n";
    cout << "  - = Empty space\n\n";

    // Display initial state
    cout << "INITIAL STATE:\n";
    shouldContinue = crockettIsland.runSimulation();

    // Main simulation loop
    int totalGenerations = GENERATION;

    for (int i = 1; i < totalGenerations && shouldContinue; i++) {
        this_thread::sleep_for(chrono::milliseconds(INTERVAL));

        //one generation
        shouldContinue = crockettIsland.runSimulation();

    }

    if (shouldContinue) {
        cout << "\nThe humans and vampires have found harmony!" << endl;
    }

    cout << "\n===========================================\n";
    cout << "                   AMEN\n";
    cout << "===========================================\n";

    return 0;

} // end of main