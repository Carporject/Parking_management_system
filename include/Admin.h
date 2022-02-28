#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>
#include <time.h>
using namespace std;

class Admin{
private:
    string car_num;
    string phone_num;
    int is_mem;
    int total_cost;

    time_t enter_date;
    time_t exit_date;

public:

    vector<vector<string>> memlist_;

    void loadExit();
    void perDay();
    void perMonth();

};