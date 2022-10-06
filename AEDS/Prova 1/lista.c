#include "lista.h"
#include "uteis.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

lista_t * criaLista(){
    lista_t * lista = (lista_t*) malloc(sizeof(lista_t));
    lista->nItens = 0;
    lista->primeiro = NULL;
    return lista;
}

void insereNaListaORD(lista_t * lista, registroLista_t registro){
    registroLista_t * novo,
                  * anterior = NULL,
                  * aux = lista->primeiro;

    novo = (registroLista_t*) malloc(sizeof(registroLista_t));

    strcpy(novo->pessoa.nome, registro.pessoa.nome);
    strcpy(novo->pessoa.cpf, registro.pessoa.cpf);

    while(aux != NULL && strcmp(aux->pessoa.cpf, registro.pessoa.cpf) < 0 ){
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

void imprimeLista(lista_t * lista){
    printf("IMPRESSAO DA LISTA: \n");
    for(registroLista_t * i = lista->primeiro; i != NULL; i = i->prox){
        printf("Nome: %s \t|CPF: %s\n", i->pessoa.nome, i->pessoa.cpf);
        uteis_imprimeTracinhos(45);
        printf("\n\n");
    }
    
    printf("\n\n");
}

bool_t listaVazia(lista_t * lista){
    if(lista->primeiro != NULL) return FALSO;

    return VERDADEIRO;
}

bool_t rmvRegistro(lista_t * lista, char cpf[]){
    registroLista_t * anterior = NULL, *atual = lista->primeiro;

    while(atual != NULL && strcmp(atual->pessoa.cpf, cpf) != 0){
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL) return FALSO;

    if(anterior == NULL){
        lista->primeiro = atual->prox;

    }else{
        anterior->prox = atual->prox;

    }

    lista->nItens--;
    free(atual);
    return VERDADEIRO;
}

void liberaLista(lista_t * lista){
    registroLista_t * atual = lista->primeiro;

    while(atual != NULL){
        registroLista_t * t = atual->prox;
        atual = t;
        free(atual);
    }
}
