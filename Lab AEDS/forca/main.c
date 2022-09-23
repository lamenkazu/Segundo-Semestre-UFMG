#include <stdio.h>
#include <string.h>
#define OK 0
#define PALAVRA 30

int main(int argc, char ** argv){
    char lixo, carac, chute[PALAVRA], acertos[PALAVRA], palavra[PALAVRA];;
    int op, aux, tentativas;

    printf("Defina a Dificuldade!\nNumero de tentativas: ");
    scanf("%d%c", &tentativas, &lixo);
    printf("Informe a palavra do jogo: ");
    fgets(palavra, PALAVRA, stdin);
    for(int i = 0; i < strlen(palavra); i++){
        if(palavra[i] == '\n') {
            palavra[i] = '\0';
        }
    }

    for(int i = 0; i < strlen(palavra); i++){
        acertos[i] = '_';
    }

    system("CLS");

    do{
        aux = 0;
        if(tentativas == 0){
            printf("Esgotaram as tentativas, você perdeu!");

        }else{
            if(strcmp(palavra, acertos) == 0){
                system("CLS");
                printf("Fim de jogo! Acertou a palavra: %s", palavra);
                tentativas = 0;

            }else{
                printf("Numero de tentativas: %d\n", tentativas);
                printf("Palavra: ");
                for(int i = 0; i < strlen(palavra); i++){
                    printf("%c ", acertos[i]);              
                }

                printf("\n1- Chutar uma letra\n2- Chutar a palavra\nOp: ");
                scanf("%d%c", &op, &lixo);

                switch (op){
                case 1:
                        printf("Letra: ");
                        carac = fgetc(stdin);
                        for(int i = 0; i < strlen(palavra); i++){
                            if(palavra[i] == carac){
                                acertos[i] = carac;
                                aux = 1;
                            }
                        }
                        if(aux != 1){
                            tentativas--;
                        }
                    break;

                case 2:
                        printf("Palavra: ");
                        fgets(chute, PALAVRA, stdin);
                        for(int i = 0; i < strlen(chute); i++){
                            if(chute[i] == '\n') chute[i] = '\0';
                            
                        }
                        if(strcmp(palavra, chute) == 0){
                            printf("Fim de jogo! Acertou a palavra: %s", palavra);
                            tentativas = 0;

                        }else{
                            printf("Palavra incorreta, perdeu o jogo!");
                            tentativas = 0;
                        }
                    break;
                
                default:
                    break;
                }
            }
            

        }
            

    }while(tentativas != 0);

    return OK;
}