#define OK 0
#define LISTA_VAZIA 1

/* Tipos */
typedef int dadosItem;

//Estrutura do item da lista
typedef struct itemLista{
    dadosItem info;
    struct itemLista * prox;
} itemListaE_t;

//Estrutura da Lista em si
typedef struct lista{
    unsigned int nItens;
    itemListaE_t * primeiro;
} lista_t;

//Estrutura com informações da Lista
lista_t * criaLista();

void insereNaLista(lista_t * lista, dadosItem info);

void insereOrdenado(lista_t * lista, dadosItem info);

void imprimeLista(lista_t *lista);

int listaVazia(lista_t * lista);

itemListaE_t * buscaNaLista(lista_t * lista, dadosItem val);

void rmvItemLista(lista_t *lista, dadosItem val);

void liberaLista(lista_t * lista);