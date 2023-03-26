#include <string.h>

void tiraBarraN(char texto[]){
    for(int i = 0; i < strlen(texto); i++ ){
        if(texto[i] == '\n')
            texto[i] = '\0';
    }
}