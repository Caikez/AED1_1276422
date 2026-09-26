#include <stdio.h>


int main(){
    int idade = 42;
    int *p = &idade;

    printf("Value: %d\n", *p);
    printf("Address: %p\n", (void *)p);

    return 0;
}