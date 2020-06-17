#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Defini��o da Estrutura
typedef struct tipoNo no;
struct tipoNo
{
    int codigo;
    struct tipoNo *prox;
};

int tam;

void inicializa(no *pilha, no *topo);
void push(no **pilha, no **topo);
void imprime(no *pilha);
void pop(no **pilha, no **topo);
void desempilhaTudo(no **pilha, no **topo);

int main()
{
    no *pilha = NULL;
    no *topo = NULL;
    char maisum;

    inicializa(pilha, topo);

    int op;
    do
    {
        printf("para imprimir 1 \n");
        printf("para pop remover 2 \n");
        printf("para desempilhar 3 \n");
        printf("para sair 4  \n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            imprime(pilha);
            break;

        case 2:
            pop(&pilha, &topo);
            break;
        case 3:
            desempilhaTudo(&pilha, &topo);
            break;
        case 4:
            do
            {
                push(&pilha, &topo);
                printf("Inserir mais um (S/N)? ");
                fflush(stdin);
                scanf("%c", &maisum);
            } while (maisum == 'S' || maisum == 's');
            break;

        default:
            break;
        }
    } while (op != 5);

    system("PAUSE");
    return 0;
}

void inicializa(no *pilha, no *topo)
{
    tam = 0;
    printf("Pilha inicializada!\n");
    printf("Inicio.: %d\n", pilha);
    printf("Topo...: %d\n", topo);
    printf("Tamanho: %d\n", tam);
}

void push(no **pilha, no **topo)
{
    no *novo = (no *)malloc(sizeof(no));
    if (tam == MAX)
    {
        printf("Pilha cheia!\n");
        return;
    }

    if (!novo)
    {
        printf("Heap overflow!\n");
        return;
    }

    if (novo)
    {
        printf("Novo codigo: ");
        scanf("%d", &novo->codigo);
        novo->prox = NULL;
        if (!(*pilha))
        {
            *pilha = novo;
            *topo = novo;
        }
        else
        {

            (*topo)->prox = novo;
            *topo = novo;

            tam++;
        }
    }
    return;
}

void imprime(no *pilha)
{
    printf("Tamanho da pilha: %d\n", tam);
    int vetor[tam];
    int i;
    for (i = 0; i < tam; i++)
    {
        vetor[i] = pilha->codigo;
        pilha = pilha->prox;
    }
    printf("\nPilha na ordem de push: ");
    for (i = 0; i < tam; i++)
        printf("%d ", vetor[i]);

    printf("\nPilha na ordem de pop: ");
    for (i = tam - 1; i >= 0; i--)
        printf("%d ", vetor[i]);
    printf("\n\n");
    return;
}

void pop(no **pilha, no **topo)
{
    printf("\n");
    if (!(*pilha) && !(*topo))
    {
        printf("Pilha vazia. Impossivel remover!\n");
        return;
    }

    no *aux = *topo;
    if (*pilha == *topo)
    {
        *pilha = NULL;
        *topo = NULL;
        free(aux);
        tam--;
        return;
    }

    //while(aux->prox != *topo)
    //  aux = aux->pro

    *topo = aux->prox;
    free(aux);

    tam--;
    return;
}

void desempilhaTudo(no **pilha, no **topo)
{
    int i;
    int aux = tam;
    for (i = 1; i <= aux; i++)
    {
        pop(pilha, topo);
        imprime(*pilha);
    }
    return;
}
