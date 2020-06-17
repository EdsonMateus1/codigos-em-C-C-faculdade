




#include <stdio.h>
#include <stdlib.h>

// Definição da Estrutura
typedef struct tipoCliente cliente;
struct tipoCliente {
    int codigo;
    float valor;
    struct tipoCliente *prox;
};

int tam;

void inicializa(cliente *inicio, cliente *fim);

int main(){
    cliente *inicio = NULL;
    cliente *fim = NULL;
    
    inicializa(inicio, fim);
    
    system("PAUSE");
    return 0;
}

void inicializa(cliente *inicio, cliente *fim) {
    tam = 0;
    printf("Fila inicializada!\n");
    printf("Inicio.: %d\n", inicio);
    printf("Fim....: %d\n", fim);
    printf("Tamanho: %d\n", tam);
}
