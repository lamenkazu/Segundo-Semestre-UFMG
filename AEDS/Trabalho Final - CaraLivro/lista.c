
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"



/* Funções */
//Cria uma lista vazia
lista_t * criaLista(){
    lista_t * lista;
    lista = (lista_t*) malloc(sizeof(lista_t));
    lista->primeiro = NULL;
    lista->nItens = 0;
    return lista;
}

listaCurtidas_t * criaListaCurtidas(){
    listaCurtidas_t * curtidas = (listaCurtidas_t*) malloc(sizeof(listaCurtidas_t));
    curtidas->primeiro = NULL;
    curtidas->nItens = 0;
    return curtidas;
}

//Insere item no inicio da lista
void insereNaLista(listaCurtidas_t * lista, perfil_t * logProfile ){
    //Aloca um novo endereço que aponta para um item da lista
    itemCurtidas_t * novo;
    novo = (itemCurtidas_t*) calloc(sizeof(itemCurtidas_t), 1);

    //Insere os dados desse item
    novo->curtiu = TRUE;
    novo->idProfile = logProfile->id;
    novo->prox = lista->primeiro; //o antigo primeiro se torna o segundo
    

    lista->primeiro = novo; //o novo item se torna o primeiro
    lista->nItens++;

}

//Insere item na lista de forma ordenada
void insereOrdenado(lista_t * lista, Conteudo texto, perfil_t * perfil){     

    itemListaE_t * novo,
                 * anterior = NULL,
                 * aux = lista->primeiro;
                 

    novo = (itemListaE_t*) malloc(sizeof(itemListaE_t));
    novo->postagem.id = lista->nItens + IDCODE;
    strcpy(novo->postagem.texto, texto);
    strncpy(novo->postagem.resumo, texto, TSHORT);
    novo->postagem.perfil = *perfil;
    novo->postagem.curtidas = criaListaCurtidas();

    while(aux != NULL && aux->postagem.id > novo->postagem.id){
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
    
    printf("Lista com %d postagens: \n------------------------\n", lista->nItens);
    for(itemListaE_t * i = lista->primeiro; i != NULL; i = i->prox){
        printf("Profile: %s", i->postagem.perfil.nome);
        printf("\nPost: %d ", i->postagem.id);
        printf("\nShort: %s ", i->postagem.resumo);
        printf("\n\n");
    }
}

void imprimeListaCurtidas(itemListaE_t * post, perfil_t * perfis){
    perfil_t profile;

    printf("\nLista de quem curtiu esta postagem: \n------------------------\n");

    for(itemListaE_t * j = post; post != NULL; post = post->prox){

        for(itemCurtidas_t * i = j->postagem.curtidas->primeiro; i != NULL; i = i->prox){

            for(int w = 0; w < qntPerfis; w++){
                if(i->idProfile == perfis[w].id){

                    if(i->curtiu == TRUE){
                        printf("Profile: %s", perfis[w].nome);
                        printf(" Curtiu!\n");
                    }
                }
            }
    }
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
itemCurtidas_t * buscaNaLista(listaCurtidas_t * lista, int val){
    for(itemCurtidas_t * i = lista->primeiro; i != NULL; i = i->prox){
        if(i->curtiu == TRUE){
            return i;
        }
    }
    return NULL;
}

//Função remove: retira elemento da lista
void rmvItemLista(lista_t *lista, uint16_t id){
    itemListaE_t * ant = NULL;
    itemListaE_t *atual = lista->primeiro;

    while(atual != NULL && atual->postagem.id != id){
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
    printf("\n%d removido com sucesso", atual->postagem);
    lista->nItens--;
    free(atual);
}

void rmvCurtida(listaCurtidas_t * curtidas, uint16_t id){

    itemCurtidas_t * ant = NULL, *atual = curtidas->primeiro;

    while(atual != NULL && atual->idProfile != id){
        ant = atual;
        atual = atual->prox;
    }

    //Se nao encontrou nao faz nada
    if(atual == NULL){
        printf("Item não encontrado para remover");
        return;
    }

    if(ant == NULL){
        curtidas->primeiro = atual->prox;
    }else{
        ant->prox = atual->prox;
    }

    curtidas->nItens--;
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