#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define TAM 5

int questao1(){

    int vet[TAM];
    for(int i = 0; i < TAM; i++){
        vet[i] = rand() % 100;
    }

    FILE * arqTxt;
    arqTxt = fopen("questao1.txt", "w");
    if(arqTxt != NULL){
        for(int i = 0; i < TAM; i++){
            fprintf(arqTxt, "%d ", vet[i] );
        }

        printf("Arquivo Gravado com sucesso!\n\n");
        fclose(arqTxt);
    }





    return OK;
}