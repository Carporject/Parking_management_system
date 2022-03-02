#include "./include/Mem.h"
#include "./include/FileLoad.h"
#include<map>
#include<cstring>
#include<fstream>
using namespace std;
bool Mem::findPhoneNum(current *HEAD){
    current *tmp;
    char fcar_num[40]="";
    tmp=HEAD;

    cout<<"자동차 번호를 입력하세요 ";
    fgets(fcar_num,40,stdin);
    fcar_num[strlen(fcar_num)-1]='\0';
    
    
    while(tmp){
        if(strcmp(tmp->car_num ,fcar_num)==0){
            cout<< "전화번호(개인사용금지)"<<endl;
            cout<<tmp->car_phone<<endl;
            cout<<endl;
            return true;
        }
        tmp=tmp->next;
    }
    cout<< "찾으시는 번호의 차량이 없습니다"<<endl;
    cout<<endl;
    return false;


}
bool Mem::isMem(string car_num){
    map<string, string> mem_map={};
    loadMem(mem_map); // 멤버 받아오기
    
    while(true){
        if(mem_map.find(car_num)==mem_map.end()){//끝까지 찾는 자동차 번호가 없다면
            return false;
            }
        else{
            cout<<mem_map[car_num]<<endl;
            return true;
        }
    }    
    return true;
}
void Mem::registerMem(){
    string car_num="";
    string phone_num="";

    cout<<"등록하실 차량 번호를 입력해주세요>>";
    getline(cin,car_num);

    cout<<"전화번호를 입력해주세요>>";
    getline(cin,phone_num);
    
    ofstream fout;
    fout.open("member.txt",ios::out |ios::app);
    fout<<car_num<<','<<phone_num<<endl;
    fout.close();
    cout<<"회원등록이 완료되셨습니다. 감사합니다.\n";
    cout<<endl;
    return;

  
}
