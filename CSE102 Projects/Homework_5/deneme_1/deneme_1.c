







#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LEN 250


void myFunc(char *myStr,int dash)
{
    for (int i = 0; i < strlen(myStr);i++){
        printf("Control 1\n");
        printf("%d\n",strlen(myStr));
        if(myStr[i] == '(')
            myFunc(myStr+i,dash+i);  //add dash to dash string
        else if(myStr[i] == ')')
            return;             //remove 1 dash from dash string by moving starting point forward by one
        else if(myStr[i] == ','){}
        else{
            printf("%s%s\n",dash,myStr[i]);
        }
    }
    return;
}




int main(){

    FILE *file;
    FILE *file_result;
    file = fopen("input.txt","r+");
    file_result = fopen("output.txt","w+");

    char myStr[STRING_LEN];

    fgets(myStr, STRING_LEN, file);
    printf("%d\n",strlen(myStr));
    myFunc(myStr,0);


return 0;
}