#include <iostream>
#include <map>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <stdio.h>


using namespace std;


struct ROM{
   string titulo;
   string genero;
   string anoLanc;
   string nomeDesen;
   string qtdJog;
   
};
typedef struct ROM tROM;

int menu();
void cadastra(map <int, tROM> &game);
void consulta(map <int, tROM> game);
void consultaTitulo(map <int, tROM> game);
void consultaGenero(map <int, tROM> game);
void consultaLancamento(map <int, tROM> game);
void consultaDesenvolvedora(map <int, tROM> game);
void consultaJogadores(map <int, tROM> game);

int pk = 0;

int main(void){
    map <int, tROM> game;
    
    int opcao;
    

	do{
		opcao = menu();
		
		switch(opcao){
			case 1: cadastra(game);
					break;
					
			case 2: consulta(game);
					break;

			case 3: cout << "Encerrando o programa..." << endl;
					break;
					
			default: cout << "Encerrando o programa!\n" << endl;
		}
		getch();
	}while(opcao != 3);

    return 0;
}

int menu() {
	system("cls");
	
	int opcao;
	
	cout << "\t\t *** ROMs Do Patrick Estrela ***" << endl;
	cout << endl;
	cout << "1 - Cadastrar Jogo" << endl;
	cout << "2 - Consultar Jogo" << endl;
	cout << "3 - Excluir Jogo" << endl;
	cout << "4 - Finalizar" << endl;
	cout << endl;
	cout << "Sua Opcao: ";
	cin >> opcao;
	
	return opcao;
	
}

void cadastra(map<int, tROM> &game) {	
	system("cls");
	cin.ignore();
	
	tROM novo;
	
	cout << "\t\t *** CADASTRO DE JOGOS ***" << endl;
	
	cout << "Titulo.....: ";
    getline(cin, novo.titulo);
    
    cout << "Genero..: ";
    getline(cin, novo.genero);
    
    cout << "Ano de lancamento......: ";
    getline(cin, novo.anoLanc);
    
    cout << "Desenvolvedora......: ";
    getline(cin, novo.nomeDesen);
    
    cout << "Jogadores......: ";
    getline(cin, novo.qtdJog);
    
    pk++;
    
    game[pk] = novo;
    
    cout << "Cadastro " << pk << " realizado com sucesso!";
    
    return;
}

void consulta(map <int, tROM> game) {
	system("cls");
	cin.ignore();
	
	int codigoPesquisa;
	
	do{
		cout << "\t\t *** CONSULTA DE JOGOS ***" << endl;
		cout << endl;
		cout << "1 - Por Titulo" << endl;
		cout << "2 - Por Genero" << endl;
		cout << "3 - Por Ano De Lancamento" << endl;
		cout << "4 - Por Nome Da Desenvolvedora" << endl;
		cout << "5 - Por Numero De Jogadores" << endl;
		cout << endl;
		cout << "Sua opcao: ";
		cin >> codigoPesquisa;
	}while(codigoPesquisa < 1 || codigoPesquisa > 5);
	
	cin.ignore();
	
	switch(codigoPesquisa){
		case 1:	consultaTitulo(game);
				break;
		case 2: consultaGenero(game);
				break;
		case 3: consultaAnoLanc(game);
				break;
		case 4: consultaNomeDesen(game);
				break;
		case 5: consultaQtdJog(game);	
				break;			
	}
	
	return;
}

void consultaTitulo(map <int, tROM> game) {	
	map <int, tROM>::iterator mapIterator;
	string titulo;
	
	cout << "Titulo: ";
    getline(cin, titulo);

	for(mapIterator = game.begin(); mapIterator != game.end(); mapIterator++) {
        if((mapIterator->second.titulo).find(titulo) != -1) {
            cout << "<" << mapIterator->second.titulo << "> ";
            cout << mapIterator->second.genero;
            cout << " (" << mapIterator->second.anoLanc << ") - ";
            cout << " < " << mapIterator->second.nomeDesen << " > - ";
            cout << mapIterator->second.qtdJog << endl;
            break;                         
        }
    }
    
	return;
}

void consultaGenero(map <int, tROM> game) {	
	map <int, tROM>::iterator mapIterator;
	string genero;
	
	cout << "Genero: ";
    getline(cin, genero);
	
	for(mapIterator = game.begin(); mapIterator != game.end(); mapIterator++) {
        if( (mapIterator->second.genero).find(genero) != -1) {
            cout << "<" << mapIterator->second.titulo << "> ";
            cout << mapIterator->second.genero;
            cout << " (" << mapIterator->second.anoLanc << ") - ";
            cout << " < " << mapIterator->second.nomeDesen << " > - ";
            cout << mapIterator->second.qtdJog << endl;
        }
        cout << endl;
    }
    
	return;
}

void consultaAnoLanc(map <int, tROM> game) {
	map <int, tROM>::iterator mapIterator;
	string anoLanc;
	
	cout << "Data de Lancamento: ";
    getline(cin, anoLanc);
	
	for(mapIterator = game.begin(); mapIterator != game.end(); mapIterator++) {
        if( (mapIterator->second.anoLanc).find(anoLanc) != -1) {
            cout << "<" << mapIterator->second.titulo << "> ";
            cout << mapIterator->second.genero;
            cout << " (" << mapIterator->second.anoLanc << ") - ";
            cout << " < " << mapIterator->second.nomeDesen << " > - ";
            cout << mapIterator->second.qtdJog << endl;
		}
		cout << endl;
    }
    
    return;
}

void consultaNomeDesen(map <int, tROM> game) {	
	map <int, tROM>::iterator mapIterator;
	string nomeDesen;
	
	cout << "Nome Da Desenvolvedora: ";
    getline(cin, nomeDesen);
	
	for(mapIterator = game.begin(); mapIterator != game.end(); mapIterator++) {
        if( (mapIterator->second.nomeDesen).find(nomeDesen) != -1) {
            cout << "<" << mapIterator->second.titulo << "> ";
            cout << mapIterator->second.genero;
            cout << " (" << mapIterator->second.anoLanc << ") - ";
            cout << " < " << mapIterator->second.nomeDesen << " > - ";
            cout << mapIterator->second.qtdJog << endl;
        }
        cout << endl;
    }
    
	return;
}

void consultaQtdJog(map <int, tROM> game) {	
	map <int, tROM>::iterator mapIterator;
	string qtdJog;
	
	cout << "Quantidade De Jogadores: ";
    getline(cin, qtdJog);
	
	for(mapIterator = game.begin(); mapIterator != game.end(); mapIterator++) {
        if( (mapIterator->second.qtdJog).find(qtdJog) != -1) {
            cout << "<" << mapIterator->second.titulo << "> ";
            cout << mapIterator->second.genero;
            cout << " (" << mapIterator->second.anoLan << ") - ";
            cout << " < " << mapIterator->second.nomeDesen << " > - ";
            cout << mapIterator->second.qtdJog << endl;
        }
        cout << endl;
    }
    
	return;
}

