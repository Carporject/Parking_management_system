#include<cstring>
#include<iomanip>
#include "./include/Parking.h"
#include "./include/Car.h"
#include"./include/FileLoad.h"
#include<iostream>
#include<regex>
using namespace std;
Parking::Parking(){
    total=20*3;
    empty_area=0;
    }
Parking::~Parking(){}
//입차 함수 기능
bool Parking::isNumber(string s) {
    if(s.size()==0) return false;
    for(int i=0;i<s.size();i++) {
        if(s[0]=='0') return false;
        if((s[i]>='0' && s[i]<='9')==false) {
            return false;
        }
    }
    return true;
}
bool Parking::enterCar(current **HEAD,current  **TAIL){
    current *tmp;
    tmp=(current*)malloc(sizeof(current));
    if (tmp==NULL){
        cout<< "저장 공간을 할당 받지 못했습니다.\n";
        return false;
    }
    while(1){
        cout << "============================================="<<'\n';
        cout<<"\t주차하실 층을 선택해주세요>> "<<endl;
        cout<<"\t\t";
        string sfloor="0";
        getline(cin,sfloor);
        cout<<endl;
        if(!Parking::isNumber(sfloor)){
            tmp->floor=0;
        }
        else{
            tmp->floor=atoi(sfloor.c_str());
        }
        if(tmp->floor>3 || tmp->floor<=0){
            cout<<"잘못된 층수를 입력하셨습니다.다시 입력해주세요\n";
            cout<<endl;
            continue;
        }
        break;
    }

    int curcnt=0;
    printPos(*HEAD,tmp->floor,curcnt);//전체 주차장 모습 보여줌
    if(curcnt==20){
        cout<<"해당층은 만차입니다.다른층을 선택해주세요.\n";
        cout<<endl;
        return false;
    }
    //2. 주차 공간 선택
    while(true){

        while(1){
            cout<<"입차하실 공간 번호를 입력하세요>>"<<endl;
            string spos="";
            getline(cin,spos);
            cout<<endl;
            if(!isNumber(spos)){
                tmp->car_pos=0;
            }
            else{
                tmp->car_pos=atoi(spos.c_str());
            }
            if (tmp->car_pos<=0 || tmp->car_pos>20){
                cout<<"번호를 잘못입력하셨습니다. 다시 입력해주세요\n";
                cout<<endl;
                continue;
            }
            break;
        }

        if(CheckEmptyArea(*HEAD,tmp->car_pos,tmp->floor)){ //이미 주차되어 있는지 확인
            tmp->car_pos-=1;
            cout<<"자동차 번호를 입력하세요>> "<<endl;
            fgets(tmp->car_num,100,stdin);
            tmp->car_num[strlen(tmp->car_num)-1]='\0';
            cout<<endl;

            if(Checkexitnum(*HEAD,tmp->car_num)){
                while(1){
                    cout<<"운전자 전화번호를 입력하세요>> "<<endl;
                    fgets(tmp->car_phone,100,stdin);
                    tmp->car_phone[strlen(tmp->car_phone)-1]='\0';
                    cout<<endl;
                    
                    string str(tmp->car_phone);                
                    regex re("[01]{3}-\\d{3,4}-\\d{4}");
                    if(regex_match(str, re) == 0){
                        cout << "잘못된 입력입니다. 전화번호 형식을 확인해주세요."<<endl;
                        cout<<endl;
                        continue;
                    }
                    break;
                }
                cout<<endl;
                cout<<"차량번호 "<<tmp->car_num<<"는"<<tmp->floor<<"층에 입차완료 되셨습니다\n";
                cout<<endl;
                break;
                }
            else{
                free(tmp);
                cout<<"\t이미 주차되어 있는 차량입니다\n";
                cout << "============================================="<<'\n';
                cout<<endl;
                return false;
            }
        }
        else{//이미 주차되어있다면 다시 반복
            cout<<"이미 주차되어 있는 공간입니다.\n";
            cout << "============================================="<<'\n';
            cout<<endl;
            return false;
        }
        cout << "============================================="<<'\n';
        cout<<endl;
        return true;
    }
    
    //3. 입차 시간 기록 car *p p->enter_date=calc_time()
    Car *ttime=new Car;
    string enterd=""; //tmp->enter_date:char[] -> string 변환
    
    ttime->calc_time(&enterd); //현재시간 불러오기
    strcpy(tmp->enter_date,enterd.c_str());
    tmp->next = NULL;                  //segementation 오류 지점
    
    if (*HEAD==NULL){
        (*HEAD)=(*TAIL)=tmp;
    }
    else{
        (*TAIL)->next = tmp;
        (*TAIL)=tmp;
    }
    delete ttime;//ttime할당 해제
    ttime=NULL;
    return true;
}
//출차 함수 기능
bool Parking::exitCar(current **HEAD,current  **TAIL){
    current *tmp,*before;
    char exit_carnum[100]="";
    
    //1.Car:printPos->Parkinglot->p_position배열을 읽고 있으면->Car:car_pos 없으면->”없다고 출력”
    cout<<endl;
    cout << "============================================="<<'\n';
    cout<<"\t출차하실 자동차 번호를 입력하세요: "<<endl;
    cout<<"\t\t";
    fgets(exit_carnum,100,stdin);
    exit_carnum[strlen(exit_carnum)-1]='\0';
    cout<<endl;
    
    Car *p=new Car; //Car클래스 생성자
    tmp=*HEAD;
    before=*HEAD;
    string exit_date="";
    int cost=0;
    char exitd[100]="";
    
    while(tmp){
        if(strcmp(tmp-> car_num,exit_carnum)==0){
            p->calc_time(&exit_date);  // 현재 시간을 받아오고
            strcpy(exitd,exit_date.c_str());
            p->calc_cost(tmp, &cost); //정산을 하고
            cout<<"\t총 가격: "<<cost<<"원 입니다"<<endl;
            
            saveExit(tmp,cost,exitd);
            
            cout<<tmp->car_num<<" 출차 처리되셨습니다.안녕히가십시오\n";
            cout<<endl;
            if(tmp ==(*HEAD)) {//  노드 위치 케이스 확인 필요!!!!!!!!!!(헤드, 테일, 중간)
                (*HEAD)=(*HEAD)->next;
            }
            else if(tmp == (*TAIL)){
                (*TAIL) = before;
                (*TAIL)->next = NULL;
            }
            else {
                before->next = tmp ->next;
            }
            free(tmp); //해당 tmp해제(삭제)
            break;
        }
        before = tmp;
        tmp = tmp -> next;
    }
    if(tmp==NULL){
        cout<<"\t출차하실 차량번호를 찾을 수 없습니다.\n";
        cout << "============================================="<<'\n';
        cout<<endl;
        delete p;
        return false;
    }
    cout << "============================================="<<'\n';
    cout<<endl;
    delete p;
    return true;
}
//해당 주차장 구역이 비었는지 확인
bool Parking::CheckEmptyArea(current *HEAD, int car_pos,int floor){
    current *tmp;
    tmp=HEAD;
    while(tmp){
        if(tmp->car_pos == (car_pos-1) && floor==tmp->floor){
            return false;
        }
        tmp = tmp -> next;
    }
    return true;
}
bool Parking::Checkexitnum(current *HEAD, string car_num){
    current *tmp;
    tmp=HEAD;
    while(tmp){
        if(strcmp(tmp->car_num ,car_num.c_str())==0){
            return false;
        }
        tmp = tmp -> next;
    }
    return true;
}
//주차장 전체 현황 출력
void Parking::printPos(current *HEAD,int curfloor,int &curcnt){
    int p_arr[3][20]={0};
    current *tmp;
    Parking *p=new Parking;
    tmp = HEAD;
    while(tmp){
        if (tmp->floor==curfloor){ //현재 층수 맞는지 확인
            // cout<<tmp->floor<<curfloor<<tmp->car_pos;
            p_arr[curfloor-1][tmp->car_pos] = 1; //tmp->car_pos 주차된 위치 정보가 존재하면 배열값 1로 전환 ==> 0:빈공간 1:주차된 공간
            curcnt++;
        }
        tmp = tmp->next;
        p->empty_area++;
    }

    cout<<setw(80)<<setfill('-')<<' '<<endl;      //주차장 정보 출력 ui
    cout<<setw(5)<<setfill(' ');
        for(int i=0;i<4;i++){
            cout<<setw(5)<<setfill(' ');
            for(int j=0;j<5;j++){
                if(p_arr[curfloor-1][i*5+j]==1){
                    cout<<"|"<<setw(5)<<setfill(' ')<<'X'<<setw(5)<<setfill(' ')<<'|'<<setw(5)<<setfill(' ');
                }
                else{
                    cout<<"|"<<setw(5)<<setfill(' ')<<left<<(i*5+(j+1))<<setw(5)<<setfill(' ')<<'|'<<setw(5)<<setfill(' ');
                }
            }
            cout<<endl;
        }
        cout<<setw(80)<<setfill('-')<<' '<<endl;
    // 추후 추가예정
    if(p->empty_area==p->total){
        cout<<"\t\t만차입니다.\n";
    }
    else{
        cout<<"\t\t\t차량 "<<(p->total)-(p->empty_area)<<"대 주차가능"<<endl;
    }
    delete p;
    cout<<endl;
}