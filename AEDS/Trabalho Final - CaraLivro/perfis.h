/* Includes *************/
#include "tipos.h"
#include "grafo_MA.h"


/*Definições*/
#define tNome 61 //Tamanho do nome
#define qntPerfis 10 //Quantidade máxima de perfis permitidos

//Typedefs
typedef char Nome[tNome];

typedef struct perfil_s{ //Estrutura de um Perfil
    int id;
    Nome nome;
    bool_t ativo;
    bool_t criado;
} perfil_t;


/*Funções *****************************************/
perfil_t * iniciaPerfis(grafo_t ** grafo, tipoGrafo_t tipoGrafo);

bool_t cadastroPerfil(perfil_t * perfis, Nome nome);

void listaPerfis(perfil_t * perfis);

void alternarAtividadePerfil(perfil_t * perfis, uint16_t id);

bool_t seguirPerfil(perfil_t * profile, grafo_t ** grafo, perfil_t * perfis, uint16_t id);

bool_t unfollowPerfil(perfil_t * profile, grafo_t ** grafo, perfil_t * perfis, uint16_t id);

void perfilLogado(perfil_t * perfis, perfil_t * logProfile);

void logIn(perfil_t * perfis, perfil_t * logProfile, uint16_t id);

void logOut(perfil_t * perfis, perfil_t * logProfile);

