//Alocação Estática de Memória

//Usada por variáveis que permanecem na memória durante toda a execução do programa,
//por exemplo, no caso das variáveis globais e constantes.
//Essa alocação é feita no segmento de dados.

#include <stdio.h>

int valorGlobal = 20;

void exibirValor(){
    printf("Valor global: %d\n", valorGlobal);
}

int main(){
    exibirValor(); //chama a função para exibir o valor global
    return 0;
}