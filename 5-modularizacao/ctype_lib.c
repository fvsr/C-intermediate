//Biblioteca ctype.h

//Biblioteca usada para manipulação de caracteres.
//Contém funções permitem verificar se um caractere é uma letra, um número ou um espaço.

/*Função que verifica se um caractere é uma letra.
if(isalpha(c)){
  printf("O caractere é uma letra.\n");
}
*/
/*Função que verifica se o caractere é um número.
if(isdigit(c)){
    printf("O caractere é um número.\n");
}
*/
/*Função verifica se o caractere é um espaço.
if(isspace(c)){
    printf("O caractere é um espaço em branco.\n");
}
*/

//Existem também funções de transformação.

/*Função que transforma os caracteres em maiúsculas.
c = toupper(c);
printf("Letra em maiúsculo: %c.\n", c);
*/
/*Função que transforma os caracteres em minúsculas.
c = tolower(c);
printf("Letra em minúsculo: %c.\n", c);
*/

//Código usando as funçoes de caractere.
#include <stdio.h>
#include <ctype.h>

int main () {
    char texto[] = "Programacao123";
    int i = 0;

    //Percorrendo cada caractere da string
    while(texto[i]){ //o índice "i" é usado porque eu quero navegar ítem por ítem da string
        //verificando se é uma letra
        if(isalpha(texto[i])){
            printf("%c é uma letra.", texto[i]);
        }
        if(islower(texto[i])){
            texto[i] = toupper(texto[i]);
            printf("%c foi convertido para maiúsculo. \n", texto[i]);
        }
        else if(isdigit(texto[i])){
            printf("%c é um número.\n", texto[i]);
        }
        i++; //i = i + 1;
    }
    //aqui não existe colchete porque eu quero imprimir a string completa
    printf("Texto transformado %s.\n", texto); 

    return 0;
}