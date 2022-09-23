#include <stdio.h>
#include <stdlib.h>

int ** alocaMatriz(int x, int y){

    int ** matriz;

    //Aloca a primeira dimensão da matriz
    matriz = (int **) malloc(x * sizeof(int*));
    if(matriz == NULL){
        printf("***erro***");
        return 1;
    }

    //Aloca a segunda dimensão da matriz
    for(int i = 0; i < x; i++){
        matriz[i] = (int*) malloc(y * sizeof(int));
        if(matriz[i] == NULL){
            printf("***erro***");
            return 1;
        }
    }

    return matriz;

}

void preencheMatriz01(int ** matriz, int x, int y){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            matriz[i][j] = rand() % 2;
        }
    }

}

void imprimeMatriz(int ** matriz, int x, int y){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("M[%d][%d] = %d\n", i+1, j+1, matriz[i][j] );
        }
    }
}

void questao4_1(){
    int x, y;
    int qnt0 = 0, qnt1 = 0;
    char lixo;

    int ** matriz;

    printf("CONTA 0 E 1 DA MATRIZ\nInforme as dimencoes [x][y] da matriz\nx: ");
    scanf("%d%c", &x, &lixo);
    printf("y: ");
    scanf("%d%c", &y, &lixo);

    matriz = alocaMatriz(x, y);
    preencheMatriz01(matriz, x, y);
    imprimeMatriz(matriz, x, y);

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(matriz[i][j] == 0){
                qnt0++;
            }else{
                qnt1++;
            }
        }
    }

    printf("A matriz possui %d 0's e %d 1's", qnt0, qnt1);

    
}