//Alocação Automática de Memória

//Quando uma função é chamada, 
//automaticamente é alocado um espaço temporário de memória para as variáveis dessa função.
//Quando a função é terminada, automaticamente o espaço é liberado.
//Uma pilha faz a alocação e liberação do espaço para as variáveis.

#include <stdio.h>

void funcaoExemplo(){

    int numero = 10; //o espaço de memória para 'número' é criado automaticamente
    printf("O valor da variável 'numero' é: %d\n", numero);
}

int main(){

    funcaoExemplo(); //chamada de função
    return 0;
}
