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
                printf("---Realizar empréstimos");

                if(totalEmprestimos >= MAX_EMPRESTIMOS){
                    printf("Limite de empréstimos atingido!\n\n");
                }
                else{
                    printf("Livros disponíveis:\n");
                    int disponiveis = 0;
                    for(int i=0; i<totalLivros; i++){
                        if(biblioteca[i].disponivel == 1){
                            printf("%d - %s", i+1, biblioteca[i].nome);
                            disponiveis++;
                        }
                    }
                    if(disponiveis == 0){
                        printf("Nenhum livro disponível para empréstimo.\n");
                    }
                    else{
                        printf("\nDigite o número do livro que deseja emprestar: ");
                        int numLivro;
                        scanf("%d", &numLivro);
                        limparBufferEntrada();
                        int indice = numLivro -1; //converte para o índice do array, de 0 a N-1

                        //Validação da escolha do usuário.
                        if(indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel){
                            printf("Digite o nome do usuário que está pegando o livro:");
                            fgets(emprestimos[totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                            emprestimos[totalEmprestimos].nomeUsuario[strcspn(emprestimos[totalEmprestimos].nomeUsuario,"\n")] = '\0';

                            //Registra o empréstimo.
                            emprestimos[totalEmprestimos].indiceLivro = indice;

                            //Atualiza o estatus do livro para indisponível
                            biblioteca[indice].disponivel = 0;

                            totalEmprestimos++;
                            printf("\nEmpréstimo realizado com sucesso!\n");
                        }
                        else{
                            printf("\nNúmero de livro inválido ou livro indisponível.\n");
                        }
                    }
                }
                printf("\nPressione qualquer tecla para continuar...");
                getchar();
            break;
            
            case 4: //Listar empréstimos
                printf("---Lista de empréstimos---\n\n");
                if(totalEmprestimos == 0){
                    printf("Nenhum empréstimo realizado.\n");
                }
                else{
                    for(int i=0; i<totalEmprestimos; i++){
                        //Usa o índice armazenado no empréstimo para buscar o nome do livro.
                        int indiceLivro = emprestimos[i].indiceLivro;
                        printf("--------------------------------");
                        printf("EMPRESTIMO %d\n", i+1);
                        printf("Livro: %s\n", biblioteca[indiceLivro].nome);
                        printf("Usuário: %s\n", emprestimos[i].nomeUsuario);
                    }
                    printf("--------------------------------");
                }
                printf("\nPressione Enter para continuar...");
                getchar();
            break;

            case 0:
                printf("\nSaindo do sistema...\n");
            break;

            default:
                printf("\nOpção inválida!\n");
                printf("\nPressione qualquer tecla para continuar...");
                getchar();
            break;
        }

    } while(opcao != 0);

    //Antes de terminar e essencial liberar memória alocada dinamicamente.
    //Isso evita "memory leaks", vazamentos de memória.
    free(biblioteca);
    free(emprestimos);
    
    //Para ter certeza que a memória foi liberada com sucesso é preciso testar.
    if(biblioteca == NULL || emprestimos == NULL){
        printf("Memória liberada com sucesso.\n");
    }

    return 0;


}