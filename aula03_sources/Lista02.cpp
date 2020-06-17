#include <stdio.h>
#include <stdlib.h>

// Defini��o da Estrutura
typedef struct tipo_no no;
struct tipo_no {
    int info;
    struct tipo_no *prox;
};

void insereInicio(int n, no **inicio);

int main(){
    // Inicializa��o da lista
    no *lista = NULL;
    
    // Insere na lista
    insereInicio(3, &lista);
    insereInicio(2, &lista);
    insereInicio(1, &lista);
    
    system("PAUSE");
    return 0;
}

void insereInicio(int n, no **inicio) {
    // Aloca espa�o para novo n�
    no *aux = (no*) malloc(sizeof(no));
    
    if(aux) {                          // Se conseguiu alocar espa�o
        aux->info = n;
        if(!(*inicio)) {                // � o mesmo que if(*inicio==NULL)
            *inicio = aux;           // Aponta o in�cio para o n� criado
            (*inicio)->prox = NULL;    // O n� inserido aponta para NULL
        }
        else {                         // Lista n�o vazia
            aux->prox = *inicio;     // Liga o novo n� � lista
            *inicio = aux;           // O in�cio da lista passa a ser o novo n�
        }
    }
    else
        printf("Heap overflow!\n");

    return;
}
