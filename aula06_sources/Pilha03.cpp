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
void push(no **pilha, no **topo);
void imprime(no *pilha);

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
    
    imprime(pilha);
    
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
            (*topo)->prox = novo;
            *topo = novo;
            /*no *aux = (*pilha);
            while(aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novo;     
            *topo = novo;*/
        }
        tam++;  
    }   
    return;
}

void imprime(no *pilha){
    printf("Tamanho da pilha: %d\n", tam);
    int vetor[tam];
    int i;
    for(i = 0; i < tam; i++) {
        vetor[i] = pilha->codigo;
        pilha = pilha->prox;
    }
    printf("\nPilha na ordem de push: ");
    for(i = 0; i < tam; i++)
        printf("%d ", vetor[i]);
        
    printf("\nPilha na ordem de pop: ");
    for(i = tam-1; i >= 0; i--)
        printf("%d ", vetor[i]);
    printf("\n\n");
    return;
}
