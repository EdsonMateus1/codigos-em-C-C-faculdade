#include <stdio.h>



int main(void){
    int valor = 10 , *p1,**p2;
    p1 = &valor;
    p2 = &p1;

    printf("valor %d\t",valor);
    printf("poiter 1 %d\t",p1);
    printf("ponter 2  %d\t",*p2);
} 