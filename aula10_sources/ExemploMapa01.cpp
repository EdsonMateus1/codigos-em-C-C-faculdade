#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

int main(void){
    // Criação da estrutura do mapa
    map <string,int> mapa;
    
    // Armazena na estrutura de mapas
    mapa["brasil"] = 5;
    mapa["argentina"] = 2;
    mapa["inglaterra"] = 1;
    mapa["alemanha"] = 4;
    
    // Testa se há um valor    
    if(mapa["uruguai"])
        printf("%d\n",mapa["uruguai"]);
    
    // Cria o iterator para percorrer o mapa
    map<string,int>::iterator mapit;
    
    // Percorre e imprime o mapa
    for(mapit = mapa.begin(); mapit != mapa.end(); mapit++)
        cout << mapit->first << " " << mapit->second << endl;
    
    system("PAUSE");
    
    return 0;
}
