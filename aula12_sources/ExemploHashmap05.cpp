#include <iostream>
#include <unordered_map>

using namespace std;

int main (void) {
	// Criação do hasmap string, string
	unordered_map<string, string> stringMap;
	
	// Criação de função hash para nosso mapa
	unordered_map<string, string>::hasher hashFunction = stringMap.hash_function();
	
	string str1 = "rato";
	string str2 = "rota";
	string str3 = "taro";
	string str4 = "tora";
	
	
	cout << str1 << " -> " << hashFunction(str1) << endl;
  	cout << str2 << " -> " << hashFunction(str2) << endl;
  	cout << str3 << " -> " << hashFunction(str3) << endl;
  	cout << str4 << " -> " << hashFunction(str4) << endl;
	
	return 0;
}
