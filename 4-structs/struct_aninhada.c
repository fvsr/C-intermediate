//Structs aninhadas
//São structs que contém outras structs como membros.

//Aqui é usado também o recurso de passagem de parâmetros por referência,
//onde passamos para a função o ponteiro para uma struct.
//Isso é útil para evitar a cópia de grandes estruturas de dados,
//o que pode ser ineficiente em termos de desempenho e uso de memória.
//Usando o ponteiro para uma struct, passamos o endereço do início da struct,
//e podemos modificar diretamente os dados da struct original,
//sem precisar fazer uma cópia dela. 

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
    struct Disciplina disciplinas[3]; //struct curso aninhada dentro de struct Aluno
};

//função para cadastrar um aluno
//Aqui estamos passando uma struct por referência, um ponteiro para uma struct.
//As variáveis nome e professor pertencem à struct Disciplina,
//e têm que ser passadas por refência porque são arrays de caracteres,
//ou seja, strings em C, desse modo não precisamos copiar toda a string,
//apenas passamos o endereço de memória onde o primeiro caractere da string está armazenado. 

//O uso "const" aqui significa que as strings passadas para a função não serão modificadas,
//ou seja, a função não irá alterar o conteúdo das strings.
//Isso é uma boa prática para evitar modificações acidentais e melhorar a segurança do código
//e a legibilidade, indicando que essas strings são apenas para leitura dentro da função.
//As variáveis que não usam "const" subentende-se que poderão sofrer atualização em algum momento,
//como cargaHoraria, idade e matrícula.
void cadastrarDisciplina(struct Disciplina *disciplina, const char *nome, const char *professor, int cargaHoraria){
    strcpy(disciplina->nome, nome);
    strcpy(disciplina->professor, professor);
    disciplina->cargaHoraria = cargaHoraria;
}

//função cadastrar aluno
void cadastrarAluno(struct Aluno *aluno, const char *nome, int idade, int matricula){
    strcpy(aluno->nome, nome);
    aluno->idade = idade;
    aluno->matricula = matricula;
    
    //cadastrando disciplinas
    //função dentro de outra função
    cadastrarDisciplina(&aluno->disciplinas[0], "Matemática", "Prof. João", 60);
    cadastrarDisciplina(&aluno->disciplinas[1], "Física", "Prof. Maria", 45);
    cadastrarDisciplina(&aluno->disciplinas[2], "Química", "Prof. José", 30);
}

void exibirAluno(struct Aluno *aluno){
    int i;

    printf("Nome: %s\n", aluno->nome);
    printf("Idade: %d\n", aluno->idade);
    printf("Matrícula: %d\n\n", aluno->matricula);
    
    printf("Disciplinas:\n");
    for(i = 0; i < 3; i++){
        printf("Disciplina %d:\n", i + 1);
        printf("  Nome: %s.\n", aluno->disciplinas[i].nome);
        printf("  Professor: %s.\n", aluno->disciplinas[i].professor);
        printf("  Carga Horária: %d.\n", aluno->disciplinas[i].cargaHoraria);
    }
}

//função principal
int main(){
    //declaração de uma variável do tipo "struct Aluno"
    struct Aluno aluno;//A variável aluno é do tipo struct Aluno,
                       //e o ponteiro struct Aluno *aluno não tem relação com ela,
                       //a não ser pelo nome ser igual.
                       //Elas têm escopos diferentes, uma em "main" e outra na função cadastrarAluno,
                       //além disso a primeira é uma struct e a segunda um ponteiro para struct.

    cadastrarAluno(&aluno, "Alana Lima", 20, 123456); //Aqui é enviado endereço de "aluno",
                                                      //ou seja, um ponteiro para a variável struct Aluno aluno,
                                                      //visto que a função cadastrarAluno espera um ponteiro para struct Aluno.
    exibirAluno(&aluno);

    return 0;
}