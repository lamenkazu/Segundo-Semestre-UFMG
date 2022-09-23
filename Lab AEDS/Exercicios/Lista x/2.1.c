#include <stdio.h>
/* 
    Faça um programa para imprimir um triângulo de altura 2n − 1 e largura n. Por exemplo,
para n = 4 a gura deve car como abaixo:
                        *
                        **
                        ***
                        ****
                        ***
                        **
                        *
*/
void questao2_1(){

    int larg, indice;
    char lixo;

    printf("GERA TRIANGULO\nEscolha a largura do triangulo: ");
    scanf("%d%c", &larg, &lixo);
    indice = larg;

    //Imprime parte superior do triangulo
    for(int i = 0; i < larg; i++){
        for(int j = indice; j > larg ; j--){
            printf("* ");
        }
        indice++;
        printf("\n");
    }

    //Imprime parte inferior do triangulo
    indice = 0;
    for(int i = 0; i < larg; i++){
        for(int j = indice; j < larg ; j++){
            printf("* ");
        }
        indice++;
        printf("\n");
    }

}