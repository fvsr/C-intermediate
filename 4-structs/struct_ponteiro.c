//Ponteiros para uma struct
//Acesso direto e indireto a uma struct

//includes de bibliotecas
#include <stdio.h>
#include <string.h>

//Definição do formato da struct
struct Paciente{
    char nome[50];
    int idade;
    char telefone[15];
}; //Este ponto e vírgula é importante

//Declaração de uma variável do tipo da struct definida anteriormente
struct Paciente paciente1;

//Na declaração de um ponteiro o "*" faz parte do tipo,
//mostrando que a variável se destingue por ser um ponteiro. 
//Aqui o ponteiro é declarado e inicializado.
struct Paciente *pPaciente = &paciente1; //O ponteiro aponta para o endereço de "paciente1".

//função principal
int main(){

    //Inicializando a variável "paciente1"
    strcpy(paciente1.nome, "Maria Oliveira"); //A função strcpy deve ser chamada de dentro de "int main()"  
    paciente1.idade = 30;
    strcpy(paciente1.telefone, "12345-6789");

    //Imprimindo os dados de "paciente1"
    printf("Dados de 'paciente1':\n");
    printf("Nome: %s.\n", paciente1.nome);
    printf("Idade: %d.\n", paciente1.idade);
    printf("Telefone: %s.\n", paciente1.telefone);

    //Imprimindo os dados de "pPaciente", que aponta para "paciente1",
    //os dados devem seros mesmos
    //É possível acessar os dados da struct para qual o ponteiro aponta através de setas,
    //mas nesse caso não se usa operador de desreferência ou de indireção ("*"). 
    printf("Os mesmos dados de 'paciente1' acessados via ponteiro 'pPaciente':\n");
    printf("Nome: %s.\n", pPaciente->nome);
    printf("Idade: %d.\n", pPaciente->idade);
    printf("Telefone: %s.\n", pPaciente->telefone);

    return 0;

}