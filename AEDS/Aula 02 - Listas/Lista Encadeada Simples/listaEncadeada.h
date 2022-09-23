#include "listaEncadeada.c"

//Estrutura com informações da Lista
listaE * criaLista();

void insereNaLista(listaE **lista, dadosItem info);

void imprimeLista(listaE *lista);

int listaVazia(listaE * lista);

listaE * buscaNaLista(listaE * lista, dadosItem val);

listaE * rmvItemLista(listaE *lista, dadosItem val);

void liberaLista(listaE * lista);