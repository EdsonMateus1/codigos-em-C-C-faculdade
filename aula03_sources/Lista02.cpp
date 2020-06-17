#include <stdio.h>
#include <stdlib.h>

// Definição da Estrutura
typedef struct tipo_no no;
struct tipo_no {
    int info;
    struct tipo_no *prox;
};

void insereInicio(int n, no **inicio);

int main(){
    // Inicialização da lista
    no *lista = NULL;
    
    // Insere na lista
    insereInicio(3, &lista);
    insereInicio(2, &lista);
    insereInicio(1, &lista);
    
    system("PAUSE");
    return 0;
}

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
