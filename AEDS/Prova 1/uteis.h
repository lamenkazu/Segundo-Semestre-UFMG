#pragma once

/**
 * @file   uteis.h
 * @brief  Arquivo com as definições de tipos e funções úteis utilizados 
 * na prova de AEDS.
 * @author Leandro Maia
 * @date   2022-09-23
 */

/* Constantes */

/// Definição do valor booleano verdadeiro
#define VERDADEIRO (1 == 1)
/// Definição do valor booleano falso
#define FALSO      (!VERDADEIRO)

/* Tipos */

/// Tipo booleano
typedef unsigned int bool_t;

/* Funções exportadas */

void uteis_removeQuebraLinhaFinal(char texto[]);
void uteis_imprimeTracinhos(int nTracinhos);
void uteis_converteInteiroParaTexto(int numero, char texto[]);
int uteis_converteTextoParaInteiro(char numeroTexto[]);