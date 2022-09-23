#include <stdio.h>
#define OK 0
#define TAM 5

void ordenaIntTxt(int vet[]){
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

int questao8(){

    int vet[TAM];
    FILE * arqTxt;

    arqTxt = fopen("questao1.txt", "r");
    if(arqTxt != NULL){
        for(int i = 0; i < TAM; i++){
            fscanf(arqTxt, "%d", &vet[i]);
        }
        printf("Arquivo lido com sucesso!\n\n");
        fclose(arqTxt);
    }

    arqTxt = fopen("questao1.txt", "w");
    if(arqTxt != NULL){
        ordenaIntTxt(&vet);
        for(int i = 0; i < TAM; i++){
            fprintf(arqTxt, "%d ", vet[i]);
        }

        fclose(arqTxt);
    }

    return OK;
}