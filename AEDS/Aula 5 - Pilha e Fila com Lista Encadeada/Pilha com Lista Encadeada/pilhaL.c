#include "pilhaL.h"
#include <stdio.h>
#include <string.h>

typedef unsigned int tipoItem;

typedef struct itemPilhaL_s {
    tipoItem dado;
    struct itemPilha_s * prox;
} itemPilhaL;

static void iniciaPilhaL(PilhaL * pilha){
    pilha->nItens = 0;
    pilha->topo = NULL;
}

PilhaL * criaPilhaL(){
    PilhaL * pilha = (PilhaL*) malloc(sizeof(PilhaL));

    iniciaPilhaL(pilha);

    return pilha;
}


void destroiPilhaL(PilhaL * pilha){
    itemPilhaL * atual, *proximo;

    //Começa pelo topo da pilha
    atual = (itemPilhaL*) pilha->topo;

    //Percorre todos os elementos da Pilha dando free em cada um
    while(atual != NULL){
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    free(pilha);
}

bool_t empilhaPilhaL(PilhaL * pilha, tipoItem dado){
    itemPilhaL * novoItem = (itemPilhaL*) malloc(sizeof(itemPilhaL));
    if(novoItem == NULL) return FALSE; else{
        //Cria o novo item
        novoItem->dado = dado;
        novoItem->prox = (itemPilhaL*) pilha->topo;

        //Define o novo topo da fila
        pilha->topo = novoItem;

        //Incrementa e retorna
        pilha->nItens++;
        return TRUE;
    }
    
}

bool_t desempilhaPilhaL(PilhaL * pilha, tipoItem * dado){

    itemPilhaL * descarte = (itemPilhaL*) pilha->topo;

    //Se a pilha estiver vazia
    if(descarte == NULL) return FALSE;

    //Copia os dados do item antes de remover
    (void) memcpy(dado, &descarte->dado, sizeof(tipoItem));

    //Faz o próximo item ser o novo Topo
    pilha->topo = descarte->prox;

    free(descarte);
    pilha->nItens--;
    return TRUE;


}

bool_t buscaNaPilhaL(PilhaL * pilha, tipoItem dado, unsigned int * posicao){
    
    int i = 0;
    itemPilhaL * proximo = (itemPilhaL*) pilha->topo;

    //Percorre os elementos da pilha procurando aquele cuja informação é a desejada
    while(proximo != NULL){
        if(proximo->dado == dado) break;
        proximo = proximo->prox;
        i++;
    }

    if(proximo == NULL) return FALSE;

    *posicao = i;
    return TRUE;
}

bool_t pilhaLVazia(PilhaL * pilha){
    if(pilha->nItens == 0) return TRUE;
    return FALSE;
}

void imprimePilhaL(PilhaL * pilha){
    itemPilhaL * atual;
    itemPilhaL * proximo = (itemPilhaL*)pilha->topo;

    printf("Pilha com %d itens\n", pilha->nItens);
    printf("___________________________________\n");
    for(int i = 0; i < pilha->nItens; i++){
        atual = proximo;
        proximo = atual->prox;

        printf("Pos: %d | Valor: %d", i, atual->prox);
    }
    printf("___________________________________\n");
}

