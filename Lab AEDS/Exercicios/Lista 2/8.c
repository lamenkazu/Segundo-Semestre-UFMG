#include <stdio.h>
#define OK 0

#define TAMA 5
#define RES 2

void descobreMaiorEMenor(int vet[], int res[]){

    int maior=-9999999, menor=9999999;

    for(int i = 0; i < TAMA; i++){
        if(vet[i] > maior){
            maior = vet[i];
        }
        if(vet[i] < menor){
            menor = vet[i];
        }
    }

    res[0] = menor;
    res[1] = maior;

}

int questao8(){

    int vet[TAMA], res[RES];

    for(int i = 0; i < TAMA; i++){
        vet[i] = rand() % 10;
    }

    for(int i = 0; i < TAMA; i++){
        printf("vet[%d] = %d\n", i, vet[i]);
    }

    descobreMaiorEMenor(vet, res);
    
    printf("O menor valor eh: %d\nO maior valor eh: %d\n", res[0], res[1]);


    return OK;

}