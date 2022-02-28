#include "Mem.h"
#include "Fileload.h"
#include<cstring>
bool Mem::findPhoneNum(current *HEAD){
    current *tmp;
    string car_num;
    tmp=HEAD;

    cout<<"자동차 번호를 입력하세요 ";
    fgets(tmp->car_num,40,stdin);
    tmp->car_num[strlen(tmp->car_num)-1]='\0';
    
    
    while(tmp){
        if(tmp->car_num == car_num){
            cout<< "전화번호(개인사용금지)"<<endl;
            cout<<tmp->car_phone;
            return true;
        }
    }
    cout<< "찾으시는 번호의 차량이 없습니다"<<endl;
    return false;


}
bool Mem::isMem(string car_num){
    map<string, string> mem_map;
    Fileload *fp;
    fp->loadMem(mem_map); // 멤버 받아오기
    
    while(true){
        if(mem_map.find(car_num)==mem_map.end()){//끝까지 찾는 자동차 번호가 없다면
            return false;
            }
        else{
            cout<<mem_map[car_num]<<endl;
            return true;
        }
    }    
}
void Mem::registerMem(){
    string car_num;
    string phone_num;

    cout<<"등록하실 차량 번호를 입력해주세요"<<endl;
    getline(cin,car_num);

    cout<<"전화번호를 입력해주세요"<<endl;
    getline(cin,phone_num);
    
    ofstream fout;
    fout.open("member.txt",ios::out |ios::app);
    fout<<car_num<<'\t'<<phone_num<<endl;
    fout.close();
    return;

  
}
