#include <stdio.h>
#include <stdlib.h>
#include "./include/FileLoad.h"
#include "./include/Car_list.h"
#include "math.h"
#include "string.h"

 void saveExit(current *tmp, int cost, char* exit_date ){

     printf("saveExit 시작\n");

     FILE *fp = fopen("total.txt","a");
     printf("파일 열기 성공\n");

     char string[20];
     int size = floor(log10(cost)+1);
     
     //순서 : tmp->car_num, tmp-> phone_num, temp -> enter_date, exit_date, cost

     fputs(tmp->car_num,fp);
     fputs(", ",fp);
     fputs(tmp->car_phone,fp);
     fputs(", ",fp);
     fputs(tmp->enter_date,fp);
     fputs(", ",fp);
     fputs(exit_date,fp);
     fputs(", ",fp);
     fprintf(fp, "%d \n",cost);

     printf("파일 저장 끝\n");

     fclose(fp);
 }

void savePos( current *HEAD){

     printf("savePos 시작\n");

     FILE *fp = fopen("parking.txt","a");
     printf("파일 열기 성공\n");

     current *tmp;
     tmp = HEAD;

     while(tmp){
        fputs(tmp->car_num,fp);
        fputs(", ",fp);
        fputs(tmp->car_phone,fp);
        fputs(", ",fp);
        fputs(tmp->enter_date,fp);
        fputs(", ",fp);
        fprintf(fp, "%d \n",tmp->car_pos);

        tmp = tmp->next;
     }

     printf("파일 저장 끝\n");

     fclose(fp);
}

void loadPos(current **HEAD, current **TAIL){
    FILE *fp = fopen("parking.txt", "r");

    current *tmp;
    
    while(1){
        tmp = (current*)malloc(sizeof(current));

        if(tmp == NULL){//예외처리

        }

        char string[100];

        //파일 받아오는거 완성하면 수정할것!!!
        while (1)
        {
            fgets(string, sizeof(string), fp);
            if(feof(fp)){
                break;
            }
            printf("%s", string);
            
            int idx = 0;
            while(string[idx] != ','){
                if(idx == 0 && (string[idx] == ' ' ||string[idx] =='\n')){
                    continue;
                }
                tmp->car_num[idx++] = string[idx];
            }
            tmp->car_num[idx] = '\0';
            
            idx = 0;
            while(string[idx] != ','){
                if(idx == 0 && (string[idx] == ' ' ||string[idx] =='\n')){
                    continue;
                }
                tmp->car_phone[idx++] = string[idx];
            }
            tmp->car_phone[idx] = '\0';
            
            idx = 0;
            while(string[idx] != ','){
                if(idx == 0 && (string[idx] == ' ' ||string[idx] =='\n')){
                    continue;
                }
                tmp->car_phone[idx++] = string[idx];
            }
            tmp->enter_date[idx] = '\0';
            
            
            idx = 0;
            while(string[idx] != ','){
                if(idx == 0 && (string[idx] == ' ' ||string[idx] =='\n')){
                    continue;
                }
                tmp->enter_date[idx++] = string[idx];
            }
            tmp->enter_date[idx] = '\0';

            idx = 0;
            int p = 0;
            while(string[idx] != ','){
                if(idx == 0 && (string[idx] == ' ' ||string[idx] =='\n')){
                    continue;
                }
                tmp->car_pos += (tmp->car_pos)*10 + string[idx]-'0';
            }
            


            if(*HEAD == NULL){
                *HEAD = *TAIL = tmp;
            }
            else{
                (*TAIL)->next = tmp;
                *TAIL=tmp;
            }
        }
        

    }
    fclose(fp);
}