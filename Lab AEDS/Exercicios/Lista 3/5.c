#include <stdio.h>
#define OK 0
#define TAM 5

void ordenaIntAsc(int vet[]){
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

int questao5(){

    int vet[TAM];

    FILE * arqTxt;
    arqTxt = fopen("questao1.txt", "r");
    if(arqTxt != NULL){
        for(int i = 0; i < TAM; i++){
            fscanf(arqTxt,"%d", &vet[i]);
        }

        printf("Arquivo Lido com Sucesso!\n");
        ordenaIntAsc(&vet);

        fclose(arqTxt);
    }

    return OK;
}