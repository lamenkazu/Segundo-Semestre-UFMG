#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char tipoNo;
#define T_NOME 20

typedef int(* comparaNomes) (char *, char *);

/*Definição da Árvore*/
typedef struct node {
    tipoNo frase[T_NOME];
    struct node * esq;
    struct node * dir;

} No;

No * criaArvore(){
    return NULL;
}


/*Inserção**********************************************************/
comparaNomes comparaNomesASC( char * nome1, char * nome2){
    return strcmp(nome1, nome2);
}

comparaNomes comparaNomesDESC( char * nome1, char * nome2){
    return strcmp(nome2, nome1);
}



void insereNaArvore(No ** raiz, tipoNo frase[], comparaNomes compara){
    if(*raiz == NULL){

        *raiz = (No*) malloc(sizeof(No));
        (*raiz)->dir = NULL;
        (*raiz)->esq = NULL;

        //(*raiz)->frase = frase;
        strcpy((*raiz)->frase, frase);

    }else {

        if(compara(frase, ((*raiz))->frase) > 0){
            insereNaArvore(&(*raiz)->dir, frase, comparaNomesASC);

        } else{
            insereNaArvore(&(*raiz)->esq, frase, comparaNomesASC);

        }

    }
}



/*Exibir ********************************************/

void exibirEmOrdem(No * raiz){
    if(raiz != NULL){
        exibirEmOrdem(raiz->esq);

        printf("%s ", raiz->frase);
        
        exibirEmOrdem(raiz->dir);
    }
}

void exibirPreOrdem(No * raiz){

    if(raiz != NULL){
        printf("%s ", raiz->frase);

        exibirPreOrdem(raiz->esq);
        
        exibirPreOrdem(raiz->dir);
    }

}

void exibirPosOrdem(No * raiz){

    if(raiz != NULL){

        exibirPosOrdem(raiz->esq);

        exibirPosOrdem(raiz->dir);

        printf("%s ", raiz->frase);

    }

}

/*************************************************/

/*Remoção*/

/*

No * MaiorDireita(No ** node){

}

No * MenorEsquerda (No ** node){

}

void removeDaArvore(No ** raiz, char frase[]){

    if(*raiz != NULL){
        
        if( strcmp( frase, (*raiz)->frase ) < 0){

            removeDaArvore( &(*raiz)->esq, frase)

        }else if(strcmp(frase, (*raiz)->frase) > 0){
                removeDaArvore(&(*raiz)->dir, frase);
        }else{
            No * pAux = *raiz;


            
            if( ( (*raiz)->esq == NULL && (*raiz) ) )
            
            


        }

        

    }

}

*/


/*Contagem *******************************************************/
int contaNos(No * raiz){

    if(raiz == NULL) return 0;
    else
        return 1 + contaNos(raiz->esq) + contaNos(raiz->dir);
    

}

int contaFolhas(No * raiz){

    if(raiz == NULL)
        return 0;
    
    if(raiz->esq == NULL && raiz->dir == NULL) 
        return 1;
    
    return contaFolhas(raiz->esq) + contaFolhas(raiz->dir);

}

/*****************************************************************/

/* altura ********************************************************************/
int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int alturaDaArvore(No * raiz){
    if((raiz == NULL) || (raiz->esq == NULL  && raiz->dir == NULL))
        return 0;
    else 
        return 1 + maior(alturaDaArvore(raiz->esq), alturaDaArvore(raiz->dir));
}
/*****************************************************************************/


int main(){


 No * raiz = criaArvore();

    insereNaArvore(&raiz, "Gumayusi", comparaNomesASC);
    
    insereNaArvore(&(raiz), "Tovu", comparaNomesASC);

    insereNaArvore(&(raiz), "Toycoyn");

    insereNaArvore(&(raiz), "Vuheyr");

    insereNaArvore(&(raiz), "Xiucualo");

    insereNaArvore(&(raiz), "Xaiho");

    insereNaArvore(&(raiz), "Midia");

    insereNaArvore(&(raiz), "Pioguis");

    insereNaArvore(&(raiz), "Fikunun");

    insereNaArvore(&(raiz), "Lufur");

    insereNaArvore(&(raiz), "Sepal");

    exibirEmOrdem(raiz);

    printf("\nTem %d nos", contaNos(raiz));

    printf("\nTem %d folhas", contaFolhas(raiz) );

    printf("\nTem %d de altura", alturaDaArvore(raiz));

    
    


}
