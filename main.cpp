#include<iostream>
#include"./include/Parking.h"
#include"./include/Mem.h"
#include"./include/Car_list.h"
#include"./include/Car.h"
#include"./include/FileLoad.h"
#include<iomanip>
#include<cstring>
using namespace std;

int main(){
	Parking *p=new Parking();
	Mem m;
	Car c;

	
	current *HEAD=NULL;
    current *TAIL=NULL;

	int num=0;
	while(true){
		cout<<"주차관리시스템\n";
		cout<<"---------------------------------------\n";
		cout<<"---------------------------------------\n";
		cout<<"1.입차\n";
		cout<<"2.출차\n";
		cout<<"3.주차장 전체 현황 보기\n";
		cout<<"4.번호조회\n";
		cout<<"5.회원등록\n";
		cout<<"6.위치확인\n";
		cout<<"7.load\n";
		cout<<"9.종료\n";
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
		 case(9)://종료
		 	return 0;
		 				 
		 }
	}
	delete p;
	return 0;
}
