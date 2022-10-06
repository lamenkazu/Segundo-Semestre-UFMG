#pragma once

/**
 * @file   dado.h
 * @brief  Arquivo com a definição dos tipos referentes a um dado da lista
 *         ou da fila utilizados na prova de AEDS.
 * @author <coloque_seu_nome_aqui>
 * @date   2022-09-23
 */

/* Inclusões */
#include <stdint.h>

/* Constantes */

// Tamanho de um CPF em número de dígitos
#define CPF_TAMANHO   (11+1)
// Tamanho máximo de um nome
#define NOME_TAMANHO_MAXIMO   (20)

/* Tipos */

/// Tipo referente a um CPF
typedef char CPF_t[CPF_TAMANHO];

/// Tipo referente a um Nome
typedef char nome_t[NOME_TAMANHO_MAXIMO];

/// Estrutura com os campos de um registro de dados
struct registro_s {
  CPF_t cpf;
  nome_t nome;
};

/// Tipo "Registro"
typedef struct registro_s registro_t;