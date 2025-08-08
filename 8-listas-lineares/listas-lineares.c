//Alocação sequencial

//Os dados ocupam posições contíguas na memória, isto é, um espaço de memória do lado do outro.
//A alocação sequencial pode ser feita em tempo de compilação ou em tempo de execução.

//Em linguagens de programação de alto nível, a alocação sequencial é feita por vetores.
//Um vetor aloca uma certa quantidade de posições de memória.
//Uma posição de memória depende do tamanho do tipo de dado e da palavra da memória.

//A palavra de memória é o tamanho dos dados que o processador processa em uma única operação.
//Isso depende da arquitetura do processador e ao tamanho dos registradores de uma CPU.
//Por exemplo, existem microcontroladores de 8 bits, 16 bits e 32 bits, existe o Windows 32 bits e o 64 bits.

//O tamanho do tipo de dado é uma convenção, na especificação C99 o tipo "int" em C tem 16 bits.

/*
O número total de posições de memória alocadas é:
numero_total_de_posicoes_de memoria =
 numero_de_posicoes_definidas_no_vetor * ( tamanho_do_tipo_de_dados / tamanho_da_palavra )
*/

//Os elementos de um vetor podem ser acessados diretamente através do seu índice.
//O número do índice do primeiro elemento de um vetor é 0 (zero).

//A alocação sequencial favorece o acesso.
//A alocação de memória em tempo de compilação é chamada alocação estática.
//A alocação dinâmica, em tempo de execução,
//é mais interessante no caso de deletar elementos, 
//para evitar remanejar toda lista a cada operação de deletar.

//Lista lineares são estruturas de dados não primitivas,
//usadas para reunir um conjunto de elementos que guardam relação entre si.

//Verificar pseudo códigos para busca, inserção e remoção de elementos de uma lista.
//Busca:
/*
int buscar ( chave )                         //1)
    se n > 0                                 //2) 
 		para i = 1 até i <= n                //3)
 			se Lista [ i ].chave == chave    //4)
 			retornar i                       //5)
 	retornar n + 1                           //6)

1) int buscar ( chave )
Declara uma função chamada "buscar" que recebe um parâmetro "chave", o valor a ser procurado.
Retorna um valor do tipo "int", inteiro,
que será a posição onde a chave foi encontrada,
ou um valor indicando que não foi encontrada.
2) se n > 0
Verifica se "n" (tamanho da lista) é maior que 0.
Se a lista estiver vazia (n == 0), o algoritmo pula direto para a linha 6
e retorna n + 1 (que seria 1).
3) para i = 1 até i <= n
Inicia um loop que percorre a lista do índice 1 até o índice n (último elemento).
4) se Lista [ i ].chave == chave
Para cada elemento da lista, verifica se o campo chave do elemento atual (Lista[i].chave)
é igual ao valor chave passado como argumento.
A variável "Lista[i].chave" é um campo que pertence a uma struct que está em um vetor de structs. 
5) retornar i
Se a chave for encontrada, retorna o índice i 
(posição onde o elemento está armazenado na lista).
6)retornar n + 1
Se o loop terminar sem encontrar a chave, retorna n + 1,
indicando que o elemento não está na lista.

Observações:
a) Retorno n + 1:
    Se n == 0 (lista vazia), retorna 1.
    Se n > 0 e a chave não for encontrada, retorna um valor fora do intervalo da lista
    (útil para indicar falha na busca).
b) Índices começando em 1:
    O pseudocódigo parece assumir que a lista é indexada a partir de 1
(comum em algumas linguagens como Pascal, 
mas diferente de C, Python, Java, etc., onde geralmente começa em 0).
*/

//Inserção:
/*
 int inserir ( novo_elemento )                  1)
 	se busca ( novo_elemento.chave ) == n + 1   2)
 		Lista [ n + 1 ] == novo_elemento        3)
 		n = n + 1                               4)
 		retornar 1                              5)
 	senão retornar -1                           6)

1) int inserir ( novo_elemento )
Declara uma função chamada "inserir" que recebe um parâmetro "novo_elemento"
(o elemento a ser inserido).
Retorna um valor inteiro (1 para sucesso, -1 para falha).
2)se busca ( novo_elemento.chave ) == n + 1
Chama a função "busca" (definida anteriormente)
para verificar se novo_elemento.chave já existe na lista.
Considerando que "n" é o número de elementos da lista,
e busca() retornar n + 1, significa que a chave não existe na lista (condição para inserção). 
3)Lista [ n + 1 ] == novo_elemento
(Observação: provavelmente deveria ser = em vez de ==, 
já que == é comparação, = seria atribuição. Isso parece um erro de digitação.)
Se a chave não existir, insere "novo_elemento" na posição n + 1 (final da lista).
4)n = n + 1
Incrementa o tamanho da lista (n) em 1, pois um novo elemento foi adicionado.
5) retornar 1
Retorna 1 indicando inserção bem-sucedida.
6)senão retornar -1
Se a chave já existir (se busca() retornar um valor diferente de n + 1),
retorna -1 indicando falha na inserção (evitando duplicatas).

Observações:
a) Verificação de chave duplicada:
    A função "busca" é usada para garantir que não haja elementos com a mesma chave.
    Se busca() retornar um índice válido (≤ n), a inserção é rejeitada.
b) Inserção no final da lista:
    O novo elemento é colocado em Lista[n + 1], aumentando dinamicamente o tamanho da lista.
c) Possível erro na linha 3 (== vs =)
    Se o pseudocódigo estiver correto como escrito (==),
isso seria uma comparação, não uma atribuição, o que não faria sentido.
    O mais provável é que deveria ser Lista[n + 1] = novo_elemento.
*/

//Remoção:
/*
	int remover ( chave )                          1)
		se n > 0                                   2)
			int i = busca ( chave )                3)
    		se i < n + 1                           4)
				para a = i até a < n               5)
					Lista [ i ] = Lista [ i + 1 ]  6)
					n = n -1                       7)
			senão retornar -1                      8)
		senão retornar “Erro: lista vazia”         9)

1) int remover ( chave )
Declara uma função chamada remover que recebe uma chave como argumento.
Retorna um valor inteiro (indicando sucesso ou falha).

    se n > 0

        Verifica se a lista não está vazia (n = tamanho atual da lista).

        Se n == 0, pula para a linha 9 e retorna um erro.

    int i = busca ( chave )

        Chama a função busca(chave) para encontrar a posição (i) do elemento com a chave especificada.

        Se a chave não existir, busca() retorna n + 1.

    se i < n + 1

        Verifica se a chave foi encontrada (ou seja, se i é um índice válido dentro da lista).

        Se i == n + 1, significa que a chave não existe, então vai para a linha 8 e retorna -1.

    para a = i até a < n

        Inicia um loop para deslocar os elementos após a posição i uma casa para trás (sobrescrevendo o elemento removido).

        Problema: O código usa Lista[i] dentro do loop, mas deveria usar Lista[a] (possível erro de digitação).

    Lista [ i ] = Lista [ i + 1 ] (Possível erro: deveria ser Lista[a] = Lista[a + 1])

        Se corrigido: Lista[a] = Lista[a + 1] desloca cada elemento subsequente para a posição anterior.

        Se não corrigido: O código sempre sobrescreve Lista[i] com Lista[i + 1], o que não remove corretamente.

    n = n - 1

        Decrementa o tamanho da lista (n), já que um elemento foi removido.

        Problema: Esta linha está dentro do loop, o que faria n diminuir várias vezes (erro lógico).

        Correção: Deveria estar fora do loop (após a linha 6).

    senão retornar -1

        Executado se a chave não for encontrada (i == n + 1).

        Retorna -1 indicando falha na remoção.

    senão retornar “Erro: lista vazia”

        Executado se a lista estiver vazia (n == 0).

        Retorna uma mensagem de erro.
*/