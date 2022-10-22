/*
1-> Search input file num by num.
2-> For each num, search it in array.
3-> If num already exist in array, increment its counter which is second column for that num.
4-> If num doesn't exist in array, add it to next available slot in array.
5-> Execute insertion sort for first column which are numbers from input file.
6-> Execute insertion sort for second column which are counts of individual numbers. 
7-> Print the result array to output.txt file.

Time complexity: My program search through every integer in input file once so its time complexity is O(N) where N is number count.
There are 2 insertion sorts but since there can be only 100 different integers, their time complexity is 2x(100^2) which is constant number and it doesn't included
in our time complexity. As a result, our time comlexity is O(N) where N is the number count in input.txt file.
*/

#include <stdio.h>
#include<ctype.h>

#define NROWS 100
#define NCOLS 2

int arr[NROWS][NCOLS];


void insertionSort(int arr[NROWS][NCOLS],int cursor){

    for(int i = 0; i < 2; i++){     //column selector loop. "0" is for numbers column, "1" is for counts column.

        for (int y = 1; y < cursor; y++) {  //loop through every number in array
            int tempNum = arr[y][i];
            int j = y - 1;  //j is for left number of our current number(tempNum)

            // Compare key with each element on the left of it until an element smaller than
            
            while (tempNum < arr[j][i] && j >= 0) { //Compare every number on our currents numbers left with our current number.
                arr[j + 1][i] = arr[j][i]; //move sorted number to the right
                --j;
            }
            arr[j + 1][i] = tempNum;    //put our number to desired position in array
        }

    }
    
};

int main(){

    FILE *file;
    FILE *file_result;
    file = fopen("input.txt","r+");
    file_result = fopen("output.txt","w+");
    int num;
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

    insertionSort(arr,cursor);   //Insertion Sort.
    
   for(int i = 0; i < cursor; i++)  //print arr to output.txt
   {
       fprintf(file_result,"%d:%d\n",arr[i][0],arr[i][1]);
   }

    fclose(file);       //close files.
    fclose(file_result);

    return 0;
}