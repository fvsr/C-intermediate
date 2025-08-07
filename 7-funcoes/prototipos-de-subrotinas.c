//Protótipo de subrotinas

/*
Um protótipo de função diz ao compilador que uma função existe,
qual seu nome,
qual será o seu tipo de retorno, isto é, 
qual o tipo de valor que uma função vai retornar, seja int, float, char ou void,
e quais os parâmetros ela vai receber,
mas não apresenta o corpo da função, isto é, não contém o código da função.

Sintaxe de um protótipo de função:
tipo_de_retorno nome_da_funcao(tipo1, tipo2, ...);
*/

//exemplo de uso de um protótipo de função
#include <stdio.h>

float calcular_area_circulo(float raio);
int calcular_area_retangulo(int largura, int altura);

int main () {
    float raio_main = 5;
    int largura_main = 4;
    int altura_main = 6;

    //Chamando as funções antes da sua definição completa
    printf("Área do círculo: %.2f.\n", calcular_area_circulo(raio_main));
    printf("Área do retângulo: %d.\n", calcular_area_retangulo(largura_main, altura_main));

    return 0;
}

float calcular_area_circulo(float raio){
    return 3.14159 * raio * raio;
}

int calcular_area_retangulo(int largura, int altura){
    return largura * altura;
}

