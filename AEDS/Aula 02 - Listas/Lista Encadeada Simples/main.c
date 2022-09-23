#include "listaEncadeada.h"

int main(int argc, char ** argv){

    listaE * lista;
    lista = criaLista();

    if(listaVazia(lista) != OK){
        printf("A lista esta vazia\n");
    }else{
        printf("a lista nao esta vazia\n");
    }

    insereNaLista(&lista, 42);
    insereNaLista(&lista, 13);
    insereNaLista(&lista, 66);
    insereNaLista(&lista, 34);

    imprimeLista(lista);

    if(listaVazia(lista) != OK){
        printf("\nA lista esta vazia\n");
    }else{
        printf("\na lista nao esta vazia\n");
    }

    listaE * busca;
    busca = buscaNaLista(lista, 34);
    printf("encontrado: %d", busca->info);

    lista = rmvItemLista(lista, 34);
    busca = buscaNaLista(lista, 34);
    if(busca == NULL){
        printf("\nitem nao encontrado.");
    }else{
        printf("encontrado: %d", busca->info);
    }
    

    liberaLista(lista);

    return OK;
}