#include <stdio.h>


#define DEBUG   1
#define MAX     20
/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

int main()
{
    int i;
    int n = 1;
    int flag = 0;
    while (!flag)
    {
        for (i = 11; i <= MAX; i++) //11 to optimize
        {
            if (!DEBUG) printf("n = %d\n", n);
            if ((n % i) == 0)
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            printf("The number is %d!\n", n);
            break;
        }
        n++;
    }
}
