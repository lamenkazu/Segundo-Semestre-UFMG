#include <stdio.h>
#define OK 0

int descobreMenor(int val1, int val2, int val3){

    int menor;

    if((val1 < val2) && (val1 < val3)){
        menor = val1;
    }else if((val2 < val1) && (val2 < val3)){
        menor = val2;
    }else{
        menor = val3;
    }

    return menor;
}

int questao7(){

    int val1, val2, val3;
    int menor;

    printf("Informe 3 valores para comparar: ");
    scanf("%d %d %d", &val1, &val2, &val3);
    menor = descobreMenor(val1, val2, val3);
    printf("O menor valor é: %d\n", menor);

    return OK;
}