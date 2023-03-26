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
#include "tabelaHash.h"

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
uint32_t eHashHorner(char chave[], int tamanho){
  int valHash = 0, k = 0, cst = 127;

  while(chave[k] != '\0'){

    valHash = valHash * cst + (int)(chave[k]);
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
void tabelaHash_inicializa(tabelaHash_t* tabHash, uint32_t tamanho, hash_f funcaoHash) {

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
void tabelaHash_finaliza(tabelaHash_t* tabHash) {
  
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
  itemLista = lista_busca(tabHash->tabela[posicao], item);
  if (itemLista != NULL) return FALSO;

  // Vai na lista e insere
  lista_insereInicio(tabHash->tabela[posicao], item);
  
  //Contagem
  printf("%d\n", tabHash->tabela[posicao]->nItens - 1 );

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
  itemLista = lista_busca(tabHash->tabela[posicao], item);

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
  removeu = lista_retira(tabHash->tabela[posicao], item);
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

int main(){

  char * TEXTOS[] = {
  "rLVTzBZai2QjpXahpM3i",
  "KeGo2tc523CHzzrjmpA5",
  "QElVanON124zmUAFB3dm",
  "bRFf5jGtkHwvtAlHSsb0",
  "LvJeQJSjsjJCuQOXDT5B",
  "hmmrbncM9290qTQqJqSX",
  "wnRNTlLaNZ1w1fLSwckw",
  "CoxBYzjPhfKSWneY0slm",
  "EWFhBoumInpLQolQz3bG",
  "wwiIcSxCYE0jYfnw17Yt",
  "2eMtXxrDtAXTrIzaMMa0",
  "9naOGmjjENSqSB3HDdlS",
  "gzrCaSLAymKYR5CDdxUT",
  "iyaAEDb3S30VxSBu56C4",
  "6eJYbwc1G2kS0WnT0LdM",
  "HXIBsgNpDBtfTR9yW54r",
  "yzcrRgvBl1H9pHm4tV5y",
  "o1V8uMunJj0by1HAVgyg",
  "KezqwHUX6mTqxzBZHUtZ",
  "GlMrlyKj4k0Pf9qSmPxq",
  "RxdOYhSSaAC2RM8LstAy",
  "5VWgDL0GkrDW6nEq8oLc",
  "Pmu1axMup5do56W9oemG",
  "6YRQCJlk5IfTQruVOKmL",
  "ktSr4Phuwa1QY2EdnsJI",
  "6XRu8E5ADmT0Ub3Oautk",
  "tHb8s9G8s385yXSsdWt4",
  "HhNJKhIIiSlCWC7t6UBJ",
  "WgjfQCKrc8TuJMzg0BaG",
  "lrGZuoc97yAti8gJUG4t",
  "DGJDeo3mCSSHAG0to3Pz",
  "HeNUhF7wwivYyXphSycf",
  "EKFAnnaM6KqsaduBBISj",
  "GnJe3LXra7TbqacmRmtN",
  "lVPymBtogO2SDj9cUyRH",
  "AUrDKoSgzN4YISuICayg",
  "8cCijwcu8I3lbl1SYYHU",
  "7WGWkQomx11riJ1nfjRH",
  "O4CbiowXN5DlMz10KEMQ",
  "g7KtD8YUn1UXodROa7wI",
  "bY0FB7FG0LLMMZ4A1bt4",
  "gDFuaaKGt7tshJiWPaD3",
  "RJLyFLTDWsWEETt5YV9x",
  "kkgsUxTqkdthFn6fIAu3",
  "w7ofxnnnLEAX9Z5qewGU",
  "wjCd0aQzjywFoPEIvGP0",
  "MByvf0zjoWDe6qdh7eIX",
  "pmJYoyp6Y5VMLJFi5I7j",
  "iYkCruo91mRuFrK5dBuE",
  "14poTaAUMWU6amJl9IFv",
  "a70YkLFYxjKnbYOrAByX",
  "GIAxaVq3dijjja8gwAGW",
  "QFmt5TI3J7BclPZiM2x0",
  "b0VnlnkAjTKwTITb77Ez",
  "nVRSDoL23aBUHs9ekf7l",
  "cQG4icb72mHMAcdckHlt",
  "j5BT0BYgdH8SE0D7Mhsz",
  "lvYqNvcVmBVBsiquZhd2",
  "TeB9tcWqpsMGtn7jH6Gj",
  "Pe1ZOGIRqHanO0LjaUMf",
  "EnWsUOS17F3oZjVqqPxg",
  "A0Ye2EM368xfN1iIuSHe",
  "8nSmP6bjF8j9EjxUGhkC",
  "Yt9Jc9Jm2lUBesIMQalF",
  "wzS7B5r0fhv6zosWxMWC",
  "ImLzfcfseeIHIemW2qzm",
  "sSxYeMkr1MWO0n6DtEVM",
  "XmejW5Yx4589e39BN55U",
  "IsksfQJolNSNn7lhcltG",
  "ePYMZcuGyTrieI2ZbeHA",
  "xataJRPg6egR0CPNrVGY",
  "MBhS13JkBKk4xhxJrxSk",
  "rLOx7OwRc05njeQpij23",
  "vpiNjj7WPbnoOSUipQTS",
  "qyuOxhQ7rtl3SY9dCzK0",
  "BUDFqowC2oKkyHenMLOP",
  "WGwtFL91P5dolyEjwfxI",
  "2j1s0xmJLyE4zRV9pTgu",
  "K9lWqq4bTrdX4nObLvl0",
  "94uGxyYugNSR5q79qtX8",
  "O5lYlaKCOoQOF6YhATxg",
  "YydNElgjqzhKvJSbnzYD",
  "rYMPjsbKKKx3cyrCGRse",
  "I5lAJeQ6BA200sIU8dWA",
  "JPjL4BtZnIz6bQqm3GGL",
  "KkPrZeMYRz2EJnBibFLv",
  "UDEqGFM8UPgcBLrxqoZU",
  "6hzdMTDyY7FTC1CuY9EY",
  "K75buYdBcSj5QTkB2jSo",
  "cohXenibzUXbr3zNqdyr",
  "Z2BPzTbR8h5MkePlYGwg",
  "1uyqkYkJbbsO60UaMKFA",
  "vUgmUNWh0GW8TxyaIOc2",
  "ZRVzxlj0F3ypYqM1o8pp",
  "rqorc1RsExTOXAB3tsHy",
  "EXJV6ORlx7pOH0KWNzlR",
  "zh2ctdP9FO49SMUpHepI",
  "S4WHvbzIqaa2CR2RWRSt",
  "b6Bo17hz3DnE2FHFvDFZ",
  "FcfOItBkSElaeQOV3m2y"
};


  /*Tabela Hash Normal */
  tabelaHash_t tabHashNormal1;
  tabelaHash_inicializa(&tabHashNormal1, 10, eHashNormal);
  for(int i = 0; i < 100; i++){
    tabelaHash_insere(&tabHashNormal1, TEXTOS[i]);
  }
  tabelaHash_imprime(&tabHashNormal1);

  
  tabelaHash_t tabHashNormal2;
  tabelaHash_inicializa(&tabHashNormal2, 20, eHashNormal);
  for(int i = 0; i < 100; i++){
    tabelaHash_insere(&tabHashNormal2, TEXTOS[i]);
  }
  tabelaHash_imprime(&tabHashNormal2);


  printf("\n\n\n");

  /*Tabela Hash 2*/
  tabelaHash_t tabHashHorner1;
  tabelaHash_inicializa(&tabHashHorner1, 10, eHashHorner);
  for(int i = 0; i < 100; i++){
    tabelaHash_insere(&tabHashHorner1, TEXTOS[i]);
  }
  tabelaHash_imprime(&tabHashHorner1);

  tabelaHash_t tabHashHorner2;
  tabelaHash_inicializa(&tabHashHorner2, 10, eHashHorner);
  for(int i = 0; i < 100; i++){
    tabelaHash_insere(&tabHashHorner2, TEXTOS[i]);
  }
  tabelaHash_imprime(&tabHashHorner2);

}