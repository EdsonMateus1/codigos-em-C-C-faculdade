#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

int imprimeMenu();
int cadastraVeiculo(map <string, string> &veiculo);
int consultaVeiculo(map <string, string> &veiculo);
int excluiVeiculo(map <string, string> &veiculo);

int main(){
    // Criação da estrutura do mapa
    map <string, string> detran;
	int opcao;
	int retorno;
	
	do{
		opcao = imprimeMenu();
		
		switch(opcao){	
			case 1: retorno = cadastraVeiculo(detran);
					system("PAUSE");
					break;
					
			case 2: retorno = consultaVeiculo(detran);
					system("PAUSE");
					break;
					
			case 3: retorno = excluiVeiculo(detran);
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
	cout << "DETRAN/MG" << endl;
	
	cout << "1 - Cadastra Veiculo" << endl;
	cout << "2 - Consulta Veiculo" << endl;
	cout << "3 - Exclui Veiculo" << endl;
	cout << "4 - Sair" << endl;
	
	cout << "Opcao: ";
	cin >> opcao;
	
	cin.ignore();
	
	return opcao;
}

int cadastraVeiculo(map <string, string> &veiculo){
	string placa, modelo;
	
	cout << "Digite a placa do veiculo: ";
	getline(cin, placa);
	
	cout << "Digite o modelo do veiculo: ";
	getline(cin, modelo);
	
	veiculo[placa] = modelo;
	
	return 1;
}

int consultaVeiculo(map <string, string> &veiculo){
	map<string, string>::iterator mapIterator;
	
	for(mapIterator = veiculo.begin(); mapIterator != veiculo.end(); mapIterator++)
		cout << mapIterator->first << " " << mapIterator->second << endl;
		
	return 1;
}

int excluiVeiculo(map <string, string> &veiculo){
	string placa;
	char opcao;

	
	cout << "Placa do veiculo a ser excluido: ";
    cin >> placa;
    
    if(veiculo.find(placa) == veiculo.end())
        cout << "Placa nao encontrada!" << endl;
    else {
        cout << "Placa " << placa << " encontrada! O modelo e " << veiculo[placa] << endl;
    
		cin.ignore();    
	    cout << "Deseja excluir? (S/N): " << endl;
	    cin >> opcao;
	    
	    
	    if(opcao == 'S' || opcao == 's') {
	    	veiculo.erase(placa);
	    	return 1;
		}
		else return 0;
	}
}
