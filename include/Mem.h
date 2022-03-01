#ifndef MEM_H
#define MEM_H
#include "Car_list.h"
#include <string>
#include<iostream>
using namespace std;
class Mem{
    string mcar_num;
    string mphone_num;
    int  is_mem;
    
    public:
        bool findPhoneNum(current *HEAD);
        bool isMem(string car_num);
        void registerMem();

};
#endif