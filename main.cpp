#include<iostream>
#include"./include/Parking.h"
#include"./include/Mem.h"
#include"./include/Car_list.h"
#include"./include/Car.h"
#include"./include/FileLoad.h"
#include"./include/Admin.h"
#include<iomanip>
#include<cstring>
using namespace std;
int main(){
	Parking *p=new Parking();
	Mem *m=new Mem();
	Car *c=new Car();

	
	current *HEAD=NULL;
    current *TAIL=NULL;

	// int num=0;
	string snum;

	loadPos(&HEAD,&TAIL);
	while(true){
		cout << "-----------------------------------------------\n";
		cout << "	****주차 관리 시스템****     " << '\n';
		cout << "-----------------------------------------------\n";
		cout<<"	1.입차			2. 출차\n";
		cout<<"	3.현황 보기		4. 번호 조회\n";
		cout<<"	5.회원등록		6. 위치 확인\n";
		cout<<"	7.관리자 모드		8. 종료\n";
		cout << "-----------------------------------------------\n";
		cout << "-----------------------------------------------\n";
		cout<<endl;


		cout<<"선택하실 메뉴 번호를 입력하세요>>>>";
		int num=0;
		getline(cin,snum);
		if(!p->isNumber(snum)){
			num=0;
		}
		else{
			num=atoi(snum.c_str());
		}
		switch(num){
		 case(1)://입차
		 	if(p->enterCar(&HEAD,&TAIL))
				savePos(HEAD);
			break;
		 case(2)://출차
		 	p->exitCar(&HEAD,&TAIL);
			savePos(HEAD);
			break;
		 case(3)://주차장 전체 현황 보기
		 	{
			string sfloor="0";
			int floor=0;
			while(1){
				cout<<"층을 선택해주세요>>";
				getline(cin,sfloor);
				if(!p->isNumber(sfloor)){
					floor=0;
				}
				else{
					floor=atoi(sfloor.c_str());
				}
				if(floor>3 || floor<=0){
					cout<<"잘못된 층수를 입력하셨습니다.다시 입력해주세요\n";
					cout<<endl;
					continue;
				}
				break;
			}
		 	p->printPos(HEAD,floor);
			break;
			}
		 case(4)://전화번호 찾기
		 	m->findPhoneNum(HEAD);
			break;
		 case(5)://회원등록
		 	m->registerMem();
			break;
		 case(6)://위치 반환
		 	c->findPos(HEAD);
		 	break;
		 case(7)://관리자 모드
		 {
		 	Admin admin;
			Admin *a = &admin;

		 	break;
		 }
		 case(8)://종료
		 	return 0;
		default:
			cout<<"알맞은 숫자를 입력해주세요!\n";
			cout<<endl;
		 	continue;			 
		 }
	}
	delete p;
	delete m;
	delete c;
	return 0;
}