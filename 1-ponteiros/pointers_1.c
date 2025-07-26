#include<stdio.h>

int main(){
    int numero = 10; //variável normal
    int *ponteiro;   //declaração de um ponteiro
                     //o tipo desta variável é 'int *'

    ponteiro = &numero; //inicia a variável "ponteiro" com o endereço de "numero"
                        //aqui o sinal & é o operador de endereço

    printf("O valor da variável 'numero' é: %d\n", numero);
    printf("O endereço da variável 'numero' é: %p\n", ponteiro);
    printf("O valor apontado por 'ponteiro' é: %d\n", *ponteiro); //acesso indireto
    //aqui o sinal % é especificador de formato
    //%p é usado para ponteiros
    //Se uma função recebe um ponteiro está sendo passado um valor por referência.
    //O oposto é passar um valor por cópia, onde o valor é copiado para outra variável dentro da função.
    //O ponteiro evita a cópia de dados.

    //Na declaração de um ponteiro o asterisco "*" faz parte da declaração do tipo,
    //por exemplo, um ponteiro para um inteiro, assim: "int*".
    //Para se obter o valor contido no espaço de memória para qual o ponteiro aponta,
    //usa-se também o asterisco "*" com a função de operador de desreferência ou operador de indireção, assim:
    //*ponteiro

    return 0;
}