#include <stdio.h>
#include <stdlib.h>

// Definição da Estrutura
typedef struct tipo_no no;
struct tipo_no {
    int info;
    struct tipo_no *prox;
};

void insereInicio(int n, no **inicio);
int removePrimeiro(no **inicio);
void imprimeLista(no *inicio);

int main(){
    int num;
    // Inicialização da lista
    no *lista = NULL;
    
    // Insere na lista
    insereInicio(3, &lista);
    imprimeLista(lista);
    insereInicio(2, &lista);
    imprimeLista(lista);
    insereInicio(1, &lista);
    imprimeLista(lista);
    
    // Remove primeiro
    num = removePrimeiro(&lista);
    printf("No removido: %d\n", num);
    imprimeLista(lista);
    
    system("PAUSE");
    return 0;
}

// Insere um nó de valor N no início da lista
void insereInicio(int n, no **inicio) {
    // Aloca espaço para novo nó
    no *aux = (no*) malloc(sizeof(no));
    
    if(aux) {                          // Se conseguiu alocar espaço
        aux->info = n;
        if(!(*inicio)) {                // É o mesmo que if(*inicio==NULL)
            *inicio = aux;           // Aponta o início para o nó criado
            (*inicio)->prox = NULL;    // O nó inserido aponta para NULL
        }
        else {                         // Lista não vazia
            aux->prox = *inicio;     // Liga o novo nó à lista
            *inicio = aux;           // O início da lista passa a ser o novo nó
        }
    }
    else
        printf("Heap overflow!\n");

    return;
}

// Imprime os nós da lista
void imprimeLista(no *inicio) {
    printf("Lista atual: ");
    while(inicio) {                    // Enquanto houver lista
        printf("%d ", inicio->info);   // Imprime o valor do nó
        inicio = inicio->prox;         // Anda para o próximo nó
    } 
    printf("\n");
    return;
}

int removePrimeiro(no **inicio) {
    if(!(*inicio))             // Retorna -1 se a lista estiver vazia
        return -1;             
    no *aux = *inicio;         // Guarda o primeiro nó em aux
    int n = (*inicio)->info;   // Guarda o valor do nó para retornar 
    *inicio = (*inicio)->prox; // Anda com o inicio para o segundo nó
    free(aux);                 // Libera o espaço de memória ocupado pelo nó removido
    return n;                  // Retorna o valor do nó removido
    
}
