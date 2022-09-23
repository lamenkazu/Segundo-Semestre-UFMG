/*
    Na linguagem C padrao, dado um array arr[], sabemos que o valor de arr[0] pode
tamb ́em ser dado pela nota ̧c ̃ao com o operador asterisco (*), ou seja arr[0] pode ser
dado por ∗(arr +0). Faça um programa em C para gerar um vetor de tamanho 6, de
n ́umeros inteiros aleat ́orios entre 1 e 20, e use a nota ̧c ̃ao com o operador * para mostrar
seus elementos.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 6

int questao1(){

    int arr[TAM];

    for(int i = 0; i < TAM; i++){
        *(arr+i) = 1 + (rand() % 20) ;
    }

    for(int i = 0; i < TAM; i++){
        printf("%d ", *(arr+i));
    }

    printf("\n");


    return 0;
}