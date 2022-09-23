#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#define OK 0
#define PALAVRA 30
#define DICA 140

void tiraBarraN(char str[]){
    for(unsigned int i = 0; i < strlen(str); i++){
        if(str[i] == '\n') str[i] = '\0';
    }
}

void iniciaPalavraJogo(char str[], char palavra[]){
    for(unsigned int i = 0; i < strlen(palavra); i++){
        if(palavra[i] == ' '){
            str[i] = ' ';
        }else{
            str[i] = '_';
        }
    }
    str[strlen(palavra)] = '\0';
}

void defineJogo(int * tentativas, char str[], char dica[]){
    char lixo;

    //Define quantas tentativas terão para acertar a palavra
    printf("\nDefina a Dificuldade!\nNumero de tentativas: ");
    scanf("%d%c", tentativas, &lixo);

    //Define a palavra a ser acertada
    printf("Informe a palavra do jogo: ");
    fgets(str, PALAVRA, stdin);
    tiraBarraN(str);

    //Define dica
    printf("Dica da palavra: ");
    fgets(dica, DICA, stdin);
    tiraBarraN(dica);

    system("CLS");
}

void imprimeEstado(int tentativas, char palavra[], char acertos[], char dica[]){
    
    system("CLS");
    printf("Numero de tentativas: %d\n", tentativas);
    printf("Dica: ");
    fputs(dica, stdout);
    printf("\nPalavra: ");
    for(unsigned int i = 0; i < strlen(palavra); i++){
        printf("%c ", acertos[i]);              
    }
}

void exibeOpt(int * op){
    char lixo;
    printf("\n1- Chutar uma letra\n2- Chutar a palavra\nOp: ");
    scanf("%d%c", op, &lixo);
}

void chutaCaractere(char palavra[], char acertos[], int * tentativas, int * aux){
    char carac;
    printf("Letra: ");
    carac = fgetc(stdin);

    for(unsigned int i = 0; i < strlen(palavra); i++){
        if(palavra[i] == carac){
            acertos[i] = carac;
            *(aux) = 1;
        }
    }

    if(*(aux) != 1){
        *(tentativas) -= 1;
        if(*(tentativas) == 0){
            exibeDerrota(tentativas);
        }
    }
}

void chutaPalavra(char palavra[], int * tentativas){
    char chute[PALAVRA];

    printf("Palavra: ");
    fgets(chute, PALAVRA, stdin);
    tiraBarraN(chute);

    if(strcmp(palavra, chute) == 0){
        exibeVitoria(palavra, tentativas);

    }else{
        exibeDerrota(tentativas);
    }
}

void exibeVitoria(char palavra[], int * tentativas){
    system("CLS");
    printf("Boa vagabundo!!\nAcertou que era %s, agora vai fazer algo melhor da sua vida, vai", palavra);
    for(int i = 0; i < 3; i++){
        printf(".");
        Sleep(750);
    }
    printf("\n");
    *tentativas = 0;
}

void exibeDerrota(int * tentativas){
    printf("Mais uma derrota pra conta");
    for(int i = 0; i < 3; i++){
        printf(". ");
        Sleep(750);
    }
    *tentativas = 0;
}

int questao15(){
    char acertos[PALAVRA], palavra[PALAVRA], dica[DICA];
    int op, aux, tentativas;

    defineJogo(&tentativas, palavra, dica);
    iniciaPalavraJogo(acertos, palavra);

    do{
        aux = 0;
        if(tentativas == 0){
            exibeDerrota(tentativas);

        }else{
            if(strcmp(palavra, acertos) == 0){
                exibeVitoria(palavra, &tentativas);

            }else{
                imprimeEstado(tentativas, palavra, acertos, dica);
                exibeOpt(&op);

                switch (op){
                case 1: 
                        chutaCaractere(palavra, acertos, &tentativas, &aux);
                    break;

                case 2:
                        chutaPalavra(palavra, &tentativas);
                    break;
                
                default:
                    break;
                }
            }
            

        }
            

    }while(tentativas != 0);

    return OK;
}

int main(){
    questao15();
}