#include <stdio.h>
#define LIMIT   10001
#define DEBUG   1

/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?
*/

int main()
{
    int i = 1, k = 2, j = 1;
    int flag;
    while(i <= 10001)
    {
        flag = 1;
        j++;
        for(k = 2; k < j; k++)
        {

            if((j % k)== 0)
            {
                flag = 0;
                break;
            }
        }


        if (flag == 1)
            i++;
        if (!DEBUG && flag)
        {
            printf("%d - Checked = %d\n",i-1, j);
            //getchar();
        }

    }
    printf("%d - Checked = %d\n",i-1, j);

}
