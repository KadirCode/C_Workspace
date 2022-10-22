//1-> Read char by char
//2-> Write every char to result text until encounter of a number or '-' (for negative numbers)
//3-> When encountring a number or a '-', move curser left by one and read number as integer
//4-> Move cursor in result txt to start and compare all numbers with the one in original file
//5-> If you find a number which is the same with the original one, put blank space in result file
//6-> If you don't find the same number in result file, put original number to result file.

//Time complexity: My program reads the file char by char so in worst case, time complexity for reading chars part is O(n) where n is char count. While reading,
//there is another loop for checking if the original number exist in result txt file. Worst case of that would be factorial of num count
//since second loop is going through every number exists in result text file. When we add them up, result is O(n + x!) where n is char count for original file
//and x is number count.

#include <stdio.h>
#include<ctype.h>

int main(){

    FILE *file;
    FILE *file_result;
    file = fopen("file.txt","r+");
    file_result = fopen("file_result.txt","w+");
    char c;
    int num;
    int num_record;
    int bool_check = 0;

    while((c = fgetc(file)) != EOF)  //scan our main txt file char by char
    {
        if(isdigit(c) || c == '-') //encounter of a number
        {
            fseek(file, -1, SEEK_CUR); // move cursor 1 digit backwards
            fscanf(file,"%d",&num); // get number from original file
            rewind(file_result); // move curser to start in result file
            
            while(fscanf(file_result,"%d",&num_record) == 1) //checking result txt for current numbers
                {
                    if(num == num_record)
                        bool_check = 1;
                }

            if(bool_check)  //if the number already exist in result file
                {
                    fprintf(file_result,"%c",' ');
                    bool_check = 0;
                }
            else            //if the number does not exist in result file
                fprintf(file_result,"%d",num);

        }
        else    //c is not a number so put whatever in original file to result file
            fprintf(file_result,"%c",c);

    }

    fclose(file);
    fclose(file_result);

    //replace result file with original file
    remove("file.txt");
    rename("file_result.txt","file.txt");

    return 0;
}