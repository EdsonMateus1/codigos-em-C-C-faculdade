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
void imprime(cliente *inicio);
void consome(cliente **inicio, cliente **fim);
int busca(cliente *inicio);

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
    
    consome(&inicio, &fim);
    imprime(inicio);
    int resultadoBusca = busca(inicio);
    if(resultadoBusca == -1)
        printf("Lista vazia!\n");
    else
    	if(resultadoBusca == 0)
        	printf("Codigo nao encontrado!\n");
        else printf("Codigo encontrado na posicao %d.\n", resultadoBusca);
    
    
    system("PAUSE");
    return 0;
}

void inicializa(cliente *inicio, cliente *fim) {
    tam = 0;
    printf("Fila inicializada!\n");
    printf("Inicio.: %d\n", inicio);
    printf("Fim....: %d\n", fim);
    printf("Tamanho: %d\n", tam);
    printf("\n");
}

void insere(cliente **inicio, cliente **fim){
    printf("\n");
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
            cliente *aux = (*inicio);
            while(aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novo;     
            *fim = novo;
        }
        tam++;
    }   
    printf("\n");
    return;
}

void imprime(cliente *inicio){
    printf("\n");
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

void consome(cliente **inicio, cliente **fim) {
    printf("\n");
    if(!(*inicio) && !(*fim)) {
        printf("Fila vazia. Impossivel remover!\n");
        return;
    }
    
    cliente *aux = *inicio;
    if(*inicio == *fim) {
        *inicio = NULL;
        *fim = NULL;
        free(aux);
        tam--;
        return;
    }
    
    *inicio = (*inicio)->prox;
    free(aux);
    
    tam--;  
    return;
}

int busca(int codigo, cliente *inicio) {
    
}

int busca(cliente *inicio) {
    printf("\n");
    if(inicio == NULL)
    	return -1;
    	
    int codigo;
    printf("Codigo a buscar: ");
    scanf("%d", &codigo);
    
	int pos = 1;
	
	while(inicio) {						//(inicio != NULL)
        if(inicio->codigo == codigo)    // Encontrou o elemento
			return pos;
        inicio = inicio->prox;	 		// Anda para o próxio elemento
    	pos++;
	}
    return 0;                    		// Percorreu a lista, mas não encontrou
}
