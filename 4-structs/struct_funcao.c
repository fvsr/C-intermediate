//Este código mostra o exemplo de uma função que recebe uma struct como parâmetro.

//inclusão de bibliotecas
#include <stdio.h>
#include <string.h> //a função strcpy usa esta biblioteca

//definição da struct
struct Paciente {
    char nome[50];
    int idade;
    char telefone[15];
};

//Uma função para exibir o nome do paciente.
//Esta função recebe um struct, e retorna void
void exibirPaciente(struct Paciente p){ 
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Telefone: %s\n\n", p.telefone);
}

int main() {
    //declaração de uma variável do tipo struct
    struct Paciente paciente1 = {"Fernando", 12, "77777-8888"};

    //chamada da função que exibe os dados do paciente
    exibirPaciente(paciente1);

    return 0;
}