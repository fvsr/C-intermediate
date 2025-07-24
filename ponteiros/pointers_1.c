#include<stdio.h>

int main(){
    int numero = 10; //variável normal
    int *ponteiro;   //declaração de um ponteiro

    ponteiro = &numero; //inicia a variável "ponteiro" com o endereço de "numero"

    printf("O valor da variável 'numero' é: %d\n", numero);
    printf("O endereço da variável 'numero' é: %p\n", ponteiro);
    printf("O valor apontado por 'ponteiro' é: %d\n", *ponteiro);

    return 0;
}