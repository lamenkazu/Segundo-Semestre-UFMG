#include <stdio.h>
#define OK 0
#define TAM 5

void ordenaIntBin(int vet[]){
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

}

int questao7(){

    int vet[TAM];
    FILE * arqBin;

    arqBin = fopen("questao2.bin", "rb");
    if(arqBin != NULL){
        for(int i = 0; i < TAM; i++){
            fread(&vet, sizeof(int), TAM, arqBin);
        }
        printf("Arquivo lido com sucesso!");
        fclose(arqBin);
    }

    arqBin = fopen("questao2.bin", "wb");
    if(arqBin != NULL){
        ordenaIntBin(&vet);
        fwrite(&vet, sizeof(int), TAM, arqBin);        

        fclose(arqBin);
    }

    return OK;
}