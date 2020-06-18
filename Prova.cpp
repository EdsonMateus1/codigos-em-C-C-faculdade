#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

// definindo a estrutura
struct rom{
	string title;
  	string gender;
	string developers;
	int id;
	int launch;
	int players;
};
typedef struct rom Roms;


int chamaMenu();
void cadastraRoms(map <int, Roms> &biblioteca);
void imprimeCatalogo(map <int, Roms> biblioteca);
void consultaRom(map <int, Roms> biblioteca);
int excluiRom(map <int, Roms> biblioteca);
//void consultaMarca(map <int, Roms> estoque);

int cont_id = 0;

int main(void){
    map <int, Roms> biblioteca;
    
    int escolha;

	do{
		escolha = chamaMenu();
		
		switch(escolha){
			case 1: cadastraRoms(biblioteca);
					break;
					
			case 2: imprimeCatalogo(biblioteca);
					break;
			
			case 3: excluiRom(biblioteca);
					break;
					
			case 4: 
					break;
					
			case 5: consultaRom(biblioteca);
					break;
			
			case 6: cout << "Encerrando o programa..." << endl;
					break;
			
			default: cout << "Opcao invalida!\n" << endl;
		}
		getch();
	}while(escolha != 6);

    return 0;
}

int chamaMenu() {
	system("cls");
	
	int escolha;
	
	cout << "||| Biblioteca de ROMS" << endl;
	cout << endl;
	cout << "1 - Cadastrar Rom" << endl;
	cout << "2 - Imprimir Roms Cadastradas" << endl;
	cout << "3 - Excluir Rom" << endl;
	cout << "4 - Editar Rom" << endl;
	cout << "5 - Consultar Rom" << endl;
	cout << "6 - Finalizar" << endl;
	cout << endl;
	
	cout << "Insira sua opçao: ";
	cin >> escolha;
	
	return escolha;
	
}

void cadastraRoms(map <int, Roms> &biblioteca) {	
	system("cls");
	cin.ignore();
	
	Roms nova;
	
	cout << "\t\t *** CADASTRO NO biblioteca ***" << endl;
    
    
    cout << "Nome do Jogo: ";
    getline(cin, nova.title);
    
    cout << "Desenvolvedora:";
    getline(cin, nova.developers);
    
    cout << "Genero: ";
    getline(cin, nova.gender);
    
    cout << "Ano de Lancamento: ";
    cin >> nova.launch;
    
    cout << "Quantidade de Jogadores: ";
    cin >> nova.players;

    cont_id++;
    
    nova.id = cont_id;
    
    biblioteca[cont_id] = nova;
    
    cout << "Cadastro " << cont_id << " realizado com sucesso!";
    
    return;
}

void imprimeCatalogo(map <int, Roms> biblioteca) {	
	map <int, Roms>::iterator mapIterator;
	
	for(mapIterator = biblioteca.begin(); mapIterator != biblioteca.end(); mapIterator++) {
            cout << "ID: " << mapIterator->second.id << endl << "Nome: " << mapIterator->second.title << endl << "Desenvolvedores: " << mapIterator->second.developers << endl;
            cout << "Genero: " << mapIterator->second.gender << endl << "Jogadores: " << mapIterator->second.players << endl << endl << endl;
        }
};

void consultaRom(map <int, Roms> biblioteca){
	
	int escolha;
	
	
	map <int, Roms>::iterator mapIterator;
	cout << "Insira um ID para ser procurado:";
	cin >> escolha;
	
	if(biblioteca.find(escolha) == biblioteca.end()){
	
	cout << "Codigo nao Encontrado";
		
	}else{
		cout << "ID: " << biblioteca[escolha].id << endl << "Nome: " << biblioteca[escolha].title << endl << "Desenvolvedores: " << biblioteca[escolha].developers << endl;
        cout << "Genero: " << biblioteca[escolha].gender << endl << "Jogadores: " << biblioteca[escolha].players << endl << endl << endl;
	};
	
};

int excluiRom(map <int, Roms> biblioteca){
	
	int escolha;
	
	cout << "Insira um ID para ser excluido:";
	cin >> escolha;
	
	biblioteca.erase(escolha);
		
	if(biblioteca.find(escolha) == biblioteca.end()){
	
	cout << "Codigo nao Encontrado";
		
	}else{
	
	biblioteca.erase(escolha,biblioteca);
	return 0;
	};
	
	
};
	
/*	for(mapIterator = biblioteca.begin(); mapIterator != biblioteca.end(); mapIterator++) {
	
		if(mapIterator->second.id == escolha) {
			cout << "ID: " << mapIterator->second.id << endl << "Nome: " << mapIterator->second.title << endl << "Desenvolvedores: " << mapIterator->second.developers << endl;
            cout << "Genero: " << mapIterator->second.gender << endl << "Jogadores: " << mapIterator->second.players << endl << endl << endl;	
			cout << "Tem certeza que deseja excluir a Rom " << mapIterator->second.title << "?";		
			
			cout << "(1) Sim - (0) Nao";
			cin >> escolha2;
			
			if(escolha == 1 ){
				biblioteca.erase(mapIterator->escolha,mapIterator->second);
			}else{
				return 0;
			};
		};
	};*/

