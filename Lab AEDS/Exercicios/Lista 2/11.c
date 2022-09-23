#include <stdio.h>

float calculaExponencial(float x, float y){
    float res = 1.0f;
    for(int i = 0; i < y; i++){
        res*= x;
    }
    return res;
}

int questao11(){

    float x, y, z;

    printf("Calcule o exponencial x ^ y\nx: ");
    scanf("%f", &x);
    printf("y: ");
    scanf("%f", &y);

    z = calculaExponencial(x, y);

    printf("%g ^ %g = %g", x, y, z);


    return 0;
}