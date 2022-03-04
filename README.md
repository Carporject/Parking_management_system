# Parking_management_system

**[🚗주차장 관리 시스템🚗]**  

> 운전자에게 편리한 주차 시스템을 제공하기 위한 프로그램으로 입차,출차,정산 등의 기능을 수행할 수 있으며 관리자는 정산내역을 관리할 수 있는 프로그램
>

### Environment / 환경

```
실행 환경 : 가상머신 기반의 Raspbian
개발 환경 : C/C++, Raspbian(Linux), Mobaxterm, Visual studio code
```

### Prerequisites / 선행 조건

```
컴파일: MOBIS_06 폴더에서 make입력 -> 자동 컴파일
       
        MOBIS_06->make
        libcpp->make
        maincpp->make
    
```

### Installing / 설치


Clone the repo : git clone 
```
MOBIS_06.tar -> tar -xvf MOBIS_06.tar
vi .bashrc=>export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/pi/lib 공유라이브러리 위치 설정
```

## Preview




## Running the tests / 테스트의 실행
```
실행: ./maincpp/main
```

## 코드 점검표

테스트케이스와 테스트케이스를 실행했을때 예상 결과 확인용

![그림1](https://user-images.githubusercontent.com/45057466/156676646-203ebefb-2279-4694-b3b2-de4cc10c3d61.png)



## Built With / 팀원


이름|개발
---|---|
권현지|file 및 정산과 관련 기능 개발|
안현빈|관리자 기능 개발|
정해경|주차장과 회원 관련 기능 개발|



