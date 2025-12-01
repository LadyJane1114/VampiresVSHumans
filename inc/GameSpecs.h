
#ifndef VAMPIRESVSHUMANS_GAMESPECS_H
#define VAMPIRESVSHUMANS_GAMESPECS_H

const int CROCKETT_ISLAND = 10; // actual number 20

const int HUMAN_STARTCOUNT = 20; // actual number 100
const int VAMPIRE_STARTCOUNT = 1; // actual number 5

const int HUMAN_RECRUIT = 3;

const int VAMPIRE_SIRE = 8;
const int VAMPIRE_STARVE = 3;

const char HUMAN_CH = 'H';
const char VAMPIRE_CH = 'v';
const char SPACE_CH = '-';
const char BUILDING_CH = '#';

constexpr const char* COLOR_CYAN  = "\033[36m";
constexpr const char* COLOR_RED   = "\033[31m";
constexpr const char* COLOR_WHITE = "\033[37m";
constexpr const char* BG_WHITE    = "\033[47m";
constexpr const char* COLOR_RESET = "\033[0m";


const int INTERVAL = 300;
const int ITERATIONS = 100; // actual 1000



#endif //VAMPIRESVSHUMANS_GAMESPECS_H