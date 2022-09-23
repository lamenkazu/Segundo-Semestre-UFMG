#include <stdio.h>
#define OK 0

int calculaSomatorio(int inicio, int final){
    int soma = 0;
    for(int i = inicio; i <= final; i++){
        soma += i;
    }

    return soma;
}

int questao13(){

    int inicio, final;

    printf("Calcule o Somatorio\nInforme o inicio: ");
    scanf("%d", &inicio);
    printf("Informe o final: ");
    scanf("%d", &final);

    printf("O somatorio de %d a %d eh %d", inicio, final, calculaSomatorio(inicio, final));


    return OK;
}