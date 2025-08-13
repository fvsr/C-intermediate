//Erro ao usar a função "malloc"

//O erro ao usar a função "malloc" ocorre ao tentar liberar memória estática.

#include <stdio.h>
#include <stdlib.h> //a função malloc usa esta biblioteca

int main (){
    //declaração de uma variável comum e um ponteiro
    int *a, b;

    //inicialização do ponteiro alocando memória dinâmicamente
    a = (int*)malloc(sizeof(int));

    //armazenando um valor nas variáveis
    *a = 20; //o asterisco aqui é operador de desreferência
    b = 10;

    //instruções que causam erro
    a = &b; //a variável perdeu a referência do espaço alocado
            //uma variável que foi inicializada com memória dinâmica recebe um valor estático, está errado
    free(a); //tentativa de liberar memória estática

    return 0;
}

//O compilador retorna o seguinte erro: free(): invalid pointer
//O ponteiro é inválido porque aponta para um espaço de memória estático