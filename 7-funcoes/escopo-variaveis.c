//Escopo de uma variável

/*
    O escopo de uma variável define onde a variável existe ou deixa de existir,
considerando um código.
    Variável local: só existe dentro de uma função específica, a função na qual foi declarada.
    Variável global: é declarada fora de qualquer função,
e existe para todas as funções no código.
    Parâmetros ou parâmetros formais: variáveis criadas no momento em que uma função é chamada,
deixam de existir quando o valor final da função é retornado,
ou quando é finalizada a execução de um procedimento, que é uma subrotina que não retorna valor.
    Argumentos: são os valores reais enviados às funções através dos parâmetros formais.
*/

//Simulação de um sistema de gestão de estoque
#include <stdio.h>

//variável global para o total de ítens no estoque
int totalEstoque = 100; //declarada fora de uma função
                        //é acessível dentro de qualquer função
                        //o valor atualizado esta sempre disponível

//Procedimento para adicionar ítens ao estoque
void adicionarEstoque(int quantidade){ //A variável "quantidade" é parâmetro formal.
    totalEstoque += quantidade;
    printf("Ítens adicionados: %d.\n", quantidade);
    printf("Estoque atualizado: %d.\n", totalEstoque);
}

//Procedimento para remover ítens do estoque
void removerEstoque(int quantidade){ //A variável "quantidade" é parâmetro formal.
    if(quantidade <= totalEstoque){
        totalEstoque -= quantidade;
        printf("Ítens removidos: %d.\n", quantidade);
        printf("Estoque atualizado: %d.\n", totalEstoque);
    }
    else{
        printf("Tentativa de remover %d ítens do estoque.\n", quantidade);
        printf("Erro: quantidade insuficiente no estoque %d.\n", totalEstoque);
    }
}
//Função principal
int main () {
    //A variável local armazena a quantidade de ítens a ser processada
    int quantidade;

    //Declara o estoque inicial
    printf("Estoque inicial: %d.\n", totalEstoque);

    //Adicionar ítens ao estoque
    quantidade = 20; //argumento que vai ser passado a uma função
    adicionarEstoque(quantidade);

    //Remover ítens do estoque
    quantidade = 15; //argumento que vai ser passado a uma função
    removerEstoque(quantidade);

    //Tentar remover uma quantidade maior que o estoque
    quantidade = 200; //argumento que vai ser passado a uma função
    removerEstoque(quantidade);

    return 0;
}