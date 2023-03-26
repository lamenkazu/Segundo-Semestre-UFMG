
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool_t;
#define TRUE (1==1)
#define FALSE !TRUE
#define OK 0
#define T_NOME 50


/**Tipo Casal utilizado nas estruturas de dados***********************/
typedef struct tipoCasal_s{
    char menorNome[T_NOME];
    char maiorNome[T_NOME];
} tipoCasal;


/********Pilha com lista encadeada********/

typedef struct itemPilhaL_s {
    tipoCasal dado;
    struct itemPilha_s * prox;
} itemPilhaL;

typedef struct pilhaL_s {
    void * topo;
    unsigned int nItens;
} PilhaL;

static void iniciaPilhaL(PilhaL * pilha){
    pilha->nItens = 0;
    pilha->topo = NULL;
}

PilhaL * criaPilhaL(){
    PilhaL * pilha = (PilhaL*) malloc(sizeof(PilhaL));

    iniciaPilhaL(pilha);

    return pilha;
}


bool_t empilhaPilhaL(PilhaL * pilha, tipoCasal dado){
    itemPilhaL * novoItem = (itemPilhaL*) malloc(sizeof(itemPilhaL));
    if(novoItem == NULL) return FALSE; else{
        //Cria o novo item
        novoItem->dado = dado;
        novoItem->prox = (itemPilhaL*) pilha->topo;

        //Define o novo topo da fila
        pilha->topo = novoItem;

        //Incrementa e retorna
        pilha->nItens++;
        return TRUE;
    }
    
}

bool_t desempilhaPilhaL(PilhaL * pilha, tipoCasal * dado){

    itemPilhaL * descarte = (itemPilhaL*) pilha->topo;

    //Se a pilha estiver vazia
    if(descarte == NULL) return FALSE;

    //Copia os dados do item antes de remover
    (void) memcpy(dado, &descarte->dado, sizeof(tipoCasal));

    //Faz o próximo item ser o novo Topo
    pilha->topo = descarte->prox;

    free(descarte);
    pilha->nItens--;
    return TRUE;


}

void imprimePilhaL(PilhaL * pilha){
    itemPilhaL * atual;
    itemPilhaL * proximo = (itemPilhaL*)pilha->topo;

    printf("Pilha com %d itens\n", pilha->nItens);
    printf("___________________________________\n");
    for(unsigned int i = 0; i < pilha->nItens; i++){
        atual = proximo;
        proximo = atual->prox;

        printf("Casal %d | Menor nome: %s\t| Maior nome: %s\n", i+1, atual->dado.menorNome, atual->dado.maiorNome);
    }
    printf("___________________________________\n");
}

/************************************************************************/

/*Árvore*/
typedef tipoCasal tipoNo;
typedef int(* comparaNomes) (tipoNo *, tipoNo *);

/*Definição da Árvore*/
typedef struct node {
    tipoNo casal;
    struct node * esq;
    struct node * dir;

} No;

No * criaArvore(){
    return NULL;
}

int comparaCasal(tipoNo * casal1, tipoNo * casal2){
    
    char aux[T_NOME];
    
    if(strlen(casal1->maiorNome) < strlen(casal1->menorNome)){
        strcpy(aux, casal1->maiorNome);
        strcpy(casal1->maiorNome, casal1->menorNome);
        strcpy(casal1->menorNome, aux);
    }

        if(strlen(casal2->maiorNome) < strlen(casal2->menorNome)){
        strcpy(aux, casal2->maiorNome);
        strcpy(casal2->maiorNome, casal2->menorNome);
        strcpy(casal2->menorNome, aux);
    }
    
    if(strlen(casal1->menorNome) < strlen(casal2->menorNome)) return -1;

    if(strlen(casal1->menorNome) > strlen(casal2->menorNome)) return 1;

    if(strlen(casal1->menorNome) == strlen(casal2->menorNome)){
        if(strlen(casal1->maiorNome) < strlen(casal2->maiorNome)) return -1;

        if(strlen(casal1->maiorNome) > strlen(casal2->maiorNome)) return 1;

        /*******/
    }

    return strcmp(casal1->menorNome, casal2->menorNome);
    

}

void insereNaArvore(No ** raiz, tipoNo * casal, comparaNomes compara){
    if(*raiz == NULL){

        *raiz = (No*) malloc(sizeof(No));
        (*raiz)->dir = NULL;
        (*raiz)->esq = NULL;

        //(*raiz)->frase = frase;
        (*raiz)->casal = *casal;

    }else {

        if(compara(casal, &((*raiz))->casal) > 0){
            insereNaArvore(&(*raiz)->dir, casal, comparaCasal);

        } else{
            insereNaArvore(&(*raiz)->esq, casal, comparaCasal);

        }

    }
}

void exibirPreOrdem(No * raiz, int nivel){

    if(raiz != NULL){
        printf("%d %s %s\n", nivel, raiz->casal.maiorNome, raiz->casal.menorNome);
        nivel++;

        exibirPreOrdem(raiz->esq, nivel);
        
        exibirPreOrdem(raiz->dir, nivel);
    }

}


/************************************************************************/

/*****TAREFAS DA PROVA*******/
void tarefa1(){
    /*Tarefa 1************/

    PilhaL * pilha = criaPilhaL();

    //Listar os registros da pilha
    imprimePilhaL(pilha);


    //Inserir 20 casais em ordem aleatoria
    tipoCasal casal;
    strcpy(casal.maiorNome, "Erick");
    strcpy(casal.menorNome, "Tais");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Emerenciana");
    strcpy(casal.menorNome, "Marcelo");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Raimunda");
    strcpy(casal.menorNome, "Antônio");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Urnu");
    strcpy(casal.menorNome, "Zoan");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Ordalea");
    strcpy(casal.menorNome, "Feora");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Hyacu");
    strcpy(casal.menorNome, "Gounu");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Loceyurr");
    strcpy(casal.menorNome, "Zyune");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Moybu");
    strcpy(casal.menorNome, "Vihor");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Fesen");
    strcpy(casal.menorNome, "Ishin");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Xyuhuyxu");
    strcpy(casal.menorNome, "Mois");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Iskenor");
    strcpy(casal.menorNome, "Benui");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Xozefu");
    strcpy(casal.menorNome, "Seplo");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Lowuyzo");
    strcpy(casal.menorNome, "Fuipu");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Fliseibu");
    strcpy(casal.menorNome, "Hocir");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Kaypu");
    strcpy(casal.menorNome, "Onisgi");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Seboi");
    strcpy(casal.menorNome, "Behor");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Ropaes");
    strcpy(casal.menorNome, "Vouxu");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Plios");
    strcpy(casal.menorNome, "Rieza");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Zadus");
    strcpy(casal.menorNome, "Mogol");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Veundin");
    strcpy(casal.menorNome, "Boaol");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    //Listar os registros
    imprimePilhaL(pilha);

    //Remover registro por registro até a pilha ficar vazia, imprimindo o conteudo da pilha a cada remoção

    for(int i = 0; i < 20; i++){
        desempilhaPilhaL(pilha, &casal);
        imprimePilhaL(pilha);
    }
}

void tarefa2(){

    No * arvore = criaArvore();

    tipoCasal casal;
    strcpy(casal.maiorNome, "Erick");
    strcpy(casal.menorNome, "Tais");
    insereNaArvore(&arvore, &casal, comparaCasal);

    strcpy(casal.maiorNome, "Emerenciana");
    strcpy(casal.menorNome, "Marcelo");
    insereNaArvore(&arvore, &casal, comparaCasal);

    strcpy(casal.maiorNome, "Raimunda");
    strcpy(casal.menorNome, "Antônio");
    insereNaArvore(&arvore, &casal, comparaCasal);

    strcpy(casal.maiorNome, "Urnu");
    strcpy(casal.menorNome, "Zoan");
    insereNaArvore(&arvore, &casal, comparaCasal);

    strcpy(casal.maiorNome, "Ordalea");
    strcpy(casal.menorNome, "Feora");
    insereNaArvore(&arvore, &casal, comparaCasal);

    strcpy(casal.maiorNome, "Hyacu");
    strcpy(casal.menorNome, "Gounu");
    insereNaArvore(&arvore, &casal, comparaCasal);

    strcpy(casal.maiorNome, "Loceyurr");
    strcpy(casal.menorNome, "Zyune");
    insereNaArvore(&arvore, &casal, comparaCasal);
    strcpy(casal.maiorNome, "Moybu");
    strcpy(casal.menorNome, "Vihor");
    insereNaArvore(&arvore, &casal, comparaCasal);

    strcpy(casal.maiorNome, "Fesen");
    strcpy(casal.menorNome, "Ishin");
    insereNaArvore(&arvore, &casal, comparaCasal);

    strcpy(casal.maiorNome, "Xyuhuyxu");
    strcpy(casal.menorNome, "Mois");
    insereNaArvore(&arvore, &casal, comparaCasal);

    strcpy(casal.maiorNome, "Iskenor");
    strcpy(casal.menorNome, "Benui");
    insereNaArvore(&arvore, &casal, comparaCasal);

    strcpy(casal.maiorNome, "Xozefu");
    strcpy(casal.menorNome, "Seplo");
    insereNaArvore(&arvore, &casal, comparaCasal);

    strcpy(casal.maiorNome, "Lowuyzo");
    strcpy(casal.menorNome, "Fuipu");
    insereNaArvore(&arvore, &casal, comparaCasal);

    strcpy(casal.maiorNome, "Fliseibu");
    strcpy(casal.menorNome, "Hocir");
    insereNaArvore(&arvore, &casal, comparaCasal);

    strcpy(casal.maiorNome, "Kaypu");
    strcpy(casal.menorNome, "Onisgi");
    insereNaArvore(&arvore, &casal, comparaCasal);

    strcpy(casal.maiorNome, "Seboi");
    strcpy(casal.menorNome, "Behor");
    insereNaArvore(&arvore, &casal, comparaCasal);

    strcpy(casal.maiorNome, "Ropaes");
    strcpy(casal.menorNome, "Vouxu");
    insereNaArvore(&arvore, &casal, comparaCasal);

    strcpy(casal.maiorNome, "Plios");
    strcpy(casal.menorNome, "Rieza");
    insereNaArvore(&arvore, &casal, comparaCasal);

    strcpy(casal.maiorNome, "Zadus");
    strcpy(casal.menorNome, "Mogol");
    insereNaArvore(&arvore, &casal, comparaCasal);

    strcpy(casal.maiorNome, "Veundin");
    strcpy(casal.menorNome, "Boaol");
    insereNaArvore(&arvore, &casal, comparaCasal);

    exibirPreOrdem(arvore, 0);
    
}

void tarefa3(){

    PilhaL * pilha = criaPilhaL();
    No * arvore = criaArvore();

    //Listar os registros da pilha
    imprimePilhaL(pilha);


    //Inserir 20 casais em ordem aleatoria
    tipoCasal casal;
    strcpy(casal.maiorNome, "Erick");
    strcpy(casal.menorNome, "Tais");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Emerenciana");
    strcpy(casal.menorNome, "Marcelo");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Raimunda");
    strcpy(casal.menorNome, "Antônio");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Urnu");
    strcpy(casal.menorNome, "Zoan");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Ordalea");
    strcpy(casal.menorNome, "Feora");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Hyacu");
    strcpy(casal.menorNome, "Gounu");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Loceyurr");
    strcpy(casal.menorNome, "Zyune");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Moybu");
    strcpy(casal.menorNome, "Vihor");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Fesen");
    strcpy(casal.menorNome, "Ishin");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Xyuhuyxu");
    strcpy(casal.menorNome, "Mois");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Iskenor");
    strcpy(casal.menorNome, "Benui");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Xozefu");
    strcpy(casal.menorNome, "Seplo");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Lowuyzo");
    strcpy(casal.menorNome, "Fuipu");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Fliseibu");
    strcpy(casal.menorNome, "Hocir");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Kaypu");
    strcpy(casal.menorNome, "Onisgi");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Seboi");
    strcpy(casal.menorNome, "Behor");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Ropaes");
    strcpy(casal.menorNome, "Vouxu");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Plios");
    strcpy(casal.menorNome, "Rieza");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Zadus");
    strcpy(casal.menorNome, "Mogol");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    strcpy(casal.maiorNome, "Veundin");
    strcpy(casal.menorNome, "Boaol");
    if(empilhaPilhaL(pilha, casal)){
        printf("ok\n");
    }

    //Listar os registros
    imprimePilhaL(pilha);

    //Remover registro por registro até a pilha ficar vazia, imprimindo o conteudo da pilha a cada remoção

    for(int i = 0; i < 20; i++){
        desempilhaPilhaL(pilha, &casal);
        insereNaArvore(&arvore, &casal, comparaCasal);
        imprimePilhaL(pilha);
    }

    exibirPreOrdem(arvore, 0);

}

int main(int argc, char ** argv){

    char lixo;
    int op;

    do{
        printf("\n\n");
        printf("1 - Tarefa 1\n2 - Tarefa 2\n3 - Tarefa 3\n0 - sair\nOp: ");
        scanf("%d%c", &op, &lixo);

        switch (op)
        {
        case 1:
            tarefa1();
            break;
        case 2:
            tarefa2();
            break;
        case 3:
            tarefa3();
            break;
        
        default:
            break;
        }

    }while(op != 0);


    


}