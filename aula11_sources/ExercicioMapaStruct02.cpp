#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>

using namespace std;

struct Materias{
   string codigo;
   string disciplina;
   int periodo;
};
typedef struct Materias tMaterias;

int main(){
    string disciplina;
    int i = 1;
    int j;
    
    map<int, tMaterias> MapaLista;
    
    tMaterias mat;
    
    mat.codigo = "103";
    mat.disciplina = "ESTRUTURA DE DADOS";
    mat.periodo = 3;
    MapaLista[i] = mat;
    i++;
    
    mat.codigo = "203";
    mat.disciplina = "ESTRUTURA DE DADOS AVANCADO";
    mat.periodo = 4;
    MapaLista[i] = mat;
    
    i++;
    mat.codigo = "303";
    mat.disciplina = "PROGRAMACAO ORIENTADA A OBJETOS";
    mat.periodo = 5;
    MapaLista[i] = mat;
    
    cout << "Informe o nome da disciplina: ";
    getline(cin, disciplina);

    int encontrado = 0;
    
    for(j = 1; j <= MapaLista.size(); j++) {
		if((MapaLista[j].disciplina).find(disciplina) != -1){
            cout << "Encontrada!" << endl;
            cout << MapaLista[j].codigo << endl;
            cout << MapaLista[j].disciplina << endl;
            cout << MapaLista[j].periodo << endl;
            encontrado++;
        }
    }
    
    if(encontrado == 0) {
        cout << "Nao Encontrado!" << endl;
        
        cout << "Informe o codigo: ";
        getline(cin, mat.codigo);
        
        cout << "Informe o nome: ";
        getline(cin, mat.disciplina);
        
        cout << "Informe o periodo: ";
        cin >> mat.periodo;
        
        MapaLista[j] = mat;
    }    
    
    system("PAUSE");
    return 0;
}
