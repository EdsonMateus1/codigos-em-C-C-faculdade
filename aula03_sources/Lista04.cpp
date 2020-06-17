#include <stdio.h>
#include <stdlib.h>

// Defini��o da Estrutura
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
    // Inicializa��o da lista
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

// Insere um n� de valor N no in�cio da lista
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

// Imprime os n�s da lista
void imprimeLista(no *inicio) {
    printf("Lista atual: ");
    while(inicio) {                    // Enquanto houver lista
        printf("%d ", inicio->info);   // Imprime o valor do n�
        inicio = inicio->prox;         // Anda para o pr�ximo n�
    } 
    printf("\n");
    return;
}

int removePrimeiro(no **inicio) {
    if(!(*inicio))             // Retorna -1 se a lista estiver vazia
        return -1;             
    no *aux = *inicio;         // Guarda o primeiro n� em aux
    int n = (*inicio)->info;   // Guarda o valor do n� para retornar 
    *inicio = (*inicio)->prox; // Anda com o inicio para o segundo n�
    free(aux);                 // Libera o espa�o de mem�ria ocupado pelo n� removido
    return n;                  // Retorna o valor do n� removido
    
}
