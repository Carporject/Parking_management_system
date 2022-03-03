#include "include/Admin.h"
#include <algorithm>

void Admin::loadExit(){
    FILE *inputFile = NULL;
    inputFile = fopen("./total.txt", "r");
    char buffer[256];

    lineCount = 0;
    if(inputFile != NULL){

        char buffer[256];

        while(!feof(inputFile)){
            //한줄 씩 입력 받음
            if(!fgets(buffer, sizeof(buffer), inputFile)){
                break;
            }
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
        printf("X 입력 파일 존재 X. \n");
    }
}

void Admin::printMemList(){

    if(lineCount < 1){printf("\n 현재 이용자수가 0명이므로 관리 내역 조회 불가입니다.\n "); return;}

    cout << "========================================================================="<<'\n';
    cout << "  차량번호     전화번호           입차일             출차일         요금"<<'\n';
    cout << "========================================================================="<<'\n';

    for(int i=0; i<lineCount; i++){
        for(int j=0; j<PINFO; j++){
            if(j==PINFO-1){
                cout << this->memlist_[i][j];
                break;
            }
            cout << this->memlist_[i][j] << "   ";
        }cout << "\n";
    }
    
    cout << "========================================================================="<<'\n';
    cout << "전체 출차 이용객수 : " <<  lineCount << endl;
    cout << '\n';


}

void Admin::perDay(){

    if(lineCount < 1){printf("\n 현재 이용자수가 0명이므로 관리 내역 조회 불가입니다.\n "); return;}

    int change_month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    string exit_date = this->memlist_[lineCount-1][3];

    // 문자열 parsing 
    string m = "";
    string d = "";
    
    for(int i=1; i<11; i++){ 
        if(i>=5 && i<=6){
            m += exit_date[i];
        }else if(i>=8 && i<=9){
            d += exit_date[i];
        }
    }

    month = atoi( m.c_str());
    day = atoi( d.c_str());

    // 마지막 출차일을 일 단위로 변환 
    int lastday = 0;

    for(int i=1; i<month; i++){
        lastday += change_month[i];
    }
    lastday += day;

    total_cost = 0;
    // 리스트 순회 하며 날짜 변환 -> 일단위로 변환 -> 차가 7일 이내면 요금 더함
    cout << "\n";
    cout << "===================================================================="<<'\n';
    cout << " 차량번호    전화번호        입차일        출차일        요금"<<'\n';
    cout << "===================================================================="<<'\n';
    for(int k=lineCount-1; k>=0; k--){

        int diffday, diffmonth;
        int mon2day_ = 0;

        string diff = this->memlist_[k][3];

        string dm = "";
        string dd = "";

        for(int i=0; i<11; i++){ 
            if(i>4 && i<7){
                dm += diff[i];
            }else if(i>7 && i<10){
                dd += diff[i];
            }
        }

        diffmonth = atoi( dm.c_str());
        diffday = atoi( dd.c_str());


        for(int j=0; j<PINFO; j++){
            cout << this->memlist_[k][j] << " ";
        }cout << '\n';

        for(int m=1; m<diffmonth; m++){
            mon2day_ += change_month[m];
        }
        mon2day_ += diffday;

        if( abs(lastday - mon2day_) <=7 && abs(lastday - mon2day_) >= 0){
            string cost_ = this->memlist_[k][4];
            total_cost += atoi(cost_.c_str());
        }else break;
    }
    cout << "========================================================================="<<'\n';
    cout << " 마지막 이용 고객으로 부터 7일간 총 정산 금액 ==> " << total_cost <<"원 입니다"<< endl;
    cout<<endl;

}

void Admin::perMonth() {
    string search_month, search_year;
    int month,year;
    bool find = true;

    if(lineCount < 1){printf("\n 현재 이용자수가 0명이므로 관리 내역 조회 불가입니다.\n "); return;}

    cout << "조회 하고 싶은 년도와 달을 입력하세요." << endl;
    while(1){
        cout << "년도  : ";
        getline(cin,search_year);
        if(!Parking::isNumber(search_year)){
            year=0;
        }
        else{
            year=atoi(search_year.c_str());
        }
        if(year<=1900){
            cout<<"잘못된 년도를 입력하셨습니다.다시 입력해주세요\n";
            cout<<endl;
            continue;
        }
        break;
    }

    while(1){
        cout << "월(ex 3월: 3)   : ";
        getline(cin,search_month);
        if(!Parking::isNumber(search_month)){
            month=0;
        }
        else{
            month=atoi(search_month.c_str());
        }
        if(month<=0 || month>12){
            cout<<"잘못된 월를 입력하셨습니다.다시 입력해주세요\n";
            cout<<endl;
            continue;
        }
        break;
    }

    total_month_cost = 0;

    for(int k=lineCount-1; k>=0; k--){

        int diffmonth, diffyear;

        string diff = this->memlist_[k][3];

        string dm = "";
        string dy = "";
        
        for(int i=0; i<11; i++){ 
            if(i>4 && i<7){
                dm += diff[i];
            }else if(i>=0 && i<4){
                dy += diff[i];
            }
        }

        diffmonth= stoi(dm);
        diffyear= stoi(dy);

        if(month == diffmonth && year == diffyear){
            find = false;
            string cost_ = this->memlist_[k][4];
            total_month_cost += stoi(cost_);
        }

    }

    if(find == true){
        cout << " 찾으시는 정보가 없습니다 :( " << '\n';
    }else{
        cout << '\n';
        cout << "========================================================================="<<'\n';
        cout << year << "년 " << month << " 월의 총 금액은 ===> " << total_month_cost <<"원입니다\n"<<endl;
        cout << '\n';

    }

}

void Admin::analyzeMonth(){
    if(lineCount < 1){printf("\n 현재 이용자수가 0명이므로 관리 내역 조회 불가입니다.\n "); return;}
    string syear;
    int search_year_;
    bool find = true;
    vector<int> analyze_cost;
    while(1){
        cout << "분석 하고자 하는 년도를 입력하세요 : ";
        getline(cin,syear);
        if(!Parking::isNumber(syear)){
            search_year_=0;
        }
        else{
            search_year_=atoi(syear.c_str());
        }
        if(search_year_<=0){
            cout<<" 년도를 잘못 입력하셨습니다.다시 입력해주세요\n";
            cout<<endl;
            continue;
        }
        break;
    }


    for(int m=1;m<13;m++){
        total_month_cost = 0;
        for(int k=lineCount-1; k>=0; k--){
            int diffmonth, diffyear;
            string diff = this->memlist_[k][3];
            string dm = "";
            string dy = "";
            for(int i=0; i<11; i++){
                if(i>=5 && i<=6){
                    dm += diff[i];
                }else if(i>=0 && i<4){
                    dy += diff[i];
                }
            }
            diffmonth= atoi(dm.c_str());
            diffyear= atoi(dy.c_str());
            if(m == diffmonth && search_year_ == diffyear){
                find = false;
                string cost_ = this->memlist_[k][4];
                total_month_cost += stoi(cost_);
            }
        }
        cost.push_back(total_month_cost);
    }
    if(find == true){
        cout << '\n';
        cout << "찾으시는 년도가 리스트에 없습니다 :( " << endl;
        cout << '\n';
        return;
    }
    int whole = 0;
    double percent;
    double average;
    //전체를 구하고
    for(int i=0; i<cost.size(); i++){
        whole += cost[i];
    }

    //평균 / 전체 * 100
    for(int i=0; i<cost.size(); i++){
        percent = ((double)cost[i]/(double)whole)*100;
        analyze_cost.push_back(percent);
    }
    int max = *max_element(analyze_cost.begin(), analyze_cost.end());
    for(max ; max>0; max--){
        for(int j=0; j<analyze_cost.size(); j++){
            if(analyze_cost[j] >= max){
                cout << " ■■■ ";
            }else cout << "     ";
        }
        cout <<'\n';
    }

    cout << "=============================================================" << endl;
    cout << " 1월  2월  3월  4월  5월  6월  7월  8월  9월  10월  11월  12월" << endl;
    cout << "=================="<< search_year_<<"년의 월 별 요금 추이===================" << endl;
    cout<<endl;

}
