#include "Admin.h"

void Admin::loadExit(){

    vector<string> getoneline_;

    FILE *inputFile = NULL;

    inputFile = fopen("./total.txt", "r");
    
    int lineCount = 1;

    if(inputFile != NULL){
        char buffer[256];

        while(!feof(inputFile)){
            fgets(buffer, sizeof(buffer), inputFile);

            char *ptr = strtok(buffer, ",");

            while(ptr != NULL){
                getoneline_.push_back(ptr);
                ptr = strtok(NULL, " ");
            }
        }
        memlist_.push_back(getoneline_);
        fclose(inputFile);

    }else {
        printf("입력 파일 존재 X. \n");
    }

    //file load 된 것 확인
    /*for(int i=0; i<memlist_.size(); i++){
        for(int j=0; j<getoneline_.size(); j++){
            cout << memlist_[i][j] << " ";
        }
        cout << '\n';
    }*/

}

int main(){
    Admin admin;

    admin.loadExit();

}