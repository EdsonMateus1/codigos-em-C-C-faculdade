#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

int main(){
    // Criação da estrutura do mapa
    map <int, string> mapa2;
    
    // Armazena na estrutura de mapas
    mapa2[3] = "Argentina";
    mapa2[4] = "Inglaterra";
    mapa2[1] = "Brasil";
    mapa2[2] = "Alemanha";

    // Cria o iterator para percorrer o mapa
    map<int, string>::iterator mapit2;
    
    // Percorre e imprime o mapa
    for(mapit2 = mapa2.begin(); mapit2 != mapa2.end(); mapit2++)
        cout << mapit2->first << " " << mapit2->second << endl;
    
    system("PAUSE");
    
    return 0;
}
