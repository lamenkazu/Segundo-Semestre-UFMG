/**
 * @file   tabelaHashA_LE.c
 * @brief  Implementação da tabela hash utilizando
 *         Hash Aberto e Lista Encadeada.
 */

/* Inclusões */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "lista.h"
#include "tabHash_P3.h"

/*Funções Hash*/
//Função Hash Normal Slide
uint32_t eHashNormal(char chave[], int tamanho){

  int valHash = 0, k = 0;

  while(chave[k] != '\0'){
    valHash += (int)(chave[k]);
    k++;
  }

  return (valHash % tamanho);

}

//Função Hash Horner Slide
uint32_t eHashHorner(itemTH_t item, int tamanho){
  int valHash = 0, k = 0, cst = 127;

  while(item.info->caracteres[k] != '\0'){

    valHash = valHash * cst + (int)(item.info->caracteres[k]);
    k++;
  }

  return (valHash % tamanho);
}

/// <summary>
/// Função que inicializa uma tabela hash.
/// </summary>
/// <param name="tabHash">Endereço da tabela.</param>
/// <param name="tamanho">Tamanho da tabela.</param>
/// <param name="funcaoHash">Endereço da função de cálculo Hash.</param>
void tabelaHash_cria(tabelaHash_t* tabHash, uint32_t tamanho, hash_f funcaoHash) {

   

  uint32_t i;

  // Cria o espaço para as listas da tabela
  tabHash->tabela = malloc(sizeof(lista_t*) * tamanho);
  if (tabHash->tabela == NULL) return;

   

  tabHash->tamanho = tamanho;
  tabHash->funcaoHash = funcaoHash;
  tabHash->nItens = 0;

  // Cria as listas
  for (i = 0; i < tamanho; i++) {
    tabHash->tabela[i] = lista_cria();
  }

  
}

/// <summary>
/// Função que finaliza uma tabela hash.
/// </summary>
/// <param name="tabHash"></param>
void tabelaHash_destroi(tabelaHash_t* tabHash) {
  
  uint32_t i;

  // Destroi as listas
  for (i = 0; i < tabHash->tamanho; i++) {
    lista_libera(tabHash->tabela[i]);
  }

  // Libera o espaço para as listas
  free(tabHash->tabela);

  tabHash->funcaoHash = NULL;
  tabHash->tabela = NULL;
  tabHash->tamanho = 0;
  tabHash->nItens = 0;
}

/// <summary>
/// 
/// </summary>
/// <param name="tabHash"></param>
/// <param name="posicao"></param>
/// <returns></returns>
static uint32_t tabelaHash_posicaoSegura(tabelaHash_t* tabHash, uint32_t posicao) {
  return posicao % tabHash->tamanho;
}

/// <summary>
/// Função que insere um item na tabela hash.
/// </summary>
/// <param name="tabHash">Endereço da tabela.</param>
/// <param name="item">Item a ser inserido.</param>
/// <returns>
/// VERDADEIRO caso o item seja inserido na tabela corretamente, ou
/// FALSO caso ele já esteja na tabela.
/// </returns>
bool_t tabelaHash_insere(tabelaHash_t* tabHash, itemTH_t item) {

    

  uint32_t posicao;
  itemLista_t* itemLista;

  // Calcula a posição onde inserir o elemento
  posicao = tabHash->funcaoHash(item, tabHash->tamanho);
  posicao = tabelaHash_posicaoSegura(tabHash, posicao);

  // Verifica se o item já está na lista
  // Procura na lista
  itemLista = lista_busca(tabHash->tabela[posicao], *(item.info));
  if (itemLista != NULL) return FALSO;

  

  // Vai na lista e insere
  lista_insereInicio(tabHash->tabela[posicao], *(item.info));
  
  //Contagem
  //printf("%d\n", tabHash->tabela[posicao]->nItens - 1 );

  // Se chegou até aqui é porque conseguiu inserir
  tabHash->nItens++;
  return VERDADEIRO;
}

/// <summary>
/// Função que verifica se um determinado item está presente na tabela hash.
/// </summary>
/// <param name="tabHash">Endereço da tabela.</param>
/// <param name="item">Item a ser procurado.</param>
/// <returns></returns>
bool_t tabelaHash_estaPresente(tabelaHash_t* tabHash, itemTH_t item) {

  uint32_t posicao;
  itemLista_t* itemLista;

  // Calcula a posição onde inserir o elemento
  posicao = tabHash->funcaoHash(item, tabHash->tamanho);
  posicao = tabelaHash_posicaoSegura(tabHash, posicao);

  // Procura na lista
  itemLista = lista_busca(tabHash->tabela[posicao], *(item.info));

  // Verifica se encontrou
  return itemLista != NULL;
}

/// <summary>
/// Função que remove um item da tabela hash.
/// </summary>
/// <param name="tabHash">Endereço da tabela.</param>
/// <param name="item">Item a ser removido.</param>
/// <returns></returns>
bool_t tabelaHash_remove(tabelaHash_t* tabHash, itemTH_t item) {

  uint32_t posicao;
  bool_t removeu;

  // Calcula a posição onde inserir o elemento
  posicao = tabHash->funcaoHash(item, tabHash->tamanho);
  posicao = tabelaHash_posicaoSegura(tabHash, posicao);

  // Tenta remover
  removeu = lista_retira(tabHash->tabela[posicao], *(item.info));
  if (removeu) tabHash->nItens--;
  return removeu;
}

/// <summary>
/// Função que imprime todos os elementos da tabela hash.
/// </summary>
/// <param name="tabHash">Endereço da tabela.</param>
void tabelaHash_imprime(tabelaHash_t* tabHash) {

  uint32_t i;

  for (i = 0; i < tabHash->tamanho; i++) {
    lista_imprime(tabHash->tabela[i]);
  }
}
