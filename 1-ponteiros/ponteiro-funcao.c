//Ponteiro para uma função

#include <stdio.h>

void saudacao () {
    printf("Olá, mundo!\n");
}

int main () {
    //declara um ponteiro para um a função que retorna nada e não tem parâmetros ("void" duas vezes)
    void (*ptr)() = saudacao;
    //poderia ser também "void (*ptr)(void) = saudacao;"

    //chama a função através do ponteiro
    ptr();

    return 0;
}