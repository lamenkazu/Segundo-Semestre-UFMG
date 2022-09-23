#include <stdio.h>
#define OK 0
#define TAM 5

void encontraMaiorBin(int vet[]){
    int maior = -99999999;

    for(int i = 0; i < TAM; i++){
        if(vet[i] > maior){
            maior = vet[i];
        }
    }

    printf("\nO maior valor eh: %d\n\n", maior);
}

int questao4(){

    int vet[TAM];

    FILE * arqBin;
    arqBin = fopen("questao2.bin", "rb");
    if(arqBin != NULL){
        for(int i = 0; i < TAM; i++){
            fread(&vet, sizeof(int), TAM, arqBin);
        }
        
        printf("Arquivo Lido Com Sucesso!\n");
        for(int i = 0; i < TAM; i++){
            printf("%d ", vet[i]);
        }
        encontraMaiorBin(&vet);
        fclose(arqBin);
    }

    return OK;
}