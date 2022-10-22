




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

    checker = ifProperty(myStr);    //check if entry is property or not

    if(checker){

        checker = 0;
        char * myItem;   

        char arr[STRING_LEN][STRING_LEN];   //items array
        int idx = 0;

        char* token = strtok(myStr, "+");   //use strtok to split  items with '+'
  
        while (token != NULL) {
            //printf("token [%d] is %s\n", idx, token);
            strcpy(arr[idx], token);    //put item to array
            idx++;  //increment array index
            token = strtok(NULL, "+");  //go to next token
        }
        //printf("---------------------------\n");

        for (int i = 0; i < idx ; i++)  //process items is item array
        {
            //printf("arr[%d] = %s\n",i,arr[i]);

            multiplicator = atoi(arr[i]);   //get multiplicator of the item
            //printf("multiplicator is: %d\n",multiplicator);

            myItem = strchr(arr[i],'*');    //get item name after the multiplicator
            myItem++;

            printf("What is %s?:\n",myItem);    //ask for current item

            scanf("%s",myStr);

            sum = multiplicator * myFunc(myStr,sum);    //go to recurrence with new item


        }


        
    }
    return sum + strtod(myStr,&ptr);    //string to double and add to total sum
    //return sum + (strtod(myStr,&ptr)*multiplicator);
}




int main(){

    double sum = 0.0;
    char myStr[STRING_LEN];
    char original[STRING_LEN];
    
    printf("Define Object: ");
    scanf("%s",myStr);

    memset(original, '\0', sizeof(original));   //for keeping main object
    strcpy(original, myStr);

    printf("What is %s?:\n",myStr);
    scanf("%s",myStr);
   
    sum = myFunc(myStr,sum);
    printf("Total cost of %s is: %lf \n",original,sum);

return 0;
}