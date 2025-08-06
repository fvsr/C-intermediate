//Biblioteca string.h
//Biblioteca usada para manipulação de strings.

//A função "srtlen" retorna o comprimento de uma string, menos o caractere de finalização, o "\0"
//#include <stdio.h>
//#include <string.h>
/*
int main() {
    char nome[] = "Programacao";
    
    int comprimento = strlen(nome); //A string nome tem comprimento de 12 caracteres porque o último é "\0".
    
    printf("O comprmento da string é %d.\n", comprimento); //Retorna que o comprimento é 11.
}
*/

/*A função strcpy copia uma string entre dois espaços de memória.
int main () {
    char origem[] = "Olá, mundo!";
    char destino[50];
    strcpy(destino, origem);
    printf("Conteúdo copiado: %s.\n", destino);
}
*/

//A função strcmp() compara duas strings.
/*
int main () {
    char string1[] = "Programacao";
    char string2[] = "programacao";

    if(strcmp(string1, string2) == 0){ //retorna um valor positivo se a primeira string for maior
                                       //retorna um valor negativo se a primeira string for menor
        printf("As strings são iguais.\n");
    }
    else{
        printf("As strings são diferentes.\n");
    }
}
*/

//A função strcat() concatena duas strings.
/*
int main () {
    char saudacao[] = "Olá, ";
    char nome[] = "mundo!";

    strcat(saudacao, nome); //A string concatenada é escrita na primeira variável, "saudacao".

    printf("%s\n", saudacao);

}
*/

//A função sprintf() formata strings.
/*
int main(){
    char buffer[100];
    int idade = 25;
    
    sprintf(buffer, "A idade de João é %d anos.\n", idade); //A string "buffer" vai receber o texto completo.

    printf("%s\n",buffer);

}
*/

//A função sscanf() lê dados formatados em uma string e os coloca em uma ou mais variáveis.
/*
int main () {
    char buffer[] = "João tem 25 anos.";
    char nome[20];
    int idade;

    sscanf(buffer, "%s tem %d anos.", nome, &idade);

    printf("%s tem %d anos.", nome, idade);
}
*/

//aplicando as funções
#include <stdio.h>
#include <string.h>

int main () {
    char nome1[50] = "Alana ";
    char nome2[] = "Silva";

    //Concatenando strings
    strcat(nome1,nome2);
    printf("Nome completo: %s. \n", nome1);

    //Medindo o comprimento da string concatenada
    int comprimento = strlen(nome1);
    printf("Comprimento do nome completo: %d.\n", comprimento);
 
    //Comparando strings
    if(strcmp(nome1, "Alana Silva") == 0){
        printf("As strings são iguais.\n");
    }
    else{
        printf("As strings são diferentes.\n");
    }

    //Copiando uma string para outra
    char copia[50];
    strcpy(copia, nome1);
    printf("Copia do nome: %s.\n", copia);

}