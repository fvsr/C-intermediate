//Copiando dados entre structs

//includes
#include <stdio.h>

//declarando o formato da struct
struct Paciente{
    char nome[50];
    int idade;
    char telefone[15];
};

//declarando uma variável tipo "struct Paciente"
struct Paciente paciente1 = {"Joana", 26, "12345-6789"};
struct Paciente paciente2;

//função principal
int main(){

    paciente2 = paciente1; //cópia direta

    printf("Nome do paciente 2: %s.\n", paciente2.nome);

    return 0;
}