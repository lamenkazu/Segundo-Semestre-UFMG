#pragma once

#ifndef __LISTA_h__
#define __LISTA_h__

/* Inclusões */
#include <stdint.h>
#include "tipos.h"

/* Constantes */

/* Tipos */

/// <summary>
/// Tipo do valor do item da lista
/// </summary>
typedef char infoLista_t[21];

/// <summary>
/// Estrutura com os membros de um item da lista encadeada.
/// </summary>
struct itemLista_s {
  infoLista_t info;
  struct itemLista_s* prox;
};

/// <summary>
/// Tipo "Item da Lista Encadeada"
/// </summary>
typedef struct itemLista_s itemLista_t;

/// <summary>
/// Estrutura com os membros de uma lista encadeada.
/// </summary>
struct lista_s {
  itemLista_t* primeiro;
  uint32_t nItens;
};

/// <summary>
/// Tipo "Lista Encadeada"
/// </summary>
typedef struct lista_s lista_t;

/* Funções Exportadas */

lista_t* lista_cria(void);
void lista_libera(lista_t* lista);
void lista_insereInicio(lista_t* lista, infoLista_t item);
bool_t lista_estaVazia(lista_t* lista);
itemLista_t* lista_busca(lista_t* lista, infoLista_t valor);
bool_t lista_retira(lista_t* lista, infoLista_t valor);
void lista_imprime(lista_t* lista);

#endif // __LISTA_h__