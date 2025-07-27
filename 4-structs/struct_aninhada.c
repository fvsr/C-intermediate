//Structs aninhadas
//São structs que contém outras structs como membros.

//includes
#include <stdio.h>
#include <string.h>

//definindo duas structs
struct Disciplina{
    char nome[30];
    char professor[50];
    int cargaHoraria;
};

struct Aluno{
    char nome[50];
    int idade;
    int matricula;
    struct Disciplina disciplina; //struct curso aninhada dentro de struct Aluno
};

void cadastrarDisciplin

//função principal
int main(){}