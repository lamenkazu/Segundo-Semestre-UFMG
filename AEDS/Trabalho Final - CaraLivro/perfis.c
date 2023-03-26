/* Includes *************/
#include "tipos.h"
#include "perfis.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Funções *****************************************/

/*Aloca dinamicamente a quantidade de Perfis*/
perfil_t * iniciaPerfis(grafo_t ** grafo, tipoGrafo_t tipoGrafo){
    perfil_t * perfis =  (perfil_t*) calloc(qntPerfis, sizeof(perfil_t));
    
    criaGrafo(grafo, qntPerfis, tipoGrafo);

    return perfis;
}

/*Cadastra um perfil com os dados enviados por parâmetro*/
bool_t cadastroPerfil(perfil_t * perfis, Nome nome){

    for(int i = 0; i < qntPerfis; i++){
        if(perfis[i].criado == FALSE){

            strcpy(perfis[i].nome, nome);
            perfis[i].id = i+1;
            perfis[i].ativo = FALSE;
            perfis[i].criado = TRUE;

            return TRUE;
        }
    }

}

/*Exibe no terminal os perfis e seus dados*/
void listaPerfis(perfil_t * perfis){

    printf("Perfis existentes: \n");
    for(int i = 0; i < qntPerfis; i++){

        char atividade[10];
        strcpy(atividade, perfis[i].ativo == TRUE ? "Ativo" : "Inativo");

        if(perfis[i].criado == TRUE)
            printf("%d\t|%s\t|%s\n", perfis[i].id, perfis[i].nome, atividade);   

    }
}

void alternarAtividadePerfil(perfil_t * perfis, uint16_t id){

    perfis[id - 1].ativo = ( perfis[id-1].ativo == TRUE ? FALSE : TRUE);

}

bool_t seguirPerfil(perfil_t * profile, grafo_t ** grafo, perfil_t * perfis, uint16_t id){

    if(profile->id == 0){
        return FALSE;
    }

    return criaAresta(grafo, ((profile->id)), id, CUSTO_SEGUIDOR);

}

bool_t unfollowPerfil(perfil_t * profile, grafo_t ** grafo, perfil_t * perfis, uint16_t id){
    if(profile->id == 0){
        return FALSE;
    }

    return removeAresta(grafo, (profile->id), id);
}

void perfilLogado(perfil_t * perfis, perfil_t * logProfile){

    for(int i = 0; i < qntPerfis; i++){
        if(perfis[i].ativo == TRUE){
            *logProfile = perfis[i];
        }
    }

}

void logIn(perfil_t * perfis, perfil_t * logProfile, uint16_t id){


    alternarAtividadePerfil(perfis, id);

    perfilLogado(perfis, logProfile);
   

}

void logOut(perfil_t * perfis, perfil_t * logProfile){

    alternarAtividadePerfil(perfis, logProfile->id);

    logProfile->id = 0;
    logProfile->ativo = FALSE;
    strcpy(logProfile->nome, "");

 


}

