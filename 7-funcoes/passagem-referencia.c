//Passagem de parâmetro por referência

//A passagem de valor por referência não entrega para a função nem o dado nem a cópia,
//mas sim o endereço onde o dado original está guardado na memória.
//Para entregar o endereço de uma variável precisamos usar a técnica de ponteiros.
//O ponteiro é uma variável que guarda um endereço de memória.
//Quando se trabalha com dados muito grandes,
//pode não haver espaço de memória suficiente para fazer a cópia,
//então é melhor trabalhar com ponteiros.
//Passar strings do teclado para um arquivo, como na função scanf, são usados ponteiros.

//Exemplo de código

#include <stdio.h>

//A função recebe um endereço, isto é, um ponteiro para int.
void dobrar(int* x){ //Aqui o asterisco faz parte do tipo, mostrando que "x" é um ponteiro para um inteiro.
    //a função dobra o valor recebido
    *x = *x * 2; //Aqui o ponteiro é um operador de indireção ou desreferência, 
                 //mostrando que apesar de "x" ter sido declarado como ponteiro,
                 //o que está sendo manipulado é o dado, não o endereço.
                 //Pode ser escrito *x = (*x) * 2 para ficar mais claro, mas não é necessário.
}

int main(){
    //declara e inicializa uma variável
    int numero = 5;

    //Imprime o valor da variável antes que ele seja enviado a função
    printf("Antes de chamar a função, o valor de x é: %d\n",numero);

    //Passa "numero" por valor
    dobrar(&numero); //Aqui é preciso usar o operador de endereço,
                     //pois o parâmetro da função é um ponteiro, 
                     //então ele recebe um endereço e não o valor da variável.

    //Imprime o valor da variável depois do retorno da função
    printf("Depois de chamar a função, o valor de x é: %d\n",numero);

    return 0;
}
