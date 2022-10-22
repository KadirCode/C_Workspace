




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

    checker = ifProperty(myStr);
    int multiplicator = 1;

    if(checker){
        //entry var
        checker = 0;
        char * tokenPlus;
        char * myItem;
        char * context = NULL;


        tokenPlus = strtok_r(myStr, "+",&context); //first item

        printf("tokenPlus = %s\n",tokenPlus);//--------------

        multiplicator = atoi(tokenPlus);
        //printf("multiplicator is: %d\n",multiplicator);

        myItem = strchr(tokenPlus,'*');
        myItem++;

        printf("What is %s?:\n",myItem);

        scanf("%s",myStr);

        sum = myFunc(myStr,sum);

        // loop through the string to extract all other tokens
        do {

            tokenPlus = strtok_r(NULL, "+",&context);

            if(tokenPlus != NULL){

                printf("tokenPlus1 = %s\n",tokenPlus);//--------------

                multiplicator = atoi(tokenPlus);
                //printf("multiplicator is: %d\n",multiplicator);

                myItem = strchr(tokenPlus,'*');
                myItem++;

                printf("What is %s?:\n",myItem);

                scanf("%s",myStr);

                sum = myFunc(myStr,sum);
            }

        }while( tokenPlus != NULL);


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