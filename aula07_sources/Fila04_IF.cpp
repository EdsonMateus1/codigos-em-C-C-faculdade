#include <stdio.h>
#include <stdlib.h>

#define TAMMAX 10
// Definição da Estrutura
// Definindo um novo tipo de dado e criando um alias (apelido)
// typedef struct tipoCliente define a estrutura
// cliente define o apelido
typedef struct tipoCliente cliente;
// As linhas abaixo criam um novo tipo de dado
struct tipoCliente {
	// Possui um int chamado código
    int codigo;
    // Possui um float chamado valor
    float valor;
    // Possui um ponteiro chamado prox que aponta para um tipo struct tipoCliente
    struct tipoCliente *prox;
};

// Variável global para controlar o tamanho da fila
int tam;

// Assinaturas das funções
// Assinatura é composta de <tipo_de_retorno> <nome_da_função> (<parametros>)
void inicializa(cliente *inicio, cliente *fim);
void insere(cliente **inicio, cliente **fim);
void imprime(cliente *inicio);
void consome(cliente **inicio, cliente **fim);

// Função principal do programa
// Onde começa a execução
int main(){
	// Os dois ponteiros abaixo controlam o início e fim da minha fila
	// Cria uma variável ponteiro do tipo cliente chamada inicio e inicializa com NULL
    cliente *inicio = NULL;
    // Cria uma variável ponteiro do tipo cliente chamada fim e inicializa com NULL
	cliente *fim = NULL;
	// Variável que controla se serão inseridos mais clientes
	// Armazena S ou N
    char maisum;
    
    // Chamada da função inicializa para inicializar a minha fila
    // Os parâmetros são os ponteiros inicio e fim
    inicializa(inicio, fim);
    
    // Estrutua de repetição que insere clientes na fila
    do{
    	// Chamada da função insere
    	// Os parâmetros são os endereços dos ponteiros inicio e fim
        insere(&inicio, &fim);
        // Pergunta se quer inserir mais um
        printf("Inserir mais um (S/N)? ");
        // Dá uma descarga no buffer do teclado
        // Ou seja, limpa a entrada de dados de possíveis sujeiras
		fflush(stdin);
		// Lê a opção para a variável maisum do tipo char
        scanf("%c", &maisum);
    }while(maisum == 'S' || maisum == 's');
    
    // Chama função imprime passando o endereço do primeiro cliente
    imprime(inicio);
    
    // Chama a função de consuir da fila
    // Ou seja, remover quem está na primeira posição
    consome(&inicio, &fim);
    imprime(inicio);
    consome(&inicio, &fim);
    imprime(inicio);
    consome(&inicio, &fim);
    imprime(inicio);
    
    system("PAUSE");
    return 0;
}

// Implementação da função inicializa
void inicializa(cliente *inicio, cliente *fim) {
	// Inicializa valor da variável global tam com 0 (zero)
    tam = 0;
    // Imprime informações na tela
    printf("Fila inicializada!\n");
    // Imprime para onde inicio aponta
    printf("Inicio.: %d\n", inicio);
    // Imprime para onde fim aponta
	printf("Fim....: %d\n", fim);
    // Imprime tamanho da fila (0)
	printf("Tamanho: %d\n", tam);
    printf("\n");
}

// Implementação da função inicializa
void insere(cliente **inicio, cliente **fim){
	if(tam == TAMMAX) {
		printf("Fila lotada. Volte logo :) \n");
		return;
	}
	
	printf("\n");
	// Aloca dinamicamente na memória o espaço de uma variável cliente
	// Reserva essa área
	// Passa o endereço da área reservada para o ponteiro *novo
    cliente *novo = (cliente *)malloc(sizeof(cliente));
    // Verifica se conseguiu alocar um espaço
    // if(novo) é a mesma coisa que if(novo != NULL)
    if(novo) {
    	// Solicita a entrada do código do novo cliente
        printf("Novo codigo: ");
        // Armazena o código na área alocada
        scanf("%d", &novo->codigo);
        // Solicita a entrada do valor do novo cliente
        printf("Novo valor: ");
        // Armazena o valor na área alocada
        scanf("%f", &novo->valor);
        // Aponta o cliente atual para NULL
        novo->prox = NULL;
        // Verifica se o inicio e o fim da fila são NULL
        // Ou seja a fila está vazia
        // Esse cliente é o primeiro a entrar na fila
        if(!(*inicio) && !(*fim)) {
            // Faz inicio apontar para o novo cliente alocado
			*inicio = novo;
			// Faz fim apontar para o novo cliente alocado
            *fim = novo;
        }
        // Se desviar para cá, significa que já existe alguém na fila
        // Quantos? Não sei...
        else {
        	// Cria um ponteiro auxiliar para receber o primeiro cliente da fila
            cliente *aux = (*inicio);
            // Verifica se o cliente aponta para alguém
            // Se aponta para NULL, ele é o último
            // Se aponta para um endereço, não é o último
            while(aux->prox != NULL)
                aux = aux->prox;
            // Faz o último cliente apontar para o cliente recém chegado
            aux->prox = novo;     
            // Faz o fim da fila apontar para o recém chegado
            *fim = novo;
        }
        // Incrementa +1 no tamanho da variável que controla o tamanho da fila
        tam++;
    }   
    printf("\n");
    return;
}
// Implementação da função de impressão da fila
void imprime(cliente *inicio){
    printf("\n");
    // IMprime o tamanho atual da fila
    // Está armazenado na variável global TAM
    printf("Tamanho da lista: %d\n", tam);
    // Cria variável local pos, para imprimir as posições da fila
    // Inicializa com 1 pois é a primeira posição
    int pos = 1;
    // while(inicio) é a mesma coisa que while(inicio != NULL)
    while(inicio) {
        printf("\n");
        // Imprime valor atual de pos
        printf("Posicao.: %d\n", pos);
        // Imprime o código do cliente atual
        printf("Codigo..: %d\n", inicio->codigo);
        // Imprime o valor do cliente atual
        printf("Valor...: %.2f\n", inicio->valor);
        // Incrementa posição
		pos++;
		// Caminha para o próximo cliente
        inicio = inicio->prox;
    }
    return;
}

// Implementação da função de consumir a fila
void consome(cliente **inicio, cliente **fim) {
    printf("\n");
    // 
	if(!(*inicio) && !(*fim)) { // if ( (inicio == NULL) && (fim == NULL) )
        printf("Fila vazia. Impossivel remover!\n");
        return;
    }
    
    // Crio um ponteior auxiliar para apontar para inicio
    cliente *aux = *inicio;
    // Verifica se inicio e fim apontam para o mesmo cliente
    // Se sim, só existe um cliente na fila
	if(*inicio == *fim) {
		// Faz inicio apontar para NULL
        *inicio = NULL;
        // Faz fim apontar para NULL
		*fim = NULL;
        // Libera aux da memória (que era o primeiro e único cliente na fila)
		free(aux);
        // Diminui 1 no tamanho da fila
		tam--;
        return;
    }
    
    // Se o if anterior for FALSE
    // Faz o iníio apontar para o segundo cliente
    // É o mesmo que inicio apontar para quem o primeiro clinte aponta
    *inicio = (*inicio)->prox;
    // Libera o primeiro lciente da memório (fila)
    free(aux);
    //Substrai 1 do tamanho da fila
    tam--;  
    return;
}
