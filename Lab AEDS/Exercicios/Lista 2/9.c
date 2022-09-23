#include <stdio.h>
#include <math.h>

#define OK 0

int calculaDelta(int a, int b, int c){

    return ((b * b) - (4 * a * c));
}


int questao9(){

    int a, b, c;
    int delta;
    int x1, x2;

    printf("Informe os coeficientes a b c da equação de segundo grau: ");
    scanf("%d %d %d", &a, &b, &c);

    delta = calculaDelta(a, b, c);

    if(sqrt(delta) < 0){
        printf("Não há raizes reais nesta equação.");
    }else{
        x1 = (((b * -1) + sqrt(delta) ) / (2 * a));
        x2 = (((b * -1) - sqrt(delta) ) / (2 * a));
        printf("x1 = %d\nx2 = %d\n", x1, x2);
    }



    return OK;
}