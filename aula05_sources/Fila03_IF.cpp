#include <stdio.h>
#include <stdlib.h>

// Defini��o da Estrutura
typedef struct tipoCliente cliente;
struct tipoCliente {
    int codigo;
    float valor;
    struct tipoCliente *prox;
};

int tam;

void inicializa(cliente *inicio, cliente *fim);
void insere(cliente **inicio, cliente **fim);
void imprime(cliente *inicio);

int main(){
    cliente *inicio = NULL;
    cliente *fim = NULL;
    char maisum;
    
    inicializa(inicio, fim);
    
    do{
        insere(&inicio, &fim);
        printf("Inserir mais um (S/N)? ");
        fflush(stdin);
        scanf("%c", &maisum);
    }while(maisum == 'S' || maisum == 's');
    
    imprime(inicio);
    
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
        if(!(*inicio) && !(*fim)) {
            *inicio = novo;
            *fim = novo;
        }
        else {
        //    cliente *aux = (*inicio);
        //    while(aux->prox != NULL)
        //        aux = aux->prox;
         //   aux->prox = novo;
            (*fim)->prox=novo;     
            *fim = novo;
       // }
        tam++;
    }   

    return;
}

void imprime(cliente *inicio){
    printf("Tamanho da lista: %d\n", tam);
    int pos = 1;
    while(inicio) {
        printf("\n");
        printf("Posicao.: %d\n", pos);
        printf("Codigo..: %d\n", inicio->codigo);
        printf("Valor...: %.2f\n", inicio->valor);
        pos++;
        inicio = inicio->prox;
    }
    return;
}
