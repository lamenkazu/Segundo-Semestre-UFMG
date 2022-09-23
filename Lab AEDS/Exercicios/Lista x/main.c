#include "listax.h"

int main(int argc, char ** argv){

    int op1, op2;
    char lixo;

    printf("Questões Feitas em sala - Erick Etiene\nSelecione um grupo de questoes (1-4):\nOption: ");
    scanf("%d%c", &op1, &lixo);

    switch (op1)
    {
    case 1:
        printf("GRUPO 1\n 2 questoes feitas: \n1)1.1\n9)1.9\n");
        printf("Option: ");
        scanf("%d%c", &op2, &lixo);

            switch (op2)
            {
            case 1:
                questao1_1();
                break;
            case 9: 
                questao1_9();
                break;
            
            default:
                break;
            }

        break;

    case 2:
        printf("GRUPO 2\n 1 questão feita: \n1)2.1\n");
        printf("Option: ");
        scanf("%d%c", &op2, &lixo);
            switch (op2)
            {
            case 1:
                questao2_1();
                break;
            
            default:
                break;
            }
        break;
    case 3:
        printf("GRUPO 3\n 1 questão feita: \n1)3.2\n3.5\n");
        printf("Option: ");
        scanf("%d%c", &op2, &lixo);
            switch (op2)
            {
            case 1:
                questao3_2();
                break;
            case 2:
                questao3_5();
                break;
            
            default:
                break;
            }
        break;
    case 4:
        printf("GRUPO 4\n 1 questão feita: \n1)4.1\n");
        printf("Option: ");
        scanf("%d%c", &op2, &lixo);
            switch (op2)
            {
            case 1:
                questao4_1();
                break;
            case 2:

                break;
            
            default:
                break;
            }
        break;
    

    return OK;
    }

}