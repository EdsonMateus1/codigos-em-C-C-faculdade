#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Defini��o da Estrutura
typedef struct tipoNo no;
struct tipoNo {
    int codigo;
    struct tipoNo *prox;
};

int tam;

void inicializa(no *pilha, no *topo);
void push(no **pilha, no **topo);

int main(){
    no *pilha = NULL;
    no *topo = NULL;
    char maisum;
    
    inicializa(pilha, topo);
    
    do{
        push(&pilha, &topo);
        printf("Inserir mais um (S/N)? ");
        fflush(stdin);
        scanf("%c", &maisum);
    }while(maisum == 'S' || maisum == 's');
    
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

void push(no **pilha, no **topo){
    no *novo = (no *)malloc(sizeof(no));
    if(tam == MAX) {
        printf("Pilha cheia!\n");
        return;       
    }
    
    if(!novo) {
        printf("Heap overflow!\n");
        return;          
    }
    
    if(novo) {
        printf("Novo codigo: ");
        scanf("%d", &novo->codigo);
        novo->prox = NULL;
        if(!(*pilha)) {
            *pilha = novo;
            *topo = novo;
        }
        else {
            novo->prox = (*topo);
            *topo = novo;
          
        }
        tam++;  
    }   
    return;
}
