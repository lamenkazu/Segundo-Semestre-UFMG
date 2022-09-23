#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define LISTA_VAZIA 1


typedef int dadosItem;

typedef struct lista{
    dadosItem info;
    struct lista * prox;
} listaE;


//Cria uma lista vazia
listaE * criaLista(){
    return NULL;
}

//Insere item no inicio da lista
void insereNaLista(listaE **lista, dadosItem info){
    //Aloca um novo endereço que aponta para um item da lista
    listaE * novo;
    novo = (listaE*) malloc(sizeof(listaE));

    //Insere os dados desse item
    novo->info = info;
    novo->prox = *lista; //o antigo primeiro se torna o segundo

    *lista = novo; //o novo item se torna o primeiro
}

//Percorre os elementos da Lista (A exemplo imprime a lista)
void imprimeLista(listaE *lista){
    for(listaE * i = lista; i != NULL; i = i->prox){
        printf("info %d ", i->info);
    }
}

//Verifica se a lista esta vazia
int listaVazia(listaE * lista){
    if(lista != NULL){
        return OK;
    }else{
        return LISTA_VAZIA;
    }
}

//Função Busca> busca um elemento na lista
listaE * buscaNaLista(listaE * lista, dadosItem val){
    for(listaE * i = lista; i != NULL; i = i->prox){
        if(i->info == val){
            return i;
        }
    }
    return NULL;
}

//Função remove: retira elemento da lista
listaE * rmvItemLista(listaE *lista, dadosItem val){
    listaE * ant = NULL;
    listaE *aux = lista;

    while(aux != NULL && aux->info != val){
        ant = aux;
        aux = aux->prox;
    }

    if(aux == NULL) return lista;
    if(ant == NULL){
        lista = aux->prox;
    }else{
        ant->prox = aux->prox;
    }

    free(aux);
    return lista;
}

//Função libera lista
void liberaLista(listaE * lista){
    listaE * aux = lista;

    while(aux != NULL){
        listaE * t = aux->prox;
        free(aux);
        aux = t;
    }
}