#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

int main(){
    // Criação da estrutura do mapa
    map <int, string> mapa2;
    
    int chave;
    
    // Armazena na estrutura de mapas
    mapa2[1] = "Brasil";
    mapa2[2] = "Alemanha";
    mapa2[3] = "Argentina";
    mapa2[4] = "Inglaterra";
    
    cout << "Digite a chave: ";
    cin >> chave;
    
    // Procura pela chave
    if(mapa2.find(chave) == mapa2.end())
        cout << "Chave nao encontrada!" << endl;
    else
        cout << "Chave " << chave << " encontrada! Seu valor e " << mapa2[chave] << endl;
    
    system("PAUSE");
    
    return 0;
}
