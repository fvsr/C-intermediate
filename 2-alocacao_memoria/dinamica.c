//Alocação Dinâmica de Memória

//Permite que o programa reserve memória conforme necessário durante a execução.
//Usa as funções 'malloc', 'calloc' e 'free'.

#include <stdio.h>
#include <stdlib.h>

int main(){

    int *ponteiro; //O tipo é "int *"
    ponteiro = (int*) malloc(sizeof(int));

    if(ponteiro != NULL){
        *ponteiro = 30;
        printf("Valor alocado dinamicamente: %d\n", *ponteiro);
        free(ponteiro); //libera a memória
    }
    else{
        printf("Erro na alocação de memória");
    }

    return 0;
}