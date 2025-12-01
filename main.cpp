#include <iostream>
#include <chrono>
#include <thread>
#include "Island.h"

using namespace std;



//Clear screen to go to the next screen
void ClearScreen()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

int main() {
    Island *island = new Island();
    chrono:: milliseconds interval(INTERVAL);

    while(island->hasDiversity()) { //while both humans and vampires exist
        this_thread::sleep_for(interval);
        ClearScreen();
        island->turnAll();
        island->resetMoves(); //resets moved flags
        island->countOrganisms(VAMPIRE_CH);
        island->countOrganisms(HUMAN_CH);// run once for each type
        cout << *island; //prints city
        cout << "GENERATION " << island->getGeneration() << endl;
        cout << "HUMANS: " << island->countType(HUMAN_CH) << endl;
        cout << "VAMPIRES: " << island->countType(VAMPIRE_CH) << endl;
    } // end of while
} // end of main