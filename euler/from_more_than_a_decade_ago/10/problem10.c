#include <stdio.h>
#include <math.h>

/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/

int main()
{
    int i;
    int n;
    int flag;
    long long sum = 0;
    for (n = 2; n < 2000000; n++)
    {
        flag = 1;
        for (i = 2; i <= sqrt(n); i++)
        {
            if ((n % i) == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
//("n = %d\n", n);
  //          getchar();
            sum = sum + n;

        }
    }
    printf("Sum = %lld\n", sum);
}
