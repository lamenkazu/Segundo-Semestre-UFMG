#pragma once

#ifndef __LISTA_h__
#define __LISTA_h__

#include "tipos.h"
#include "perfis.h"

#include <stdint.h>


#define LISTA_VAZIA 1
#define TCONTEUDO 144
#define TSHORT 24

#define IDCODE 100

typedef char Conteudo[TCONTEUDO];
typedef char Short[TSHORT];

/* Tipos */

typedef struct itemCurtidas{
    bool_t curtiu;
    uint16_t idProfile;
    struct itemCurtidas * prox;
} itemCurtidas_t;

typedef struct listaCurtidas{
    unsigned int nItens;
    itemCurtidas_t * primeiro;
}listaCurtidas_t ;



typedef struct postagem {

    uint32_t id;
    Conteudo texto;
    Short resumo;
    perfil_t perfil;
    listaCurtidas_t * curtidas;

} postagem_t;

//Estrutura do item da lista
typedef struct itemLista{

    postagem_t postagem;
    struct itemLista * prox;

} itemListaE_t;

//Estrutura da Lista em si
typedef struct lista{

    unsigned int nItens;

    itemListaE_t * primeiro;

} lista_t;

//Estrutura com informações da Lista
lista_t * criaLista();

listaCurtidas_t * criaListaCurtidas();

void insereNaLista(listaCurtidas_t * lista, perfil_t * logProfile);

void insereOrdenado(lista_t * lista, Conteudo texto, perfil_t * perfil);

void imprimeLista(lista_t *lista);

void imprimeListaCurtidas(itemListaE_t * postagens, perfil_t * perfis);

int listaVazia(lista_t * lista);

itemCurtidas_t * buscaNaLista(listaCurtidas_t * lista, int val);

void rmvItemLista(lista_t *lista, uint16_t id);

void rmvCurtida(listaCurtidas_t * curtidas, uint16_t id);

void liberaLista(lista_t * lista);

#endif // __TABELA_HASH_h__