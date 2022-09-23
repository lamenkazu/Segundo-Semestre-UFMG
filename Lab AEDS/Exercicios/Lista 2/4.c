#include <stdio.h>

int questao4(){

    int mat[3] = {5, 9, 11};

    int *ptr;

    ptr = mat;

    printf(" %d", *(ptr));
    printf(" %d", *(ptr + 2));

    return 0;
}

/*

    Seja o código abaixo, pede-se: 
    (a) O que ser ́a impresso (responda antes de executar o programa)?
        Será impresso 6 e 9

    (b) E se acrescentarmos as trˆes linhas abaixo, o que ser ́a impresso?
        ptr = mat;
        printf(" %d", *(ptr));
        printf(" %d", *(ptr + 2));

            Será impresso 5 e 11


*/