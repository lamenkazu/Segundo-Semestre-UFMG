#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>
/*
    @param capacidade Capacidade máxima da pilha
    @rertun Endereço da pilha criada, em caso de erro, NULL
*/
Pilha * pilha_cria(unsigned int capacidade){
    Pilha * pilha = (Pilha*) malloc(sizeof(Pilha));
    if(pilha == NULL) return NULL;

    pilha->dados = (itemPilha*) malloc(sizeof(itemPilha) * capacidade);
    if(pilha->dados == NULL){
        free(pilha);
        return NULL;
    }
    
    pilha->capacidade = capacidade;
    pilha->nElementos = 0;
    return pilha;
}
/*
    @param pilha
    @param valor
    @return boolean
*/
bool_t pilha_push(Pilha *pilha, itemPilha val){
    if(pilha->nElementos == pilha->capacidade){
        return FALSE;
    }
    pilha->dados[pilha->nElementos] = val;
    pilha->nElementos++;
    return TRUE;
}

/*

*/
bool_t pilha_pop(Pilha*pilha, itemPilha *dado){

    if(pilha_vazia(pilha)) return FALSE;

    *dado = pilha->dados[pilha->nElementos - 1];
    pilha->nElementos--;
    return TRUE;
}

bool_t pilha_vazia(Pilha * pilha){
    return (pilha->nElementos == 0);
}

void pilha_libera(Pilha * pilha){
    free(pilha->dados);
    free(pilha);

}

void pilha_imprime(Pilha * pilha){
    printf("Impressao da pilha\n"\
            "No de elementos: %d | Capacidade: %d\n"\
            "---------------\n", pilha->nElementos, pilha->capacidade);

    for(int i = 0; i < pilha->nElementos; i++){
        printf("Elemento: %g\n", pilha->dados[pilha->nElementos - i - 1]);
    }
}

int main(){
    Pilha * pilha;

    pilha = pilha_cria(10);
    if(pilha == NULL){
        fprintf(stderr, "Erro ao criar a pilha");

    }

    pilha_push(pilha, 2);
    pilha_push(pilha, 8);
    pilha_push(pilha, 3);
    pilha_push(pilha, 7);
    pilha_push(pilha, 9);
    pilha_push(pilha, 11);

    pilha_imprime(pilha);

    pilha_libera(pilha);
}