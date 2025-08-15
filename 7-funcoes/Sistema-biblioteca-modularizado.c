//Sistema de biblioteca com modularização

//includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defines
#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 100
#define TAM_STRING 100

//definiçã das estruturas
struct Livro{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel;
};

struct Emprestimo{
    int indiceLivro;
    char nomeUsuario[TAM_STRING];
};

//Protótipos das funções
//Declarar os protótipos das funções aqui permite que a "main" as chame antes de suas definições.
void limparBufferEntrada();
void exibirMenu();
void cadastrarLivro(struct Livro *biblioteca, int *totalLivros);
void listarLivros(const struct Livro *biblioteca, int totalLivros); //verificar porque usar constante aqui
void realizarEmprestimo(struct Livro *biblioteca, int totalLivros, struct Emprestimo *emprestimos,);//incompleto
void listarEmprestimos(const struct Livro *biblioteca, const struct Emprestimo *emprestimos);//incompleto
void liberarMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos);



