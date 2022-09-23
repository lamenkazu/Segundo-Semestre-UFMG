#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"


/* Funções */
//Cria uma lista vazia
lista_t * criaLista(){
    lista_t * lista;
    lista = (lista_t*) malloc(sizeof(lista_t));
    lista->primeiro = NULL;
    lista->nItens = 0;
    return lista;
}

//Insere item no inicio da lista
void insereNaLista(lista_t * lista, dadosItem info){
    //Aloca um novo endereço que aponta para um item da lista
    itemListaE_t * novo;
    novo = (itemListaE_t*) malloc(sizeof(itemListaE_t));

    //Insere os dados desse item
    novo->info = info;
    novo->prox = lista->primeiro; //o antigo primeiro se torna o segundo

    lista->primeiro = novo; //o novo item se torna o primeiro
    lista->nItens++;
}

//Insere item na lista de forma ordenada
void insereOrdenado(lista_t * lista, dadosItem info){     

    itemListaE_t * novo,
                 * anterior = NULL,
                 * aux = lista->primeiro;
                 

    novo = (itemListaE_t*) malloc(sizeof(itemListaE_t));
    novo->info = info;

    while(aux != NULL && aux->info < info){
        anterior = aux;
        aux = aux->prox;
    }

    if(anterior == NULL){
        novo->prox = lista->primeiro;
        lista->primeiro = novo;
    }else{
        novo->prox = anterior->prox;
        anterior->prox = novo;
    }

    lista->nItens++;

}

//Percorre os elementos da Lista (A exemplo imprime a lista)
void imprimeLista(lista_t * lista){
    
    for(itemListaE_t * i = lista->primeiro; i != NULL; i = i->prox){
        printf("\ninfo %d ", i->info);
    }
}

//Verifica se a lista esta vazia
int listaVazia(lista_t * lista){
    if(lista->primeiro != NULL){
        return OK;
    }else{
        return LISTA_VAZIA;
    }
}

//Função Busca> busca um elemento na lista
itemListaE_t * buscaNaLista(lista_t * lista, dadosItem val){
    for(itemListaE_t * i = lista->primeiro; i != NULL; i = i->prox){
        if(i->info == val){
            return i;
        }
    }
    return NULL;
}

//Função remove: retira elemento da lista
void rmvItemLista(lista_t *lista, dadosItem val){
    itemListaE_t * ant = NULL;
    itemListaE_t *atual = lista->primeiro;

    while(atual != NULL && atual->info != val){
        ant = atual;
        atual = atual->prox;
    }

    //se não encontrou retorna nada
    if(atual == NULL) {
        printf("Item nao encontrado para remover");
        return;
    }


    if(ant == NULL){
        lista->primeiro = atual->prox;
    }else{
        ant->prox = atual->prox;
    }
    printf("\n%d removido com sucesso", atual->info);
    lista->nItens--;
    free(atual);
}

//Função libera lista
void liberaLista(lista_t * lista){
    itemListaE_t * atual = lista->primeiro;

    while(atual != NULL){
        itemListaE_t * t = atual->prox;
        atual = t;
    }
    free(atual);
}