#include <stdio.h>
#define OK 0

int descobreMaior(int val1, int val2, int val3){

    int maior;

    if((val1 > val2) && (val1 > val3)){
        maior = val1;
    }else if((val2 > val1) && (val2 > val3)){
        maior = val2;
    }else{
        maior = val3;
    }

    return maior;
}

int questao6(){

    int val1, val2, val3;
    int maior;

    printf("Informe 3 valores para comparar: ");
    scanf("%d %d %d", &val1, &val2, &val3);
    maior = descobreMaior(val1, val2, val3);
    printf("O maior valor é: %d\n", maior);

    return OK;
}