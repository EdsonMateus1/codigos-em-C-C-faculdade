#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int  MAX =  89;

typedef struct veiculo
{
    int placa;
    int primayKey;
    int *prox;
} Veiculo;

typedef struct hashTable
{
    int qtde;
    int TABLE_SIZE;
    struct veiculo **hashItens;
} HashTable;
HashTable *criarHash(int TABLE_SIZE);
int funcionHash(int key, int tam);
int insereListaDupla(Veiculo **lista);
int insereHash(HashTable *hash, Veiculo **veiculo);

int main(void)
{
    Veiculo *veiculo = NULL;
    HashTable *hash = NULL;
    hash = criarHash(MAX);
    insereHash(hash,&veiculo);

    system("PAUSE");
}

HashTable *criarHash(int TABLE_SIZE)
{
    HashTable *hash = (HashTable *)malloc(sizeof(HashTable));
    if (hash != NULL)
    {
        hash->TABLE_SIZE = TABLE_SIZE;
        hash->hashItens = (Veiculo **)malloc(TABLE_SIZE * sizeof(Veiculo));
        if (hash->hashItens == NULL)
        {
            free(hash);
            return NULL;
        }
        hash->qtde = 0;
        for (int i = 0; i < hash->TABLE_SIZE; i++)
        {
            hash->hashItens[i] = NULL;
        }
    }
    return hash;
}

int funcionHash(int key, int tam)
{
    int chave = (key % tam);
    return chave;
}

int insereListaDupla(Veiculo **lista)
{
    Veiculo *novo = (Veiculo *)malloc(sizeof(Veiculo));

    if (novo != NULL)
    {
        printf("Digite o codigo do produto: ");
        scanf("%d", &novo->placa);
        if (*lista == NULL)
        {
            *lista = novo;
            novo->prox = NULL;
        }
        else
        {
            novo->prox = *lista;
            *lista = novo;
        }
    }
    else
    {
        printf("Sem area para insercao! Heap overflow!\n\n");
    }
    srand(time(NULL));
    int key = 0;
    for (int i=0; i < 10; i++)
  {
     key = (key +  rand() % 89) ;
  }
    return key;

}

int insereHash(HashTable *hash, Veiculo **veiculo)
{
    if (hash == NULL || hash->qtde == hash->TABLE_SIZE)
    {
        return 0;
    }
    int key = insereListaDupla(&veiculo);
    printf("%dkey\n",key);
    int pos = funcionHash(key, hash->TABLE_SIZE);
    printf("%dpos\n",pos);

    Veiculo *novo = (Veiculo *)malloc(sizeof(Veiculo));
    novo = *veiculo;
    hash->hashItens[pos] = novo;
    hash->qtde++;

    return 1;
}
