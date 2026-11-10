/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Caike Morelli Ciola Fonseca
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1200
Data        : 10/11/2026
Objetivo    : 
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da Árvore Binária de Busca
typedef struct Node {
    char dado;
    struct Node *esquerda;
    struct Node *direita;
} Node;

// Variável auxiliar para controlar a formatação dos espaços nos percursos
int primeiro_elemento = 1;

// Função para criar um novo nó
Node* criarNo(char valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->dado = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

// Função para inserir um elemento na ABP
Node* inserir(Node* raiz, char valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->dado) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->dado) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

// Função para pesquisar um elemento na ABP
int pesquisar(Node* raiz, char valor) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->dado == valor) {
        return 1;
    }
    if (valor < raiz->dado) {
        return pesquisar(raiz->esquerda, valor);
    }
    return pesquisar(raiz->direita, valor);
}

// Percurso Infixo (Em-ordem): Esquerda -> Raiz -> Direita
void infixa(Node* raiz) {
    if (raiz != NULL) {
        infixa(raiz->esquerda);
        if (!primeiro_elemento) {
            printf(" ");
        }
        printf("%c", raiz->dado);
        primeiro_elemento = 0;
        infixa(raiz->direita);
    }
}

// Percurso Prefixo (Pré-ordem): Raiz -> Esquerda -> Direita
void prefixa(Node* raiz) {
    if (raiz != NULL) {
        if (!primeiro_elemento) {
            printf(" ");
        }
        printf("%c", raiz->dado);
        primeiro_elemento = 0;
        prefixa(raiz->esquerda);
        prefixa(raiz->direita);
    }
}

// Percurso Pósfixo (Pós-ordem): Esquerda -> Direita -> Raiz
void posfixa(Node* raiz) {
    if (raiz != NULL) {
        posfixa(raiz->esquerda);
        posfixa(raiz->direita);
        if (!primeiro_elemento) {
            printf(" ");
        }
        printf("%c", raiz->dado);
        primeiro_elemento = 0;
    }
}

// Função para liberar a memória alocada dinamicamente
void liberarArvore(Node* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    Node* raiz = NULL;
    char comando[20];
    char elemento;

    // Processa comandos até o Fim do Arquivo (EOF)
    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &elemento);
            raiz = inserir(raiz, elemento);
        } 
        else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &elemento);
            if (pesquisar(raiz, elemento)) {
                printf("%c existe\n", elemento);
            } else {
                printf("%c nao existe\n", elemento);
            }
        } 
        else if (strcmp(comando, "INFIXA") == 0) {
            primeiro_elemento = 1;
            infixa(raiz);
            printf("\n");
        } 
        else if (strcmp(comando, "PREFIXA") == 0) {
            primeiro_elemento = 1;
            prefixa(raiz);
            printf("\n");
        } 
        else if (strcmp(comando, "POSFIXA") == 0) {
            primeiro_elemento = 1;
            posfixa(raiz);
            printf("\n");
        }
    }

    liberarArvore(raiz);
    return 0;
}