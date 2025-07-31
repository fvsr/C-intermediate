//Subrotinas

//Uma subrotina é um bloco de código que reliza uma tarefa específica.
//Existem dois tipos de subrotinas: funções e procedimentos.
//Os procedimentos realizam uma tarefa e não retornam um valor como resultado.
//Para os procedimentos usamos o termo "void" no lugar do tipo de retorno,
//indicando que não há retorno de valor.

#include <stdio.h>

void exibirBoasVindas() {
    
    printf("Bem vindo a festa!\n"); //Procedimento que exibe uma mensagem
}

int main(){

    exibirBoasVindas(); //chama o procedimento para exibir mensagem
    return 0;
}