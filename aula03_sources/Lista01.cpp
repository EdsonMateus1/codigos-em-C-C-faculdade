#include <stdio.h>
#include <stdlib.h>

// Defini��o da Estrutura
typedef struct tipo_no no;
struct tipo_no {
    int info;
    struct tipo_no *prox;
};

int main(){
    // Inicializa��o da lista
    no *lista = NULL;
    
    system("PAUSE");
    return 0;
}
