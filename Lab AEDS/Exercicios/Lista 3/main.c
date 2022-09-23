#include <stdio.h>
#include "lista3.h"
#define OK 0

int main(int argc, char ** argv){

    int op;
    char lixo;

    do{
        printf("\n\nLista de exercicios 3 - Erick Etiene\nEscolha o exercicio (1 a 12 - 15) para rodar: ");
        scanf("%d%c", &op, &lixo);

        switch(op){
            case 1: questao1(); 
            break;
            case 2: questao2(); 
            break;
            case 3: questao3(); 
            break;
            case 4: questao4(); 
            break;
            case 5: questao5(); 
            break;
            case 6: questao6(); 
            break;
            case 7: questao7(); 
            break;
            case 8: questao8(); 
            break;
            case 9: questao9(); 
            break;
            case 10: questao10(); 
            break;
            case 11: questao11(); 
            break;
            case 12: questao12(); 
            break;
            case 15: questao15(); 
            break;
        }


    }while(op != 0);

    return OK;
}