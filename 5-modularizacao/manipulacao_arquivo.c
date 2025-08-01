//Funções para trabalhar com arquivos

//São funções usadas para maipular arquivos,
//todas localizadas dentro da bilioteca stdio.h.

//fopen(): abre um arquivo para leitura, escrita ou atualização.
//fprintf(): escreve dados em um arquivo.
//printf(): escreve dados na tela.
//fscanf(): lê dados de um arquivo.
//scanf(): lê dados do teclado.
//fclose(): fecha o arquivo que foi aberto.
//fgetc() e fputc(): lê e escreve um caracter no arquivo.

//Usando a função fopen(): FILE *arquivo = fopen("dados.txt", "r");
//"r" abre o arquivo apenas para leitura.
//"w" abre o arquivo para escrita.
//"a" abre o arquivo para adicionar conteúdo.
//"r+" abre o arquivo para leitura e escrita.
//Se o arquivo não existir a função fopen() retorna nulo,
//indicando que algo deu errado.

//Usando a função fprintf(arquivo, "Nome: %s\nIdade: %d\n", nome, idade);

//Usando a função fscan(arquivo, "%s %d", nome, &idade);

//Usando a função fclose(arquivo);

//exemplo
#include <stdio.h>

int main(){
    FILE *arquivo; //ponteiro para o arquivo
    char nome[50];
    int idade;

    //abrindo o arquivo no modo "w" para escrita
    arquivo = fopen("dados.txt","w");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    printf("Digite o nome: ");
    scanf("%s", nome); //não usa o sinal & porque não está usando [],
                       //então aponta o endereço inicial de nome.
    printf("Digite a idade: ");
    scanf("%d", &idade); //aqui precisa do & para indicar endereço

    //Gravando dados no arquivo
    fprintf(arquivo, "Nome: %s\nIdade: %d", nome, idade); 

    //Fechando o arquivo
    fclose(arquivo);

    //Reabrindo o arquivo no modo "r" para leitura
    arquivo = fopen("dados.txt","r");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    fscanf(arquivo, "Nome: %s\nIdade: %d\n", nome, &idade);

    //Exibindo os dados lidos
    printf("Dados lidos no arquivo:\n");
    printf("Nome: %s\nIdade: %d", nome, idade);

    //Fechando o arquivo
    //fclose(arquivo);

    return 0;
}
