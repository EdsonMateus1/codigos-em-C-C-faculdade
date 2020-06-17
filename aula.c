#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

// Defini��o da Estrutura N�
// Aten��o para a cria��o do novo membro da estrutura:
// O ponteiro para o n� anterior
typedef struct tipo_no no;
struct tipo_no {
    int codigo;
    struct tipo_no *prox;
    struct tipo_no *ant;
};

void insereListaDupla(no **lista);
void imprimeListaDupla(no *lista);
bool buscaListaDupla(no *lista);
int imprimeMenu();

int main(){
    int opcao;
    no *lista = NULL;

    
    do{
        opcao = imprimeMenu();
        
        switch(opcao){
            case 1: {
						insereListaDupla(&lista);
                    	break;
                	}
            case 2: // todo
                    break;
                    
            case 3: {
						imprimeListaDupla(lista);
                    	break;
                	}
            
			case 4: {
						bool busca = buscaListaDupla(lista);
                    	if(busca)
                        	printf("Codigo encontrado!\n");
                    	else
                        	printf("Codigo nao encontrado!\n");
                    
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
