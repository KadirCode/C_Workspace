




#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define STRING_LEN 100

char *ptr;

int checker = 1;


int helper_func(char *myStr)    //checks if our input is a property or a string entry
{
    for(int i = 0; i < strlen(myStr); i++)
    {
        if(myStr[i] == '*')
            return 1;
    }
    return 0;
}


double myFunc(char *myStr, double sum){

    checker = helper_func(myStr);
    int multiplicator = 1;

    if(checker){
        //entry var
        checker = 0;

        char * tokenPlus;
        char * tokenAsterisk;

        tokenPlus = strtok(myStr, "+"); //first item

        printf("tokenPlus = %s\n",tokenPlus);//--------------

        tokenAsterisk = strtok(tokenPlus,"*");  //get multiplicator
        printf("multiplicator string = %s\n",tokenAsterisk);//--------------

        multiplicator = atoi(tokenAsterisk);    //make multiplicator integer
        printf("multiplicator = %d\n",multiplicator);//--------------

        tokenAsterisk = strtok(NULL, "*");  //ask second item
        printf("item = %s\n",tokenAsterisk); //------------

        printf("What is %s?:\n",tokenAsterisk);

        scanf("%s",myStr);

        sum = myFunc(myStr,sum);

        // loop through the string to extract all other tokens
        while( tokenPlus != NULL ) {
            tokenPlus = strtok(NULL, "+");

            tokenAsterisk = strtok(tokenPlus,"*");  //get multiplicator

            multiplicator = atoi(tokenAsterisk);    //make multiplicator integer

            tokenAsterisk = strtok(NULL, "*");  //ask second item

            printf("What is %s?:\n",tokenAsterisk);

            scanf("%s",myStr);

            sum = myFunc(myStr,sum);

        }


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