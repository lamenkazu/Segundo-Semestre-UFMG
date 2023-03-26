#include "FilaL.h"
#include <stdio.h>
#include <stdlib.h>

typedef int bool_t;
#define TRUE 1==1
#define FALSE !TRUE

typedef int tipoItem;

typedef struct itemFilaL_s{
    tipoItem dado;
    struct itemFilaL_s * proximo;
} ItemFilaL;

static void iniciaFilaL(FilaL * fila){
    fila->nItens = 0;
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}

FilaL * criaFilaL(){
    FilaL * fila = (FilaL*) malloc(sizeof(FilaL));

    iniciaFilaL(fila);

    return fila;
}

bool_t insereNaFilaL(FilaL * fila, tipoItem info){
    
    ItemFilaL * novoItem;

    novoItem = (ItemFilaL *) malloc(sizeof(ItemFilaL));
    if(novoItem == NULL) return FALSE; else{

        novoItem->dado = info;
        novoItem->proximo = NULL;

        //Se tem item na fila, então o novo entra depois dele
        if(fila->ultimo != NULL){
            ((ItemFilaL*) fila->ultimo)->proximo = novoItem;
        }
        //Senão, ele é o primeiro também
        else{
            fila->primeiro = novoItem;
        }

        //O novo item é sempre o ultimo;
        fila->ultimo = novoItem;
        fila->nItens++;
        return TRUE;
    }

}

bool_t removeDaFilaL(FilaL * fila, tipoItem * info){
    ItemFilaL * descarte = (ItemFilaL * ) fila->primeiro;

    //Verifica se a fila não está vazia
    if(fila->nItens == 0) return FALSE;

    //Copia os dados do descarte para info para q seja retornado fora do retorno da função
    (void) memcpy(info, &descarte->dado, sizeof(tipoItem));
    //  e remove o item da fila
    fila->primeiro = descarte->proximo;

    //Se a fila ficou vazia, então o último não é mais valido
    if(fila->primeiro == NULL) fila->ultimo = NULL;

    //Removeu o item com sucesso se chegou até aqui
    free(descarte);
    fila->nItens--;
    return TRUE;




}


bool_t primeiroDaFilaL(FilaL * fila, tipoItem * primeiro){

    //Se estiver vazia não tem primeiro
    if(fila->nItens == 0) return FALSE;

    //Copia o valor que está no inicio para a variável primeiro para q seja retornada fora do retorno da função
    (void) memcpy(primeiro, fila->primeiro, sizeof(tipoItem));

    //Retorna verdadeiro por conseguir retornar o primeiro para uma variavel externa.
    return TRUE;

}

bool_t buscaNaFilaL(FilaL * fila, tipoItem info, int * posicao){
    int pos = 0;
    ItemFilaL * atual = (ItemFilaL *) fila->primeiro;

    //Percorre os elementos da fila procurando aquele que a informação foi passada por parametro
    while(atuaç != NULL){

        if(atual->dado == info) break;

        atual = atual->proximo;
        pos++;

    }

    /*O elemento que está no Atual é o item encontrado.
      Caso a fila tenha chegado no final e nenhum item foi encontrado, então
      o próximo é NULL
      Caso a fila esteja vazia, então o Próximo é NULL desde o Início.
    */
   if(atual == NULL) return FALSE;

   //Se chegou aqui é pq o Item foi encontrado e sua posicao esta em
   *posicao = pos;

   return TRUE;
}

bool_t taVaziaFilaL(FilaL * fila){
    if(fila->nItens == 0) return TRUE;
    return FALSE;
}

void imprimeFilaL(FilaL * fila){
    ItemFilaL *atual;
    ItemFilaL *proximo = (ItemFilaL*) fila->primeiro;

    printf("Fila com %d itens\n", fila->nItens);
    printf("_________________________________\n");
    for(int i = 0; i < fila->nItens; i++){
        //Links da fila
        atual = proximo;
        proximo = atual->proximo;

        printf("Pos: %d | Val: %d\n", i+1, atual->dado);
    }
    printf("_________________________________\n");
}


void destroiFilaL(FilaL * fila){
    ItemFilaL *atual, *proximo;

    atual = (ItemFilaL*) fila->primeiro;

    while(atual!= NULL){
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(fila);
}

