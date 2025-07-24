#include<stdio.h>

int main(){
    int numero = 10; //variável normal
    int *ponteiro;   //declaração de um ponteiro
                     // o tipo desta variável é 'int *'

    ponteiro = &numero; //inicia a variável "ponteiro" com o endereço de "numero"
                        //aqui o sinal & é o operador de endereço

    printf("O valor da variável 'numero' é: %d\n", numero);
    printf("O endereço da variável 'numero' é: %p\n", ponteiro);
    printf("O valor apontado por 'ponteiro' é: %d\n", *ponteiro); //acesso indireto
    //aqui o sinal % é especificador de formato
    //%p é usado para ponteiros
    //se uma função recebe um ponteiro está sendo passado um valor por referência
    //o oposto é passar um valor por cópia, onde o valor é copiado para outra variável dentro da função
    //o ponteiro evita a cópia de dados 

    return 0;
}