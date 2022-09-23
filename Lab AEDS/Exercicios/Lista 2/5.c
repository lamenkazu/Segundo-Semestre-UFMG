#include <stdio.h>

#define OK 0

int calculaFatorial(int val){

    int res=1;

    for(int i = 1; i <= val; i++){
        res *= i ;
    }

    return res;

}

int questao5(){

    int val, res;

    printf("Informe um valor para calcular o fatorial: ");
    scanf("%d", &val);
    res = calculaFatorial(val);

    printf("O fatorial de %d é %d\n\n", val, res);


    return OK;
}