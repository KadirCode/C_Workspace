

#include <stdio.h>

#include <string.h>

#define STRING_LEN 250

int strLength = 0;  
int idx = 0;    //keeping current index globally for looping through myStr char by char

FILE *file_result;


int myFunc(char *myStr,int dash)
{
    while(idx != strLength) //function will terminate when it comes to end of myStr
    {
        if(myStr[idx] == '(')   //go to next child node if current char is '('
        {
            idx++;
            myFunc(myStr,dash+1);   // increase dash count by 1 for going to child node
        }
        else if(myStr[idx] == ')')  //return the parent node if current char is ')'
        {
            idx++;
            return 0;
        }
        else if(myStr[idx] == ',')  // just increment idx if current char is ','
        {
            idx++;
        }
        else
        {
            for(int i = 0; i < dash; i++)   //put dashes as dash count
                fprintf(file_result,"%c",'-');
            fprintf(file_result,"%c\n",myStr[idx]); //put our current char
            idx++;
        }

    }

    return 1;
}

int main(){

    FILE *file;

    file = fopen("input.txt","r+"); //open text file
    file_result = fopen("output.txt","w+"); //create output file

    char myStr[STRING_LEN]; //main String
    int dash = 0;   //dash count for recursive purposes

    fgets(myStr, STRING_LEN, file); //get string from text file to myStr

    strLength = strlen(myStr); //get string length globally

    myFunc(myStr, dash);


return 0;
}