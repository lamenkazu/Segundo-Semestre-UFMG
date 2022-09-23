#include <fila.h>

/*
    Podemos declarar o tipo fila como sendo uma estrutura com três
    componentes: 
        -Um vetor de tamanho N;
        -Um inteiro n que representa o numero de elementos armazenados na fila;
        -Um índici ini para o inicio da fila
    ini marca a posição do próximo elemento a ser retirado da fila e fim marca a posição (vazia) em que será inserido o próximo elemento
    Podemos calcular o índice fim incrementando ini de n unidades: fim = (ini + n) % TAM
*/

static int incremento(int i){
    return (i+1) % TAM;
}

Fila * fila_cria(){
    Fila * fila = (Fila*) malloc(sizeof(Fila));
    fila->nElementos = 0;
    fila->ini = 0;
    return fila;
}

bool_t fila_insere(Fila * fila, tipoFila val){
    int fim;
    if(fila->nElementos == TAM){
        printf("Capacidade estourou!");
        return FALSE;
    }
    fim = (fila->ini + fila->nElementos) % TAM;
    fila->vet[fim] = val;
    fila->nElementos++;
    return TRUE;
}

bool_t fila_retira(Fila * fila){
    tipoFila val;
    if(fila_vazia(fila)){
        printf("Fila vazia!");
        return FALSE;
    }
    val = fila->vet[fila->ini];
    fila->ini = (fila->ini + 1) % TAM;
    return TRUE;
}

bool_t fila_vazia(Fila * fila){
    if(fila->nElementos == 0) return TRUE;
    return FALSE;
}

void fila_libera(Fila * fila){
    free(fila);
}