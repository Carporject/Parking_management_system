#include <iostream>
using namespace std;
#include <map>
#include <fstream>
#include <iostream>

#include "./include/FileLoad.h"

void loadMem(map <string, string> **mem_map){
    ifstream is;
    is.open("member.txt");
    string car;
    string phone;
    if(!is.is_open()){
        cout << "파일이 열리지 않았습니다." << endl;
    }
    while(!is.eof()){
        is >> car;
        is >> phone;

        (*mem_map)->insert(make_pair(car, phone));
    }

    is.close();

}