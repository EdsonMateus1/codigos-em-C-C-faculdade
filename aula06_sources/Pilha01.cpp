#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Definição da Estrutura
typedef struct tipoNo no;
struct tipoNo {
    int codigo;
    struct tipoNo *prox;
};

int tam;

void inicializa(no *pilha, no *topo);

int main(){
    no *pilha = NULL;
    no *topo = NULL;
    
    inicializa(pilha, topo);
    
    system("PAUSE");
    return 0;
}

void inicializa(no *pilha, no *topo) {
    tam = 0;
    printf("Pilha inicializada!\n");
    printf("Inicio.: %d\n", pilha);
    printf("Topo...: %d\n", topo);
    printf("Tamanho: %d\n", tam);
}
