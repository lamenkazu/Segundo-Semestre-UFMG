#include <stdio.h>
/*
    Faça um programa para gerar um triângulo de números, de N linhas, com linhas de números
    decrescentes, a partir de N até 1 na primeira linha, de N até 2 na segunda, e assim por diant,
    até a última linha com apenas o número igual N. A gura abaixo mostra o caso de N = 5.
    Considere 2 ≤ N ≤ 9.
                                        5 4 3 2 1
                                        5 4 3 2
                                        5 4 3
                                        5 4
                                        5
*/
void questao1_9(){
    
    int val, aux, indice = 0;
    char lixo;

    printf("GERADOR DE TRIANGULO!\nInforme o valor (entre 2 e 9): ");
    scanf("%d%c", &val, &lixo);
    
    for(int i = 0; i < val; i++){
        aux = val;
        for(int j = indice; j < val; j++){
            printf("%d ", aux);
            aux--;
        }
        indice++;
        printf("\n");
    }


}