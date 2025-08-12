//Sistema de biblioteca - parte 1

//Implementar o cadastro e a listagem de livros usando um array estático.
//Structs, entrada e saída e dados.

//includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //para strcspn()

//defines
#define MAX_LIVROS 50  //As definições não são constantes, são diretivas de pré-processamento,
#define TAM_STRING 100 //já que não foram definidos tipos para receber os valores.
                       //Neste caso os valores literais são substituidos
                       //pelos valores numéricos antes do processamento.

//struct
struct Livros {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};

//limpar buffer de entrada
//A função "getchar()" lê um caractere por vez do buffer de entrada.
//O loop continua enquanto o caractere lido não for quebra de linha, "\n", 
//e não for fim de arquivo, EOF,
//que pode ocorrer em entradas redirecionadas ou erros.
void limparBufferEntrada(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main () {
    //definição de variáveis
    struct Livros biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    //laço principal do menu
    do{
        //exibe o menu de opções
        printf("Escolha uma opção:\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("0 - Sair\n");

        //lê a opção do usuário
        scanf("%d", &opcao); 
        limparBufferEntrada(); //limpa o "\n" deixado pelo scanf


        //processamento da opção
        switch (opcao) {
            case 1: //cadastro de novo livro
                //declara a opção
                printf("Cadastro de novo livro\n");

                //continua com o cadastramento
                if(totalLivros < MAX_LIVROS){ //verifica se a memória já atingiu o número máximo de livros
                    //fgets lê uma linha completa do stdin,
                    //até encontrar uma quebra de linha (\n) ou atingir o tamanho máximo especificado.
                    //É uma função mais segura para leitura de strings, pois evita estouros de buffer.
                    //stdin indica que a entrada de dados é por teclado.
                    //Não é necessário usar "&" porque o nove da string já é um ponteiro.
                    printf("Digite o nome do livro: ");
                    fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);
                    printf("\nDigite o autor: ");
                    fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);
                    printf("\nDigite a editora: ");
                    fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);
                    
                    /*
                    Quando você usa fgets() para ler uma string do teclado (ex.: "Dom Casmurro" + Enter),
                    a string armazenada fica assim: "Dom Casmurro\n\0".
                    O \n é inserido porque o fgets() captura a tecla Enter pressionada pelo usuário.
                    Isso pode causar problemas em comparações ou processamentos posteriores
                    (ex.: strcmp(), impressão com printf).
                    Solução: Substituir \n por \0.
                    A linha em questão localiza o \n
                    e o substitui por \0 (terminador de string), efetivamente "encurtando" a string.
                    O mesmo código, de outra forma:
                    size_t len = strlen(biblioteca[totalLivros].nome);
                    if (len > 0 && biblioteca[totalLivros].nome[len - 1] == '\n') {
                        biblioteca[totalLivros].nome[len - 1] = '\0';
                    }
                    */          
                    biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
                    biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
                    biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

                    printf("Digite a edição: ");
                    scanf("%d", &biblioteca[totalLivros].edicao);
                    limparBufferEntrada();

                    totalLivros++;

                    printf("\nLivro cadastrado com sucesso!\n");
                                                                            
                }
                else{
                    printf("Biblioteca cheia! Não é possível cadastrar mais livros.");
                }

                printf("\nPressione qualquer tecla para continuar...");
                getchar();

            break;
            case 2: //listagem de livros
                if(totalLivros == 0){
                    printf("Nenhum livro cadastrado ainda.\n");
                }
                else{
                    for(int i=0; i<totalLivros; i++){
                        printf("Livro %d\n", i+1);
                        printf("Nome %s\n", biblioteca[i].nome);
                        printf("Autor %s\n", biblioteca[i].autor);
                        printf("Editora %s\n", biblioteca[i].editora);
                        printf("Edicao %d\n", biblioteca[i].edicao);
                    }
                }
            break;
            case 0:
                printf("\nSaindo do sistema...\n");
            break;
            default: //opção inválida
                printf("\nOpção inválida! Tente novamente.");
                printf("Pressione ENTER para continuar...");
                getchar();
            break;
        }


    } while(opcao != 0);


    return 0;
}