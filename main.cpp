#include <iostream>
#include <chrono>
#include <thread>
#include "CrockettIsland.h"


using namespace std;



int main() {
    bool shouldContinue;
    // Create the city
    CrockettIsland crockettIsland;

    cout << "\n\033[33m===========================================\033[0m\n";
    cout << "        \033[34mWelcome to Crockett Island!\033[0m\n";
    cout << "\033[33m===========================================\033[0m\n";
    cout << "We live a blessed life in our parish, but...\n";
    cout << "... we've had a little problem ever since the \033[32mnew priest\033[0m came to town.\n";
    cout << "Now the town is overrun by \033[31mvampires!\033[0m\n";
    cout << "Start the simulation to watch what happens.\n\n";
    cout << "\nLegend:\n";
    cout << "  \033[36mO = Human (Cyan)\033[0m\n";
    cout << "  \033[31mV = Vampire (Red)\033[0m\n";
    cout << "  - = Empty space\n\n";

    //start button to start SIM
    cout << "Press enter to start the simulation...";
    cin.get();

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