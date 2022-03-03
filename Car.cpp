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
#include<vector>

Car::Car(){
    exit_date="";
    cost=1000;
    }
Car::~Car(){}

int calc_hour(string exit, string enter){
    cout<<"입차하신 시간 :"<<enter<<endl;
    cout<<"출차하실 시간 :"<<exit<<endl;
    exit += ":00";
    enter += ":00";
    struct tm intime;
    istringstream in(enter);
    // cout<<"확인"<<enter;
    in >> get_time(&intime, "%Y %m %d %H:%M:%S");
    struct tm outtime;
    istringstream out(exit);
    out >> get_time(&outtime, "%Y %m %d %H:%M:%S");
    // cout<<"exit"<<outtime.tm_mon;
    //" "기준으로 토큰으로 끊어서 각각 year, month, day, hour, min으로 넣기
    //같은 날 출차이면 그냥 빼기해서 계산
    //다른 날 출차이면 월이 다른 경우, 년이 다른 경우 따로 계산
    // printf("입차시간 : %d %d %d %d : %d", intime.tm_year, intime.tm_mon, intime.tm_mday, intime.tm_hour, intime.tm_min);
    // printf("출차시간 : %d %d %d %d : %d", outtime.tm_year, outtime.tm_mon, outtime.tm_mday, outtime.tm_hour, outtime.tm_min);
    double diff_time = difftime(mktime(&outtime), mktime(&intime));
    int t_hour, t_min;
    t_hour = diff_time / (60*60);
    diff_time = diff_time - (t_hour*60*60);
    t_min = diff_time / (60);
    diff_time = diff_time - (t_min*60);
    printf ("입차일과 출차일은 %d시간 %d분 차이가 납니다.\n", t_hour, t_min);
    printf("\n");
    return t_hour;

}

void Car::calc_cost(current *tmp, int *cost){
    Car *p=new Car;
    Mem m;
    calc_time(&(p->exit_date));
    int time = calc_hour(p->exit_date, tmp->enter_date);
    if(m.isMem(tmp->car_num)){
        cout<<tmp->car_num<<"님은 회원이십니다\n";
        p->cost = time*1000*0.8;
    }
    else{

        p->cost = time*1000;
    }
    *cost+=(p->cost);
    delete p;
    return;
}

void Car::calc_time(string *date){

    time_t curTime = time(NULL);
    struct tm *pLocal = localtime(&curTime);
    string year = to_string(pLocal->tm_year + 1900);
    string mon = "";
    if(pLocal->tm_mon+1<10){
        mon+="0";
    }
    mon += to_string(pLocal->tm_mon+1);
    string day="";
     if(pLocal->tm_mday+1<10){
        day+="0";
    }
    day += to_string(pLocal->tm_mday);

    string min="";
     if(pLocal->tm_min+1<10){
        min+="0";
    }
    min += to_string(pLocal->tm_min);

    string hour="";
     if(pLocal->tm_hour+1<10){
        hour+="0";
    }
    hour += to_string(pLocal->tm_hour);


    // string day = to_string(pLocal->tm_mday);
    // string hour = to_string(pLocal->tm_hour);
    // string min = to_string(pLocal->tm_min);

    *date = year+" "+mon+" "+day+" "+hour+":"+min;
    return;
}

void Car::findPos(current *HEAD){
    cout<<"찾으시는 자동차 번호를 입력하세요>>";
    char car_num[40]="";
    fgets(car_num,100,stdin);
    car_num[strlen(car_num)-1]='\0';
    current *tmp;
    tmp = HEAD;

    while(tmp){
        if(strcmp(tmp->car_num,car_num)==0){
            cout << tmp->floor<<"층 "<<(tmp->car_pos)+1 <<"번에 주차되어 있습니다.\n";
            cout<<endl;
            return;
        }

        tmp = tmp->next;
    }

    cout << "찾으시는 차량이 주차되어있지 않습니다." << endl;

    return;
}