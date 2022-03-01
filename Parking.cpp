#include<cstring>
#include<iomanip>
#include "Parking.h"
#include "Car.h"

//입차 함수 기능
bool Parking::enterCar(current **HEAD,current  **TAIL){
    current *tmp;
    tmp=(current*)malloc(sizeof(current));
    if (tmp==NULL){
        cout<< "주차 공간을 할당 받지 못했습니다.\n";
        return false;
    }
    
    printPos(*HEAD);//전체 주차장 모습 보여줌
    
    
    //2. 주차 공간 선택
    while(true){
        cout<<"입차하실 공간 번호를 입력하세요: ";
        cin >> tmp->car_pos;
        if(CheckEmptyArea(*HEAD,tmp->car_pos)){ //이미 주차되어 있는지 확인
            cout<<"자동차 번호를 입력하세요: ";
            fgets(tmp->car_num,40,stdin);
            tmp->car_num[strlen(tmp->car_num)-1]='\0';

            cout<<"운전자 전화번호를 입력하세요: ";
            fgets(tmp->car_phone,40,stdin);
            tmp->car_phone[strlen(tmp->car_phone)-1]='\0';
            break;
        }
        else{//이미 주차되어있다면 다시 반복
            cout<<"이미 주차되어 있는 공간입니다.\n";
        }
    }


    //3. 입차 시간 기록 car *p p->enter_date=calc_time()    
    Car *ttime;
    string enterd=(tmp->enter_date); //tmp->enter_date:char[] -> string 변환
    ttime->calc_time(&enterd); //현재시간 불러오기
    tmp->next = NULL;
    (*TAIL)->next = tmp;
    (*TAIL)=tmp;

    return true;

}


//출차 함수 기능
bool Parking::exitCar(current **HEAD,current  **TAIL){
    current *tmp,*before;
    char exit_carnum[40];
    //1.Car:printPos->Parkinglot->p_position배열을 읽고 있으면->Car:car_pos 없으면->”없다고 출력”
    cout<<"출차하실 자동차 번호를 입력하세요: ";
    fgets(exit_carnum,40,stdin);
    exit_carnum[strlen(tmp->car_num)-1]='\0';

    Car *p; //Car클래스의 
    tmp=*HEAD;
    before=*HEAD;
    string exit_date;
    int cost;
    while(tmp){
        if(tmp-> car_num == exit_carnum){
            p->calc_time(&exit_date);  // 현재 시간을 받아오고
            p->calc_cost(tmp, &cost); //정산을 하고
            saveExit(tmp,&cost,exit_date);
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
            free(tmp); //해당 tmp해제
            break;
        }
        before = tmp;
        tmp = tmp -> next;
        return true;
    }
    if(tmp==NULL){
        cout<<"출차실 차량번호를 찾을 수 없습니다.\n";
    }
    return false;
            

    
}

//해당 주차장 구역이 비었는지 확인
bool Parking::CheckEmptyArea(current *HEAD, int car_pos){
    current *tmp;
    tmp=HEAD;
    while(tmp){
        if(tmp->car_pos == car_pos){
            return true;
        }
        tmp = tmp -> next;
    }
    return false;  
}

//주차장 전체 현황 출력
void Parking::printPos(current *HEAD){
    int p_arr[20]={0};
    current *tmp;
    tmp = HEAD;
    
    while(tmp){
        p_arr[tmp->car_pos] = 1; //tmp->car_pos 주차된 위치 정보가 존재하면 배열값 1로 전환 ==> 0:빈공간 1:주차된 공간
        tmp = tmp->next;
    }
    cout<<setw(80)<<setfill('-')<<' '<<endl;      //주차장 정보 출력 ui
        for(int i=0;i<4;i++){
            for(int j=0;j<5;j++){               
                if(p_arr[i*5+j]==0){
                    cout<<"|"<<setw(5)<<setfill(' ')<<'X'<<setw(5)<<setfill(' ')<<'|'<<setw(5)<<setfill(' ');
                }
                else{
                    cout<<"|"<<setw(5)<<setfill(' ')<<left<<(i*5+(j+1))<<setw(5)<<setfill(' ')<<'|'<<setw(5)<<setfill(' ');
            
                }
            }
            cout<<endl;
        }
        cout<<setw(80)<<setfill('-')<<' '<<endl;
}
  