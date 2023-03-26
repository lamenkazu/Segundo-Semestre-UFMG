#pragma once

#ifndef __TABELA_HASH_h__
#define __TABELA_HASH_h__

/* Inclusões */
#include <stdint.h>
#include "tipos.h"
#include "lista.h"

/* Constantes */

/* Tipos */

/// <summary>
/// Tipo do elemento da tabela hash.
/// </summary>
typedef char itemTH_t[21];

/// <summary>
/// Tipo de um ponteiro de função que calcula o hash
/// para o tipo adequado.
/// </summary>
typedef uint32_t(*hash_f) (itemTH_t, int);

/// <summary>
///  Estrutura com os membros necessários para a manipulação
/// da tabela hash.
/// </summary>
struct tabelaHash_s {
  // Tamanho da tabela
  uint32_t tamanho;
  // Endereço da função de cálculo do hash
  hash_f funcaoHash;
  // Tabela Hash
  lista_t** tabela;
  // Número de itens na tabela.
  uint64_t nItens;
};

/// <summary>
/// Tipo "Tabela Hash"
/// </summary>
typedef struct tabelaHash_s tabelaHash_t;

/* Funções Exportadas */
void tabelaHash_inicializa(tabelaHash_t* tabHash, uint32_t tamanho, hash_f funcaoHash);
void tabelaHash_finaliza(tabelaHash_t* tabHash);
bool_t tabelaHash_insere(tabelaHash_t* tabHash, itemTH_t item);
bool_t tabelaHash_estaPresente(tabelaHash_t* tabHash, itemTH_t item);
bool_t tabelaHash_remove(tabelaHash_t* tabHash, itemTH_t item);
void tabelaHash_imprime(tabelaHash_t* tabHash);

#endif // __TABELA_HASH_h__