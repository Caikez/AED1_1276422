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

typedef struct No {
    int carta;
    struct No *prox;
} No;


// Retira o primeiro nó da lista
No* retirar(No **inicio, No **fim) {
    No *removido = *inicio;

    *inicio = (*inicio)->prox;

    if (*inicio == NULL)
        *fim = NULL;

    removido->prox = NULL;

    return removido;
}


// Coloca um nó no final da lista
void colocar(No **inicio, No **fim, No *novo) {

    novo->prox = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
        *fim = novo;
    } else {
        (*fim)->prox = novo;
        *fim = novo;
    }
}


int main() {
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {

        No *inicio = NULL;
        No *fim = NULL;

        // Criando as cartas
        for (int i = 1; i <= n; i++) {

            No *novo = malloc(sizeof(No));

            novo->carta = i;
            novo->prox = NULL;

            colocar(&inicio, &fim, novo);
        }

        printf("Discarded cards:");

        int primeiro = 1;

        while (inicio->prox != NULL) {

            // Retira a carta do topo
            No *removido = retirar(&inicio, &fim);

            if (!primeiro)
                printf(",");
            
            printf(" %d", removido->carta);

            primeiro = 0;

            free(removido);

            // Retira a próxima carta
            No *movido = retirar(&inicio, &fim);

            // Coloca essa carta no final
            colocar(&inicio, &fim, movido);
        }

        printf("\nRemaining card: %d\n", inicio->carta);

        free(inicio);
    }

    return 0;
}