/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Caike Morelli Ciola Fonseca
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1095
Data        : 27/10/2026
Objetivo    : 
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */

#include <stdio.h>
 
int main() {
    int j = 1;
    for(int i = 60; i > -5; i = i -5){
        printf("I=%d J=%d\n", j, i);
        j = j + 3;
    }
    
     
    return 0;
}