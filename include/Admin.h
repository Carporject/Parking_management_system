#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>

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
    int lineCount;
    int month, day, year;
    vector<int> cost;
    vector<string> memlist_[INT16_MAX];

public:

    Admin() {

        int secret;
        
        cout << "관리자 모드 : 비밀 번호를 입력하세요 ";
        cin >> secret;

        if(secret != 0000){
            cout << "암호가 틀렸습니다 !!!" << endl;
            exitCall();
        }

        loadExit();

        int select;

        while(true){

            cout << "-----------------------------------------------\n";
            cout << "     ****주차 관리 시스템 관리자 모드****     " << '\n';
            cout << "-----------------------------------------------\n";
            cout << "1. 전체 회원 리스트    2. 일별 정산 요금 조회" << '\n';
            cout << "3. 월별 정산 요금 조회 4. 월별 소득 추이" << '\n';
            cout << "5. 종료 (0 클릭)" << '\n';
            cout << "-----------------------------------------------\n";


            cout << "선택하실 메뉴 번호를 입력하세요 >>> ";
            cin >> select;

            switch(select){
                case 1:
                    printMemList();
                    break;
                case 2:
                    perDay();
                    break;
                case 3:
                    perMonth();
                    break;
                case 4:
                    analyzeMonth();
                    break;
                case 0:
                    return;
                default:
                    cout << "잘못된 입력 입니다. " << select << endl;
            }
        }
    }

    ~Admin(){}

    void loadExit();
    void printMemList();
    void perDay();
    void perMonth();
    void analyzeMonth();

    void exitCall(){
        exit(0);
    }


};