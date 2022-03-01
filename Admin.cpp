#include "./include/Admin.h"


void Admin::loadExit(){


    vector<string> getoneline_;

    FILE *inputFile = NULL;

    inputFile = fopen("./total.txt", "r");
    
    int lineCount = 1;

    if(inputFile != NULL){
        char buffer[256];

        while(!feof(inputFile)){
            fgets(buffer, sizeof(buffer), inputFile);

            char *ptr = strtok(buffer, ",");

            while(ptr != NULL){
                getoneline_.push_back(ptr);
                ptr = strtok(NULL, " ");
                vector<string> getoneline_;
            }
        }
        memlist_.push_back(getoneline_);
        fclose(inputFile);

    }else {
        printf("입력 파일 존재 X. \n");
    }

    //%%%%%%file load 된 것 확인%%%%%
    for(int i=0; i<memlist_.size(); i++){
        for(int j=0; j<getoneline_.size(); j++){
            cout << memlist_[i][j] << " ";
        }
        cout << '\n';
    }

}

void Admin::perDay(){
    //차량번호, 전화번호, 입차일, 출차일, 정산요금
    vector<vector<string>> mlist;

    //TODO -> segmentation fault

    cout << this->memlist_[0][2] << endl;

}

void Admin::perMonth(){
    cout << " still upgrading ............... " << endl;
}



int main(){

    Admin admin;

    Admin *a = &admin;

    int select;

    cout << "주차 관리 시스템 관리자 모드" << '\n';

    cout << "1. 전체 회원 리스트 " << '\n';
    cout << "2. 일별 정산 요금 조회" << '\n';
    cout << "3. 월별 정산 요금 조회" << '\n';


    cin >> select;

    switch(select){
        case 1:
            a->loadExit();
            break;
        case 2:
            a->perDay();
            break;
        case 3:
            a->perMonth();
            break;
        case 0:
            break;
            return 0;
        default:
            cout << "잘못된 입력 입니다. " << select << endl;
    }

}
