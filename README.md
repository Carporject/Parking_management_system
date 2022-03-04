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



```
Clone the repo : git clone https://github.com/M-Parking-Project/Parking_management_system.git
MOBIS_06.tar -> tar -xvf MOBIS_06.tar
vi .bashrc=>export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/pi/lib 공유라이브러리 위치 설정
```

## 실행방법

1. 압축파일을 다운
2. tar -xvf MOBIS_06.tar 명령어를 사용하여 압축 해제
3. .bashsrc 파일에 공유라이브러리 위치 설정 (ex : export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/pi/lib 추가)
4. make명령어를 사용하여 컴파일
5. ./maincpp/main을 입력하여 실행


## Running the tests / 테스트의 실행
```
실행: ./maincpp/main
```

## 실행화면 예시

메인화면
![메인화면](https://user-images.githubusercontent.com/45057466/156688293-9cc96e5e-df8e-42fc-93c5-f3a50b50003b.PNG)

전화번호조회
![전화번호조회](https://user-images.githubusercontent.com/45057466/156688286-c3fe3b37-0d55-4f4e-906a-0639abd1d895.PNG)

출차
![출차](https://user-images.githubusercontent.com/45057466/156688289-3248895b-195a-4d9c-a956-35dbf200b6e1.PNG)

회원등록
![회원등록](https://user-images.githubusercontent.com/45057466/156688294-89e6518a-9c78-408a-9ffa-f9a5c189850c.PNG)

입차
![입차](https://user-images.githubusercontent.com/45057466/156688292-89f85fae-d75d-4dbc-be9a-c0d8678e70fa.PNG)

현황보기
![현황보기](https://user-images.githubusercontent.com/45057466/156688288-ae5500d9-fe61-4a15-9843-c42e65373b06.PNG)



## Built With / 팀원


이름|개발
---|---|
권현지|file 및 정산과 관련 기능 개발|
안현빈|관리자 기능 개발|
정해경|주차장과 회원 관련 기능 개발|



