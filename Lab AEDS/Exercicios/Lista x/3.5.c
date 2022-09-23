#include <stdio.h>

void questao3_5(){

    int alt, indice, soma;
    char lixo;

    printf("TRIANGULO E SOMA\n");

    do{
        printf("(0 para sair) Informe a altura do triangulo (1 < N <= 9): ");
        scanf("%d%c", &alt, &lixo);
        indice = 1;

        if(alt > 1 && alt <=9){
            for(int i = 0; i < alt; i++){
                soma = 0;

                for(int j = 1; j <= indice; j++){
                    printf("%d ", j);
                    soma += j;
                }

                indice++;
                printf("\t\t%d\n", soma);

            }
        }else{
            printf("Valor fora da faixa indicada, tente novamente.\n");
        }

    }while(alt != 0);

    


}
