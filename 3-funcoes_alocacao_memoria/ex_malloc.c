//A função "malloc"

//A função "malloc" é usada para alocar um bloco de memória contínuo em bytes.
//Essa memória não é inicializada, então seu conteúdo pode ser qualquer coisa.
//A função "maloc" recebe o número de bytes que desejamos alocar,
//e retorna um ponteiro para o inicio do bloco de memória.
//Se não houver memória suficiente disponível, "malloc" retorna "NULL".

// void* malloc(size_t size); //"size" recebe o número de bytes que queremos alocar

//

//A função "calloc"

//A função "calloc" também aloca um bloco contínuo de memória.
//Ela recebe dois argumentos, o número de elementos e o tamanho de cada argumento.
//Ela também inicia todos os bytes de memória do bloco com zero.

//void* calloc(size_t num_elements, size_t size_of_each_element);
//"num_elements" é o número de elementos a serem alocados.
//"size_of_each_element" é o tamanho em bytes de cada elemento.

//

//A função "free"

//Libera memória que foi alocada dinamicamente pela função "malloc" ou "calloc".
//Após o uso da memória alocada, sempre devemos liberar esse espaço com a função "free",
//para que ele esteja disponível para outras partes do programa, ou para outros programas.
//Quando não lberamos a memória após o uso, isso pode resultar em vazamento de memória.

// void free(void* ptr); //ptr: ponteiro para o bloco de memória ser liberado