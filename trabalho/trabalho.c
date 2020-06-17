#include <stdio.h>

int main (void){
    char string [] = "www.google.com";

    for (size_t i = 0; i < sizeof(string); i++)
    {
        printf("%c",string[i]);
        if(string[i] == '.'){
            while(string[i] != '.'){
                for (size_t i = 0; i < sizeof(string); i++)
                {
                    printf("%c",string[i]);
                }
                
            }
        }
    }
    

}