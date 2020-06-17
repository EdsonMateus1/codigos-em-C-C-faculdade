#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int info ;
    struct list *prox;
}List;

List *criar_no();
List *insert_inicio(List *list , int info);
void imprime_lista(List *list);
int main (){
    List *list = NULL;

    list = insert_inicio(list,20);
    imprime_lista(list);

    return 0 ;
}

List *criar_no(){
    List *novoNo = (List*) malloc(sizeof(List));
    return novoNo;
}

List *insert_inicio(List *list , int info){
    List *novoNo = criar_no();
    novoNo->info = info;
    if (list == NULL)
    {
        list = novoNo ;
        novoNo->prox = NULL;
    }
    else
    {
        novoNo->prox = list->prox;
        list->prox = novoNo;
    }
    //printf("%d %d",novoNo->prox,list);
    return list;
}

void imprime_lista(List *list){
    List *aux = list;
    while (aux != NULL)
    {
        printf(" conteudo :%d \n ponteiro %p",aux->info,aux->prox );
        aux = aux->prox;
    }
}
