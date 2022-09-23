#include <stdio.h>

void questao3_2(){

    int val, aux;
    char lixo;

    printf("GERA TRIANGULO\nInforme o valor da base do triangulo: ");
    scanf("%d%c", &val, &lixo);
    aux = val;

    for(int i = 1; i <= val; i++){
        printf("Linha %d \t", i);
        for(int j = aux; j <= val; j++){
            printf("* ");
        }
        aux--;
        printf("\n");
    }

}
