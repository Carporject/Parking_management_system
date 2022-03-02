#include "include/Admin.h"
#include <algorithm>

void Admin::loadExit(){

    FILE *inputFile = NULL;
    inputFile = fopen("./total.txt", "r");

    if(inputFile != NULL){
        char buffer[256];

        while(!feof(inputFile)){
            //한줄 씩 입력 받음
            if(!fgets(buffer, sizeof(buffer), inputFile)){

                printf(" \n 현재 멤버 수 0명 이므로 관리 불가 입니다 .. \n");
                break;
            }

            fgets(buffer, sizeof(buffer), inputFile);

            char *ptr = strtok(buffer, ",");

            while(ptr){
                string str(ptr);
                memlist_[lineCount].push_back(str);
                ptr = strtok(NULL, ",");
            }
            lineCount++;
        }
        fclose(inputFile);

    }else {
        printf("입력 파일 존재 X. \n");
    }
}

void Admin::printMemList(){

    if(lineCount < 1){printf("\n 현재 멤버수 0명이므로 관리 내역 조회 불가입니다.\n "); return;}

    cout << "전체 회원 수 : " <<  lineCount << endl;

    cout << "===================================================================="<<'\n';
    cout << "  차량번호      전화번호         입차일           출차일       요금"<<'\n';
    cout << "===================================================================="<<'\n';

    for(int i=0; i<lineCount; i++){
        for(int j=0; j<PINFO; j++){
            cout << this->memlist_[i][j] << " ";
        }cout << "\n";
    }
    cout << '\n';


}

void Admin::perDay(){

    if(lineCount < 1){printf("\n 현재 멤버수 0명이므로 관리 내역 조회 불가입니다.\n "); return;}

    int change_month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    string exit_date = this->memlist_[lineCount-1][3];  //출차일 기준으로 7일 계산

    // 문자열 parsing 
    string m = "";
    string d = "";

    for(int i=0; i<10; i++){ 
        if(i>=5 && i<=6){
            m += exit_date[i];
        }else if(i>=8 && i<=9){
            d += exit_date[i];
        }
    }

    month = stoi(m);
    day = stoi(d);


    // 마지막 출차일을 일 단위로 변환 
    int lastday = month * change_month[month] + day;

    // 가장 최근 이용자의 요금으로 total cost 초기화
    total_cost = stoi(this->memlist_[lineCount-1][4]);

    // 리스트 순회 하며 날짜 변환 -> 일단위로 변환 -> 차가 7일 이내면 요금 더함
    for(int k=lineCount-2; k>=0; k--){

        int diffday, diffmonth;
        int mon2day_ = 0;

        string diff = this->memlist_[k][3];

        string dm = "";
        string dd = "";

        for(int i=1; i<11; i++){ 
            if(i>=6 && i<=7){
                dm += diff[i];
            }else if(i>=9 && i<=10){
                dd += diff[i];
            }
        }

        diffday = stoi(dd);
        diffmonth= stoi(dm);

        mon2day_ = diffmonth * change_month[diffmonth] + diffday;

        if( (lastday - mon2day_) <=7 && (lastday - mon2day_) >= 0){
            string cost_ = this->memlist_[k][4];
            total_cost += stoi(cost_);

        }else break;
    }

    cout << " 최근 7일간 정산 금액 ==> " << total_cost << endl;

}

void Admin::perMonth() {

    if(lineCount < 1){printf("\n 현재 멤버수 0명이므로 관리 내역 조회 불가입니다.\n "); return;}

    string exit_date = this->memlist_[lineCount-1][3];  // 가장 최근 출차일

    // 문자열 parsing 
    string m = "";
    string y = "";

    for(int i=0; i<11; i++){ 
        if(i>=0 && i<=3){
            y += exit_date[i];
        }else if(i>=5 && i<=6){
            m += exit_date[i];
        }
    }
    month = stoi(m);
    year = stoi(y);   //이번년도

    cout << "이번년도 " << year << endl;

    // 가장 최근 이용자의 요금으로 total cost 초기화
    total_month_cost = stoi(this->memlist_[lineCount-1][4]);

    cout << "가장 최근 이용자 요금 " << total_month_cost << endl;

    // 리스트 순회 하며 날짜 변환 -> 일단위로 변환 -> 차가 7일 이내면 요금 더함
    for(int k=lineCount-2; k>=0; k--){
        int diffmonth = 0;
        int diffyear = 0;

        string diff = this->memlist_[k][3];

        string dm = "";
        string dy = "";

        for(int i=0; i<11; i++){ 
            if(i>=0 && i<=3){
                dy += diff[i];
            }else if(i>=5 && i<=6){
                dm += diff[i];
            }
        }
        diffmonth= stoi(dm);
        diffyear= stoi(dy);

        cout << "달라진 년도 " << diffyear << endl;

        if(diffyear != year){
            break;
        }else{
            if(month == diffmonth){
                string cost_ = this->memlist_[k][4];
                total_month_cost += stoi(cost_);

            }else break;
        }

    }

    cout << month << "월의 총 금액은 === >" << total_month_cost << endl;


}

void Admin::analyzeMonth(){

    if(lineCount < 1){printf("\n 현재 멤버수 0명이므로 관리 내역 조회 불가입니다.\n "); return;}

    // 리스트 순회 하며 날짜 변환 -> 일단위로 변환 -> 차가 7일 이내면 요금 더함
    int month_list[13] = {1,2,3,4,5,6,7,8,9,10,11,12};

    for(int m : month_list){
        total_month_cost = 0;
        for(int k=lineCount-2; k>=0; k--){

            int diffmonth;

            string diff = this->memlist_[k][3];

            string dm = "";

            for(int i=1; i<11; i++){ 
                if(i>=6 && i<=7){
                    dm += diff[i];
                }
            }
            diffmonth= stoi(dm);

            if(m == diffmonth){
                string cost_ = this->memlist_[k][4];
                total_month_cost += stoi(cost_);
            }
        }
        cost.push_back(total_month_cost);
    }
    
    int max = *max_element(cost.begin(), cost.end());

    int divide;
    if(max > 100000){
        divide = 10000;
        max = max/divide;
    }else if(max > 10000 && max < 100000){
        divide = 1000;
        max = max/divide;
    }

    for(max ; max>0; max--){
        int costj = 0;
        for(int j=0; j<13; j++){
            costj = cost[j] / divide;
            if(costj >= max){
                cout << " ░░░ ";
            }else cout << "     ";
        }
        cout <<'\n';
    }
    cout << "=============================================================" << endl; 
    cout << " 1월  2월  3월  4월  5월  6월  7월  8월  9월  10월  11월  12월" << endl; 
    cout << "===================월 별 요금 추이(만원단위)==================" << endl; 

}

/*void Admin::mostUser(){
    if(lineCount < 1){printf("\n 현재 멤버수 0명이므로 관리 내역 조회 불가입니다.\n "); return;}

    vector<pair<int,string>> user_cost_list;
    int user_cost;
    int idx = 0;

    while(lineCount+2 != idx){
        cout << idx << lineCount << endl;
        user_cost += stoi(this->memlist_[idx][4]);

        cout << "가격 " << user_cost << endl;

        if (this->memlist_[idx][0] != this->memlist_[idx+1][0]){
            user_cost_list.push_back(make_pair(user_cost, this->memlist_[idx][0]));
            user_cost = 0;            
        }
        idx++;

    }

    for(int i=0; i<user_cost_list.size(); i++){
        cout << user_cost_list[i].first <<" "<< user_cost_list[i].second << endl;
    }

    int max = -1;
    string max_s = "";
    for(int i=0; i<user_cost_list.size(); i++){
        if(user_cost_list[i].first > max){
            max = user_cost_list[i].first;
            max_s = user_cost_list[i].second; 
        }
    }

    cout << "전체 회원 중 VIP 고객의 차량번호      ==> " << max_s << '\n'; 
    cout << "전체 회원 중 VIP 고객의 총 지출 요금  ==> " << max << '\n'; 



}*/
