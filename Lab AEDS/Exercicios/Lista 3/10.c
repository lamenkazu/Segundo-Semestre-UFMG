#include <stdio.h>
#define OK 0
#define TAM 10

int verificaArquivosBin(FILE * arqBin1, FILE * arqBin2){

    int val1, val2;
    for(int i = 0; i < TAM; i++){
            fread(&val1, sizeof(int), 1, arqBin1);
            fread(&val2, sizeof(int), 1, arqBin2);
            if(val1 != val2){
                printf("Arquivos Não Identicos!\n\n");
                return !OK;
            }
            
    }
    printf("Arquivos Identicos!\n\n");
    return OK;

}

int questao10(){

    int val1, val2;
    FILE * arqBin1;
    FILE * arqBin2;

    arqBin1 = fopen("arq1.bin", "rb");
    arqBin2 = fopen("arq2.bin", "rb");
    if(arqBin1 != NULL && arqBin2 != NULL){

        verificaArquivosBin(arqBin1, arqBin2);

        fclose(arqBin1);
        fclose(arqBin2);
    }


    return OK;
}