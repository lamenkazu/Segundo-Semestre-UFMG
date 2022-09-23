#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define TAM 10

int main(){

    int vet[TAM];
    for(int i = 0; i < TAM; i++){
        vet[i] = rand() % 60;
    }

    FILE * arqBin;
    arqBin = fopen("arq2.bin", "wb");
    if(arqBin != NULL){
        fwrite(vet, sizeof(int), TAM, arqBin);

        fclose(arqBin);
    }

    return OK;
}