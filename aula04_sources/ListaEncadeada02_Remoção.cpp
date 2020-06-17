#include <stdio.h>
#include <stdlib.h>

// Definição da Estrutura Nó
// Atenção para a criação do novo membro da estrutura:
// O ponteiro para o nó anterior
typedef struct tipo_no no;
struct tipo_no {
    int codigo;
    struct tipo_no *prox;
    struct tipo_no *ant;
};

void insereListaDupla(no **lista);
int removeListaDupla(no **lista);
void imprimeListaDupla(no *lista);
bool buscaListaDupla(no *lista);
int imprimeMenu();

int main(){
    int opcao;
    no *lista = NULL;

    
    do{
        system("CLS");
		opcao = imprimeMenu();
        
        switch(opcao){
            case 1: {
						insereListaDupla(&lista);
						system("PAUSE");
                    	break;
                	}
            case 2: {
            			int remove = removeListaDupla(&lista);
            			if(remove == -1)
            				printf("Nao ha codigos registrados. Impossivel remover!\n\n");
						else
            				if(remove == 0)
            					printf("O codigo informado nao existe. Impossivel remover!\n\n", remove);
            				else
            					printf("O codigo %d foi removido com sucesso!\n", remove);
                    	system("PAUSE");
						break;
                	}
            case 3: {
						imprimeListaDupla(lista);
						system("PAUSE");
                    	break;
                	}
            
			case 4: {
						bool busca = buscaListaDupla(lista);
                    	if(busca)
                        	printf("Codigo encontrado!\n");
                    	else
                        	printf("Codigo nao encontrado!\n");
                    	system("PAUSE");
                    	break;
                	}
                	
            case 5: {
						printf("O programa sera encerrado...\n\n");
						break;
					}
					
			default: printf("Opcao invalida!\n");          
        }
        
    }while(opcao != 5);
    
    system("PAUSE");
    return 0;
}


void insereListaDupla(no **lista) {
     no *novo = (no*) malloc(sizeof(no));
     
     if(novo != NULL) {
         printf("Digite o codigo do produto: ");
         scanf("%d", &novo->codigo);
         if(*lista == NULL) {
             *lista = novo;
             novo->prox = NULL;
             novo->ant = NULL;
         }
         else {
             novo->prox = *lista;
             novo->ant = NULL;
             (*lista)->ant = novo;
             *lista = novo;             
         }
     }
     else {
         printf("Sem area para insercao! Heap overflow!\n\n"); 
     }
     
     return;
}

int removeListaDupla(no **lista) {
	int codigo;
	
	printf("Informe o codigo a ser removido: ");
    scanf("%d", &codigo);
	
	// Se lista estiver vazia
	if(*lista == NULL)
        return -1;
    
    // Se a lista tiver um elemento e este for o elemento escolhido para remoção
    if( ((*lista)->codigo == codigo) && ((*lista)->prox == NULL) ){
    	free(*lista);
    	*lista = NULL;
    	return codigo;
	}
	
	no *temp = (*lista);
	
	// Se a lista tiver mais de um elemento e o elemento a ser removido for o primeiro
	if(temp->codigo == codigo) {
		(temp->prox)->ant = NULL;
		(*lista) = (*lista)->prox;
		free(temp);
		return codigo;
	}
	
	// Se a lista tiver mais de um elemento e o elemento a ser removido for intermediário
	while(temp->prox) {
		if(temp->codigo == codigo) {
			(temp->prox)->ant = temp->ant;
			(temp->ant)->prox = temp->prox;
			free(temp);
			return codigo;
		}
		temp = temp->prox;
	}
	
	// Se a lista tiver mais de um elemento e o elemento a ser removido for o último
	if(temp->codigo == codigo) {
		(temp->ant)->prox = NULL;
		free(temp);
		return codigo;
	}
	
	return 0;
}

void imprimeListaDupla(no *lista){
    printf("Lista atual: \n\n");
    int i = 1;
    while(lista) {
        printf("%02d. Codigo: %d \n\n", i, lista->codigo);
        lista = lista->prox;
        i++;
    } 
    
    printf("\n");
    
    return;
}

bool buscaListaDupla(no *lista) {
    int codigo;
    
    printf("Informe o codigo a ser buscado: ");
    scanf("%d", &codigo);
    
    if(lista == NULL)
        return false;
    else {
    	while(lista) {
    		if(lista->codigo == codigo)
    			return true;
    		lista = lista->prox;
		}
	}
        
}

int imprimeMenu(){
     int opcao;
     
     do{
         printf("\n\n");
         printf("Escolha uma das opcoes abaixo:\n\n");
         printf("1 - Insere na lista\n");
         printf("2 - Remove na lista\n");
         printf("3 - Imprime lista\n");
         printf("4 - Busca na lista\n");
         printf("5 - Sair\n");
         printf("\nSua opcao: ");
         scanf("%d", &opcao);
         if(opcao < 1 || opcao > 5)
             printf("Opcao invalida!\n");
     }while(opcao < 1 || opcao > 5);
     
     return opcao;
}
