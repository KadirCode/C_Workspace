#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

const int MAX_DIGITS = 10;

//fetches a sequence of digits from the input,
//converts to integer values, records size
void input( int numbe[], int& size);

//displays the large integer's digits int correct order on the screen
void output( const int number[], int size);

//input: two large integers
//output: a large integer that is the sum of the inputs
void add ( int first[], int firstSize, int second[], int secondSize, int sum[], int& sumSize);

int main()
{
    //Design decision: lower indices correspond to lower order digits

    int first[MAX_DIGITS+1]; //MAX_DIGITS + 1: to prevent glitch in input
    int firstSize;           //number of digits firstsize
    int second[MAX_DIGITS+1];
    int secondSize;
    int sum[MAX_DIGITS+1];
    int sumSize;

    cout << "Large integer summing program " << endl;
    cout << "Please enter an integer, 20 digits or less " << endl;
    input( first, firstSize);
    cout << "You entered" << endl;
    output (first, firstSize);
    cout << endl;
    cout << "Enter another integer, 20 digits or less " << endl;
    input( second, secondSize);
    cout << "You entered" << endl;
    output (second, secondSize); 
    cout << endl << endl;
 
    
    cout << "The sum is: " << endl;
    output(first, firstSize);
    cout << endl;
    output(second, secondSize);
    cout << endl;
    cout << "---------------------------" << endl;
    add(first, firstSize, second, secondSize, sum, sumSize);
    output(sum, sumSize);
    cout << endl;

    return 0;
}

void input( int number[], int& numberSize)
{
    char ch;
    int i = 0;
    numberSize = 0;
    cin.get(ch);
    while ( '\n' != ch)     // This error handling is too drastic.
    {
        //Error handling should allow user to reenter the number.
        if ( !isdigit(ch) )
        {
            cout << "non digit entered. Aborting. " << endl;
            exit(1);
        }
        number[i] = int(ch) - int('0');
        numberSize++;
        i++;
        cin.get(ch);
    }

    //more of the draconian error control!
    if (numberSize > 20)
    {
        cout << "Input number size too large. Aborting. " << endl;
        exit(1);
    }
    
    //Reverse array
    for ( int k = 0; k < numberSize/2; k++)
    {
        int temp = number[k];
        number[k] = number[numberSize-1-k];
        number[numberSize-1-k] = temp;
    }
}

void output( const int number[], int numberSize)
{
    //MS VC++ 6.0 puts for-loop control variable in surrounding block instead of the 
    //for-loop block, so declare it here for both for-loops
    int i;

    //insert lead spaces ro visually align the output.
    for(i = 20; i >= numberSize; i--)
        cout << " ";
    for(i = numberSize - 1; i >= 0; i--)
        cout << number[i];
    
    
}

void add(int first[], int firstSize, int second[], int secondSize, int sum[], int& sumSize)
{
    int carry = 0;
    int largerSize;
    //pad the input with the smaller number of digits to the size of the larger with zeros.
    if (firstSize > secondSize)
    {
        for (int i = secondSize; i < firstSize; i++)
            second[i] = 0;
        largerSize = firstSize;        
    }
    else
    {
        for(int i = firstSize; i < secondSize; i++)
            first[i] = 0;
        largerSize = secondSize;
    }
    
    // code to addition ...
    for(int i = 0; i < largerSize; i++)
    {
        sum[i] = first[i] + second[i] + carry;
        if(sum[i] > 9)
        {
            carry = 1;
            sum[i] = sum[i] -10;
        }
        else
            carry = 0;

        if(1 == carry)
        {
            if( largerSize == 20)
            {
                cout << "An overflow has occured. Result is set to 0. " << endl;
                sumSize = 1;
                sum[0] = 0;
            }
            else
            {
                sum[largerSize] = carry;
                sumSize = largerSize +1;
            }
        }
        else
            sumSize = largerSize;
    }
    
}