#include <iostream>
#include <unordered_map>

using namespace std;

int main (void) {
	// Cria��o do hasmap string, string
	unordered_map<string, string> stringMap;
	
	// Cria��o de fun��o hash para nosso mapa
	unordered_map<string, string>::hasher hashFunction = stringMap.hash_function();
	
	string str1 = "isso";
	string str2 = "isto";
	
	cout << str1 << " -> " << hashFunction(str1) << endl;
  	cout << str2 << " -> " << hashFunction(str2) << endl;
	
	return 0;
}
