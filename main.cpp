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

	Mem m;
	Car c;

	
	current *HEAD=NULL;
    current *TAIL=NULL;


	current temp;

	// strcpy(temp.car_num,"1234");
	// strcpy(temp.car_phone,"12345");
	// strcpy(temp.enter_date,"2020 02 02 12:30");
	// temp.next=NULL;
	// temp.car_pos=1;

	// HEAD=&temp;
	// TAIL=&temp;

	loadPos(&HEAD,&TAIL);
	int num=0;
	while(true){
		cout<<"---------------------------------------\n";
		cout<<"         ****주차관리시스템****         \n";
		cout<<"---------------------------------------\n";
		cout<<"       1.입차           2.출차         \n";
		cout<<"3.주차장 전체 현황 보기  4. 번호 조회    \n";
		cout<<"     5.회원등록         6. 위치 확인    \n";
		cout<<"     7.load             8. 관리자 모드  \n";
		cout<<"     9.종료                            \n";
		cout<<"---------------------------------------\n";
		cout<<"---------------------------------------\n";
		cout<<endl;


		cout<<"선택하실 메뉴 번호를 입력하세요>>>>";
		cin >> num;

		cin.ignore(256,'\n'); //개행 무시 
		switch(num){
		 case(1)://입차
		 	p->enterCar(&HEAD,&TAIL);
			break;
		 case(2)://출차
		 	p->exitCar(&HEAD,&TAIL);
			savePos(HEAD);
			break;
		 case(3)://주차장 전체 현황 보기
		 	p->printPos(HEAD);
			break;
		 case(4)://전화번호 찾기
		 	m.findPhoneNum(HEAD);
			break;
		 case(5)://회원등록
		 	m.registerMem();
			break;
		 case(6)://위치 반환
		 	c.findPos(HEAD);
		 	break;
		 case(8)://관리자 모드
		 {
		 	Admin admin;
			Admin *a = &admin;

		 	break;
		 }
		 case(9)://종료
		 	return 0;
		 				 
		 }
	}
	delete p;
	return 0;
}
