/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Caike Morelli Ciola Fonseca
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1094
Data        : 27/10/2026
Objetivo    : 
Dificuldade : 
Uso de IA   : Correção
-------------------------------------------------------------------------- */

#include <stdio.h>

int main() {
    int N;
    int total = 0;
    int coelhos = 0;
    int ratos = 0;
    int sapos = 0;

    // Lê a quantidade de experimentos
    if (scanf("%d", &N) != 1) return 0;

    for (int i = 0; i < N; i++) {
        int quantia;
        char tipo;

        // Lê a quantidade e o tipo de cobaia do experimento
        scanf("%d %c", &quantia, &tipo);

        total += quantia;

        if (tipo == 'C') {
            coelhos += quantia;
        } else if (tipo == 'R') {
            ratos += quantia;
        } else if (tipo == 'S') {
            sapos += quantia;
        }
    }

    // Calculando os percentuais em relação ao total
    double p_coelhos = ((double)coelhos / total) * 100.0;
    double p_ratos = ((double)ratos / total) * 100.0;
    double p_sapos = ((double)sapos / total) * 100.0;

    // Impressão dos resultados no formato especificado
    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", coelhos);
    printf("Total de ratos: %d\n", ratos);
    printf("Total de sapos: %d\n", sapos);
    printf("Percentual de coelhos: %.2f %%\n", p_coelhos);
    printf("Percentual de ratos: %.2f %%\n", p_ratos);
    printf("Percentual de sapos: %.2f %%\n", p_sapos);

    return 0;
}