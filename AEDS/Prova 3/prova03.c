/**
* @file   prova03.c
* @author <seu_nome>
* @date   2022-12-07
*/

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "tipos.h"
#include "tabHash_P3.h"
#include "grafo.h"

/* Constantes */

/* Tipos */

/// Tipo que representa um valor booleano
typedef unsigned char bool_t;

// Valores dos textos para serem usados na prova
static const char * TEXTOS[NUMERO_TEXTOS] = {
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

/**
 * Função que obtem um item.
 * @param valor Endereço do local para onde o valor será copiado.
 * @param indice Endereço do local para onde o índice será copiado.
 * @param reiniciar Verdadeiro caso queira que o índice retorne a 0,
 * ou Falso caso queira que continue a contagem. O normal é chamar
 * uma vez com o valor verdadeiro e as demais com valor falso.
 */
void util_obtemItem(char * valor, int * indice, bool_t reiniciar) {

  static int indiceAtual = 0;

  // Se for para reiniciar,  volta a contar do 0
  if (reiniciar) {
    indiceAtual = 0;
    srand((unsigned int)(time(NULL)));
  }

  // Obtem um valor da posição
  strcpy(valor, TEXTOS[rand() % NUMERO_TEXTOS]);
  *indice = indiceAtual++;
}

/**
 * Função que dá um exemplo de uso da função util_obtemItem.
 */
void exemploUsoObtemItem(void) {

  char texto[TAMANHO_TEXTO];
  int indice;

  util_obtemItem(texto, &indice, VERDADEIRO);
  printf("Indice: %d | Valor: %s\n", indice, texto);
  util_obtemItem(texto, &indice, FALSO);
  printf("Indice: %d | Valor: %s\n", indice, texto);
  util_obtemItem(texto, &indice, FALSO);
  printf("Indice: %d | Valor: %s\n", indice, texto);
  util_obtemItem(texto, &indice, FALSO);
  printf("Indice: %d | Valor: %s\n", indice, texto);
  util_obtemItem(texto, &indice, FALSO);
  printf("Indice: %d | Valor: %s\n", indice, texto);
  util_obtemItem(texto, &indice, FALSO);
  printf("Indice: %d | Valor: %s\n", indice, texto);
  util_obtemItem(texto, &indice, FALSO);
  printf("Indice: %d | Valor: %s\n", indice, texto);
}


/**
 * Tarefa 01.
 */
void tarefa01(void) {

    

    itemLista_t item;

    item.info = (infoLista_t*) malloc(sizeof(infoLista_t)) ;

    tabelaHash_t tabHash;
    tabelaHash_cria(&tabHash, 10, eHashHorner);


        for(int i = 0; i < 50; i++){

            if(i > 0){
                util_obtemItem(item.info->caracteres, &item.info->inteiro, FALSO);
            }else{
                util_obtemItem(item.info->caracteres, &item.info->inteiro, VERDADEIRO);
            }

            if(tabelaHash_insere(&tabHash, item) == FALSO){
                printf("Não conseguiu colocar %s\n", item.info->caracteres);
            }
        }

        printf("\n\n");
    tabelaHash_imprime(&tabHash);

    tabelaHash_destroi(&tabHash);

    



}

/**
 * Tarefa 02.
 */
void tarefa02(void) {

    

    grafo_t * grafo;


    if(criaGrafo(&grafo, enumGrafoNaoDirecionado) == VERDADEIRO){

      /*

        if(criaAresta(&grafo, 1, 2 , 6) == FALSO){
            printf("Aresta Criada\n");
        }else{
            printf("Falha na Criação de Aresta\n");
        }

    }else{
        printf("deu ruim");
    }
    */

    imprimeGrafo(&grafo);

    destroiGrafo(&grafo);
    

}

/**
 * Tarefa 03.
 */
void tarefa03(void) {

}

/**
 * Função principal do programa.
 * @param argc Número de argumentos passados para o programa.
 * @param argv Valor dos argumentos.
 * @return OK caso programa rode conforme o esperado, ou caso
 * contrário, o código do erro ocorrido.
 */
int main(int argc, char ** argv) {

  int opcao;

  do {

    // Impressão do menu de opções
    printf("Prova 03\n"\
           "------------\n"\
           "1 - Tarefa 01\n"\
           "2 - Tarefa 02\n"\
           "3 - Tarefa 03\n"\
           "0 - Sair\n"
    );
    printf("Digite a opcao [0:3]: ");
    scanf("%d%*c", &opcao);
    printf("\n");

    // Opções
    switch (opcao) {
      // Sair
    case 0:
      break;
    case 1:
      tarefa01();
      break;
    case 2:
      tarefa02();
      break;
    case 3:
      tarefa03();
      break;
    default:
      printf("Opcao invalida!\n");
      break;
    }

  } while (opcao != 0);

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}