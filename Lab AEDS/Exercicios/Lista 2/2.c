/*
    Veja o trecho de programa dado abaixo. Rode-o e veja o que ocorre e responda as questões
*/

#include <stdio.h>

#define TAMANHO 5

int questao2(){

    int i;
    int *z;
    z = (int*) malloc(TAMANHO * sizeof(int));

    for(i=0; i<TAMANHO; i++){
        z[i] = i*i;
    }
    for(i=0; i<TAMANHO; i++){
        printf("z[%d]=%d ou *(z+%d) = %d\n", i, z[i], i, *(z+i));
    }



    return 0;
}

/*
    Sobre o programa, responda:
a) A compila ̧c ̃ao foi feita com sucesso?
    Sim, compilou com sucesso.

b) A execu ̧c ̃ao foi feita com sucesso? Se n ̃ao, por quˆe?
    Não, porque deu falha de segmentação.

c) Onde est ́a o erro, se o programa foi compilado com sucesso?
    O ponteiro *z não foi alocado então não pode ser utilizado

d) Discuta o motivo do erro na execu ̧c ̃ao.
    O compilador precisa saber no tempo de execução o tamanho necessario a ser alocado, por isso é
    necessario dizer qual é esse espaço.

e) Como resolver o erro de execu ̧c ̃ao?
    Alocando dinamicamente o tamanho desejado.

Ainda sobre o programa, entenda a rela ̧c ̃ao entre ponteiro e vetor. Repare que no
exerc ́ıcio anterior definimos um vetor e usamos como ponteiro. Nesse exemplo tentamos
fazer o contr ́ario: definir um ponteiro e us ́a-lo como vetor. Responda ainda:
f) E poss ́ıvel definir um ponteiro e us ́a-lo como vetor? sim/n ̃ao? por  ́ quˆe?
    Sim, é possível, pois é possivel saber o tamanho de bytes utilizado e é possível andar de 1 em 1 da mesma forma.

g) Resolva o problema do programa e execute-o com sucesso? Como fazer para
resolver o problema? ( ́e poss ́ıvel resolvˆe-lo acrescentando apenas uma linha
    Linha 14 adicionada.

*/