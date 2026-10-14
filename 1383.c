/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Caike Morelli Ciola Fonseca
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 27/08/2026
Objetivo    : Sudoku
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */

#include <stdio.h>

int verifica_matriz(int matriz[9][9]){

    // checagem de linhas
    for(int i = 0; i < 9; i++){
        int v[10] = {0};
        for(int j = 0; j < 9; j++){
            int val = matriz[i][j];
            if(val < 1 || val > 9 || v[val] == 1) return 0;
            v[val] = 1; // CORREÇÃO: marcou o numero como visto
        }
    }
    
    // checagem de colunas
    for(int i = 0; i < 9; i++){
        int v[10] = {0};
        for(int j = 0; j < 9; j++){
            int val = matriz[j][i];
            if(val < 1 || val > 9 || v[val] == 1) return 0;
            v[val] = 1; // CORREÇÃO: marcou o numero como visto
        }
    }

    // checagem das sub-matrizes 3x3
    for (int bloco = 0; bloco < 9; bloco++) {
        int visto[10] = {0};
        int linha_inicio = (bloco / 3) * 3;
        int coluna_inicio = (bloco % 3) * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int val = matriz[linha_inicio + i][coluna_inicio + j];
                if (val < 1 || val > 9 || visto[val]) return 0;
                visto[val] = 1;
            }   
        }
    }

    return 1;
}

void ler_matrizes(int n){
    int matriz[9][9];
    int resultado[n];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 9; j++){
            for(int k = 0; k < 9; k++){
                scanf("%d", &matriz[j][k]);
            }
        }
        resultado[i] = verifica_matriz(matriz);
    }

    // mostra resultados
    for(int l = 0; l < n; l++){
        printf("Instancia %d\n", l + 1); // CORREÇÃO: removido '\n' do inicio e ajustado para l + 1
        if(resultado[l] == 1)    
            printf("SIM\n\n");
        else 
            printf("NAO\n\n");          // CORREÇÃO: "NAO" em maiúsculas
    }
}

int main(){
    int n;
    if(scanf("%d", &n) != 1) return 0;

    ler_matrizes(n);
    
    return 0;
}