typedef int bool_t;
#define TRUE 1==1
#define FALSE !TRUE

typedef struct pilhaL_s {
    void * topo;
    unsigned int nItens;
} PilhaL;

PilhaL * criaPilhaL();
