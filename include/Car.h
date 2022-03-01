#ifndef CAR_H
#define CAR_H
#include "Car_list.h"
#include<iostream>
using namespace std;
class Car{
    string exit_date;
    int cost;

 public:
    Car();
    ~Car();
    void calc_cost(current *tmp, int *cost);
    void calc_time(string *date);
    void findPos(current * HEAD);

};
#endif

