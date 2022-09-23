#include <stdio.h>
#define OK 0

float calculaPiAprox(int prec){

    int den;
    float pi = 4;

    for (int i = 0; i < prec; i++) {
            den = i * 2 + 3;
            // (4 - 4/3 + 4/5 -4/7 + 4/9 -......)
            if (i % 2 == 0) {
                pi = pi - (4.0 / den);
            }
            else {
                pi = pi + (4.0 / den);
            }

        }

    return pi;

}

int questao12(){

    int prec;

    printf("Calcule o valor aproximado de pi!\nInforme a precisão desejada (valor inteiro): ");
    scanf("%d", &prec);

    printf("Pi = %f", calculaPiAprox(prec));

    return OK;
}