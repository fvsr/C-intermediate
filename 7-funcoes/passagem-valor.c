//Passagem de um valor para uma função

//Passar um valor para uma função fazer seu trabalho se chama passagem de parâmetro.
//A forma mais comum e também mais segura de fazer isso se chama passagem por valor.
//Ao fazer a passagem por valor para uma função o que está se fazendo na verdade
//é uma cópia do dado original, ela não recebe o dado original, que se mantém intacto.

//Exemplo de código

#include <stdio.h>

//Esta função recebe uma cópia do valor
void dobrar(int x){
    //a função dobra o valor recebido
    x = x * 2;

    //A função imprime o valor calculado
    printf("Dentro da função, o valor da cópia é: %d\n",x);
}

int main(){
    //declara e inicializa uma variável
    int numero = 5;

    //Imprime o valor da variável antes que ele seja enviado a função
    printf("Antes de chamar a função, o valor de x é: %d\n",numero);

    //Passa "numero" por valor
    dobrar(numero);

    //Imprime o valor da variável depois do retorno da função
    printf("Depois de chamar a função, o valor de x é: %d\n",numero);

    return 0;
}