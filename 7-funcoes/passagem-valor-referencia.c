//Funções

//Uma função é como se fosse um pequeno programa dentro de um programa maior.
//Realizam tarefas específicas.

/*
Elementos que compõem a declaração de uma função:
- tipo de retorno: é o que a função vai produzir, pode se númeor, texto ou ou nenhum retorno;
- nome da função;
- parâmetros: são os valores que você passa para a função para que ela possa fazer o trabalho, 
eles podem ser fornecidos de duas maneiras, por cópia ou por referência;
- corpo da função: é o código que define o que a função vai fazer com os parâmetros.
*/
//Passagem de valor por cópia
/*
#include <stdio.h>

int somar(int a, int b){
    return a + b;
}

int main () {
    int c = 10;
    int d = 15;

    //As variáveis "c" e "d" são copiadas respectivamente para as variáveis "a" e "b".
    int resultado = somar(c,d); 

    printf("O resultado da soma é %d.\n", resultado);

    return 0;
}
*/

//Este programa demonstra a passagem de valor para uma função,
//e compara passagem de valor por cópia e passagem de valor por referência.
#include<stdio.h>

void dobrar_valor_copia(int num){
    num = num * 2; //apenas a cópia é modificada
    printf("Dentro da função, por valor, o valor dobrado é %d.\n", num);
}

void dobrar_valor_ref(int *num){ //o asterisco aqui não é operador de desreferência,
                                 //mas sim parte da definição do tipo,
                                 //que no caso é ponteiro para um inteiro,
                                 //que vai receber um endereço, assim: "int *num = &numero".
    *num = *num * 2; //o valor original é modificado
    printf("Dentro da função, por referência, o valor dobrado é %d.\n", *num);
}

int main () {
    int numero = 10;

    printf("Antes da função, por valor, o número é: %d.\n", numero);
    dobrar_valor_copia(numero);
    printf("Depois da função, por valor, o número é: %d.\n", numero);

    printf("\nAntes da função, por referência, o número é: %d.\n", numero);
    dobrar_valor_ref(&numero); //Passamos o endereço da variável.
    printf("Depois da função , por referência, o número é: %d.\n", numero);

    return 0;
    
}