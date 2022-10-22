




#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define STRING_LEN 100


char *ptr;

int checker = 1;


int ifProperty(char *myStr)    //checks if our input is a property or a string entry
{
    for(int i = 0; i < strlen(myStr); i++)
    {
        if(myStr[i] == '*')
            return 1;
    }
    return 0;
}


double myFunc(char *myStr, double sum){

    int multiplicator = 1;
    printf("control_1\n");

    checker = ifProperty(myStr);
    if(checker){
        //entry var
        checker = 0;

        char arr[STRING_LEN][STRING_LEN];
        int arr_idx = 0;

        char * tokenPlus;
        char * myItem;
        
        char * context = NULL;

        tokenPlus = strtok_r(myStr, "+",&context); //first item

        for (int i = 0; (tokenPlus = strtok_r(myStr, " ", &context)); i++)
        {
            strcpy(arr[i], tokenPlus);
            arr_idx = i;
        }

        for (int i = 0; i < arr_idx ; i++)
        {
            printf("array is : %s \n",arr[i]);
        }

        /*
        printf("tokenPlus = %s\n",tokenPlus);//--------------

        multiplicator = atoi(tokenPlus);
        //printf("multiplicator is: %d\n",multiplicator);

        myItem = strchr(tokenPlus,'*');
        myItem++;

        printf("What is %s?:\n",myItem);

        scanf("%s",myStr);
        */

    }

    return sum + (strtod(myStr,&ptr)*multiplicator);
}




int main(){

    double sum = 0.0;
    char myStr[STRING_LEN];
    char original[STRING_LEN];
    
    printf("Define Object: ");
    scanf("%s",myStr);

    memset(original, '\0', sizeof(original));
    strcpy(original, myStr);

    printf("What is %s?:\n",myStr);
    scanf("%s",myStr);
    
    sum = myFunc(myStr,sum);
    printf("Total cost of %s is: %lf \n",original,sum);

return 0;
}