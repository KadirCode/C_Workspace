#include <stdio.h>
#define ROWS 512
#define COLUMNS 512
#define MAX_ISLAND_NUMBER 100

int islandID = -1;

struct cell
{
    int cellID;
    char isIsland;
};

struct cell array[ROWS][COLUMNS];

void find_island(struct cell (*array)[COLUMNS], int row, int column, int water_level)
{

    if (array[row][column].cellID > 0 && array[row][column].isIsland != 'X') /* if current cell is not belong any island and the cell is land */
    {
        array[row][column].cellID = islandID; /*it was marked as an island.  X means it is island.*/
        if (column != COLUMNS - 1)         /* checks if it is on the boundary */
            find_island(array, row, column+1, water_level);
        if (row != ROWS - 1)               /* checks if it is on the boundary */
            find_island(array, row+1, column, water_level);
        if (column != 0)                   /* checks if it is on the boundary */
            find_island(array, row, column-1, water_level);
        if (row != 0)                      /* checks if it is on the boundary */
            find_island(array, row-1, column, water_level);
    }
}

int main()
{
    FILE *input, *output;
    input = fopen("input.txt", "r+");
    output = fopen("output.txt", "w+");

    int island_number = 0, cellValue, water_level;


    if (input == NULL) /* if file is not exist.*/
        return 0;

    fscanf(input, "%d", &water_level);
    int rowIndex, columnIndex;
    for ( rowIndex = 0; rowIndex < ROWS; rowIndex++)
        for ( columnIndex = 0; columnIndex < COLUMNS; columnIndex++)
        {
            fscanf(input, "%d", &cellValue);

            if (cellValue > water_level)                   /* Each cell will be marked according it is water or land */
                array[rowIndex][columnIndex].cellID = cellValue; /* it marks cell as Land*/
            else
                array[rowIndex][columnIndex].cellID = 0; /* it marks cell as Water*/
        }
    for (int rowIndex = 0; rowIndex < ROWS; rowIndex++)
        for (int columnIndex = 0; columnIndex < COLUMNS; columnIndex++)
            if (array[rowIndex][columnIndex].isIsland != 'X' && array[rowIndex][columnIndex].cellID > 0) /* if current cell is not belong any island and the cell is land*/
            {

                island_number++; 
                find_island(array, rowIndex, columnIndex, water_level);
                islandID--; 
            }
    int printID = 0;
    
    for(int y = 0; y < COLUMNS; y++)
    {
        for(int x = 0; x < ROWS; x++)
        {
            if(array[y][x].cellID < printID)
            {
                printID--;
                fprintf(output,"%d %d\n",x,y);               
            }
        }
    }

    
    fclose(input);
    fclose(output);
    return (0);
}