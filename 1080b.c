/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Caike Morelli Ciola Fonseca
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 31/08/2026
Objetivo    : Ler 100 inteiros em um vetor e dizer qual o maior número do vetor e qual o seu indíce. Com alocação de vetor dinâmica
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int tamanho = 100, maior, index=0;
    int *vetor;

    // alocando um espaço para um vetor com 5 inteiros
    vetor = (int*) malloc(tamanho * sizeof(int));

    // verificação de segurança
    if (vetor == NULL) {
        printf("Erro: Memória insuficiente.\n");
        return 1;
    }
    
    // lendo valores vetor
    for(int i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
    }
    
    //setando primeiro elemento com maior
    maior = vetor[0];

    // analisar vetor começando pelo segundo elemento
    for(int j = 1; j < tamanho; j++){
        if(vetor[j] > maior) {
            maior = vetor[j];
            index = j;
        }
    }

    // resposta
    printf("%d\n%d\n", maior, index+1);

    // limpando espaço usado
    free(vetor);

    return 0;
}