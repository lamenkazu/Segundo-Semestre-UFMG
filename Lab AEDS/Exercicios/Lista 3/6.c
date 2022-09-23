#include <stdio.h>
#define OK 0
#define TAM 5

void ordenaIntAscBin(int vet[]){
    int aux;

    for(int i = 0; i < TAM-1; i++){
        for(int j = 0; j < TAM-1; j++){
            if(vet[j] > vet[j+1]){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }

    printf("Valores ordenados em ordem crescente: ");
    for(int i = 0; i < TAM; i++){
        printf("%d ", vet[i]);
    }
    printf("\n\n");

}

int questao6(){

    int vet[TAM];

    FILE * arqBin;
    arqBin = fopen("questao2.bin", "rb");
    if(arqBin != NULL){
        for(int i = 0; i < TAM; i++){
            fread(&vet, sizeof(int), TAM, arqBin);
        }

        printf("Arquivo Lido Com Sucesso!\n");
        ordenaIntAscBin(&vet);

        fclose(arqBin);
    }

    return OK;
}