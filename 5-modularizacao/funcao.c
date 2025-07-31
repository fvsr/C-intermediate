//Modularização

//A modularização consiste em dividir o programa em partes menores,
//partes independentes, cada uma com uma responsabilidade específica.
//Cada uma dessas partes menores é chamada de subrotina ou função.
//Criar subrotinas evita repetições, facilita a manutenção do código,
//torna o código mais organizado e legível,
//facilita o reaproveitamento de código em outros programas (através de bibliotecas),
//e permite que várias pessoas trabalhem no mesmo projeto sem conflitos,
//pois cada um pode trabalhar em uma parte específica do código.

//Subrotinas

//Uma subrotina é um bloco de código que reliza uma tarefa específica.
//Existem dois tipos de subrotinas: funções e procedimentos.
//As funções realizam uma tarefa e retornam um valor como resultado.

#include <stdio.h> //inclui a biblioteca padrão de entrada e saída

float calcularTotal(float preco1, float preco2) {
    //Função que calcula o total de dois preços
    return preco1 + preco2; //retorna a soma dos preços
}

int main(){
    
    float item1 = 5.50;
    float item2 = 3.75;
    float total = calcularTotal(item1, item2);
    printf("O total da compra é: %.2f.\n", total);
    return 0;
}

