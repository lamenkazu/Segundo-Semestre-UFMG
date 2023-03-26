#include "utils.h"
#include "lista.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool_t criaPostagem(lista_t * postagens, perfil_t * logProfile){


    Conteudo txt;
    fgets(txt, TCONTEUDO, stdin);
    tiraBarraN(txt);

    insereOrdenado(postagens, txt, logProfile);


}

bool_t curtirPostagem(){

}

void detalharPost(itemListaE_t * post, lista_t * postagens, perfil_t * logProfile, perfil_t * perfis){

    bool_t curtiu = FALSE;

    uint16_t op;
    char lixo;

        printf("Profile: %s", post->postagem.perfil.nome);
        printf("\nPost: %d ", post->postagem.id);
        printf("\n%s ", post->postagem.texto);

        //Verifica se o perfil atual Curtiu um post (substitui o Hash)
        for(itemListaE_t * i = post; i != NULL; i = i->prox){
            
                for(itemCurtidas_t * j = post->postagem.curtidas->primeiro; j!= NULL; j = j->prox){

                    if((j->curtiu == TRUE) && (j->idProfile == logProfile->id)){
                        printf("\nLIKE!(Y)");
                        curtiu = TRUE;
                    }

                }

        }

        imprimeListaCurtidas(post, perfis);

        printf("\n\n");

        if(curtiu == TRUE){
            printf("1 - Descurtir Post\n");
        }else {
            printf("1 - Curtir Post\n");
        }
    
        if(post->postagem.perfil.id == logProfile->id){
            printf("2 - Excluir Post\n");
        }
        
        printf("0 - Voltar\n");
        printf("Option: ");
        scanf("%d%c", &op, &lixo);

       

        switch (op)
        {
        //Excluir postagem;
        case 2:

                if(post->postagem.perfil.id == logProfile->id){
                    printf("ID da postagem: ");
                    scanf("%d%c", &op, &lixo);

                    rmvItemLista(postagens, op);
                }
                

            break;
        case 1:

                if(curtiu == TRUE){
                    rmvCurtida(post->postagem.curtidas, logProfile->id);
                }else{
                    insereNaLista((post->postagem.curtidas), logProfile);
                }
                
            break;
        
        default:
            break;
        }

        system("PAUSE");

}

void exibeNPostagens(lista_t * postagens, perfil_t * logProfile, uint16_t qnt){


    uint16_t cont = 0;

    for(itemListaE_t * i = postagens->primeiro; i != NULL; i = i->prox){

        if(i->postagem.perfil.id == logProfile->id){
            printf("Profile: %s", i->postagem.perfil.nome);
            printf("\nPost: %d ", i->postagem.id);
            printf("\nShort: %s ", i->postagem.resumo);
            printf("\n\n");
        }

        cont++;
        if(cont == qnt){
            return;
        }
        
    }
}

void exibePostagensPerfil(lista_t * postagens, perfil_t * logProfile, grafo_t ** grafoPerfis, perfil_t * perfis){

    uint16_t escolha;

    uint16_t op, idPost;
    char lixo;

    exibeNPostagens(postagens, logProfile, 3);

    do{

        printf("1 - Detalhar um post\n"); //OK
        printf("2 - Lista de quem sigo\n"); //OK
        printf("3 - Lista de seguidores\n"); //OK
        printf("4 - Exibir todas as postagens\n");
        printf("0 - Voltar\n");
        scanf("%d%c", &op, &lixo);

        switch (op)
        {
        case 1:
            printf("ID do Post: ");
            scanf("%d%c", &idPost, &lixo);

            for(itemListaE_t * i = postagens->primeiro; i != NULL; i = i->prox){
                if(i->postagem.id == idPost){
                    detalharPost(i, postagens, logProfile, perfis);
                }
            }
            break;

        //Lista de quem sigo
        case 2:

        

        printf("______________________________\n");
        printf("Lista de Quem sigo\n");
        printf("______________________________\n");

                for(int i = 0; i < qntPerfis; i++){

                    char atividade[10];
                    strcpy(atividade, perfis[i].ativo == TRUE ? "Ativo" : "Inativo");

                    if(GRAFO_DADOS(*grafoPerfis)[(logProfile->id)][(perfis[i].id) ] == CUSTO_SEGUIDOR){
                        printf("%d\t|%s\t|%s\n", perfis[i].id, perfis[i].nome, atividade);
                    }
                }

            printf("______________________________\n");
            printf("1 - Deixar de seguir um perfil\n0 - Voltar");
            scanf("%d%c", &escolha, &lixo);
            if( escolha == 1 ){
                
                printf("ID do perfil: ");
                scanf("%d%c", &escolha, &lixo);

                unfollowPerfil(logProfile, grafoPerfis, perfis, escolha);

            }

            break;

        //Lista de quem me segue
        case 3:

                printf("______________________________\n");
                printf("Lista de Seguidores\n");
                printf("______________________________\n");

                for(int i = 0; i < qntPerfis; i++){
                    char atividade[10];
                    strcpy(atividade, perfis[i].ativo == TRUE ? "Ativo" : "Inativo");

                    if(GRAFO_DADOS(*grafoPerfis)[(perfis[i].id)][(logProfile->id)] == CUSTO_SEGUIDOR){
                        printf("%d\t|%s\t|%s\n", perfis[i].id, perfis[i].nome, atividade);
                    }
                }
                printf("______________________________\n");

                


            break;
        case 4: exibeNPostagens(postagens, logProfile, postagens->nItens);

            break;
        
        default:
            break;
        }

    }while(op != 0);

}

void exibePostagensAmigos(lista_t * postagens, perfil_t * logProfile, grafo_t ** grafoPerfis, perfil_t * perfis){ //Precisa do GRAFO


    uint16_t op, idPost;
    char lixo;


    for(itemListaE_t * i = postagens->primeiro; i != NULL; i = i->prox){

        if(GRAFO_DADOS(*grafoPerfis)[(logProfile->id)][(i->postagem.perfil.id) ] == CUSTO_SEGUIDOR){
            printf("Profile: %s", i->postagem.perfil.nome);
            printf("\nPost: %d ", i->postagem.id);
            printf("\nShort: %s ", i->postagem.resumo);
            printf("\n\n");
        }

    }

    do{

        printf("1 - Detalhar um post\n"); //OK
        printf("0 - Voltar\n");
        printf("Option: ");
        scanf("%d%c", &op, &lixo);

        switch (op)
        {
        case 1:
            printf("ID do Post: ");
            scanf("%d%c", &idPost, &lixo);

            for(itemListaE_t * i = postagens->primeiro; i != NULL; i = i->prox){
                if(i->postagem.id == idPost){
                    detalharPost(i, postagens, logProfile, perfis);
                }
            }
            break;
        
        default:
            break;
        }

    }while(op != 0);

}