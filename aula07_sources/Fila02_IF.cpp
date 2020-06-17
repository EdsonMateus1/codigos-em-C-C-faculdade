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
void insere(cliente **inicio, cliente **fim);

int main(){
    cliente *inicio = NULL;
    cliente *fim = NULL;
    
    inicializa(inicio, fim);
    insere(&inicio, &fim);
    
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

void insere(cliente **inicio, cliente **fim){
    cliente *novo = (cliente *)malloc(sizeof(cliente));
    if(novo) {
        printf("Novo codigo: ");
        scanf("%d", &novo->codigo);
        printf("Novo valor: ");
        scanf("%f", &novo->valor);
        novo->prox = NULL;
        if(!(*inicio)) {
            *inicio = novo;
            *fim = novo;
        }
        else {
            cliente *aux = (*inicio);
            while(aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novo;     
            *fim = novo;
        }
        tam++;
    }   

    return;
}
