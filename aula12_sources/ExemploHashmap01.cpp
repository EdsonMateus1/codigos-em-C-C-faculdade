#include <iostream>
#include <locale>
#include <unordered_map>
#include <sstream>

using namespace std; 

void printFrequencies(const string &sentence);

int main(void) {
	setlocale(LC_CTYPE, "");
	
    string sentence = "Hoje visitei a velha esta��o de trem. "
					"A esta��o estava coberta de abandono. "
					"Porque, hoje, as pessoas parecem n�o dar bola para constru��es velhas como essa da esta��o de trem. "
					"Muitas pessoas s� querem saber de coisas futuras. D�o bola s� para coisas novas."; 
    
	printFrequencies(sentence); 
    
	return 0; 
}

void printFrequencies(const string &sentence) { 
	// Cria o hashmap para armazenar palavra, frequ�ncia
    unordered_map<string, int> histogram; 
	// Quebra a frase em palavras
    stringstream buffer(sentence);
    
    string word;
    
    while (buffer >> word) 
        histogram[word]++; 
  
    unordered_map<string, int>::iterator histogramIterator;
    
    for (histogramIterator = histogram.begin(); histogramIterator != histogram.end(); histogramIterator++)
    	cout << "(" << histogramIterator->first << ", " << histogramIterator->second << ")\n";
    
    return;
} 
