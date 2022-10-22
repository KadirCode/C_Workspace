







#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LEN 250

int strLenght = 0;
int idx = 0;

void myFunc(char *myStr,int dash)
{
    while(myStr[idx] != "\0")
    {
        if(myStr[idx] == '(')
        {
            idx++;
            printf("control 1\n");
            myFunc(myStr, dash+1);
        }
        else if(myStr[idx] == ')')
        {
            idx++;
            printf("control 2\n");
            dash--;
            return;
        }
        else if(myStr[idx] == ',')
            idx++;
        else
        {
            printf("control 3\n");
            if(dash > 0)
            {
                for(int i = 0; i < dash; i++)
                {
                    printf("-");
                }
            }
            printf("%c\n",myStr[idx]);
            idx++;
        }
    }
}




int main(){

    FILE *file;
    FILE *file_result;
    file = fopen("input.txt","r+");
    file_result = fopen("output.txt","w+");

    char myStr[STRING_LEN];
    int dash = 0;

    fgets(myStr, STRING_LEN, file);

    strLenght = strlen(myStr);

    printf("%s\n",myStr);

    printf("%d\n",strlen(myStr));

    myFunc(myStr, dash);


return 0;
}