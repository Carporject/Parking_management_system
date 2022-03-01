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
    string car_num;
    string phone_num;

    string enter_date;
    string exit_date;

    int is_mem;
    int total_cost;
    int total_month_cost;

protected:
    int lineCount = 0;
    int month, day, year;
    vector<int> cost;
    vector<string> memlist_[INT16_MAX];

public:

    Admin() {
        loadExit();
    }

    void loadExit();
    void printMemList();
    void perDay();
    void perMonth();
    void analyzeGraph();


};