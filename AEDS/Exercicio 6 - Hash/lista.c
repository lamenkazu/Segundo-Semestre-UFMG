/**
 * @file   main.c
 * @author Leandro Maia
 */

/* Inclus�es */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "lista.h"

/**
 * Função de criação.
 * @return Lista vazia.
 */
lista_t*  lista_cria(void) {

  lista_t* lista;

  lista = malloc(sizeof(lista_t));
  if (lista == NULL) return NULL;

  lista->primeiro = NULL;
  lista->nItens = 0;

  return lista;
}

/**
 * Função que insere um item no início da lista.
 * @param lista Lista onde o item será inserido.
 * @param item Item a ser inserido na lista.
 * @return Lista atualizada com o novo item.
 */
void lista_insereInicio(lista_t * lista, infoLista_t item) {

  itemLista_t * novo = (itemLista_t *)malloc(sizeof(itemLista_t));
  strcpy(novo->info, item);
  novo->prox = lista->primeiro;

  lista->primeiro = novo;
  lista->nItens++;  
}

/**
 * Função que imprime os itens da lista.
 * @param lista Lista cujo itens serão impressos.
 */
void lista_imprime(lista_t * lista) {

  itemLista_t * atual;

  for (atual = lista->primeiro; atual != NULL; atual = atual->prox) {
    printf("Info: %s\n", atual->info);
  }
}

/**
 * Função que verifica se a lista está vazia.
 * @param lista Lista a ser verificada.
 * @return VERDADEIRO caso a lista esteja vazia ou, caso contrário,
 * retorna FALSO.
 */
bool_t lista_estaVazia(lista_t * lista) {
  return lista->primeiro == NULL;
}

/**
 * Função que busca um item na lista.
 * @param lista Lista ondem o item ser procurado.
 * @param valor Valor do item a ser localizado.
 * @return Endereço do item na lista caso ele esteja na mesma,
 * ou caso contrário, retorna NULL.
 */
itemLista_t * lista_busca(lista_t * lista, infoLista_t valor) {

  itemLista_t * atual;

  for (atual = lista->primeiro; atual != NULL; atual = atual->prox) {
    if(strcmp(atual->info, valor) == 0){
      return atual;
    }
  }

  // Se chegou até aqui é porque não encontrou
  return NULL;
}

/**
 * Função que procura e remove um item da lista caso o item esteja presente.
 * @param lista Lista ontem o item ser procurado.
 * @param valor Valor do item a ser procurado.
 * @return Lista após a tentativa de remoção.
 */
bool_t lista_retira(lista_t * lista, infoLista_t valor) {

  itemLista_t * anterior = NULL;
  itemLista_t * atual = lista->primeiro;

  // Busca pelo item até encontrá-lo ou a lista chegar no final
  while ((atual != NULL) && (strcmp(atual->info, valor) != 0)) {
    anterior = atual;
    atual = atual->prox;
  }

  // Se chegou no final e não encontrou, retorna a lista original
  if (atual == NULL) {
    return FALSO;
  }

  // Se chegou até aqui é porque encontrou e esté em <atual>

  // Verifica se é o primeiro
  if (anterior == NULL) {
    lista->primeiro = atual->prox;
  }
  else {
    anterior->prox = atual->prox;
  }

  // Libera o espaço alocado pelo atual
  free(atual);
  lista->nItens--;
  return VERDADEIRO;
}

/**
 * Função que libera a memória utilizada pela lista.
 * @param lista Lista a ter a memória liberada.
 */
void lista_libera(lista_t * lista) {

  itemLista_t * atual = lista->primeiro;

  while (atual != NULL) {
    itemLista_t * tmp = atual->prox;
    free(atual);
    atual = tmp;
  }

  free(lista);
}