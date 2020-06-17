#include <stdio.h>
#include <stdlib.h>

typedef struct list
{   
    int info ;
    struct list *prox;
}List;

List *criar_no();
List *insert_inicio(List *list , int info);
List *insert_fim (List *list, int info);
int remover_fim(List *list);
void imprime_lista(List *list);

int main (){
    List  *list = NULL;
  
    //list = insert_inicio(list,30); 
    //list = insert_inicio(list,40); 
    list = insert_fim(list,80);
    list = insert_inicio(list,50); 
    list = insert_fim(list,90);
    list= insert_inicio(list,60); 
   
    //remover_fim(list);
    imprime_lista(list);
    printf(" lista %d",list->info);

    return 0 ; 
}

List *criar_no(){
    List *novoNo = (List*) malloc(sizeof(List));
    //novoNo->prox = NULL;
    //novoNo->info = NULL;
   // printf("dentro do no  %d\n",&novoNo);
    return novoNo;
}

List *insert_inicio(List *list , int info){
    List *novoNo = criar_no();
    novoNo->info = info;
    novoNo->prox = list;
    return novoNo;
   
}
List *insert_fim (List *list, int info){
    if(list == NULL ){
        List *novoNo = criar_no();
        novoNo->info = info;
        novoNo->prox = list;
        return novoNo;
        
    }
    else{
        List *aux = list;
        while (aux->prox != NULL)
        {
           aux = aux->prox;
          // printf(" inserir no fim %p \n",aux->prox);
        }
       List *novoNo =criar_no();
       novoNo->info = info;
       novoNo->prox = NULL;
       aux->prox = novoNo; 
       return list;
    }
}

void imprime_lista(List *list){
    List *aux = list;
    while (aux != NULL)
    {
        printf(" conteudo :%d  ponteiro %p lista :%p\n",aux->info,aux->prox,list );
        aux = aux->prox;
    }
}

int remover_fim(List *list){
    List *ant , *atual = list;
    while (atual->prox != NULL)
    {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL)
    {
        list = atual->prox;
    }
    else
    {
        ant->prox = atual->prox;
        free(atual);
    }
    return 0;
}
