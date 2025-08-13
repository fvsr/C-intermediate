//Ponteiro para uma struct

//Quando usamos ponteiros para structs, cada membro da struct é acessado pelo operador seta.
//Em uma struct que não é pontero, cada mem bro da struct é acessado pelo elemento ponto.

#include <stdio.h>
#include <stdlib.h> //a função malloc usa esta biblioteca

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

int main () {
    //p é um ponteiro para uma struct do tipo Pessoa
    //Pessoa *p = (Pessoa*)malloc(sizeof(Pessoa)); //declara e inicializa a variável em uma linha
    
    //Também poderia ser:
    Pessoa *p; //declara avariável
    p = (Pessoa*)malloc(sizeof(Pessoa)); //inicializa a variável

    //preenchendo a struct apontada com dados
    printf("Digite seu nome: ");
    scanf("%s", p->nome); //não se usa o operador de endereço
                          //por que o nome da string já é o endereço

    printf("Digite sua idade: ");
    scanf("%d", &p->idade); //aqui se usa o operador de endereço

    printf("%s tem %d anos.\n",p->nome, p->idade);

    free(p);
    return 0;
}