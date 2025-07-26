//A função "malloc"

//A função "malloc" é usada para alocar um bloco de memória contínuo em bytes.
//Essa memória não é inicializada, então seu conteúdo pode ser qualquer coisa.
//A função "maloc" recebe o número de bytes que desejamos alocar,
//e retorna um ponteiro para o inicio do bloco de memória.
//Se não houver memória suficiente disponível, "malloc" retorna "NULL".
//Ao final do uso é preciso liberar a memória usada através da função "free",
//pois a função "malloc" não faz isso automaticamente

// void* malloc(size_t size); //"size" recebe o número de bytes que queremos alocar

#include <stdio.h>
#include <stdlib.h>

int main(){
    int* ponteiro; //aqui o asterisco indica que o tipo da variável é um ponteiro
    ponteiro = (int*)malloc(5 * sizeof(int)); //"int*" retorna o endereço do início da memória alocada

    if(ponteiro != NULL){
        int i;
        for(i=0; i<5; i++){
            ponteiro[i] = i + 1;
        }
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