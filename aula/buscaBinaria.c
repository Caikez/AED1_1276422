#include <stdio.h>

int buscaBinaria(int x, int n, int v[]){
    int e, m, d;
    e = -1;
    d = n;

    while(/*X*/ e < d-1){
        m = (e + d)/2;
        if(v[m] < x) e = m;
        else d = m;
    }

    return d;
}

int main(){
    int vetor[10];
    int x, n;

    for(int i=0; i<10;i++) {
        scanf("%d", &vetor[i]);
    }

    scanf("%d %d", &x, &n);
    int posiçao = buscaBinaria(x, n, vetor);
    
    printf("%d\n", posiçao);

    return 0;
}