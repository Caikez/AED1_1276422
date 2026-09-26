/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Caike Morelli Ciola Fonseca
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 27/08/2026
Objetivo    : Ler 100 inteiros em um vetor e dizer qual o maior número do vetor e qual o seu indíce.
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */



#include <stdio.h>

int main(){
    int v[100], maior, index = 0;
    
    // lendo valores vetor
    for(int i = 0; i<100; i++)  scanf("%d", &v[i]);
    
    //setando primeiro elemento com maior
    maior = v[0];

    // analisar vetor começando pelo segundo elemento
    for(int j = 1; j < 100; j++){
        if(v[j] > maior){
            index = j;
            maior=v[j];
        }
    }

    // resposta
    printf("%d\n%d\n", maior, index+1);

    return 0;
}