#include <stdio.h>
#define OK 0
#define TAM 5

int encontraMaior(int vet[]){

    int maior = -999999999;

    for(int i = 0; i < TAM; i++){
        if(vet[i] > maior){
            maior = vet[i];
        }
    }

    return maior;
}

int questao14(){
    
    int vet[TAM];

    printf("Preencha um vetor de %d posicoes: ", TAM);
    for(int i = 0; i < TAM; i++){
        scanf("%d", &vet[i]);
    }

    printf("O maior valor do vetor eh: %d", encontraMaior(vet));

    return OK;
}