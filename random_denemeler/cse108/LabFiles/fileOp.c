#include <stdio.h>

int main(){

    FILE *fp;
    char filename[8] = "text.txt";
    fp = fopen(filename, "r");

/*
    r - read
    w - write, overwrite file if it ex ists
    a - write, but append instead of overwrite
    r+ - read & write, do not destroy file if it exists
    w+ - read & write, but overwrite file if it exists
    a+ - read & write, but append instead of overwrite
    b - may be appended to any of the above to force the file to be opened in binary mode rather than text mode

    1	fopen()	opens new or existing file
    2	fprintf()	write data into the file
    3	fscanf()	reads data from the file
    4	fputc()	writes a character into the file
    5	fgetc()	reads a character from file
    6	fclose()	closes the file
    7	fseek()	sets the file pointer to given position
    8	fputw()	writes an integer to file
    9	fgetw()	reads an integer from file
    10	ftell()	returns current position
    11	rewind()	sets the file pointer to the beginning of the file

*/

    return 0;
}