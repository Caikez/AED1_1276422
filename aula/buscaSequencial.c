#include <stdio.h>

int buscaSequencial(int x, int n, int v[]){
    int j = 0;
    while(j < n && v[j] < x) ++j;
    return j;
}

int main(){
    int vetor[10];
    int x, n;

    for(int i=0; i<10;i++) {
        scanf("%d", &vetor[i]);
    }

    scanf("%d %d", &x, &n);
    int posiçao = buscaSequencial(x, n, vetor);
    
    printf("%d\n", posiçao);
    return 0;
}