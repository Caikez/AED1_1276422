/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Caike Morelli Ciola Fonseca
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1610
Data        : 18/11/2026
Objetivo    : 
Dificuldade : 
Uso de IA   : Correção do for que estava errado
-------------------------------------------------------------------------- */

#include <stdio.h>

#define MAXN 10005
#define MAXM 30005

int head[MAXN];
int to[MAXM];
int nxt[MAXM];
int edge_cnt;

int in_degree[MAXN];
int queue[MAXN];

// Adiciona uma aresta direcionada u -> v na lista de adjacência estática
void add_edge(int u, int v) {
    to[edge_cnt] = v;
    nxt[edge_cnt] = head[u];
    head[u] = edge_cnt++;
    in_degree[v]++;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        int N, M;
        if (scanf("%d %d", &N, &M) != 2) break;

        // Inicializa as estruturas para o caso de teste atual
        for (int i = 1; i <= N; i++) {
            head[i] = -1;
            in_degree[i] = 0;
        }
        edge_cnt = 0;

        // Lê as dependências (A depende de B)
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            add_edge(A, B);
        }

        // Insere na fila todos os vértices com grau de entrada 0
        int front = 0, back = 0;
        for (int i = 1; i <= N; i++) {
            if (in_degree[i] == 0) {
                queue[back++] = i;
            }
        }

        // Processa a fila removendo dependências satisfeitas
        int visited = 0;
        while (front < back) {
            int u = queue[front++];
            visited++;

            for (int e = head[u]; e != -1; e = nxt[e]) {
                int v = to[e];
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    queue[back++] = v;
                }
            }
        }

        // Se nem todos os nós puderam ser processados, há pelo menos um ciclo
        if (visited < N) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}