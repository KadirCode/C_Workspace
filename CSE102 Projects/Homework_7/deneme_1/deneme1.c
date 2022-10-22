#include <stdio.h>
#include<ctype.h>

#define ARR_LEN 8

int arr[ARR_LEN][ARR_LEN];
int islandID = -1;

int findLand(int x,int y)
{

    if(x+1 < ARR_LEN && arr[x+1][y] > 0) //rigth
    {

        arr[x+1][y] == islandID;
        findLand(x+1,y);
    }

    if(x-1 > 0 && arr[x-1][y] > 0) //left
    {
        arr[x-1][y] == islandID;
        findLand(x-1,y);
    }

    if(y+1 < ARR_LEN && arr[x][y+1] > 0) //down
    {
        arr[x][y+1] == islandID;
        findLand(x,y+1);
    }

    if(y-1 > 0 && arr[x][y-1] > 0) //up
    {
        arr[x][y-1] == islandID;
        findLand(x,y-1);
    }

    return 0;
}


int main(){

    FILE *file;
    FILE *file_result;
    file = fopen("input.txt","r+");
    file_result = fopen("output.txt","w+");

    int waterLevel;
    int num;

    fscanf(file,"%d",&waterLevel);

    for(int i = 0; i < ARR_LEN; i++)    //place numbers into matrix
    {
        for(int y = 0; y < ARR_LEN; y++)
        {
            fscanf(file,"%d",&num);
            arr[i][y] = num;
        }
    }

    for(int x = 0; x < ARR_LEN; x++)    //place numbers into matrix
    {
        for(int y = 0; y < ARR_LEN; y++)
        {
            if(arr[x][y] > waterLevel)
            {
                arr[x][y] = islandID;
                findLand(x,y);
                islandID--;
            }
            else
            {
                arr[x][y] = 0;
            }
            
        }
    }

    for(int i = 0; i < ARR_LEN; i++)    //print matrix
    {
        for(int y = 0; y < ARR_LEN; y++)
        {
            printf("%d",arr[i][y]);
        }
        printf("\n");
    }   
    
    fclose(file);       //close files.
    fclose(file_result);

    return 0;
}