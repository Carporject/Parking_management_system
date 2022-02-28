#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>
#include <time.h>
using namespace std;

class Admin{
private:
    vector<string> car_num;
    vector<string> phone_num;
    vector<string> cost;
    vector<string> enter_date;
    vector<string> exit_date;

    int is_mem;
    int total_cost;


public:

    vector<vector<string>> memlist_;

    void loadExit();
    void perDay();
    void perMonth();

};