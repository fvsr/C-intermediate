//Ponteiros

//Um ponteiro é uma variável que guarda o endereço de outra variável.
//O sinal "&" é o operador de endereço.
//O sinal "*" é o operador de declaração, ao se declarar um ponteiro,
//ou também pode ser chamado de operador de desreferência,
//pois quando ele é usado o ponteiro deixa de representar o endereço que faz referência ao valor,
//e passa a representar o próprio valor.

//Exemplo de código
#include <stdio.h>

int main () {

    //declara variáveis
    int x = 10;
    int *p = &x;

    //exibir valores
    printf("Valor de x: %d\n", x);
    printf("Endereço de x: %p\n", &x);
    printf("Conteúdo de p (o endereço de x) %p",p);
    printf("O valor apontado por p (é p desreferenciado) %d", *p);

    return 0;
}