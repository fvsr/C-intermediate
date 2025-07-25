//A função "calloc"

//A função "calloc" também aloca um bloco contínuo de memória.
//Ela recebe dois argumentos, o número de elementos e o tamanho de cada argumento.
//Ela também inicia todos os bytes de memória do bloco com zero.

//void* calloc(size_t num_elements, size_t size_of_each_element);
//"num_elements" é o número de elementos a serem alocados.
//"size_of_each_element" é o tamanho em bytes de cada elemento.

#include <stdio.h>
#include <stdlib.h>

int main(){
    int* ponteiro; //aqui o asterisco indica que o tipo da variável é um ponteiro
    ponteiro = (int*)calloc(5, sizeof(int)); //"int*" retorna o endereço do início da memória alocada

    if(ponteiro != NULL){
        int i;
        for(i=0; i<5; i++){
            printf("A posição %d do array contém o valor %d.\n", i, ponteiro[i]);
        }
        free(ponteiro);
    }
    else{
        printf("Erro na alocaçõa de memória.\n");
    }

    return 0;
}