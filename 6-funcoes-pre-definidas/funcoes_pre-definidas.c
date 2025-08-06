//Funções pré-definidas nas bibliotecas padrão de C.

//Essas funções estão disponíveis em bibliotecas padrão do C.
//São pequenos blocos de código prontos para realizar uma tarefa específica.
//São também conhecidas como funções de biblioteca.
//Exemplo: stdio.h, stdlib.h, string.h, math.h, etc.
//Essas funções economizam tempo e evitam que tenhamos que "reinventar a roda",
//pois elas estão prontas para serem usadas.
//Exemplo de função pré-definida: Sqrt() da biblioteca math.h,
//que calcula a raiz quadrada de um número.

//biblioteca stdio.h: printf e scanf
/*
#include <stdio.h>

int main() {
    char nome[] = "Maria";

    printf("Olá, %s! Você está convidada para festa!\n", nome);

}
*/

#include <stdio.h>

int main() {
    //declara uma variável para armazenar o número
    int numero;

    //pede ao usuário para digitar um número
    printf("Digite um número inteiro: ");

    //lê o número digitado pelo usuário
    scanf("%d", &numero);

    //exibe o número digitado
    printf("Você digitou: %d.\n", numero);

    return 0;
}

//Biblioteca string.h, função strlen
/*
#include <stdio.h>
#include <string.h>

int main() {
    
    char mensagem[] = "Olá, esta é uma mensagem de exempo.";
    
    int comprimento = strlen(mensagem);

    printf("A mensagem tem %d caracteres.\n", comprimento); //os acentos são contados a parte

    return 0;

}
*/

//Biblioteca stdlib.h, função rand()
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    int sorteio = rand() % 5;

    printf("O sorteado foi o número: %d.\n", sorteio);
}
*/