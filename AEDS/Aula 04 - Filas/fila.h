//uma estruura de fila pode ser composta pelas seguintes operações
/*
    Criar fila vazia
    inserir elemento no fim
    retirar elemento do inicio
    verificar se a fila ta vazia
    liberar a fila
*/
typedef bool_t;
#define TRUE 1==1
#define FALSE !TRUE
#define TAM 50
typedef float tipoFila;

typedef struct {
    int nElementos;
    int ini;
    float vet[TAM];
    
} Fila;
Fila * fila_cria();
bool_t fila_insere(Fila * fila, tipoFila val);
bool_t fila_retira(Fila * fila);
bool_t fila_vazia(Fila * fila);
void fila_libera(Fila * fila);