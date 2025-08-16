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
void listarLivros(const struct Livro *biblioteca, int totalLivros); //Usar "const" aqui garante que os dados não vão ser modificados,
                                                                    //vão apenas ser formatados para exibição.
void realizarEmprestimo(struct Livro *biblioteca, int totalLivros, struct Emprestimo *emprestimos, int *totalEmprestimos);
void listarEmprestimos(const struct Livro *biblioteca, const struct Emprestimo *emprestimos, int totalEmprestimos);
void liberarMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos);

//função principal, "main"
//A função "main" está limpa.
//Em "main" é feita a alocação de memória, controle do menu e chamada de funções especializadas.
int main (){
    //Alocação de memória para os ponteiros.
    struct Livro *biblioteca = (struct Livro *)calloc(MAX_LIVROS,sizeof(struct Livro));
    struct Emprestimos *emprestimos = (struct Emprestimo *)malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    //Teste para verificar se a alocação de memória para os ponteiros deu certo.
    if(biblioteca == NULL || emprestimos == NULL){
        printf("Erro: falha ao alocar memória.");
        return 1;
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    do{
        exibirMenu();
        scanf("%d\n",&opcao);
        limparBufferEntrada();

        switch(opcao){
            case 1:
                cadastrarLivro(biblioteca, &totalLivros); //Biblioteca é um array de 50 posições, seu nome já é um endereço.
            break;
            case 2:
                listarLivros(biblioteca, totalLivros); 
            break;
            case 3:
                realizarEmprestimo(biblioteca, totalLivros, emprestimos, &totalEmprestimos);
            break;
            case 4:
                listarEmprestimo(biblioteca, emprestimos, totalEmprestimos);
            break;
            case 0:
                printf("\nSaindo do sistema...\n");
            break;
            default:
                printf("\nOpção inválida! Pressione Enter para tentar novamente.");
                getchar();
            break;
        }
    }while(opcao != 0);

    //Chama afunção dedicada a liberar memória.
    liberarMemoria(biblioteca, emprestimos);

    return 0;
}

//Implementação das funções

void limparBufferEntrada(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void exibirMenu(){
    printf("==================================\n");
    printf("   Biblioteca - parte 3");
    printf("==================================\n");
    printf("1 - Cadastrar novo livro\n");
    printf("2 - Listar todos os livros\n");
    printf("3 - Realizar emprestimo\n");
    printf("4 - Listar emprestimo\n");
    printf("0 - Sair\n");
    printf("----------------------------------\n");
    printf("Escolha uma opção: ");
}

/*
* @brief Cadastra um novo ivro.
* @param biblioteca O array de livros.
* @param totalLivros Ponteiro para o contador de livros, para que ele seja
*/
void cadastrarLivros(struct Livro *biblioteca, int *totalLivros){
    printf("---Cadastro de Novo Livro---\n\n");

    if(totalLivros < MAX_LIVROS){
        int indice = *totalLivros; //Usa o valor apontado pelo ponteiro para o indice.

        printf("Digite o nome do livro: ");
        fgets(biblioteca[indice].nome, TAM_STRING, stdin);
        printf("Digite o autor: ");
        fgets(biblioteca[indice].autor, TAM_STRING, stdin);
        printf("Digite a editora: ");
        fgets(biblioteca[indice].editora, TAM_STRING, stdin);
        
        biblioteca[indice].nome[strcspn(biblioteca[indice].nome, "\n")] = '\0';
        biblioteca[indice].autor[strcspn(biblioteca[indice].autor, "\n")] = '\0';
        biblioteca[indice].editora[strcspn(biblioteca[indice].editora, "\n")] = '\0';

        printf("Digite a edição: ");
        scanf("%d",&biblioteca[indice].edicao);
        limparBufferEntrada();

        biblioteca[indice].disponivel = 1;

        (*totalLivros)++; //O parêntesis aqui é para que não se incremente o ponteiro, o que equivaleria a mudar devariável.
        printf("\nLivro cadastrado com sucesso!\n");
    }
    else{
        printf("Biblioteca cheia!\n");
    }
    printf("Pressione Enter para continuar...");
    getchar();
}

/*
* @brief Lista todos os livros cadastrados.
* @param biblioteca O array (ponteiro constante, apenas para leitura).
* @param totalLivros O numero de livros (passagem por valor).
*/
void listarLivros(const struct Livro *biblioteca, int totalLivros){
    printf("---Lista de Livros Cadastrados---\n\n");
    if(totalLivros == 0){
        printf("Nenhum livro cadastrado ainda.\n");
    }
    else{
        for(int i=0; i<totalLivros; i++){
            printf("----------------------------------");
            printf("LIVRO %d\n", i+1);
            printf("Nome: %s\n", biblioteca[i].nome);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Status: %s\n", biblioteca[i].disponivel ? "Disponível" : "Emprestado");
        }
        printf("----------------------------------");
    }
    printf("\nPressione Enter para continuar...");
    getchar();
}

/*
* @brief Realiza o empréstimo de um livro.
* @param biblioteca Array de livros (modificável, para alterar o status).
* @param totalLivros Total de livros dcadastrados.
* @param emprestimos Array de empréstimos (modificável).
* @param totalEmprestimos Ponteiro para o contador de empréstimos (para ser atualizado).
*/
void  realizarEmprestimo(struct Livro *biblioteca, int totalLivros, struct Emprestimo *emprestimos, int *totalEmprestimos){
    printf("---Realizar Empréstimo---\n\n");

    if(*totalEmprestimos >= MAX_EMPRESTIMOS){
        printf("Limite de emprestimos atingido!\n");
    }
    else{
        printf("Livros disponíveis:\n");
        int disponiveis = 0;
        for(int i=0; i<totalLivros; i++){
            if(biblioteca[i].disponivel){
                printf("%d - %s\n", i+1, biblioteca[i].nome);
                disponiveis++;
            }
        }

        if(disponiveis == 0){
            printf("Nenhum livro disponível para emprestimo.\n");
        }
        else{
            printf("Digite o número do livro que deseja emprestar: ");
            int numLivro;
            scanf("%d", &numLivro);
            limparBufferEntrada();

            int indice = numLivro -1;

            if(indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel){
                printf("Digite o nome do usuário: ");
                fgets(emprestimos[*totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                emprestimos[*totalEmprestimos].nomeUsuario[strcspn(emprestimos[*totalEmprestimos].nomeUsuario,"\n")] = '\0';

                emprestimos[*totalEmprestimos].indiceLivro = indice;
                biblioteca[indice].disponivel = 0; //Modifica o array original.

                (*totalEmprestimos)++; //O parêntesis é para que o endereço não incremente e sim o valor.
                printf("\nEmpréstimo realizado com sucesso!\n");
            }
            else{
                printf("\nNúmero do livro inválido ou livro indisponível.\n");
            }
        }
    }
    printf("\nPressione Enter para continuar...");
    getchar();
}

/*
* @brief Lista todos os empréstimos realizados.
* @param biblioteca Array de livros (somente leitura).
* @param emprestimos Array de empréstimos (somente leitura).
* @param totalEmprestimos totalEmprestimos Total de emprestimos (valor).
*/
void listarEmprestimos(const struct Livro *biblioteca, const struct Emprestimo *emprestimos, int totalEmprestimos){
    printf("---Lista de Empréstimos---\n\n");
    if(totalEmprestimos == 0){
        printf("Nenhum empréstimo realizado.\n");
    }
    else{
        for(int i=0; i<totalEmprestimos; i++){
            int indiceLivro = emprestimos[i].indiceLivro;
            printf("------------------------------------");
            printf("EMPRESTIMO %d\n", i+1);
            printf("Livro: %s\n", biblioteca[indiceLivro].nome);
            printf("Usuário: %s\n", emprestimos[i].nomeUsuario);
        }
        printf("------------------------------------");
    }
    printf("\nPressione Enter para continuar...");
    getchar();
}

/*
* @brief Livera memória alocada para os arrays dinâmicos.
*/
void liberaMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos){
    free(biblioteca);
    free(emprestimos);

    if(biblioteca == NULL && emprestimos == NULL){
        printf("Memória liberada com sucesso.");
    }
}