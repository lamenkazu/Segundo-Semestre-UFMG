#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "tipos.h"
#include "grafo_MA.h"

bool_t criaGrafo(grafo_t ** grafo, uint16_t nVertices, tipoGrafo_t tipo){

    uint32_t limite;

    //Teste dos parâmetros
    if((grafo == NULL) || (nVertices == 0)){
        return FALSE;
    }
    

    //Aloca o epsaço para a estrutura do grafo
    *grafo = malloc(sizeof(grafo_t));
    if(*grafo == NULL){
        return FALSE;
    }
    
    //Aloco espaço para as "linhas"
    (*grafo)->dados = (custo_t **) malloc(sizeof(custo_t *) * nVertices);
    if((*grafo)->dados == NULL){
        free(*grafo);
        return FALSE;
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
            return FALSE;
        }
    }

    //Se chegou aqui, então conseguiu alocar espaço para o grafo. ***************

    //Inicializa o grafo
    for(int i = 0; i < nVertices; i++){

        limite = (tipo == enumGrafoDirecionado ? nVertices : (i + 1) );
        for(int j = 0; j < limite; j++){

            GRAFO_DADOS(*grafo)[i][j] = ARESTA_AUSENTE ;

        }

    }
    (*grafo)->nVertices = nVertices;
    (*grafo)->tipo = tipo ;

    return TRUE;
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
        return FALSE;
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

    return (GRAFO_DADOS(*grafo)[vOrigem][vDestino] == ARESTA_AUSENTE ? FALSE : TRUE);


}

bool_t obtemCustoAresta(grafo_t ** grafo,vertice_t origem, vertice_t destino, custo_t * custo){

    vertice_t vOrigem, vDestino;
    
    if( (origem > (*grafo)->nVertices)|| (destino > (*grafo)->nVertices)){
        return FALSE;
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

    return TRUE;


}



bool_t criaAresta(grafo_t **grafo, vertice_t origem, vertice_t destino, custo_t custo){

    vertice_t vOrigem, vDestino;

    if(existeArestaGrafo(grafo, origem, destino) == TRUE){
        printf("Existe aresta");
        return FALSE;
    }

    //Verifica se a aresta forma um self-loop
    if(origem == destino){
        return FALSE;
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

    return TRUE;


}

bool_t removeAresta(grafo_t **grafo, vertice_t origem, vertice_t destino){

    vertice_t vOrigem, vDestino;

    if(existeArestaGrafo(grafo, origem, destino) == FALSE){
        return FALSE;
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

    return TRUE;


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