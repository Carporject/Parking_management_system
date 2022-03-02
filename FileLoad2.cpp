#include <iostream>
using namespace std;
#include <map>
#include<cstring>
#include <fstream>
#include <iostream>

#include "./include/FileLoad.h"

void loadMem(map <string, string> &mem_map){
    FILE *fp = NULL;
    fp = fopen("member.txt", "r");
    if(fp!=NULL){
        char buffer[100];
        while(1)
        {
            current *tmp;
            tmp = (current*)malloc(sizeof(current));
            fgets(buffer, sizeof(buffer), fp);
            if(feof(fp))
                break;
            if(buffer==NULL){
                break;
            }
            buffer[strlen(buffer)-1] = '\0';
            char *cnum;
            char *pnum;
            cnum = strtok(buffer, ",");
            pnum = strtok(NULL, ",");
            string car(cnum);
            string phone(pnum);
            (mem_map).insert(make_pair(car,phone));
        }
    }else{
        printf("파일이 존재하지 않습니다.\n");
    }
    fclose(fp);
    return;
}