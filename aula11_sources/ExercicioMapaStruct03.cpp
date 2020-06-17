#include <iostream>
#include <map>
#include <string>
#include <stdlib.h>
#include <conio.h>

using namespace std;

// Definição de tipo
struct Materia{
   string codigo;
   string disciplina;
   string semestre;
   int cargaHoraria;
   float notaFinal;
   string status;
};
typedef struct Materia tMateria;

// Assinatura das funções
int menu();
void cadastra(map <int, tMateria> &historico);
void consulta(map <int, tMateria> historico);
void consultaCodigo(map <int, tMateria> historico);
void consultaDisciplina(map <int, tMateria> historico);
void consultaSemestre(map <int, tMateria> historico);

// Variáveis globais
int pk = 0;

int main(void){
    map <int, tMateria> historico;
    
    int opcao;

	do{
		opcao = menu();
		
		switch(opcao){
			case 1: cadastra(historico);
					break;
					
			case 2: consulta(historico);
					break;
			
			case 3: cout << "Encerrando o programa..." << endl;
					break;
			
			default: cout << "Opcao invalida!\n" << endl;
		}
		getch();
	}while(opcao != 3);

    return 0;
}

int menu() {
	system("cls");
	
	int opcao;
	
	cout << "\t\t *** CADASTRO DE HISTORICO ***" << endl;
	cout << endl;
	cout << "1 - Cadastro de Disciplinas" << endl;
	cout << "2 - Consulta de Disciplinas" << endl;
	cout << "3 - Finalizar" << endl;
	cout << endl;
	cout << "Sua opcao: ";
	cin >> opcao;
	
	return opcao;
	
}

void cadastra(map<int, tMateria> &historico) {	
	system("cls");
	cin.ignore();
	
	tMateria novo;
	
	cout << "\t\t *** CADASTRO NO HISTORICO ***" << endl;
	
	cout << "Codigo....: ";
    getline(cin, novo.codigo);
    
    cout << "Nome......: ";
    getline(cin, novo.disciplina);
    
    cout << "Semestre...: ";
    getline(cin, novo.semestre);
    
    cout << "CH........: ";
    cin >> novo.cargaHoraria;
    
    cout << "Nota......: ";
    cin >> novo.notaFinal;
    
    cout << "Status....: ";
    getline(cin, novo.status);
    
    pk++;
    
    historico[pk] = novo;
    
    cout << "Cadastro " << pk << " realizado com sucesso!";
    
    return;
}

void consulta(map <int, tMateria> historico) {
	system("cls");
	cin.ignore();
	
	int codigoPesquisa;
	
	do{
		cout << "\t\t *** CONSULTA NO HISTORICO ***" << endl;
		cout << endl;
		cout << "1 - Por codigo" << endl;
		cout << "2 - Por disciplina" << endl;
		cout << "3 - Por semestre" << endl;
		cout << endl;
		cout << "Sua opcao: ";
		cin >> codigoPesquisa;
	}while(codigoPesquisa < 1 || codigoPesquisa > 3);
	
	cin.ignore();
	
	switch(codigoPesquisa){
		case 1:	consultaCodigo(historico);
				break;
		case 2: consultaDisciplina(historico);
				break;
		case 3: consultaSemestre(historico);
				break;
	}
	
	getch();
	
	return;
}

void consultaCodigo(map <int, tMateria> historico) {	
	map <int, tMateria>::iterator mapIterator;
	string codigo;
	
	cout << "Codigo: ";
    getline(cin, codigo);

	for(mapIterator = historico.begin(); mapIterator != historico.end(); mapIterator++) {
        if(mapIterator->second.codigo == codigo) {
            cout << "Codigo.....: " << mapIterator->second.codigo << endl;
            cout << "Disciplina.: " << mapIterator->second.disciplina << endl;
            cout << "Semestre...: " << mapIterator->second.semestre << endl;
            cout << "CH.........: " << mapIterator->second.cargaHoraria << endl;;                         
        	cout << "Nota Final.: " << mapIterator->second.notaFinal << endl;
        	cout << "Status.....: " << mapIterator->second.status << endl;
            break;                         
        }
    }
    
	return;
}

void consultaDisciplina(map <int, tMateria> historico) {	
	map <int, tMateria>::iterator mapIterator;
	string disciplina;
	
	cout << "Disciplina: ";
    getline(cin, disciplina);
	
	for(mapIterator = historico.begin(); mapIterator != historico.end(); mapIterator++) {
        if( (mapIterator->second.disciplina).find(disciplina) != -1) {
            cout << "Codigo.....: " << mapIterator->second.codigo << endl;
            cout << "Disciplina.: " << mapIterator->second.disciplina << endl;
            cout << "Semestre...: " << mapIterator->second.semestre << endl;
            cout << "CH.........: " << mapIterator->second.cargaHoraria << endl;;                         
        	cout << "Nota Final.: " << mapIterator->second.notaFinal << endl;
        	cout << "Status.....: " << mapIterator->second.status << endl;
        }
        cout << endl;
    }
    
	return;
}

void consultaSemestre(map <int, tMateria> historico){
	map <int, tMateria>::iterator mapIterator;
	string semestre;
	
	cout << "Semestre: ";
    cin >> semestre;
	
	for(mapIterator = historico.begin(); mapIterator != historico.end(); mapIterator++) {
        if( (mapIterator->second.semestre).find(semestre) != -1) {
            cout << "Codigo.....: " << mapIterator->second.codigo << endl;
            cout << "Disciplina.: " << mapIterator->second.disciplina << endl;
            cout << "Semestre...: " << mapIterator->second.semestre << endl;
            cout << "CH.........: " << mapIterator->second.cargaHoraria << endl;;                         
        	cout << "Nota Final.: " << mapIterator->second.notaFinal << endl;
        	cout << "Status.....: " << mapIterator->second.status << endl;
		}
		cout << endl;
    }
    
	return;
}
