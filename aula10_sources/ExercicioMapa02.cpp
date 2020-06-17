#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

int imprimeMenu();
int cadastraCodigodeArea(map <string, int> &codigo);
int consultaCodigodeArea(map <string, int> &codigo);
int excluiCodigodeArea(map <string, int> &codigo);

int main(){
    // Criação da estrutura do mapa
    map <string, int> codigoDeArea;
	int opcao;
	int retorno;
	
	do{
		opcao = imprimeMenu();
		
		switch(opcao){	
			case 1: retorno = cadastraCodigodeArea(codigoDeArea);
					system("PAUSE");
					break;
					
			case 2: retorno = consultaCodigodeArea(codigoDeArea);
					system("PAUSE");
					break;
					
			case 3: retorno = excluiCodigodeArea(codigoDeArea);
					if(retorno)
						cout << "Exclusao realizada!" << endl;
					else
						cout << "Exclusao cancelada!" << endl;
					system("PAUSE");
					break;
					
			case 4: cout << "O programa sera finalizado..." << endl;
					break;
					
			default: cout << "Opcao invalida!" << endl;
	
		}
	}while(opcao != 4);
    
    system("PAUSE");
    
    return 0;
}

int imprimeMenu(){
	system("CLS");
	int opcao;
	cout << "ANATEL/BRASIL" << endl;
	
	cout << "1 - Cadastra Codigo de Area" << endl;
	cout << "2 - Consulta Codigo de Area" << endl;
	cout << "3 - Exclui Codigo de Area" << endl;
	cout << "4 - Sair" << endl;
	
	cout << "Opcao: ";
	cin >> opcao;
	
	cin.ignore();
	
	return opcao;
}

int cadastraCodigodeArea(map <string, int> &codigo){
	string cidade;
	int codigoDeArea;
	
	cout << "Digite a cidade: ";
	getline(cin, cidade);
	
	cout << "Digite o codigo de area: ";
	cin >> codigoDeArea;
	
	cin.ignore();
	
	codigo[cidade] = codigoDeArea;
	
	return 1;
}

int consultaCodigodeArea(map <string, int> &codigo){
	map<string, int>::iterator mapIterator;
	
	for(mapIterator = codigo.begin(); mapIterator != codigo.end(); mapIterator++)
		cout << mapIterator->first << " " << mapIterator->second << endl;
		
	return 1;
}

int excluiCodigodeArea(map <string, int> &codigo){
	string cidade;
	char opcao;

	
	cout << "Cidade a ser excluida: ";
    getline(cin, cidade);
    
    if(codigo.find(cidade) == codigo.end())
        cout << "Cidade nao encontrada!" << endl;
    else {
        cout << "Cidade " << cidade << " encontrada! O codigo e " << codigo[cidade] << endl;
     
	    cout << "Deseja excluir? (S/N): " << endl;
	    cin >> opcao;
	    
	    
	    if(opcao == 'S' || opcao == 's') {
	    	codigo.erase(cidade);
	    	return 1;
		}
		else return 0;
	}
}
