//Exemplo de um array de struct

//inclusão de bibliotecas
#include <stdio.h>
#include <string.h> //a função strcpy usa esta biblioteca

//definição da struct
struct Pessoa {
    char nome[50];
    int idade;
    char telefone[15];
};

//declaração de variáveis
struct Pessoa lista[3]; //um array de structs com 3 elementos do tipo "struct Pessoa"
int i;

int main(){

    //inicializando os dados do array "struct Pessoa lista"
    strcpy(lista[0].nome, "Alana");
    lista[0].idade = 18;
    strcpy(lista[0].telefone, "1234-5678");

    strcpy(lista[1].nome, "Lucas");
    lista[1].idade = 14;
    strcpy(lista[1].telefone, "98765-4321");
    
    strcpy(lista[2].nome, "Julia");
    lista[2].idade = 8;
    strcpy(lista[2].telefone, "54321-6789");

    //imprimindo as informações dos elementos do array "lista[3]"
    for(i=0; i<3; i++){
        printf("Paciente %d:\n", i+1);
        printf("Nome: %s.\n", lista[i].nome);
        printf("Idade: %d.\n", lista[i].idade);
        printf("Telefone: %s.\n\n", lista[i].telefone);
    }

    return 0;
}