#include <iostream>
#include <map>
using namespace std;


int main() {
	map <string, string> detram;
	string placa, modelo;
	int opcao;
	cout << "Digite 1 se deseja inserir" << endl;
	cin >> opcao;
	

	while (opcao == 1)
	{
		cout << "Digite a placa" << endl;
		cin >> placa;
		cout << "Digite a placa e o modelo" << endl;
		cin >> modelo;
		detram.insert(pair <string, string>(placa, modelo));
		cout << "Digite 1 se deseja inserir" << endl;
		cin >> opcao;
	}

	for (auto it : detram) {
		cout << it.first << " " << it.second << endl;
	}
	return 0;
	
}

