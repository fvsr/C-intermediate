//Exemplo de modularização em C

#include <stdio.h>

//Função para calcular o valor do desconto
float calcularDesconto(float preco, float percentual){
    return preco * (percentual / 100);
}

//Procedimento para exibir o valor total com desconto
void exibirTotal(float preco, float desconto){
    float total = preco - desconto;
    printf("O valor total com desconto: %.2f.\n", total); //Aqui o ponto antes do 2 é importante,
                                                          //define o número de casas depois do ponto,
                                                          //que no caso são duas.
}

int main() {
    float preco, percentualDesconto, desconto;

    //Solicita o preço e o percentual de desconto ao usuário
    printf("Digite o valor do produto: ");
    scanf("%f", &preco);
    printf("Digite o percentual de desconto: ");
    scanf("%f", &percentualDesconto);

    //Chama a função para calcular desconto
    desconto = calcularDesconto(preco, percentualDesconto);

    //Chama o procedimento para exibir o total com desconto
    exibirTotal(preco, desconto);

    return 0;
}