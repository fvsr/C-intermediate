//Passagem de um vetor para uma função

/*
    Quando passamos um vetor ou array para uma função,
o que estamos passando na verdade é o endereço do primeiro elemento do vetor,
a partir do qual a função pode ter acesso a todo vetor.
    Então passar um vetor para uma função é sempre uma passagem por referência,
e qualquer mudança ocorre no arquivo original.
    Para evitar o erro de a função tentar acessar um ítem inexistente,
geralmente é também passado para a função o número de elementos do vetor,
ou o tamanho do vetor. 
*/

//Um exemplo com uma função que faz a soma de elementos de um vetor

#include <stdio.h>

//O tamanho do vetor não é declarado,
//então o vetor passado pode ter qualquer tamanho,
//desde que a memória permita.
int calcular_soma(int vetor[], int tamanho){
    int soma = 0;
    int i;
    
    for(i=0; i<tamanho; i++){
        soma += vetor[i]; //soma = soma + vetor[i];
    }
    return soma;
}

int main () {
    //Definindo um vetor de inteiros.
    int lista_compras[] = {10, 20, 30, 40, 50};
    int tamanho = sizeof(lista_compras)/sizeof(lista_compras[0]);
    int total;
    
    //Chamando a função para calcular a soma dos elementos do vetor.
    total = calcular_soma(lista_compras, tamanho);

    //Exibindo o resultado.
    printf("O total da lista de compras é: %d.\n", total);

    return 0;
}