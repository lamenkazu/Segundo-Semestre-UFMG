#define TAM 50
#define TRUE (1==1)
#define FALSE !TRUE
#define ERRO_CRIACAO_PILHA 1
typedef bool_t; 

typedef float itemPilha;

typedef struct pilha{
    unsigned int nElementos;
    itemPilha * dados;
    unsigned int capacidade;
} Pilha;



Pilha * pilha_cria(unsigned int capacidade);
bool_t pilha_push(Pilha *pilha, itemPilha val);
bool_t pilha_pop(Pilha * pilha, itemPilha * dado);
bool_t pilha_vazia(Pilha *pilha);
void pilha_libera(Pilha *pilha);