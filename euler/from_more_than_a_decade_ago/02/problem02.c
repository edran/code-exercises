#include    <stdio.h>

/*
1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

int main(){
    printf("By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.\n");
    long i;
    long temp;
    long total = 0;
    long list = 2;
    long old_list = 1;
    long true_list;
    while(list <= 4000000){
        true_list = list + old_list;
        if ((list % 2) == 0)
           total = total + list;
        old_list = list;
        list = true_list;
    }
    printf("The sum is = %d\n", total);
    getchar();
    getchar();
    
    
}
