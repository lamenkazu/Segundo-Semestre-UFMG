#include "tipos.h"
#include "lista.h"
#include "postagens.h"
#include "utils.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void exibeMenuPerfilAtivo(perfil_t * logProfile, perfil_t * perfis, grafo_t ** grafoPerfis, lista_t * postagens){

    system("CLS");
    
    uint16_t op;
    char lixo;

    do{

        printf("________________________________________________________________________________\n\n");
        printf("Bem vindo ao seu Perfil, %s!\nUtilize todos os recursos da nossa poderosa Rede Social\n", logProfile->nome);
        printf("________________________________________________________________________________\n\n");

        //Mostrar todas as postagens do perfil atual, além de outras opções.
        printf("1 - Entrar no meu Perfil\n"); // OK
        printf("2 - Exibir Postagens De quem Sigo\n"); //OK
        printf("3 - Exibir todas as postagens da Rede\n"); //OK
        printf("4 - Fazer Nova Postagem\n"); //OK
        printf("5 - Sugestões de Amizade\n"); //OK
        printf("0 - Sair\n\n");
        
        printf("Option: ");
        scanf("%d%c", &op, &lixo);

        switch (op)
        {
        case 1: exibePostagensPerfil(postagens, logProfile, grafoPerfis, perfis);
            
            break;

        case 2: exibePostagensAmigos(postagens, logProfile, grafoPerfis, perfis);
            
            break;

        case 3: imprimeLista(postagens);

                system("PAUSE");
            
            break;

        case 4: criaPostagem(postagens, logProfile);
            
            break;

        //Sugestões de Amizade
        case 5: listaPerfis(perfis);
                int escolha;
                printf("Seguir algum perfil?\n 1 - Sim (informar ID do perfil)\n 2 - Não, quero voltar\n");
                scanf("%d%c", &escolha, &lixo);

                if(escolha == 1 ){
                    printf("Informe ID: ");
                    scanf("%d%c", &escolha, &lixo);
                    seguirPerfil(logProfile, grafoPerfis, perfis, escolha );
                    imprimeGrafo(grafoPerfis);
                }

            
            break;

        case 0:
            logOut(perfis, logProfile);

            break;
        
        default:
            break;
        }

    }while(op != 0);

    
}

void exibeMenuPrincipal(perfil_t * logProfile, perfil_t * perfis, grafo_t ** grafoPerfis, lista_t * postagens){

    char lixo;
    uint16_t op;
    Nome getNome; //Variavel para cadastro de novo Perfil

    do{

        printf("________________________________________________________________________________\n\n");
        printf("Bem vindo ao CaraLivro! Utilize todos os recursos da nossa poderosa Rede Social\n");
        printf("________________________________________________________________________________\n\n");
        printf("1 - Cadastrar um novo perfil\n"); //OK
        printf("2 - Listar Perfis Cadastrados\n"); //OK
        printf("3 - Bloquear o uso de um perfil\n"); //To Do
        printf("4 - Ativar um perfil (logar)\n"); //OK
        printf("5 - Exibir Grafo de Conhecimento Entre Perfis\n"); //OK
        printf("6 - Listar todas as postagens da Rede\n"); //OK
        printf("0 - Sair\n\n");
        printf("Option: ");
        scanf("%d%c", &op, &lixo);


        switch (op)
        {
        case 1:
            /* code cadastro de Perfil*/
            
            printf("Bem vindo ao cadastro de Perfil da nossa Rede!\n");
            printf("___________________________________________________________________________\n\n");
            printf("Nome do usuario: ");
            fgets(getNome, tNome ,stdin);
            tiraBarraN(getNome);

            cadastroPerfil(perfis, getNome);
            
            break;
        case 2:
            listaPerfis(perfis);

            break;

        case 3:
            /* code Bloquear Uso de Perfil*/

            break;

        //Logar em um perfil
        case 4:
            /* code Logar em um Perfil */
            system("CLS");

            listaPerfis(perfis); //Lista Perfis do Sistema
            printf("ID do perfil a Logar: ");
            scanf("%d%c", &logProfile->id, &lixo);

            logIn(perfis, logProfile, logProfile->id);

            exibeMenuPerfilAtivo(logProfile, perfis, grafoPerfis, postagens);



            break;

        case 5:
            imprimeGrafo(grafoPerfis);

            break;

        case 6:
            imprimeLista(postagens);

            break;

        

        default:
            break;
        }


    }while(op != 0);

}



int main(int argc, char ** argv){

    /*Inicia estruturas de dados da Rede Social.
        -Grafo de conhecimento entre perfis, 
        -Vetor De Ponteiro para pPerfis,
        -Lista Encadeada de postagens
    */
    grafo_t * grafoPerfis;
    perfil_t * perfis = iniciaPerfis(&grafoPerfis, enumGrafoDirecionado);
    lista_t * postagens = criaLista();

    perfil_t  logProfile;

    //Cadastro de Perfis Root do Sistema

    cadastroPerfil(perfis, "Breno"); //1

    cadastroPerfil(perfis, "Erick"); //2

    cadastroPerfil(perfis, "Tata"); //3
    
    cadastroPerfil(perfis, "Enzé"); //4

    cadastroPerfil(perfis, "Ana"); //5


    exibeMenuPrincipal(&logProfile, perfis, &grafoPerfis, postagens);

    return OK;
}