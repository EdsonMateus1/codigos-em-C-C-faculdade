#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

int main(){
    // Criação da estrutura do mapa
    map <int, string> mapa2;
    
    // Armazena na estrutura de mapas
    mapa2[1] = "Brasil";
    mapa2[2] = "Alemanha";
    mapa2[3] = "Argentina";
    mapa2[4] = "Inglaterra";
    
    // Cria o iterator para percorrer o mapa
    map<int, string>::iterator mapit2;
    cout << "Impressao sem exclusao." << endl;
    // Impressão do mapa original
    for(mapit2 = mapa2.begin(); mapit2 != mapa2.end(); mapit2++)
        cout << mapit2->first << " " << mapit2->second << endl;
    
    // Exclusão da chave 2
    mapa2.erase(2);
    
    cout << "Impressao apos exclusao." << endl;
    // Impressão após exclusão
    for(mapit2 = mapa2.begin(); mapit2 != mapa2.end(); mapit2++)
        cout << mapit2->first << " " << mapit2->second << endl;
    
    system("PAUSE");
    
    return 0;
}
