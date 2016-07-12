#include    <stdio.h>

/*
Project Euler - 1
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 BELOW 1000.
*/

int main(){
    int i;
    int total = 0;
    printf("Find the sum of all the multiples of 3 or 5 BELOW 1000\n");
    for(i = 0; i < 1000; i++){
        if((i % 3 == 0) || (i % 5 == 0))
              total = total + i;
        }
    printf("Il totale e' = %d\n", total);
    getch();
    getch();

}
