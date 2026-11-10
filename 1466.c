/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Caike Morelli Ciola Fonseca
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1466
Data        : 10/11/2026
Objetivo    : 
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Node* criarNo(int val) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->val = val;
    novo->left = NULL;
    novo->right = NULL;
    return novo;
}

Node* inserir(Node* raiz, int val) {
    if (raiz == NULL) {
        return criarNo(val);
    }
    if (val < raiz->val) {
        raiz->left = inserir(raiz->left, val);
    } else if (val > raiz->val) {
        raiz->right = inserir(raiz->right, val);
    }
    return raiz;
}

void bfs(Node* raiz) {
    if (raiz == NULL) return;

    // Fila estática para os nós (N <= 500)
    Node* fila[505];
    int inicio = 0, fim = 0;

    fila[fim++] = raiz;
    int primeiro = 1;

    while (inicio < fim) {
        Node* atual = fila[inicio++];

        if (!primeiro) {
            printf(" ");
        }
        printf("%d", atual->val);
        primeiro = 0;

        if (atual->left != NULL) {
            fila[fim++] = atual->left;
        }
        if (atual->right != NULL) {
            fila[fim++] = atual->right;
        }
    }
    printf("\n");
}

void liberarArvore(Node* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->left);
        liberarArvore(raiz->right);
        free(raiz);
    }
}

int main() {
    int C, N, val;

    if (scanf("%d", &C) != EOF) {
        for (int caso = 1; caso <= C; caso++) {
            scanf("%d", &N);
            Node* raiz = NULL;

            for (int i = 0; i < N; i++) {
                scanf("%d", &val);
                raiz = inserir(raiz, val);
            }

            printf("Case %d:\n", caso);
            bfs(raiz);
            printf("\n"); // Linha em branco após cada caso de teste

            liberarArvore(raiz);
        }
    }

    return 0;
}