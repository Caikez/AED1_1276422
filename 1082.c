/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Caike Morelli Ciola Fonseca
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1082
Data        : 10/11/2026
Objetivo    : 
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 26

int adj[MAXV][MAXV];
int visited[MAXV];
int comp_nodes[MAXV];
int comp_size;

// Busca em Profundidade (DFS) para encontrar todos os vértices do mesmo componente
void dfs(int u, int V) {
    visited[u] = 1;
    comp_nodes[comp_size++] = u;
    for (int v = 0; v < V; v++) {
        if (adj[u][v] && !visited[v]) {
            dfs(v, V);
        }
    }
}

// Função de comparação para ordenação alfabética
int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    for (int caso = 1; caso <= N; caso++) {
        int V, E;
        scanf("%d %d", &V, &E);

        // Limpa a matriz de adjacência e o vetor de visitados
        memset(adj, 0, sizeof(adj));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < E; i++) {
            char u, v;
            // O espaço antes de %c consome espaços em branco e quebras de linha
            scanf(" %c %c", &u, &v);
            adj[u - 'a'][v - 'a'] = 1;
            adj[v - 'a'][u - 'a'] = 1;
        }

        printf("Case #%d:\n", caso);
        int total_componentes = 0;

        // Percorre os vértices de 'a' até 'a' + V - 1
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                comp_size = 0;
                dfs(i, V);

                // Ordena os vértices do componente em ordem alfabética
                qsort(comp_nodes, comp_size, sizeof(int), comparar);

                // Imprime os vértices do componente separados por vírgula
                for (int k = 0; k < comp_size; k++) {
                    printf("%c,", comp_nodes[k] + 'a');
                }
                printf("\n");

                total_componentes++;
            }
        }

        // Mensagem final e linha em branco ao fim de cada caso de teste
        printf("%d connected components\n\n", total_componentes);
    }

    return 0;
}

