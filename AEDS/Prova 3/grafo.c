#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "tipos.h"
#include "grafo.h"

bool_t criaGrafo(grafo_t ** grafo, tipoGrafo_t tipo){

    uint32_t limite;

    //Teste dos parâmetros
    if((grafo == NULL)){
        return FALSO;
    }
    

    //Aloca o epsaço para a estrutura do grafo
    *grafo = malloc(sizeof(grafo_t));
    if(*grafo == NULL){
        return FALSO;
    }
    
    //Se chegou aqui, então conseguiu alocar espaço para o grafo. ***************

    //Inicializa o grafo

/*
    for(int i = 0; i < nVertices; i++){

        limite = (tipo == enumGrafoDirecionado ? nVertices : (i + 1) );
        for(int j = 0; j < limite; j++){

            GRAFO_DADOS(*grafo)[i][j] = ARESTA_AUSENTE ;

        }

    }
*/
    (*grafo)->nVertices = 0;
    (*grafo)->tipo = tipo ;

    return VERDADEIRO;

}

bool_t criaVertice(grafo_t ** grafo){

    uint32_t limite;

    //Aloco espaço para as "linhas"
    (*grafo)->dados = (custo_t **) malloc(sizeof(custo_t *) * nVertices);
    if((*grafo)->dados == NULL){
        free(*grafo);
        return FALSO;
    }

    //Aloca espaço para as colunas
    for(int i = 0; i < nVertices; i++){

        //Define o limite dependendo do tipo de Grafo (direcionado ou nao direiconado)
        limite = (tipo == enumGrafoDirecionado ? nVertices : (i + 1) );

        //Aloca espaço para as colunas
        GRAFO_DADOS(*grafo)[i] = (custo_t *) malloc(sizeof(custo_t) * limite);
        if(GRAFO_DADOS(*grafo)[i] == NULL){

            for(int j = 0; j < i; j++){
                free(GRAFO_DADOS(*grafo)[j]);
            }
            
            free((*grafo)->dados);
            free(*grafo);
            return FALSO;
        }
    }

}

void destroiGrafo(grafo_t ** grafo){

    uint32_t limite;

    //Libera o espaço das colunas
    for(int i = 0; i < (*grafo)->nVertices; i++){

        //Define o limite dependendo do tipo de Grafo (direcionado ou nao direiconado)
        limite = ((*grafo)->tipo == enumGrafoDirecionado ? (*grafo)->nVertices : (i + 1) );

        free(GRAFO_DADOS(*grafo)[i]);
    }

    //Libera o espaço para as linhas
    free((*grafo)->dados);

    free(*grafo);

}

bool_t existeArestaGrafo(grafo_t ** grafo,vertice_t origem, vertice_t destino){

    vertice_t vOrigem, vDestino;
    
    if( (origem > (*grafo)->nVertices)|| (destino > (*grafo)->nVertices)){
        return FALSO;
    }

    if( (*grafo)->tipo == enumGrafoDirecionado ){
        vOrigem = origem;
        vDestino = destino;
    }else{
        if(origem < destino){
            vOrigem = destino;
            vDestino = origem;
        }else{
            vOrigem = origem;
            vDestino = destino;
        }
            
    }

    return (GRAFO_DADOS(*grafo)[vOrigem][vDestino] == ARESTA_AUSENTE ? FALSO : VERDADEIRO);


}

bool_t obtemCustoAresta(grafo_t ** grafo,vertice_t origem, vertice_t destino, custo_t * custo){

    vertice_t vOrigem, vDestino;
    
    if( (origem > (*grafo)->nVertices)|| (destino > (*grafo)->nVertices)){
        return FALSO;
    }

    if( (*grafo)->tipo == enumGrafoDirecionado ){
        vOrigem = origem;
        vDestino = destino;
    }else{
        if(origem < destino){
            vOrigem = destino;
            vDestino = origem;
        }else{
            vOrigem = origem;
            vDestino = destino;
        }
            
    }

    (*custo) =  GRAFO_DADOS(*grafo)[vOrigem][vDestino];

    return VERDADEIRO;


}



bool_t criaAresta(grafo_t **grafo, vertice_t origem, vertice_t destino, custo_t custo){

    vertice_t vOrigem, vDestino;

    if(existeArestaGrafo(grafo, origem, destino) == VERDADEIRO){
        printf("Existe aresta");
        return FALSO;
    }

    //Verifica se a aresta forma um self-loop
    if(origem == destino){
        return FALSO;
    }

    if( (*grafo)->tipo == enumGrafoDirecionado ){
        vOrigem = origem;
        vDestino = destino;
    }else{
        if(origem < destino){
            vOrigem = destino;
            vDestino = origem;
        }else{
            vOrigem = origem;
            vDestino = destino;
        }
            
    }

    //Criar aresta com o custo especificado
    GRAFO_DADOS(*grafo)[vOrigem][vDestino] = custo;

    return VERDADEIRO;


}

bool_t removeAresta(grafo_t **grafo, vertice_t origem, vertice_t destino){

    vertice_t vOrigem, vDestino;

    if(existeArestaGrafo(grafo, origem, destino) == FALSO){
        return FALSO;
    }

    //Se chegou aqui Aresta existe

    if( (*grafo)->tipo == enumGrafoDirecionado ){
        vOrigem = origem;
        vDestino = destino;
    }else{
        if(origem < destino){
            vOrigem = destino;
            vDestino = origem;
        }else{
            vOrigem = origem;
            vDestino = destino;
        }
            
    }

    //Criar aresta com o custo especificado
    GRAFO_DADOS(*grafo)[vOrigem][vDestino] = ARESTA_AUSENTE;

    return VERDADEIRO;


}

void imprimeGrafo(grafo_t ** grafo){

    uint32_t limite;

    (void)printf("Impressão do Grafo - nVertices: %-5d\n", (*grafo)->nVertices);
    (void)printf("------------------------------------\n");

    for(uint32_t i = 0; i < (*grafo)->nVertices; i++){

        limite = ((*grafo)->tipo == enumGrafoDirecionado ? (*grafo)->nVertices : (i + 1) );

        for(uint32_t j = 0; j < limite; j++){

            //Se for direcionado (origem -> destino : custo)
            //Se for não direcionado (origem -- destino : custo)

            (void)printf("%5d -%c %5d : %11d\n", i, ((*grafo)->tipo == enumGrafoDirecionado ? '>' : '-'), j, GRAFO_DADOS(*grafo)[i][j]);

        }

    }

}