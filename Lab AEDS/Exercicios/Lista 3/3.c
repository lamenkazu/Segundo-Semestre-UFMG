#include <stdio.h>
#define OK 0
#define TAM 5

void encontraMaior(int vet[]){
    int maior = -99999999;

    for(int i = 0; i < TAM; i++){
        if(vet[i] > maior){
            maior = vet[i];
        }
    }

    printf("\nO maior valor eh: %d\n\n", maior);

}

int questao3(){

    int vet[TAM];

    FILE * arqTxt;
    arqTxt = fopen("questao1.txt", "r");
    if(arqTxt != NULL){
        for(int i = 0; i < TAM; i++){
            fscanf(arqTxt, "%d", &vet[i]);
        }

        printf("Arquivo Lido Com Sucesso!\nValores encontrados: ");
        for( int i = 0; i < TAM; i++){
            printf("%d ", vet[i]);
        }
        encontraMaior(&vet);
        fclose(arqTxt);
    }



    return OK;
}