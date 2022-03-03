#ifndef PARKING_H
#define PARKING_H
#include "Car_list.h"
#include <string>
#include<iostream>
using namespace std;
class Parking{
    int total;
    int empty_area;
    public:
        Parking();
        ~Parking();
        bool enterCar(current **HEAD,current  **TAIL);
        bool CheckEmptyArea(current *HEAD, int car_pos,int floor);
        bool Checkexitnum(current *HEAD, string car_num);
        bool exitCar(current **HEAD, current  **TAIL);
        void printPos(current *HEAD,int curfloor);
};
#endif