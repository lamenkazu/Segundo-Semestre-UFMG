/*
    Reescreva o programa abaixo usando ponteiros

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int questao3(){


    int *v;
    v = (int*) malloc(10 * sizeof(int));

    time_t t;
    srand((unsigned)time(&t)); //funcao time() recebe o endereço de t
    
    for(int i = 0; i < 10; i++){
        v[i] = rand()%20;
    }
    
    for(int i = 0; i < 10; i++){
        printf("V[%d]=%i\n", i+1, v[i]);
    }


    return 0;
}