#include <stdio.h>
#include <math.h>

#define OK 0


void calculaEqSegGrau(int a, int b, int c, float vet[]){

    int delta;

    delta = calculaDelta(a, b, c);

    if(sqrt(delta) < 0){
        printf("Não há raizes reais nesta equação.");
    }else{
        vet[0] = (((b * -1) + sqrt(delta) ) / (2 * a));
        vet[1] = (((b * -1) - sqrt(delta) ) / (2 * a));
        printf("x1 = %g\nx2 = %g\n", vet[0], vet[1]);
    }

}


int questao10(){

    int a, b, c;
    float vet[2];

    printf("Informe os coeficientes a b c da equação de segundo grau: ");
    scanf("%d %d %d", &a, &b, &c);

    calculaEqSegGrau(a, b, c, vet);

    



    return OK;
}