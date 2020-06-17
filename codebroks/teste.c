#include <stdio.h>

typedef struct list
{
    int info ;
    struct list *prox;
}List;



int main (){
    List *list = NULL;
    printf("%d %p ",list->info,list->prox);

    return 0 ;
}

List *criar_no(){
    List *novoNo = (List*) malloc(sizeof(List));
    return novoNo;
}
