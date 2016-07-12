#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LIMIT   999
#define DEBUG   1

/* Project Euler - Problem 04
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/
void reverse(char s[])
{
      int c, i, j;

      for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
      }
}

int main(){


    int res, i, k, j;
    char sres[30];
    char inv_sres[30];
    int len;
    int flag;
    int final = 0;

    for(i = 1; i <= LIMIT; i++){
        for(k = 1; k <= LIMIT; k++){
            res = i * k;
            itoa(res, sres, 10);
            itoa(res, inv_sres, 10);
            reverse(inv_sres);
            len = strlen(sres);
            flag = 1;
            for(j = 0; j < len; j++){
                if(sres[j] != inv_sres[j])
                    flag = 0;
                }
            if (flag == 1){
                if(!DEBUG) printf("%d is palindrome!\n", res);
                if(!DEBUG) getchar();
                if (res > final){
                    final = res;
                    printf("Il massimo e' %d\n", final);
                    }
                }
            }
        }
    }
