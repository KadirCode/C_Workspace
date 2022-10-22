#include <stdio.h>

#define ARR_LEN 8

int arr[ARR_LEN][ARR_LEN];
int islandID = -1;

int findLand(int x,int y)
{

    if(x+1 < ARR_LEN && arr[x+1][y] > 0) //rigth
    {

        arr[x+1][y] = islandID;
        findLand(x+1,y);
    }

    if(x-1 >= 0 && arr[x-1][y] > 0) //left
    {
        arr[x-1][y] = islandID;
        findLand(x-1,y);
    }

    if(y+1 < ARR_LEN && arr[x][y+1] > 0) //down
    {
        arr[x][y+1] = islandID;
        findLand(x,y+1);
    }

    if(y-1 >= 0 && arr[x][y-1] > 0) //up
    {
        arr[x][y-1] = islandID;
        findLand(x,y-1);
    }

    return 0;
}

int main(){

    FILE *file;
    FILE *file_result;
    file = fopen("input.txt","r+");
    file_result = fopen("output.txt","w+");

    int num;
    int waterLevel;

    fscanf(file,"%d",&waterLevel);

    for(int y = 0; y < ARR_LEN; y++)    //place numbers into matrix
    {
        for(int x = 0; x < ARR_LEN; x++)
        {
            fscanf(file,"%d",&num);
            if(num > waterLevel)
            {
                arr[x][y] = num;
            }
            else
            {
                arr[x][y] = 0;  //put 0 for water
            }
            
        }
    }

    for(int y = 0; y < ARR_LEN; y++)    //loop through matrix for lands
    {
        for(int x = 0; x < ARR_LEN; x++)
        {
            if(arr[x][y] > 0)
            {
                arr[x][y] = islandID;
                findLand(x,y);
                islandID--;
            }
            
        }
    }

    int printID = 0;    //for tracing printing unique islands
    for(int y = 0; y < ARR_LEN; y++)    //fprint matrix
    {
        for(int x = 0; x < ARR_LEN; x++)
        {
            if(arr[x][y] < printID)
            {
                printID--;
                fprintf(file_result,"%d %d\n",x,y);
            }
        }
    }   
    
    fclose(file);       //close files.
    fclose(file_result);

    return 0;
}