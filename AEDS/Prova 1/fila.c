#include "fila.h"
#include "uteis.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Fila * criaFila(unsigned int capac){
    Fila * fila = (Fila*) malloc(sizeof(Fila));
    fila->registros = malloc(sizeof(registro_t) * capac);
    fila->nItens = 0;
    fila->inicio = 0;
    fila->capacidade = capac;
    return fila;
}

bool_t insereNaFila(Fila * fila, registro_t reg){
    int fim;

    if(fila->nItens == fila->capacidade)
        return FALSO;

    fim = (fila->inicio + fila->nItens) % fila->capacidade;
    fila->registros[fim] = reg;
    fila->nItens++;

    return VERDADEIRO;
    

}

void imprimeFila(Fila * fila){
    printf("IMPRESSAO DA FILA: \n");
    for(int i = 0; i < fila->nItens; i++){
        int pos = (fila->inicio + i) % fila->capacidade;
        printf("Nome: %s \t|CPF: %s\n", fila->registros[pos].nome, fila->registros[pos].cpf);
        uteis_imprimeTracinhos(45);
        printf("\n\n");
    }
    printf("\n\n");
}

bool_t filaVazia(Fila*fila){
    if(fila->nItens == 0) return VERDADEIRO;
    return FALSO;
}



bool_t retiraDaFila(Fila * fila, registro_t * dado){
    if(filaVazia(fila)){
        return FALSO;
    }

    *dado = fila->registros[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->nItens--;

    return VERDADEIRO;
}

void liberaFila(Fila * fila){
    free(fila);
}