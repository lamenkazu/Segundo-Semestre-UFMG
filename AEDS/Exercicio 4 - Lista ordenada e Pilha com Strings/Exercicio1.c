/*
    - Implemente uma Lista Ordenada de Nomes conforme visto em sala.
    - Adicione os seguintes nomes, nesta ordem:
    Bruna, Joao, Erick, Jeanne, Gabriel, Vitor, Eduardo, Paulo, Arthur, Wallace F, Ian, Jessica, Mariana, Pedro, Gabriella, Jeferson, Maíra, Raphael, Wallace S.
    - Imprima o contéudo da Lista.
    - Remova os nomes a seguir e imprima o conteúdo da lista a cada remoção:
    Paulo, Bruna, Wallace S.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TRUE (1==1)
#define FALSE !TRUE
#define OK 0

typedef bool_t;

typedef char Nome[20];

//Estrutura da lista de Nomes
typedef struct nomeLista{
    Nome nome;
    struct nomeLista * prox; 
} nomeDaLista_t;

typedef struct listaDeNomes {
    unsigned int nItens;
    nomeDaLista_t * primeiro;
} listaDeNomes_t;


listaDeNomes_t * criaLista(){
    listaDeNomes_t * lista;
    lista = (listaDeNomes_t*) malloc(sizeof(listaDeNomes_t));
    lista->nItens = 0;
    lista->primeiro = NULL;

    return lista;
}

void insereNomeNaListaORD(listaDeNomes_t * lista, Nome nome){
    nomeDaLista_t * novo,
                  * anterior = NULL,
                  * aux = lista->primeiro;
    
    novo = (nomeDaLista_t*) malloc(sizeof(nomeDaLista_t));

    strcpy(novo->nome, nome);

    while(aux != NULL && strcmp(aux->nome, nome) < 0 ){
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

void imprimeLista(listaDeNomes_t * lista){
    for(nomeDaLista_t * i = lista->primeiro; i != NULL; i = i->prox){
        printf("%s, ", i->nome);
    }
    printf("\n\n");
}

bool_t listaVazia(listaDeNomes_t * lista){
    if(lista->primeiro != NULL) return FALSE;
    
    return TRUE;
}

bool_t rmvNome(listaDeNomes_t * lista, Nome nome){
    nomeDaLista_t * anterior = NULL;
    nomeDaLista_t * atual = lista->primeiro;

    while(atual != NULL && strcmp(atual->nome, nome) != 0){
        anterior = atual;
        atual = atual->prox;
    }

    //Se não encontrou retorna falso
    if(atual == NULL) return FALSE;

    if(anterior == NULL){
        lista->primeiro = atual->prox;

    }else{
        anterior->prox = atual->prox;

    }

    lista->nItens--;
    free(atual);
    return TRUE;

}

void liberaLista(listaDeNomes_t * lista){
    nomeDaLista_t * atual = lista->primeiro;

    while(atual != NULL){
        nomeDaLista_t * t = atual->prox;
        atual = t;
        free(atual);
    }
    
}

int main(int argc, char ** argv){

    listaDeNomes_t * lista = criaLista();

    if(listaVazia(lista) == TRUE){

        insereNomeNaListaORD(lista, "Bruna");
        insereNomeNaListaORD(lista, "Joao");
        insereNomeNaListaORD(lista, "Erick");
        insereNomeNaListaORD(lista, "Jeanne");
        insereNomeNaListaORD(lista, "Gabriel");
        insereNomeNaListaORD(lista, "Vitor");
        insereNomeNaListaORD(lista, "Eduardo");
        insereNomeNaListaORD(lista, "Paulo");
        insereNomeNaListaORD(lista, "Arthur");
        insereNomeNaListaORD(lista, "Wallace F.");
        insereNomeNaListaORD(lista, "Ian");
        insereNomeNaListaORD(lista, "Jessica");
        insereNomeNaListaORD(lista, "Mariana");
        insereNomeNaListaORD(lista, "Pedro");
        insereNomeNaListaORD(lista, "Gabriella");
        insereNomeNaListaORD(lista, "Jeferson");
        insereNomeNaListaORD(lista, "Maíra");
        insereNomeNaListaORD(lista, "Raphael");
        insereNomeNaListaORD(lista, "Wallace S.");

        imprimeLista(lista);

        rmvNome(lista, "Paulo");

        imprimeLista(lista);
        

        rmvNome(lista, "Bruna");

        imprimeLista(lista);

        rmvNome(lista, "Wallace S.");

        imprimeLista(lista);

    }

    


    return OK;
}

