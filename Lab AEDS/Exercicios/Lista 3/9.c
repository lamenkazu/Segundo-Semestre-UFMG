#include <stdio.h>
#define OK 0
#define TAM_MAX 10

int questao9(){
    int vetPart1[TAM_MAX], vetPart2[TAM_MAX];



    FILE * arqBin;
    arqBin = fopen("arquivo20Inteiros.bin", "rb");
    if(arqBin != NULL){
        fread(&vetPart1, sizeof(int), TAM_MAX, arqBin);
        fseek(arqBin, 10 * sizeof(int), SEEK_SET);
        fread(&vetPart2, sizeof(int), TAM_MAX, arqBin);
        
        fclose(arqBin);
    }

    for(int i = 0; i < TAM_MAX; i++){
        printf("%d ", vetPart1[i]);
    }
        
    for(int i = 0; i < TAM_MAX; i++){
        printf("%d ", vetPart2[i]);
    }


    return OK;
}