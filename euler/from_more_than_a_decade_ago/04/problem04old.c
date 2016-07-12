#include    <stdio.h>
#include    <string.h>
#include    <math.h>

/* Project Euler - Problem 04
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#define LIMIT  99
#define DEBUG   0

int main(){
    int i;
    int k;
    int j;
    int result;
    float fresult;
    char buff[20];
    int result_len;
    int result_len_fixed;
    float listn[20];
    float inv_listn[20];
    for(i = 1; i <= LIMIT; i++){
        for(k = 1; k <= LIMIT; k++){
        result = i * k;
        printf("----------\n");
        if(!DEBUG)  printf("Pure result = %d\n", result);
        itoa(result, buff, 10);
        result_len = strlen(buff);
        result_len_fixed = result_len;
        if(!DEBUG)  printf("Len = %d\n", result_len);
        fresult = result;
        ///////////////////////////////////////////////////////
        /*40044
        4004,4
        400,44
        40,044
        4,0044
        k = n-1
        k = pow(10, k)
        k = k / 100

        4,0044
        40,044
        400,44
        4004,4
        40044
        40044
        44004*/
        ///////////////////////////////////////////////////////
        j = result_len - 1;
        j = pow(10, j);
        while(result_len > 0){
            listn[result_len_fixed - result_len] = fresult /*/ pow(10, result_len - 1)*/;
            inv_listn[result_len - 1] = fresult * j/* * pow(10, result_len - 1)*/;
            j = j / 100;
            if(!DEBUG) printf("%d - %f\n%d- %f\n", result_len_fixed - result_len, listn[result_len_fixed - result_len], result_len - 1, inv_listn[result_len - 1]);
            fresult = fresult / 10.0;
            result_len--;
            }
        result_len = result_len_fixed;
        int flag = 1;
        //if(!DEBUG)  printf("Result = %s\n", listn);
        //if(!DEBUG)  printf("Inv_result = %s\n", inv_listn);
        if(!DEBUG)  getchar();
        while(result_len > 0){
        if(listn[result_len - 1] != inv_listn[result_len - 1]){
            flag = 0;
            if(!DEBUG)  printf("NOT\n");
            if(!DEBUG)  printf("%d - %f\n%d- %f\n", result_len - 1, listn[result_len - 1], result_len - 1, inv_listn[result_len - 1]);
            }
        result_len--;}
        if(flag) printf("%d is palindome!\n", result);

        }





        }

    /*
    int i;
    int k;
    int j;
    int result_i;
    int inv_result_i;
    int risultato;
    char result[100];
    char inv_result[100] = {};
    int len_result;
    int bestof = 0;
    for(i = 1; i <= LIMITE; i++){
        for(k = 1; k <= LIMITE; k++){
            risultato = i * k;
            //if(!DEBUG) printf("Risultato = %d\n", risultato);
            //if(!DEBUG) getchar();
            sprintf(result, "%d", risultato);
            len_result = strlen(result);
            //if(!DEBUG) printf("LEN = %d\n", len_result);
            //if(!DEBUG) getchar();
            for (j = len_result - 1; j >= 0; j--){
                inv_result[len_result - j] = result[j];
                //if(!DEBUG) printf("inv = %s\n", inv_result), printf("res = %s\n", result);
                if(!DEBUG){
                    //printf("STRONZO\n"),
                    printf("res = %c\n", result[j]);
                    printf("inv = %c\n", inv_result[len_result - j]);
                    getchar();
                    }
                }
            inv_result[len_result + 1] = '\0';
            if(!DEBUG) printf("inv = %s\n", inv_result), printf("res = %s\n", result);
            result_i = atoi(result);
            inv_result_i = atoi(inv_result);
            if(!DEBUG){
                printf("%d\n", result_i);
                printf("%d\n", inv_result_i);
                getchar();}
            if(result_i == inv_result_i){                                        //strcmp(result,inv_result) > 0){
                if(!DEBUG) printf("strcmp\n"), getchar();
                //result_i = atoi(result);
                //printf("result_i = %d"
                if(result_i > bestof)
                    bestof = result_i;
                    printf("%d\n", bestof);
                }
            }
    }
    printf("Il risultato è = %d\n", bestof);
    getchar();
    getchar();
    */
}
    /*
    char numeroStringa[20];
    int numero;
    int lung;
    scanf("%d", &numero);
    sprintf(numeroStringa,"%d", numero);
    printf("WOW, la stringa 200 è diventata %s!\n", numeroStringa);
    lung = strlen(numeroStringa);
    printf("La lunghezza è %d\n", lung);
    printf("%c\n", numeroStringa[0]);
    printf("%c\n", numeroStringa[1]);
    printf("%c\n", numeroStringa[2]);
    printf("%c\n", numeroStringa[3]);
    printf("%c\n", numeroStringa[4]);
    printf("%c\n", numeroStringa[5]);
    getchar();
    getchar();
    */


