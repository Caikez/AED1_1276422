/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Caike Morelli Ciola Fonseca
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 31/08/2026
Objetivo    : Uma pilha de cartas com 1 no topo que vai até n (na parte de baixo do baralho), seguindo a sequência joga a de cima fora e a proxima qu está no topo coloca em baixo. O aloritimo deve dizer quais foram descartadas e qual sobrou. Usando pilha encadeada.
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>


typedef struct celula{
    int numero;
    struct celula *seg;
} Cel;


int main(){
    int n, valor;

    while(scanf("%d", &n) && n != 0){
        int carta = 1;

        cel *p = malloc(n*sizeof(cel));

        for(int i = 0; i < n; i++){
            if (i < n-1) p[i].seg = &p[i+1];
            else p[i].seg = NULL;
        }


    }




    return 0;
}