#include <iostream>
#include <chrono>
#include <thread>

using namespace std;



//Clear screen to go to the next screen
void ClearScreen()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

int main() {
    City *city = new City();
    chrono:: milliseconds interval(INTERAVAL);

    while(city->hasDiversity()) { //while both humans and vampires exist
        this_thread::sleep_for(interval);
        ClearScreen();
        city->step();
        city->reset(); //resets moved flags
        city->countOrganisms(V or H goes here);// run once for each type
        cout << *city; //prints city
        cout << "GENERATION " << city->getGeneration() << endl;
        cout << "HUMANS: " << city->countType(HUMAN_CH) << endl;
        cout << "VAMPIRES: " << city->countType(VAMPIRE_CH) << endl;
    }
}