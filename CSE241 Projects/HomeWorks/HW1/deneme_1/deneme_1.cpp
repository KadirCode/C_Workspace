#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

int lengthOfArray(const char *arr)  // returns lenght of a char pointer array
{
    int size = 0;

    while (*arr) 
    {
        size ++;
        arr ++;
    }

    return size;
}

int lengthOfInt(int number)  //returns length of an integer
{    
    int counter=0;

    while(number)
    {        
        number=number/10;
        counter++;
    }
      return (counter);
}

bool isValid(int numArr[], int size)    //check if the number is errorless
{
    int counter = 0;

    for(int i = 0; i < size ; i++)  //check for uniqeness
    {
        for(int j = 0; i < size; i++)   //if there is any identical numbers, return false.
        {
            if(i == j)  //skip for the comparison between two identical indexes
                continue;

            if(numArr[i] == numArr[j])
                return false;
        }
    }
    return true;
}

int* createRandNum(int sNumArr[], int size)
{

    srand(time(NULL));
    sNumArr[0] = rand()%9+1; // first number cant be 0
    
    int tmp = 0;
    bool exist = false;
    int counter = 1;

    if(size > 1)    
        sNumArr[size-1] = -1;   //for while loop to know where to stop
    while(sNumArr[size-1] == -1)
    {
        tmp = rand() % 9;   //create a random number
        for(int y = 0; y < counter; y++)    //loop through array and look for identical number as generated random number
        {

            if (tmp == sNumArr[y])
            {
                exist = true;

            }
        }
        if(!exist)  //if generated number is unique, ad it to array
        {
            sNumArr[counter] = tmp;
            counter++;  //go to next index in array
        }

        exist = false;  //reset exist boolean
        
    }

    return sNumArr;

}

void game(int sNumArr[], int size)
{
   
    char guess[] = "initialize";
    
    int turn;

    int firstCount = 0;
    int secondCount = 0;

    for(turn = 1; turn <= 100; turn++)
    {
        cin >> guess;

        if(lengthOfArray(guess) != size)
        {
            cout << "E1" << endl;;
            continue;
        }


        int gNumArr[size];
        for(int i = 0; i < size ; i++)
        {
            gNumArr[i] = guess[i]-48;   // turn char array to int one by one and put it in an array
        }

        if(!isValid(gNumArr,size))  //if user enters a number with identical numbers in it, give error.
        {
            cout << "E0" << endl;
            continue;
        }

        for (int i = 0; i < size; i++) {    //i is numbers from guessed number

            for (int j = 0; j < size; j++) {    //j is from secret number

                if (sNumArr[j] == gNumArr[i]) { //if found a match
                    
                    if(i == j)  //if its in the right place, increment firstCounter
                        firstCount++;
                    else        //if its in the wrond place, increment secondCounter
                        secondCount++;

                }

            }

        }

        if(firstCount == size)
        {
            cout << "FOUND " << turn << endl;
            return;
        }
        if(turn == 100)
        {
            cout << "FAILED";
        }
        cout << firstCount << ' ' << secondCount << endl;   //print result

        //reset counters
        firstCount = 0;
        secondCount = 0;

    }
    
}

int main(int argc, char** argv)
{
    srand(time(NULL));


    char* tmpp = argv[2];  //assign argument to a string for error check   
    if(argv[1][1] == 'r')   // Normal mode
    {
        if(lengthOfArray(tmpp) > 1 || argv[2][0] < 48 || argv[2][0] > 57 || tmpp == "0")  // if argument is not valid
        {
            cout << "E0" << endl;
            return 0;
        }
           
        int size = atoi(argv[2]);    //get size
        int tmpArr[size];   //create array
        int* sNumArr = createRandNum(tmpArr, size); //create unique random numbers array(secret number)

        game(tmpArr, size); //game function

    }
    else if(argv[1][1] == 'u')  //debug mode
    {
        int secretNum = atoi(argv[2]);
        int size = lengthOfInt(secretNum);
        if(size > 0 && size < 9)    //if entered secret number is size [0-9]
        {
            int numArr[size];   //create int array
            for(int i = size-1; i >= 0 ; i--)   //put number in an integer array
            {
                numArr[i] = secretNum%10;
                secretNum = secretNum/10;
            }

            if(isValid(numArr,size))    //if entered number is valid, start game
            {
                game(numArr,size);
            }
            else
            {
                cout << "E0";
            }
           
        }
        else
        {
            cout << "E0";
            return 0;
        }
    }

    return 0;
}