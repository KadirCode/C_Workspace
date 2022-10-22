#include<stdio.h>
#include<string.h>

int main()
{
    char name[30];
    printf("Enter name: ");
    gets(name);     //Function to read string from user.
    printf("Name: ");
    puts(name);    //Function to display string.
    strlen(name); // length
    char str1[20] = "asdfasdf";
    char str2[20];
    strcpy(str2, str1); // copy str1 to str2
    strcat(str1,str2); // concatenate str2 to str1
    
    int result = strcmp(str1,str2); //return true if str1 and str2 are equal

    strlwr(str1);   //transform to lowercase
    strupr(str1);   //transform to uppercase
    
    return 0;
}