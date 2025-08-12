//O que é uma struct

//A estruct é como se fosse uma caixa que permite agrupar diferentes tipos de variáveis sob um mesmo nome.
//O ato de agrupar ou empacotar dados relacionados sob um mesmo nome se chama encapsulamento.
//Um exemplo prático é um prontuário médico, que tem dentro dele existe o nome do paciente, idade,
//histórico, etc, todas essas informações relacionadas a uma única pessoa.

//Vantagens de usar structs: facilita a organização do código, diminui a repetição, 
//favorece a reutilização e pode representar estruturas complexas.

//Exemplo em linguagem C
/*
//Este primeiro exemplo define uma struct do tipo "struct Aluno",
//mas ainda não declara uma variável.

struct Aluno{
    char nome[50]; //cada variável interna é um campo
    int idade;
    float media;
};

//Declarando um variável do tipo struct Aluno: "struct Aluno aluno1".
*/

/*
//O exemplo a seguir usa o comando "typedef" para definir uma struct.
//Isso evita ter que escrever "struct Aluno aluno1" para declarar a variável "aluno1",
//usando "typedef" agora posso declara uma variável assim "Aluno aluno1".

typedef struct{
    char nome[50]; //cada variável interna é um campo
    int idade;
    float media;
} Aluno;
*/

//Para acessar cada membro da struct usamos o ponto.

#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float media;
} Aluno;

int main () {
    //declarando e inicializando uma variável
    Aluno aluno1 = {"João", 20, 8.5};

    //Acessando dados com o operador ponto
    printf("Nome: %s\n", aluno1.nome);
    printf("Idade: %d\n", aluno1.idade);
    printf("Media: %.2f\n", aluno1.media);

    return 0;
}
