#include<iostream>
#include"Parking.h"
#include"Mem.h"
#include"Car_list.h"
using namespace std;
int main(){
	Parking *p;
	Mem *m;
	current *HEAD=NULL;
    current *TAIL=NULL;
	int num;
	cout<<"주차관리시스템";
	cout<<"--------------------------------\n";
	
	cout<<"1.입차\n";
	cout<<"2.출차\n";
	cout<<"3.주차장 전체 현황 보기\n";
	cout<<"4.번호조회\n";
	cout<<"5.회원등록\n";
	cout<<"6.위치확인\n";
	cout<<"9.종료\n";
	

	while(true){
		cout<<"선택하실 메뉴 번호를 입력하세요";
		cin >> num; 
		switch(num){
		 case(1)://입차
		 	p->enterCar(&HEAD,&TAIL);
		 case(2)://출차
		 	p->exitCar(&HEAD,&TAIL);
		 case(3)://주차장 전체 현황 보기
		 	p->printPos(HEAD);
		 case(4)://전화번호 찾기
		 	m->findPhoneNum(HEAD);
		 case(5)://회원등록
		 	m->registerMem();
		 case(6)://위치 반환
		 	
		 case(9)://종료
		 	break;
		 				 
		 }
	}
	return 0;
}
