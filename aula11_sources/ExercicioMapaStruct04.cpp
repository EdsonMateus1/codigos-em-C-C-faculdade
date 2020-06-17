#include <iostream>
#include <map>
#include <string>
#include <stdlib.h>
#include <conio.h>

using namespace std;

// Defini��o de tipo
struct peca{
   string codigo;
   string descricao;
   string marca;
   float preco;
};
typedef struct peca tPeca;

// Assinatura das fun��es
int menu();
void cadastra(map <int, tPeca> &estoque);
void consulta(map <int, tPeca> estoque);
void consultaCodigo(map <int, tPeca> estoque);
void consultaDescricao(map <int, tPeca> estoque);
void consultaMarca(map <int, tPeca> estoque);

// Vari�veis globais
int pk = 0;

int main(void){
    map <int, tPeca> estoque;
    
    int opcao;

	do{
		opcao = menu();
		
		switch(opcao){
			case 1: cadastra(estoque);
					break;
					
			case 2: consulta(estoque);
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
	
	cout << "\t\t *** LOJAS PC GUSMAO ***" << endl;
	cout << endl;
	cout << "1 - Cadastro de Pecas" << endl;
	cout << "2 - Consulta de Pecas" << endl;
	cout << "3 - Cotacao" << endl;
	cout << "4 - Finalizar" << endl;
	cout << endl;
	cout << "Sua opcao: ";
	cin >> opcao;
	
	return opcao;
	
}

void cadastra(map<int, tPeca> &estoque) {	
	system("cls");
	cin.ignore();
	
	tPeca nova;
	
	cout << "\t\t *** CADASTRO NO ESTOQUE ***" << endl;
	
	cout << "Codigo.....: ";
    getline(cin, nova.codigo);
    
    cout << "Descricao..: ";
    getline(cin, nova.descricao);
    
    cout << "Marca......: ";
    getline(cin, nova.marca);
    
    cout << "Preco......: R$ ";
    cin >> nova.preco;
    
    pk++;
    
    estoque[pk] = nova;
    
    cout << "Cadastro " << pk << " realizado com sucesso!";
    
    return;
}

void consulta(map <int, tPeca> estoque) {
	system("cls");
	cin.ignore();
	
	int codigoPesquisa;
	
	do{
		cout << "\t\t *** CONSULTA NO ESTOQUE ***" << endl;
		cout << endl;
		cout << "1 - Por codigo" << endl;
		cout << "2 - Por descricao" << endl;
		cout << "3 - Por marca" << endl;
		cout << endl;
		cout << "Sua opcao: ";
		cin >> codigoPesquisa;
	}while(codigoPesquisa < 1 || codigoPesquisa > 3);
	
	cin.ignore();
	
	switch(codigoPesquisa){
		case 1:	consultaCodigo(estoque);
				break;
		case 2: consultaDescricao(estoque);
				break;
		case 3: consultaMarca(estoque);
				break;
	}
	
	return;
}

void consultaCodigo(map <int, tPeca> estoque) {	
	map <int, tPeca>::iterator mapIterator;
	string codigo;
	
	cout << "Codigo: ";
    getline(cin, codigo);

	for(mapIterator = estoque.begin(); mapIterator != estoque.end(); mapIterator++) {
        if(mapIterator->second.codigo == codigo) {
            cout << "<" << mapIterator->second.codigo << "> ";
            cout << mapIterator->second.descricao;
            cout << " (" << mapIterator->second.marca << ") - ";
            cout << "R$ " << mapIterator->second.preco << endl;
            break;                         
        }
    }
    
	return;
}

void consultaDescricao(map <int, tPeca> estoque) {	
	map <int, tPeca>::iterator mapIterator;
	string descricao;
	
	cout << "Descricao: ";
    getline(cin, descricao);
	
	for(mapIterator = estoque.begin(); mapIterator != estoque.end(); mapIterator++) {
        if( (mapIterator->second.descricao).find(descricao) != -1) {
            cout << "<" << mapIterator->second.codigo << "> ";
            cout << mapIterator->second.descricao;
            cout << " (" << mapIterator->second.marca << ") - ";
            cout << "R$ " << mapIterator->second.preco << endl;
        }
        cout << endl;
    }
    
	return;
}

void consultaMarca(map <int, tPeca> estoque){
	map <int, tPeca>::iterator mapIterator;
	string marca;
	
	cout << "Marca: ";
    cin >> marca;
	
	for(mapIterator = estoque.begin(); mapIterator != estoque.end(); mapIterator++) {
        if( (mapIterator->second.marca).find(marca) != -1) {
            cout << "<" << mapIterator->second.codigo << "> ";
            cout << mapIterator->second.descricao;
            cout << " (" << mapIterator->second.marca << ") - ";
            cout << "R$ " << mapIterator->second.preco << endl;
		}
		cout << endl;
    }
    
	return;
}
