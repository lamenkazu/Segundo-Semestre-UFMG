/**
 * @file   prova_01_va.c
 * @brief  Arquivo principal da prova 01 de AEDS com múltiplos arquivos.
 * @author Erick Etiene Simião
 * @date   2022-09-23
 */

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "uteis.h"
#include "dado.h"
#include "lista.h"
#include "fila.h"

/* Constantes */

// Valor que define que o programa foi executado corretamente
#define SUCESSO  0
#define QNT 10

/**
 * Função com a implementação do exercício de Lista.
 */
void exercicioLista(void) {

  lista_t * lista = criaLista();
  registroLista_t registros[QNT];

  //Preenchimento dos Registros
  
  
  
    
  strcpy(registros[0].pessoa.cpf, "42617633977"); 
  strcpy(registros[0].pessoa.nome, "Joao Pedro");

  strcpy(registros[1].pessoa.nome, "Caua Jorge");
  strcpy(registros[1].pessoa.cpf, "15367920128");

  strcpy(registros[2].pessoa.nome, "Sabrina Ester");
  strcpy(registros[2].pessoa.cpf, "46822388923");


  strcpy(registros[3].pessoa.nome, "Bernardo Marcelo");
  strcpy(registros[3].pessoa.cpf, "97537506094");

  strcpy(registros[4].pessoa.nome, "Vitor Enrico");
  strcpy(registros[4].pessoa.cpf, "78128691481");

  strcpy(registros[5].pessoa.nome, "Fabio Pedro");
  strcpy(registros[5].pessoa.cpf, "08020886192");

  strcpy(registros[6].pessoa.nome, "Lorena Isabela");
  strcpy(registros[6].pessoa.cpf, "44382991447");

  strcpy(registros[7].pessoa.nome, "Danilo Sebastião");
  strcpy(registros[7].pessoa.cpf, "54086848651");
  
  

  if(listaVazia(lista) == VERDADEIRO){

      
      
      insereNaListaORD(lista, registros[0]);
      insereNaListaORD(lista, registros[1]);
      insereNaListaORD(lista, registros[2]);
      insereNaListaORD(lista, registros[3]);
      insereNaListaORD(lista, registros[4]);
      insereNaListaORD(lista, registros[5]);
      insereNaListaORD(lista, registros[6]);
      insereNaListaORD(lista, registros[7]);
      
      
      printf("\n\n");
      imprimeLista(lista);
      
      rmvRegistro(lista,"42617633977" );

      imprimeLista(lista);
      rmvRegistro(lista,"78128691481" );

      imprimeLista(lista);
      rmvRegistro(lista,"54086848651" );

      imprimeLista(lista);
      

      liberaLista(lista);
     
  }

}

/**
 * Função com a implementação do exercício de Fila.
 */
void exercicioFila(void) {

  Fila * fila = criaFila(QNT);
  registro_t registros[QNT];

  strcpy(registros[0].cpf, "42617633977"); 
  strcpy(registros[0].nome, "Joao Pedro");

  strcpy(registros[1].nome, "Caua Jorge");
  strcpy(registros[1].cpf, "15367920128");

  strcpy(registros[2].nome, "Sabrina Ester");
  strcpy(registros[2].cpf, "46822388923");


  strcpy(registros[3].nome, "Bernardo Marcelo");
  strcpy(registros[3].cpf, "97537506094");

  strcpy(registros[4].nome, "Vitor Enrico");
  strcpy(registros[4].cpf, "78128691481");

  strcpy(registros[5].nome, "Fabio Pedro");
  strcpy(registros[5].cpf, "08020886192");

  strcpy(registros[6].nome, "Lorena Isabela");
  strcpy(registros[6].cpf, "44382991447");

  strcpy(registros[7].nome, "Danilo Sebastião");
  strcpy(registros[7].cpf, "54086848651");

  if(filaVazia(fila) == VERDADEIRO){

      registro_t dado;

      insereNaFila(fila, registros[0]);
      insereNaFila(fila, registros[1]);
      insereNaFila(fila, registros[2]);
      insereNaFila(fila, registros[3]);
      insereNaFila(fila, registros[4]);
      insereNaFila(fila, registros[5]);
      insereNaFila(fila, registros[6]);
      insereNaFila(fila, registros[7]);

      imprimeFila(fila);

      retiraDaFila(fila, &dado);
      imprimeFila(fila);

        
      retiraDaFila(fila, &dado);
      imprimeFila(fila);

      retiraDaFila(fila, &dado);
      imprimeFila(fila);

      retiraDaFila(fila, &dado);
      imprimeFila(fila);

      retiraDaFila(fila, &dado);
      imprimeFila(fila);

      retiraDaFila(fila, &dado);
      imprimeFila(fila);

      retiraDaFila(fila, &dado);
      imprimeFila(fila);

      retiraDaFila(fila, &dado);
      imprimeFila(fila);
    

  }

}

int main(int argc, char ** argv) {

  int opcao;
  char lixo;

  do {

    // Imprime o menu de opções
    printf("\n"\
           "Prova 01\n"\
           "-------------\n"\
           "1 - Executar exercicio de lista\n"\
           "2 - Executar exercicio de fila\n"\
           "0 - Sair\n"
           );

    printf("Digite a opcao [0:2]: ");
    scanf("%d%c", &opcao, &lixo);

    switch (opcao) {
      case 0:
        break;
      case 1:
        exercicioLista();
        break;
      case 2:
        exercicioFila();
        break;
      default:
        printf("Opcao invalida.\n");
    }

  } while (opcao != 0);

  // Imprime mensagem de tchau
  printf("Obrigado por rodar a prova 01.");

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}