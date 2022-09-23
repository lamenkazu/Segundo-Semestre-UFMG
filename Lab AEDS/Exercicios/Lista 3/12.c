#include <stdio.h>
#define OK 0


int questao12(){

    aluno_s aluno;
    int op;

    FILE * arq;
    arq = fopen("dadosAluno.bin", "rb");
    if(arq != NULL){
        fread(&aluno, sizeof(aluno_s), 1, arq);
        fclose(arq);
    }

    do{
        printf("Escolha dados a ler:\n1- Dados pessoais\n2- Dados escolares\nOption: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            
                printf("\nDADOS PESSOAIS DO ALUNO: \n");
                printf("Nome: %sCPF: %sData de Nascimento: %sNome do Pai: %sNome da Mae: %s\n", aluno.pessoal.nome, aluno.pessoal.cpf, aluno.pessoal.dataNasc, aluno.pessoal.nomePai, aluno.pessoal.nomeMae);
    
            break;
        case 2:
                printf("\nDADOS ESCOLARES DO ALUNO:\n");
                printf("Numero de Matricula: %d\nSerie Matriculado: %d\nEscola anterior: %s\n", aluno.escolar.matricula, aluno.escolar.serie, aluno.escolar.escolaAnt);

            break; 
        }

    }while (op != 0);
    
    return OK;
}