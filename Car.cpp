#include <iostream>
using namespace std;

#include <time.h>
#include <string>
#include <cstring>
#include <sstream>
#include <locale>
#include <iomanip>

#include "./include/Car.h"
#include "./include/FileLoad.h"
#include "./include/Mem.h"

Car::Car(){
    exit_date="";
    cost=0;
    }
Car::~Car(){}

int calc_hour(string exit, string enter){

    struct tm intime;
    istringstream in(enter);
    in >> get_time(&intime, "%Y %m %d %H %M");
    
    struct tm outtime;
    istringstream out(exit);
    out >> get_time(&outtime, "%Y %m %d %H %M");
    //" "기준으로 토큰으로 끊어서 각각 year, month, day, hour, min으로 넣기
    //같은 날 출차이면 그냥 빼기해서 계산
    //다른 날 출차이면 월이 다른 경우, 년이 다른 경우 따로 계산

    
    double diff_time = difftime(mktime(&outtime), mktime(&intime));
    int t_hour, t_min;

    t_hour = diff_time / (60*60);
    diff_time = diff_time - (t_hour*60*60);

    t_min = diff_time / (60);
    diff_time = diff_time - (t_min*60);
    
    

    printf ("입차일과 출차일은 %d시 %d분 차이가 납니다.\n", t_hour, t_min);
    return t_hour;
}

void Car::calc_cost(current *tmp, int *cost){
    Car *p;
    Mem m;
    calc_time(&(p->exit_date));
    int time = calc_hour(p->exit_date, tmp->enter_date);
    if(m.isMem(tmp->car_num)){
        p->cost = time*1000*0.8;
    }
    
    p->cost = time*1000;

    return;
}

void Car::calc_time(string *date){

    time_t curTime = time(NULL);
    struct tm *pLocal = localtime(&curTime);
    string year = to_string(pLocal->tm_year+1900);
    string mon = to_string(pLocal->tm_mon+1);
    string day = to_string(pLocal->tm_mday);
    string hour = to_string(pLocal->tm_hour);
    string min = to_string(pLocal->tm_min);

    *date = year+" "+mon+" "+day+" "+hour+" "+min;
    return;
}

void Car::findPos(current *HEAD){
    string car_num;
    cin >> car_num;
    current *tmp;
    tmp = HEAD;

    while(tmp){
        if(tmp->car_num == car_num){
            cout << tmp->car_pos;
            return;
        }

        tmp = tmp->next;
    }

    cout << "찾으시는 차량이 주차되어있지 않습니다." << endl;

    return;
}