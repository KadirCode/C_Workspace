#include<iostream>
using namespace std;
int main()
{
    bool prime = true;

    for(int i=3; i<=100; i++) //start from 3 adn go to 100
    {
        for(int j=2; j<i; j++) // check every number from 2 to current number
        {
           if(i%j==0)   //if there is a nnumber such that divides evenly, its not a prime number.
           {
               prime = false;
           }
        }
        if(prime) //if its prime, print.
            cout<<i<<endl;
        prime = true;
    }

    return 0;
}