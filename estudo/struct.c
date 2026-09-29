#include <stdio.h>
#include <string.h>


typedef struct{
    int age;
    char name[99];
    float height;
} Person;


int main(){
    // first way of defining the values
    
    Person person = {
        19,
        "Caike Morelli",
        1.75,
    };

    // second way

    Person person2;

    person2.age = 25;
    strcpy(person2.name, "Joao");
    person2.height = 1.80;

    return 0;
}