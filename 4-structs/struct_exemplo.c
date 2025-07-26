//Exemplo de struct

#include <stdio.h>
#include <string.h> //a função strcpy usa esta biblioteca

struct Pessoa {
    char nome[50];
    int idade;
    char telefone[15];
};

int main(){
    struct Pessoa lista[3];
    int i;

    strcpy(lista[0].nome, "Alana");
    lista[0].idade = 18;
    strcpy(lista[0].telefone, "1234-5678");

    strcpy(lista[1].nome, "Lucas");
    lista[1].idade = 14;
    strcpy(lista[1].telefone, "98765-4321");
    
    strcpy(lista[2].nome, "Julia");
    lista[2].idade = 8;
    strcpy(lista[2].telefone, "54321-6789");

    //imprimindo as informações
    for(i=0; i<3; i++){
        printf("Nome: %s.\n", lista[i].nome);
        printf("Idade: %d.\n", lista[i].idade);
        printf("Telefone: %s.\n\n", lista[i].telefone);
    }

    return 0;
}