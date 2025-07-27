//Usando alocação dinâmica para structs e também ponteiros

//includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaração do formato da struct
struct Paciente{
    char nome[50];
    int idade;
    char telefone[15];
};

//Declaração de um ponteiro para uma struct, sem inicializar a variável.
struct Paciente* pPaciente; //o asterisco faz parte da tipagem 

int main(){
    //Aqui vamos alocar memória para o ponteiro que já foi inicializado.
    //A função "malloc" recebe um número que indica o número de bytes
    //e retorna um ponteiro para o início dos bytes alocados.
    //"void*" quer dizer a afunção malloc funciona com qualquer tipo de variável, seja primitiva ou composta. 
    //void* malloc(size_t size); //"size" recebe o número de bytes que queremos alocar
    //A função "malloc" precisa estar dentro de main para funcionar.
    pPaciente = (struct Paciente*)malloc(sizeof(struct Paciente));
    
    //Podemos também inicialzir e alocar memória numa mesma linha, o resultado é o mesmo.
    struct Paciente* pPacienteOutro = (struct Paciente*)malloc(sizeof(struct Paciente));


    //verificando se a memória foi alocada corretamente
    //caso haja falta de memória o ponteiro não vai ser alocado
    if(pPaciente != NULL && pPacienteOutro != NULL){
        
        //carregando com dados o espaço de memória para o qual o ponteiro aponta
        strcpy(pPaciente->nome, "Ana Costa");
        pPaciente->idade = 28;
        strcpy(pPaciente->telefone, "54321-9876");

        //carregando com dados o espaço de memória para o qual o outro ponteiro aponta
        strcpy(pPacienteOutro->nome, "João Silva");
        pPacienteOutro->idade = 35;
        strcpy(pPacienteOutro->telefone, "65432-1987");

        //imprime o conteúdo da memória
        printf("Dados do paciente:\n");
        printf("Nome: %s.\n", pPaciente->nome);
        printf("Idade: %d.\n", pPaciente->idade);
        printf("Telefone: %s.\n", pPaciente->telefone);

        //imprime o conteúdo da memória
        printf("\nDados do outro paciente:\n");
        printf("Nome: %s.\n", pPacienteOutro->nome);
        printf("Idade: %d.\n", pPacienteOutro->idade);
        printf("Telefone: %s.\n", pPacienteOutro->telefone);

        //libera a memória alocada
        free(pPaciente);
        free(pPacienteOutro);
    }
}