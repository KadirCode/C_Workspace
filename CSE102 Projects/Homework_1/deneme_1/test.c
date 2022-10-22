#include <stdio.h>
#include<ctype.h>

int main(){

    FILE *file;
    FILE *file_result;
    file = fopen("C:\\Users\\abdul\\Desktop\\C workspace\\CSE102 Projects\\Homework_1\\file.txt","r+");
    file_result = fopen("C:\\Users\\abdul\\Desktop\\C workspace\\CSE102 Projects\\Homework_1\\file_result.txt","w+");
    int num;
    int num_record;
    int blank_counter = 0;
    char c;
    int bool_check = 0; //for boolean activities
    char blank = ' ';

    /*
    fscanf(file,"%d",&num);
    printf("num is: %d",num);
    fprintf(file_result,"%d",num);
    */

    while((c = fgetc(file)) != EOF)  //scan our main txt file char by char
    {

        if(c == ' ')
            blank_counter++;
        else if(isdigit(c)){
            if(blank_counter > 0){  //if there was a blank in beginning
                for(int i = 0; i < blank_counter; i++)  // put spaces in result txt file
                {
                    fprintf(file_result,"%c",blank);      

                    printf("blank counter is: %d\n",blank_counter);      // TEMP    
                }
                blank_counter = 0; //reset blank counter
            
                fseek(file, 1, SEEK_CUR); // move cursor 1 digit backwards

            }
            fscanf(file,"%d",&num);

            while(fscanf(file_result,"%d",&num_record) == 1) //checking result txt for current numbers
                {
                    if(num == num_record)
                        bool_check = 1;

                }
            rewind(file_result);
            
            if(bool_check)          //if num exist in result file, put blank instead
                fprintf(file_result,"%c",blank);
            else                    //if num does not exist in result file, put num
            {
                fprintf(file_result,"%d",num);
                bool_check = 0;
            }

        }
        else
            fprintf(file_result,"\n");
        

    }
    
    fclose(file);
    fclose(file_result);

    return 0;
}