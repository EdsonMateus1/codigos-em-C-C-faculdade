#include <stdlib.h>
#include <stdio.h>

typedef struct listDupla
{
    int info;
    struct listDupla *prox;
    struct listDupla *ant;
}ListDupla;

ListDupla *criar_no();
ListDupla *inser_inicio(ListDupla *list);
ListDupla *insert_fim(ListDupla *list);
void imprimir_lista(ListDupla *list);
ListDupla *remover_fim(ListDupla *list);
ListDupla *remover_inico(ListDupla *list);
int main()
{
    ListDupla *list = NULL;
    //printf("%p\n",list);
    //inser_inicio(list,10);
    //list = insert_fim(list,20);
    list = inser_inicio(list);
    list = insert_fim(list);
    //list = remover_inico(list);
    list = inser_inicio(list);
    //list = insert_fim(list,10);
    //list = remover_fim(list);
    imprimir_lista(list);
    system("PAUSE");
    return 0;
};

ListDupla *criar_no()
{
    ListDupla *novoNo = (ListDupla *)malloc(sizeof(ListDupla));
    return novoNo;
};

ListDupla *inser_inicio(ListDupla *list)
{   ListDupla *novoNo = criar_no();
    printf("digite o conteudo a ser inserido no comeco da lista : ");
    scanf("%d",&novoNo->info);
    if (list == NULL)
    {
        list = novoNo;
        novoNo->prox = NULL;
        novoNo->ant = NULL;
        return novoNo;
    }
    else
    {
        novoNo->prox = list;
        novoNo->ant = NULL;
        list->ant = novoNo;
        return novoNo;
    }
};

ListDupla *insert_fim(ListDupla *list)
{   ListDupla *novoNo = criar_no();
    printf("digite o conteudo a ser inserido no final da lista : ");
    scanf("%d",&novoNo->info);
    if (list == NULL)
    {
        novoNo->prox = NULL;
        novoNo->ant = NULL;
        return novoNo;
    }
    else
    {
        ListDupla *aux = list;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novoNo;
        novoNo->ant = aux;
        novoNo->prox = NULL;
        return list;
    }
};

void imprimir_lista(ListDupla *list)
{
    ListDupla *aux = list;
    while (aux != NULL)
    {
        printf("conteudo :%d  proximo %p anterior %p \n",aux->info, aux->prox, aux->ant);
        aux = aux->prox;
    }
};

ListDupla *remover_fim(ListDupla *list)
{
    ListDupla *aux = list;
    while (aux->prox != NULL)
    
        aux = aux->prox;
    
    if (aux->ant == NULL)
    
        list = aux->prox;
    
    else
    
        (aux->ant)->prox = NULL;
    printf("elemento removido do final : \n");
    free(aux);
    return list;
};

ListDupla *remover_inico(ListDupla *list)
{
    if (list == NULL)
        return 0;

    ListDupla *no = list;
    list = no->prox;
    if (no->prox != NULL)
    {

        no->prox->ant = NULL;
        free(no);
        return list;
    }
};

ListDupla *remover_conteudo(ListDupla *list, int conteudo){
    ListDupla *aux = list;
    
    while (aux->info != conteudo)
    {
        
    }
    
}
