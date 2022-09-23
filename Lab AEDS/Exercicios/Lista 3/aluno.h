
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