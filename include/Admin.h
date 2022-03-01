#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>
#include <time.h>
using namespace std;

#define PINFO 5 // 차량번호, 전화번호, 입차일, 출차일, 요금

class Admin{
private:
    vector<string> car_num;
    vector<string> phone_num;
    vector<string> cost;

    string enter_date;
    string exit_date;

    int is_mem;
    int total_cost;

protected:
    int lineCount = 0;
    vector<string> memlist_[INT16_MAX];

public:

    Admin() {
        loadExit();
    }

    void loadExit();
    void print();
    void perDay();
    void perMonth();

    int change_month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

};