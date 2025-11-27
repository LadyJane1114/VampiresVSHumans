
#ifndef VAMPIRESVSHUMANS_GAMESPECS_H
#define VAMPIRESVSHUMANS_GAMESPECS_H

const int CROCKETT_ISLAND = 20;

const int HUMAN_STARTCOUNT = 100;
const int VAMPIRE_STARTCOUNT = 5;

const int HUMAN_BREED = 3;

const int VAMPIRE_BREED = 8;
const int VAMPIRE_STARVE = 3;

const char* HUMAN_CH = "\033[36m H \033[0m"; // H for a human ASCII IS 72   - CYAN TEXT
const char* SPACE_CH = "\033[37m - \033[0m"; // - for empty space ASCII IS 45 - WHITE TEXT
const char* VAMPIRE_CH = "\033[31m v \033[0m"; // V for vampire  ASCII IS 86 - RED TEXT
const char* BUILDING_CH = "\033[47m # \033[0m"; // # for a building ASCII IS 35 - WHITE BG


const int INTERVAL = 300;
const int ITERATIONS = 1000;



#endif //VAMPIRESVSHUMANS_GAMESPECS_H