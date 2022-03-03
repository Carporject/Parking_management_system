#include "./include/Mem.h"
#include "./include/FileLoad.h"
#include "./include/FileLoad2.h"
#include<map>
#include<cstring>
#include<iomanip>
#include<fstream>
#include<regex>
#include<string>
using namespace std;
bool Mem::findPhoneNum(current *HEAD){
    current *tmp;
    char fcar_num[40]="";
    tmp=HEAD;
    cout<<endl;

    cout << "============================================="<<'\n';
    cout<<"\t자동차 번호를 입력하세요>> "<<endl;
    cout<<"\t\t";
    fgets(fcar_num,40,stdin);
    fcar_num[strlen(fcar_num)-1]='\0';
    cout<<endl;
    
    
    while(tmp){
        if(strcmp(tmp->car_num ,fcar_num)==0){
            cout<< "\t전화번호(개인사용금지)"<<endl;
            cout<<"\t   "<<tmp->car_phone<<endl;
            cout << "============================================="<<'\n';  
            cout<<endl;
            return true;
        }
        tmp=tmp->next;
    }
    cout<< "\t찾으시는 번호의 차량이 없습니다"<<endl;
    cout << "============================================="<<'\n';
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
            cout<<"전화번호: "<<mem_map[car_num]<<endl;
            return true;
        }
    }    
    return true;
}
void Mem::registerMem(){
    string car_num="";
    string phone_num="";
    cout<<endl;
    cout << "============================================="<<'\n';
    cout<<"\t등록하실 차량 번호를 입력해주세요>>"<<endl;
    cout<<"\t\t";
    getline(cin,car_num);

    map<string, string> mem_map={};
    loadMem(mem_map); // 멤버 받아오기
    cout<<endl;
    while(true){
        if(mem_map.find(car_num)==mem_map.end()){//끝까지 찾는 자동차 번호가 없다면
            while(1){
                    char *cur;
                    cout<<"\t운전자 전화번호를 입력하세요>> "<<endl;
                    cout<<"\t\t";
                    fgets(cur,100,stdin);
                    cur[strlen(cur)-1]='\0';
                    cout<<endl;

                    string str(cur);        
                    phone_num=str;        
                    regex re("[01]{3}-\\d{3,4}-\\d{4}");
                    if(regex_match(str, re) == 0){
                        cout << "잘못된 입력입니다. 전화번호 형식을 확인해주세요."<<endl;
                        cout<<endl;
                        continue;
                    }
                    break;
                }
            cout<<endl;
            ofstream fout;
            fout.open("member.txt",ios::out |ios::app);
            fout<<car_num<<','<<phone_num<<endl;
            fout.close();
            cout<<"\t회원등록이 완료되셨습니다. 감사합니다.\n";
            cout << "============================================="<<'\n';
            cout<<endl;
            break;
            }
        else{
            cout<<"\t이미 등록된 회원이십니다.\n"<<endl;
            cout << "============================================="<<'\n';
            cout<<endl;
            return;
        }
    }
    return;

  
}