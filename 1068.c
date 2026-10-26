/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Caike Morelli Ciola Fonseca
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 26/10/2026
Objetivo    : Fazer usando pilha
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1005

// Estrutura da Pilha
typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

// Inicializa a pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

// Verifica se a pilha está vazia
bool estaVazia(Pilha *p) {
    return p->topo == -1;
}

// Empilha um caractere
void empilhar(Pilha *p, char c) {
    if (p->topo < MAX - 1) {
        p->dados[++(p->topo)] = c;
    }
}

// Desempilha um caractere
void desempilhar(Pilha *p) {
    if (!estaVazia(p)) {
        p->topo--;
    }
}

// Função para verificar se a expressão tem parênteses balanceados
bool verificarParenteses(const char *expressao) {
    Pilha p;
    inicializar(&p);

    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            empilhar(&p, '(');
        } else if (expressao[i] == ')') {
            // Se encontrar um ')' sem um '(' correspondente na pilha, está incorreto
            if (estaVazia(&p)) {
                return false;
            }
            desempilhar(&p);
        }
    }

    // Se ao final a pilha estiver vazia, todos os '(' foram fechados corretamente
    return estaVazia(&p);
}

int main() {
    char expressao[MAX];

    // Leitura contínua até o fim do arquivo (EOF)
    while (fgets(expressao, sizeof(expressao), stdin) != NULL) {
        if (verificarParenteses(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}