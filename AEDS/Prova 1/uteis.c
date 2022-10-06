/**
 * @file   uteis.c
 * @brief  Arquivo com as implementações das funções úteis utilizadas
 * na prova de AEDS.
 * @author Leandro Maia
 * @date   2022-09-23
 */

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Função que remove a quebra de linha final do texto caso ela
 * exista.
 * @param texto Endereço do texto a ter a quebra de linha removida.
 */
void uteis_removeQuebraLinhaFinal(char texto[]) {

  int tamanho;
  tamanho = strlen(texto);
  if ((tamanho > 0) && (texto[tamanho - 1] == '\n')) {
    texto[tamanho - 1] = '\0';
  }
}

/**
 * Função auxiliar para imprimir tracinhos.
 * @param nTracinhos Número de tracinhos a ser impresso na tela.
 */
void uteis_imprimeTracinhos(int nTracinhos) {

  int i;

  for (i = 0; i < nTracinhos; i++) {
    printf("-");
  }
}

/**
 * Função que converte de inteiro para cadeira de caracteres.
 * @param numero Número a ser convertido.
 * @param texto Endereço do local que receberá o número convertido em
 * cadeia de caracteres.
 */
void uteis_converteInteiroParaTexto(int numero, char texto[]) {
  sprintf(texto,"%d",numero);
}

/**
 * Função que converte um numero escrito em cadeia de caracteres para inteiro.
 * @param numeroTexto Endereço do local onde está o número escrito em texto.
 * @return valor equivalente ao texto.
 */
int uteis_converteTextoParaInteiro(char numeroTexto[]) {
  return atoi(numeroTexto);
}