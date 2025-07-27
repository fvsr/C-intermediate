//Declaração de uma struct

//includes
#include <stdio.h>
#include <string.h> //incluída para usar a função strcpy

//A palavra "Pessoa" é a tag (rótulo ou nome) da struct. 
//É o nome atribuido a um tipo de dado composto, também chamado de tipo agregado,
//construído a partir tipos de dados básicos, elementares ou primitivos,
//ou a partir de outros tipos compostos.
//Os tipos que compõe uma struct são chamados de membros ou campos.
struct Pessoa{
    char nome[50];
    int idade;
    char telefone[15];
};

//Declaração de uma variável do tipo "struct Pessoa"
struct Pessoa pessoa1;
struct Pessoa pessoa2;

//Inicialização direta da variável "pessoa1", do tipo "struct Pessoa", 
//aqui todos os membros da "struct Pessoa" são inicializados ao mesmo tempo. 
struct Pessoa pessoa1 = {"Maria", 28, "12345-6789"};

//função principal
int main(){

    //Inicialização da variável "pessoa2", do tipo "struct Pessoa",
    //os membros da "struct Pessoa" são inicializados separadamente
    //A função strcpy tem que ser chamada de dentro do main.
    strcpy(pessoa2.nome, "João");
    pessoa2.idade = 32;
    strcpy(pessoa2.telefone, "98765-4321");

    //Imprime dados de "pessoa1"
    printf("Nome: %s.\n", pessoa1.nome);
    printf("Idade: %d.\n", pessoa1.idade);
    printf("Telefone: %s.\n", pessoa1.telefone);

    //Imprime dados de "pessoa2"
    printf("Nome: %s.\n", pessoa2.nome);
    printf("Idade: %d.\n", pessoa2.idade);
    printf("Telefone: %s.\n", pessoa2.telefone);

    return 0;
}