/*
1-> Search input file num by num.
2-> For each num, search it in array.
3-> If num already exist in array, increment its counter which is second column for that num.
4-> If num doesn't exist in array, add it to next available slot in array.
5-> Execute selection sort for first column which are numbers from input file.
6-> Execute selection sort for second column which are counts of our numbers. 
7-> Print the result array to output.txt file.
*/

/*
Time complexity: My program search through every integer in input file once so its time complexity is O(N) where N is number count.
There are 2 selection sorts but since there can be only 100 different integers, their time complexity is 2x(100^2) which is constant number and it doesn't included
in our time complexity. As a result, our time comlexity is O(N) where N is the number count in input.txt file.
*/

#include <stdio.h>
#include<ctype.h>

int main(){

    FILE *file;
    FILE *file_result;
    file = fopen("input.txt","r+");
    file_result = fopen("output.txt","w+");
    int num;
    int arr[100][2];
    int boolExist = 0;
    int cursor = 0;     //Cursor in array for index of last number.

    while(fscanf(file,"%d",&num) == 1)          //Search input file num by num.
    {
        for(int i = 0; i < cursor; i++)       //For each num, search it in array.
        {
            if(arr[i][0] == num)                //If num already exist in array, increment its counter which is second column for that num.
            {
                arr[i][1]++;
                boolExist = 1;
            }
        }
        if(boolExist == 0)                      //If num doesn't exist in array, add it to next available slot in array.
        {
            arr[cursor][0] = num;
            arr[cursor][1] = 1;
            cursor++;
        }
        boolExist = 0; //Reset bool value.
    }

 //Selection Sort.

    int tempNum = 0,tempCount = 0;
    int indexCursor = 0;
    int column = 0;

    for(column = 0; column < 2; column++){  //outer loop is for program to work on specific column. 0 for numbers, 1 for counts.

        for(int i = 0; i < cursor;i++)
        {
        tempNum = arr[i][0];         //get our first number and its count to temp integers.
        tempCount = arr[i][1];

        for(int y = i+1; y < cursor; y++)    //search for smallest number after our current row.
        {
            if(column == 0 && arr[y][0] < tempNum)      //searcing for minimum number.
            {
                tempNum = arr[y][0];
                tempCount = arr[y][1];
                indexCursor = y;
            }

            if(column == 1 && arr[y][1] < tempCount)    //searcing for minimum count for numbers.
            {
                tempNum = arr[y][0];
                tempCount = arr[y][1];
                indexCursor = y;
            }
        }

        if(indexCursor > 0)  //if there is such smaller number, swap it with the current one.
        {
            arr[indexCursor][0] = arr[i][0];
            arr[indexCursor][1] = arr[i][1];

            arr[i][0] = tempNum;
            arr[i][1] = tempCount;

            indexCursor = 0;
        }

        }
    }

   for(int i = 0; i < cursor; i++)  //print arr to output.txt
   {
       fprintf(file_result,"%d:%d\n",arr[i][0],arr[i][1]);
   }

    fclose(file);       //close files.
    fclose(file_result);

    return 0;
}