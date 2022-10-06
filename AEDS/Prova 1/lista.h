#pragma once

/**
 * @file   lista.h
 * @brief  Arquivo com a definição dos tipos e funções de manipulação da lista
 *         utilizados na prova de AEDS.
 * @author Erick Etiene Simião
 * @date   2022-09-23
 */

/* Inclusões */
#include "dado.h"
#include "uteis.h"

/* Constantes */
#define OK 0
#define LISTA_VAZIA 1

/* Códigos de Erros */

/* Tipos */
typedef struct registroLista{
    registro_t pessoa;
    struct registroLista * prox;
} registroLista_t;

typedef struct lista{
    unsigned int nItens;
    registroLista_t * primeiro;
} lista_t;

/* Funções Exportadas */
lista_t * criaLista();
bool_t rmvRegistro(lista_t * lista, char cpf[]);
bool_t listaVazia(lista_t * lista);
void imprimeLista(lista_t * lista);
void insereNaListaORD(lista_t * lista, registroLista_t registro);
void liberaLista(lista_t * lista);