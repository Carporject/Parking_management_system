#include <stdio.h>
#include <stdlib.h>
#include "./include/FileLoad.h"
#include "./include/Car_list.h"
#include "math.h"
#include "string.h"

 void saveExit(current *tmp, int cost, char* exit_date ){

    //  printf("saveExit 시작\n");

     FILE *fp = fopen("total.txt","a");
    //  printf("파일 열기 성공\n");

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

    //  printf("파일 저장 끝\n");

     fclose(fp);
 }

void savePos(current *HEAD){

    //  printf("savePos 시작\n");

     FILE *fp = fopen("parking.txt","w");
    //  printf("파일 열기 성공\n");

     current *tmp;
     tmp = HEAD;
     while(tmp){
        fputs(tmp->car_num,fp);
        fputs(",",fp);
        fputs(tmp->car_phone,fp);
        fputs(",",fp);
        fputs(tmp->enter_date,fp);
        fputs(",",fp);
        fprintf(fp, "%d\n",tmp->car_pos);

        tmp = tmp->next;
     }

    //  printf("파일 저장 끝\n");

     fclose(fp);
}

void loadPos(current **HEAD, current **TAIL){
    printf("loadPos\n");
    FILE *fp = NULL;
    fp = fopen("parking.txt", "r");
    if(fp!=NULL){
        char string[100];
        while(1)
        {
            current *tmp;
            tmp = (current*)malloc(sizeof(current));
            fgets(string, sizeof(string), fp);
            if(feof(fp))
                break;
            if(string==NULL){
                break;
            }
            string[strlen(string)-1] = '\0';
            printf("%s\n",string);
            char *ptr = strtok(string, ",");
            strcpy(tmp->car_num, ptr);
            ptr = strtok(NULL, ",");
            strcpy(tmp->car_phone, ptr);
            ptr = strtok(NULL, ",");
            strcpy(tmp->enter_date, ptr);
            ptr = strtok(NULL,",");
            for(int i = 0; i<strlen(ptr); i++){
                // printf("%d ptr:%d num:%d", i, ptr[i], ptr[i]-'0');
                tmp->car_pos = tmp->car_pos*10 + (ptr[i]-'0');
                // printf("%d\n",tmp->car_pos);
            }
            printf("%d\n",tmp->car_pos);
            if(*HEAD == NULL){
                *HEAD = *TAIL = tmp;
            }
            else{
                (*TAIL)->next = tmp;
                *TAIL=tmp;
            }
        }
    }else{
        printf("파일이 존재하지 않습니다.\n");
    }
    fclose(fp);
    return;
}