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
int removeIntermediario(no **inicio);
int removeUltimo(no **inicio);
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
    
    insereInicio(1, &lista);
    imprimeLista(lista);
    
    // Remove intermedi�rio
    num = removeIntermediario(&lista);
    printf("No removido: %d\n", num);
    imprimeLista(lista);
    
    // Remove �ltimo
    num = removeUltimo(&lista);
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

int removeIntermediario(no **inicio) {
    if(!(*inicio) || !(*inicio)->prox) // A lista cont�m dois elementos
        return -1;
    no *aux = (*inicio)->prox;         // Guarda o n� a ser removido em aux
    int n = aux->info;                 // Guarda o valor do n� para retornar
    (*inicio)->prox = aux->prox;       // Liga o n� anterior ao removido ao posterior
    free(aux);                         // Libera o espa�o de mem�ria ocupado pelo n� removido
    return n;                          // Retorna o valor do n� removido
    
}

int removeUltimo(no **inicio) {
    int n;
    if(!(*inicio))  // Lista vazia
        return -1;
        
    if(!(*inicio)-> prox) {       // Lista com apenas um elemento
        n = (*inicio)->info;
        free(*inicio);            
        *inicio = NULL;           // Ap�s a libera��o do �nico n�, a lista passa a ser vazia
        return n;                
    }
    
    no *aux = (*inicio);         // Inicializa aux cno in�cio da lista
    while(aux->prox->prox)       // Anda com aux at� o pen�ltimo n�
        aux = aux->prox;     
    n = aux->prox->info;         // Guarda o valor do �ltimo n�
    free(aux->prox);             // Libera a mem�ria do �ltimo n�
    aux->prox = NULL;            // Atualiza o ponteiro do pen�ltimo n�
    return n;
}
