#include <stdio.h>

/*The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.*/

int main()
{
    int n = 100;
    int i;
    int square1 = 0;
    int square2;
    int sumsq = 0;
    for (i = 1; i <= n; i++)
    {
        square1 = square1 + i*i;
    }
    square2 = ((n+1)*(n/2))*((n+1)*(n/2));
    printf("The difference is %d!\n", square2 - square1);
}
