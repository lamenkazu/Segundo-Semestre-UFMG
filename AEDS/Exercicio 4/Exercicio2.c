/*
    - Implemente uma Pilha de Nomes.
    - Adicione os seguintes nomes, nesta ordem:
    Bruna, Joao, Erick, Jeanne, Gabriel, Vitor, Eduardo, Paulo, Arthur, Wallace F, Ian, Jessica, Mariana, Pedro, Gabriella, Jeferson, Maíra, Raphael, Wallace S.
    - Imprima o contéudo da Pilha.
    - Remova todos os elementos até que a pilha fique vazia, imprimindo o conteúdo da mesma a cada remoção.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef bool_t;
#define TRUE 1==1
#define FALSE !TRUE
#define CAPAC 20

typedef char Nome[20];
typedef unsigned int intPos;

typedef struct pilhaDeNomes{
    Nome * nomes;
    intPos nItens;
    intPos capac;

} Pilha;

Pilha * criaPilha( intPos capac){

    Pilha * pilha = (Pilha*) malloc(sizeof(Pilha));
    if(pilha == NULL) return NULL;

    pilha->nomes = (char*) malloc(sizeof(char) * capac);
    if(pilha->nomes == NULL){
        free(pilha);
        return NULL;
    } 

    pilha->capac = capac;
    pilha->nItens = 0;
    return pilha;    

}

bool_t pushPilha(Pilha * pilha, Nome nome){
    if(pilha->nItens == pilha->capac) return FALSE;

    strcpy(pilha->nomes[pilha->nItens++], nome);

    return TRUE;

}

bool_t pilhaVazia(Pilha * pilha){
    return (pilha->nItens == 0);
}

bool_t popPilha(Pilha * pilha, Nome * nome){
    if(pilhaVazia(pilha)) return FALSE;

    strcpy(*nome, pilha->nomes[pilha->nItens - 1]);
    pilha->nItens--;

    return TRUE;

}

void imprimePilha(Pilha * pilha){
    printf("IMPRESSAO DA PILHA\nNo de nomes: %d | Capacidade: %d\n-------------\n", pilha->nItens, pilha->capac);

    for(int i = 0; i < pilha->nItens; i++){
        printf("Nome %d: %s\n", i+1, pilha->nomes[pilha->nItens - i -1]);
    }

    printf("\n\n");
}

void liberaPilha(Pilha * pilha){
    free(pilha->nomes);
    free(pilha);
}

int main(int argc, char ** argv){

    Nome temp; //Nome temporario utilizado para remoção

    Pilha * pilha = criaPilha(CAPAC);
    if(pilha == NULL){
        fprintf(stderr, "Erro ao criar a pilha");
    }

        pushPilha(pilha, "Bruna");
        pushPilha(pilha, "Joao");
        pushPilha(pilha, "Erick");
        pushPilha(pilha, "Jeanne");
        pushPilha(pilha, "Gabriel");
        pushPilha(pilha, "Vitor");
        pushPilha(pilha, "Eduardo");
        pushPilha(pilha, "Paulo");
        pushPilha(pilha, "Arthur");
        pushPilha(pilha, "Wallace F.");
        pushPilha(pilha, "Ian");
        pushPilha(pilha, "Jessica");
        pushPilha(pilha, "Mariana");
        pushPilha(pilha, "Pedro");
        pushPilha(pilha, "Gabriella");
        pushPilha(pilha, "Jeferson");
        pushPilha(pilha, "Maíra");
        pushPilha(pilha, "Raphael");
        pushPilha(pilha, "Wallace S.");


    imprimePilha(pilha);

    popPilha(pilha, &temp);
    imprimePilha(pilha);

    popPilha(pilha, &temp);
    imprimePilha(pilha);
    
    popPilha(pilha, &temp);
    imprimePilha(pilha);

    popPilha(pilha, &temp);
    imprimePilha(pilha);

    popPilha(pilha, &temp);
    imprimePilha(pilha);

    popPilha(pilha, &temp);
    imprimePilha(pilha);

    popPilha(pilha, &temp);
    imprimePilha(pilha);

    popPilha(pilha, &temp);
    imprimePilha(pilha);

    popPilha(pilha, &temp);
    imprimePilha(pilha);

    popPilha(pilha, &temp);
    imprimePilha(pilha);

    popPilha(pilha, &temp);
    imprimePilha(pilha);

    popPilha(pilha, &temp);
    imprimePilha(pilha);

    popPilha(pilha, &temp);
    imprimePilha(pilha);

    popPilha(pilha, &temp);
    imprimePilha(pilha);

    popPilha(pilha, &temp);
    imprimePilha(pilha);

    popPilha(pilha, &temp);
    imprimePilha(pilha);

    popPilha(pilha, &temp);
    imprimePilha(pilha);

    popPilha(pilha, &temp);
    imprimePilha(pilha);

    popPilha(pilha, &temp);
    imprimePilha(pilha);

    popPilha(pilha, &temp);
    imprimePilha(pilha);



}
