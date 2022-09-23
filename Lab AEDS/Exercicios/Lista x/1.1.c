#include <stdio.h>

/*
    Faça um programa para gerar um quadrado de lado N formado de asteriscos. O valor de
3 ≤ N ≤ 15 é dado pelo usuário. A gura abaixo mostra o caso de N = 5.
                    * * * * *
                    * * * * *
                    * * * * *
                    * * * * *
                    * * * * *
*/

void questao1_1(){
    int num;
    printf("Informe o lado do quadrado: ");
    scanf("%d", &num);

    if(num >= 3 && num <= 15){
        for(int i = 0; i < num; i++){
            for(int j = 0; j < num; j++){
                printf("* ");
            }
            printf("\n");
        }
    }else{
        printf("Tamanho invalido, tente 3 <= N <= 15");
    }


}