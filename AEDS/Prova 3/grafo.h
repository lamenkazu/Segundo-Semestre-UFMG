#include <stdint.h>
#include "tipos.h"

//Tipo que representa o índice de um vértice
typedef uint16_t vertice_t;

//Valor que indica ausência de aresta
#define ARESTA_AUSENTE (0x80000000)

//Valor que indica Custo Infinito (não se passa por ele para escolher melhores caminhos)
#define ARESTA_CUSTO_INFINITO (0x7FFFFFFF)

//Custo de uma amizade
#define CUSTO_SEGUIDOR 7


//Macro para acesso aos dados do grafo
#define GRAFO_DADOS(x) ( (custo_t **) ((x)->dados) )

enum tipoGrafo_enum {
    enumGrafoDirecionado,
    enumGrafoNaoDirecionado
};

typedef enum tipoGrafo_enum tipoGrafo_t;

//Tipo que representa o custo de uma aresta
typedef int32_t custo_t;

//Estrutura com as informações do tipo Grafo
typedef struct grafo_s {
    //Dados do grafo
    void * dados;

    //numero de vertices do grafo [1: 65325]
    uint16_t nVertices;

    //Tipo do grafo
    tipoGrafo_t tipo;

} grafo_t;



bool_t criaGrafo(grafo_t ** grafo, tipoGrafo_t tipo);

void destroiGrafo(grafo_t ** grafo);

bool_t existeArestaGrafo(grafo_t ** grafo,vertice_t origem, vertice_t destino);

bool_t obtemCustoAresta(grafo_t ** grafo,vertice_t origem, vertice_t destino, custo_t * custo);

bool_t criaAresta(grafo_t **grafo, vertice_t origem, vertice_t destino, custo_t custo);

bool_t removeAresta(grafo_t **grafo, vertice_t origem, vertice_t destino);

void imprimeGrafo(grafo_t ** grafo);
