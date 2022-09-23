#include <stdio.h>
#define OK 0
#include <stdio.h>
#define TAM_NOME 50
#define TAM_CPF 12
#define TAM_DATA 11

typedef struct dadosPessoais{
     char nome[TAM_NOME];
     char cpf[TAM_CPF];
     char dataNasc[TAM_DATA];
     char nomePai[TAM_NOME];
     char nomeMae[TAM_NOME];

} dadosP_s;

typedef struct dadosEscolares{
    int matricula;
    char escolaAnt[TAM_NOME];
    int serie;

} dadosE_s;

typedef struct aluno{
    dadosP_s pessoal;
    dadosE_s escolar;

} aluno_s;


int questao11(){

    char lixo;
    aluno_s aluno;

        printf("Nome: ");
        fgets(aluno.pessoal.nome, TAM_NOME, stdin);
        printf("CPF: ");
        fgets(aluno.pessoal.cpf, TAM_CPF, stdin);
        printf("Data de nascimento: ");
        fgets(aluno.pessoal.dataNasc, TAM_DATA, stdin);
        printf("Nome do Pai: ");
        fgets(aluno.pessoal.nomePai, TAM_NOME, stdin);
        printf("Nome da Mae: ");
        fgets(aluno.pessoal.nomeMae, TAM_NOME, stdin);

        printf("informe os dados escolares do aluno: \n");
        printf("Numero de Matricula: ");
        scanf("%d%c", &aluno.escolar.matricula, &lixo);
        printf("Escola Anterior: ");
        fgets(aluno.escolar.escolaAnt, TAM_NOME, stdin);
        printf("Serie matriculada: ");
        scanf("%d%c", &aluno.escolar.serie, &lixo);

    
    

    FILE * arqBinAluno;
    arqBinAluno = fopen("dadosAluno.bin", "wb");
    if(arqBinAluno != NULL){

        fwrite(&aluno, sizeof(aluno_s), 1, arqBinAluno);

        fclose(arqBinAluno);
    }

    return OK;
}