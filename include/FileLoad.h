// #include<map>
#ifndef FILELOAD_H
#define FILELOAD_H
#include "Car_list.h"
extern "C" void saveExit(current *tmp, int cost, char* exit_date );
extern "C" void savePos( current *HEAD);
extern "C" void loadPos(current **HEAD, current **TAIL);
// extern "C" void loadMem(map <string, string> *mem_map);

#endif