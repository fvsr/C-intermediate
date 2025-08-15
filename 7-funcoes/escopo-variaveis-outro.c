//Escopo de uma variável

//Escopo de uma variável é a região do código onde a variável é visível e pode ser acessada.
//Tem a ver com a área de atuação e com o tempo de vida de uma variável.
//O escopo garante que as variáveis só terão seus dados modificados nos lugares corretos.

//Escopo local: é quando a variável é declarada dentro uma função ou bloco de código.
//A variável começa a existir quando a função começa e deixa de existir quando a função termina.
//A variável é temporária e privada.
/*
void minhaFuncao() {
    int x = 10 // "x" é uma variável local, só existe aqui
    printf("Dentro da função, x = %d\n", x);
}
*/

//Escopo global: é quando a variável é declarada fora de todas as funções, 
//geralmente no topo do arquivo.
//Ela pode ser acessada e modificada por qualquer função do programa.
/*
int contador_global = 0; //esta variável é global

void incrementar(){
    contador_global++; //ela é acessível aqui
}
*/

//Exemplo de código
#include <stdio.h>

//Variável com escopo global
int global = 10;

void mostrarGlobal(){
    //Exibe o valor da variável global
    printf("Na função mostrar global %d\n",global);

    //Erro! A variável local não existe aqui.
    //O código não vai compilar, vai dizer que a variável não foi declarada.
    //printf("%d", local);
}

int main(){
    //Variável com escopo local
    int local = 5;

    printf("Na função main (local): %d\n",local);
    printf("Na função main (global): %d\n",global);

    mostrarGlobal();

    return 0;
}