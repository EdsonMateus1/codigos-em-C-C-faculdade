#include <stdio.h>
#include <stdlib.h>

#define TAMMAX 10
// Defini��o da Estrutura
// Definindo um novo tipo de dado e criando um alias (apelido)
// typedef struct tipoCliente define a estrutura
// cliente define o apelido
typedef struct tipoCliente cliente;
// As linhas abaixo criam um novo tipo de dado
struct tipoCliente {
	// Possui um int chamado c�digo
    int codigo;
    // Possui um float chamado valor
    float valor;
    // Possui um ponteiro chamado prox que aponta para um tipo struct tipoCliente
    struct tipoCliente *prox;
};

// Vari�vel global para controlar o tamanho da fila
int tam;

// Assinaturas das fun��es
// Assinatura � composta de <tipo_de_retorno> <nome_da_fun��o> (<parametros>)
void inicializa(cliente *inicio, cliente *fim);
void insere(cliente **inicio, cliente **fim);
void imprime(cliente *inicio);
void consome(cliente **inicio, cliente **fim);

// Fun��o principal do programa
// Onde come�a a execu��o
int main(){
	// Os dois ponteiros abaixo controlam o in�cio e fim da minha fila
	// Cria uma vari�vel ponteiro do tipo cliente chamada inicio e inicializa com NULL
    cliente *inicio = NULL;
    // Cria uma vari�vel ponteiro do tipo cliente chamada fim e inicializa com NULL
	cliente *fim = NULL;
	// Vari�vel que controla se ser�o inseridos mais clientes
	// Armazena S ou N
    char maisum;
    
    // Chamada da fun��o inicializa para inicializar a minha fila
    // Os par�metros s�o os ponteiros inicio e fim
    inicializa(inicio, fim);
    
    // Estrutua de repeti��o que insere clientes na fila
    do{
    	// Chamada da fun��o insere
    	// Os par�metros s�o os endere�os dos ponteiros inicio e fim
        insere(&inicio, &fim);
        // Pergunta se quer inserir mais um
        printf("Inserir mais um (S/N)? ");
        // D� uma descarga no buffer do teclado
        // Ou seja, limpa a entrada de dados de poss�veis sujeiras
		fflush(stdin);
		// L� a op��o para a vari�vel maisum do tipo char
        scanf("%c", &maisum);
    }while(maisum == 'S' || maisum == 's');
    
    // Chama fun��o imprime passando o endere�o do primeiro cliente
    imprime(inicio);
    
    // Chama a fun��o de consuir da fila
    // Ou seja, remover quem est� na primeira posi��o
    consome(&inicio, &fim);
    imprime(inicio);
    consome(&inicio, &fim);
    imprime(inicio);
    consome(&inicio, &fim);
    imprime(inicio);
    
    system("PAUSE");
    return 0;
}

// Implementa��o da fun��o inicializa
void inicializa(cliente *inicio, cliente *fim) {
	// Inicializa valor da vari�vel global tam com 0 (zero)
    tam = 0;
    // Imprime informa��es na tela
    printf("Fila inicializada!\n");
    // Imprime para onde inicio aponta
    printf("Inicio.: %d\n", inicio);
    // Imprime para onde fim aponta
	printf("Fim....: %d\n", fim);
    // Imprime tamanho da fila (0)
	printf("Tamanho: %d\n", tam);
    printf("\n");
}

// Implementa��o da fun��o inicializa
void insere(cliente **inicio, cliente **fim){
	if(tam == TAMMAX) {
		printf("Fila lotada. Volte logo :) \n");
		return;
	}
	
	printf("\n");
	// Aloca dinamicamente na mem�ria o espa�o de uma vari�vel cliente
	// Reserva essa �rea
	// Passa o endere�o da �rea reservada para o ponteiro *novo
    cliente *novo = (cliente *)malloc(sizeof(cliente));
    // Verifica se conseguiu alocar um espa�o
    // if(novo) � a mesma coisa que if(novo != NULL)
    if(novo) {
    	// Solicita a entrada do c�digo do novo cliente
        printf("Novo codigo: ");
        // Armazena o c�digo na �rea alocada
        scanf("%d", &novo->codigo);
        // Solicita a entrada do valor do novo cliente
        printf("Novo valor: ");
        // Armazena o valor na �rea alocada
        scanf("%f", &novo->valor);
        // Aponta o cliente atual para NULL
        novo->prox = NULL;
        // Verifica se o inicio e o fim da fila s�o NULL
        // Ou seja a fila est� vazia
        // Esse cliente � o primeiro a entrar na fila
        if(!(*inicio) && !(*fim)) {
            // Faz inicio apontar para o novo cliente alocado
			*inicio = novo;
			// Faz fim apontar para o novo cliente alocado
            *fim = novo;
        }
        // Se desviar para c�, significa que j� existe algu�m na fila
        // Quantos? N�o sei...
        else {
        	// Cria um ponteiro auxiliar para receber o primeiro cliente da fila
            cliente *aux = (*inicio);
            // Verifica se o cliente aponta para algu�m
            // Se aponta para NULL, ele � o �ltimo
            // Se aponta para um endere�o, n�o � o �ltimo
            while(aux->prox != NULL)
                aux = aux->prox;
            // Faz o �ltimo cliente apontar para o cliente rec�m chegado
            aux->prox = novo;     
            // Faz o fim da fila apontar para o rec�m chegado
            *fim = novo;
        }
        // Incrementa +1 no tamanho da vari�vel que controla o tamanho da fila
        tam++;
    }   
    printf("\n");
    return;
}
// Implementa��o da fun��o de impress�o da fila
void imprime(cliente *inicio){
    printf("\n");
    // IMprime o tamanho atual da fila
    // Est� armazenado na vari�vel global TAM
    printf("Tamanho da lista: %d\n", tam);
    // Cria vari�vel local pos, para imprimir as posi��es da fila
    // Inicializa com 1 pois � a primeira posi��o
    int pos = 1;
    // while(inicio) � a mesma coisa que while(inicio != NULL)
    while(inicio) {
        printf("\n");
        // Imprime valor atual de pos
        printf("Posicao.: %d\n", pos);
        // Imprime o c�digo do cliente atual
        printf("Codigo..: %d\n", inicio->codigo);
        // Imprime o valor do cliente atual
        printf("Valor...: %.2f\n", inicio->valor);
        // Incrementa posi��o
		pos++;
		// Caminha para o pr�ximo cliente
        inicio = inicio->prox;
    }
    return;
}

// Implementa��o da fun��o de consumir a fila
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
    // Se sim, s� existe um cliente na fila
	if(*inicio == *fim) {
		// Faz inicio apontar para NULL
        *inicio = NULL;
        // Faz fim apontar para NULL
		*fim = NULL;
        // Libera aux da mem�ria (que era o primeiro e �nico cliente na fila)
		free(aux);
        // Diminui 1 no tamanho da fila
		tam--;
        return;
    }
    
    // Se o if anterior for FALSE
    // Faz o in�io apontar para o segundo cliente
    // � o mesmo que inicio apontar para quem o primeiro clinte aponta
    *inicio = (*inicio)->prox;
    // Libera o primeiro lciente da mem�rio (fila)
    free(aux);
    //Substrai 1 do tamanho da fila
    tam--;  
    return;
}
