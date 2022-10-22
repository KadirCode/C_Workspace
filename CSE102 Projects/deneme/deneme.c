#include <stdio.h>



int main()
{
    int a  = 0;
    for (int i = a; i < 3; i++)
        {
            printf("a++ = %d\n",i);
        }


    int b  = 0;
    for (int i = b; i < 3; ++i)
        {
            printf("++b = %d\n",i);
        }

    return 0;
}