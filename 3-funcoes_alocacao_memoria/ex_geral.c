//Unindo conceitos de alocação de memória e ponteiros

#include <stdio.h>
#include <stdlib.h>

int main(){
    //definição de variáveis
    int numero = 10;
    int* ponteiroInt = &numero;

    //exibindo o valor das variáveis
    printf("O valor da variável 'número' é %d.\n", numero);
    printf("O endereço para o qual 'ponteiroInt' aponta é %p.\n", ponteiroInt);
    printf("O valor apontado por 'ponteiroInt' é %d.\n", *ponteiroInt);
    //aqui o asterisco é operador de desreferenciação ou indireção
    //"%p" é o especificador de formato para ponteiros, que exibe um endereço hexadecimal

    //alterando o valor da variável 'número' através do ponteiro
    *ponteiroInt = 20;//aqui o asterisco é operador de desreferenciação ou indireção
    printf("Valor da variável 'numero' depois de ser modificada através do ponteiro: %d.\n", *ponteiroInt);

    //alocação dinâmica de memória com malloc
    int* ponteiroDinamico;
    ponteiroDinamico = (int*)malloc(sizeof(int));

    if(ponteiroDinamico == NULL){
        printf("Não foi possível alocar um ponteiro.");
        return 1; //Qual o motivo desse 'return 1'?
    }

    *ponteiroDinamico = 50;
    printf("Valor apontado pelo ponteiro dinâmico: %d.\n", *ponteiroDinamico);

    //liberando o espaço de memória alocado
    free(ponteiroDinamico);  //libera memória alocada
    ponteiroDinamico = NULL; //torna o ponteiro invalido, evita acessos acidentais (?)

    if(ponteiroDinamico == NULL){
        printf("A memória foi alocada dinamicamente e o ponteiro está inválido.\n");
    }

    return 0;
}
//A função "free"

//Libera memória que foi alocada dinamicamente pela função "malloc" ou "calloc".
//Após o uso da memória alocada, sempre devemos liberar esse espaço com a função "free",
//para que ele esteja disponível para outras partes do programa, ou para outros programas.
//Quando não lberamos a memória após o uso, isso pode resultar em vazamento de memória.

// void free(void* ptr); //ptr: ponteiro para o bloco de memória ser liberado

//

//Existe também a função "realloc".

//void *realloc (void *ptr, size_t newsize);