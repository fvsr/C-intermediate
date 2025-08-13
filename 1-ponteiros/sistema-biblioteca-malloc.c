//Sistema de biblioteca

//Construção de um sistema para biblioteca com uso de alocação dinâmica.

//includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defines
#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 100
#define TAM_STRING 100

struct Livro {
    char nome[TAM_STRING]; 
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel; //1 para sim, 0 para não //na verdade aqui esta invertido,
                    //se "calloc" inicia com 0 (zero), o livro deveria inciar disponível
};

struct Emprestimo {
    int indiceLivro; //para saber qual livro do array "biblioteca" foi emprestado
    char nomeUsuario[TAM_STRING];
};

//função para limpar o buffer de entrada
void limparBufferEntrada() {
    int c;
    while((c = getchar()) != '\n' && c != EOF); //Lê caracteres e os atribui a variável "c"
                                                //enquanto eles forem diferentes de "\n" e "EOF".
                                                //EOF significa "End OF File".        
//Verificar porque na primeira declaração se usa "c = getchar()" e na segunda apenas "c".
}

int main () {
    //Uso de ponteiros e alocação dinâmica
    //declaração de ponteiros
    struct Livro *biblioteca;
    struct Emprestimo * emprestimos;

    //Usamos calloc para o array de livros.
    //calloc(numero_elementos,tamanho_de_cada_elemento);
    //A vantagem é que "calloc" inicia toda a memória com zeros.
    //Então todos os espaçoes de memória sem cadastro de livros constam como indisponível, ou 0 (zero). 
    biblioteca = (struct Livro *) calloc(MAX_LIVROS, sizeof(struct Livro));

    //Usamos "malloc" para um array de empréstimos. malloc(tamanho_total_em_bytes)
    emprestimos = (struct Emprestimo *) malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    //É importante verificar se a alocação de memória deu certo
    if(biblioteca == NULL || emprestimos == NULL){
        printf("Erro: falha ao alocar memória!\n");
        return 1; //Retrona 1 para indicar erro.
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    do{
        printf("====================================\n");
        printf("    Sistema de biblioteca (parte 2)   ");
        printf("====================================\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("3 - Realizar empréstimo\n");
        printf("4 - Listar empréstimos\n");
        printf("0 - Sair\n");
        printf("-------------------------------------\n");
        printf("Escolha uma opção: ");

        scanf("%d", &opcao);
        limparBufferEntrada();

        switch(opcao){
            case 1: //cadastro de livro
                printf("---Cadastro de novo livro---\n\n");
                if(totalLivros < MAX_LIVROS){
                    //Devido ao uso de fgets, o acesso aos campos é igual ao do array estático.
                    //isso acontece porque a função fgets já espera uma ponteiro no primeiro parâmetro:
                    //char *fgets(char *str...
                    //Se "biblioteca" não fosse um ponteiro, aqui se usaria o operador seta (verificar), ->.
                    //O comando "stdin" significa que vai ser lida a entrada do teclado.
                    printf("Digite o nome do livro ");
                    fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);
                    //A mesma coisa para autor e editora
                    printf("Digite o nome do autor ");
                    fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);
                    printf("Digite o nome da editora ");
                    fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

                    //Eliminar o carácter "\n" que pode causar problemas depois
                    //A função "strcspn" varre a instring e passa o índice da posição onde "\n" foi encontrado,
                    //subistituindo por '\0'.
                    //A função "strcspn" retorna o número de posições percorridas antes de encontrar
                    //o caraactere especificado "\n".
                    biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome,"\n")] = '\0';
                    biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor,"\n")] = '\0';
                    biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora,"\n")] = '\0';

                    printf("Digite a edição: ");
                    scanf("%d", &biblioteca[totalLivros].edicao);
                    limparBufferEntrada();

                    //Ao cadastrar o livro automaticamente se torna disponível
                    biblioteca[totalLivros].disponivel = 1;
                }
            break;
            case 2: //Listagem de livros
                printf("---Lista de livros cadastrados---\n\n");
                if(totalLivros == 0){
                    printf("Nenhum livro cadastrado ainda.");
                }
                else{
                    for(int i=0; i<totalLivros; i++){
                        printf("-----------------------");
                        printf("Livro %d\n", i+1);
                        printf("Nome: %s\n", biblioteca[i].nome);
                        printf("Autor: %s\n", biblioteca[i].autor);
                        printf("Disponibilidade: %d", biblioteca[i].disponivel ? "Disponível" : "Emprestado");
                    }
                    printf("-----------------------");
                }
                printf("Pressione qualquer tecla para continuar...");
                getchar();
            break;
            case 3:
            break;
            case 4:
            break;
            case 0:
            break;
            default:
            break;
        }

    } while();


}