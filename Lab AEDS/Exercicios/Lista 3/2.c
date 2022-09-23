#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define TAM 5

int questao2(){

    int vet[TAM];
    for(int i = 0; i < TAM; i++){
        vet[i] = rand()%1000;
    }

    FILE * arqBin;
    arqBin = fopen("questao2.bin", "wb");
    if(arqBin != NULL){
        for(int i = 0; i < TAM; i++){
            fwrite(&vet[i], sizeof(int), 1, arqBin);
        }

        printf("Arquivo Gravado com Sucesso!\n\n");
        fclose(arqBin);
    }

    return OK;
}