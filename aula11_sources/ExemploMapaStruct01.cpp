#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

struct Materias{
   string codigo;
   string disciplina;
   int periodo;
};
typedef struct Materias tMaterias;

int main(){
    int chave;
    int i = 1;
    
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
    
    cout << "Informe a chave da disciplina: ";
    cin >> chave;
    cin.ignore();
    
    /* Se achou a chave pesquisada, escreve Encontrou, caso
    contrario Nao Encontrou */
    
    if(MapaLista.find(chave) == MapaLista.end()) {
        cout << "Nao Encontrado!" << endl;
        
        cout << "Informe o codigo: ";
        getline(cin, mat.codigo);
        
        cout << "Informe o nome: ";
        getline(cin, mat.disciplina);
        
        cout << "Informe o periodo: ";
        cin >> mat.periodo;
        
        MapaLista[chave] = mat;
    }
    else {
        cout << "Encontrado!" << endl;
        cout << "Codigo.: " << MapaLista[chave].codigo << endl;
        cout << "Nome...: " << MapaLista[chave].disciplina << endl;
        cout << "Periodo: " << MapaLista[chave].periodo << endl;
    }
    
    
    system("PAUSE");
    return 0;
}
