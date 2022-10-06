#pragma once

/**
 * @file   fila.h
 * @brief  Arquivo com a definição dos tipos e funções de manipulação da fila
 *         utilizados na prova de AEDS.
 * @author <coloque_seu_nome_aqui>
 * @date   2022-09-23
 */

/* Inclusões */
#include "dado.h"
#include "uteis.h"

/* Constantes */
#define QNT 10

/* Códigos de Erros */

/* Tipos */
typedef struct registroFila{
    unsigned int nItens;
    unsigned int inicio;
    unsigned int capacidade;
    registro_t *registros;
} Fila;

/* Funções Exportadas */
Fila * criaFila(unsigned int capac);

bool_t insereNaFila(Fila * fila, registro_t reg);

bool_t filaVazia(Fila*fila);

bool_t retiraDaFila(Fila * fila, registro_t * dado);

void liberaFila(Fila * fila);

void imprimeFila(Fila * fila);