#include <iostream>
#include <locale>
#include <unordered_map>
#include <sstream>
#include <cctype>

using namespace std;

void printFrequencies(const string &sentence);
string lowerSentence(string sentence);

int main(void) {
	setlocale(LC_CTYPE, "");
	
    string sentence = "Hoje visitei a velha estação de trem. "
					"A estação estava coberta de abandono. "
					"Porque, hoje, as pessoas parecem não dar bola para construções velhas como essa da estação de trem. "
					"Muitas pessoas só querem saber de coisas futuras. Dão bola só para coisas novas."; 
    
    sentence = lowerSentence(sentence);
	
	printFrequencies(sentence); 
    
	return 0; 
}

void printFrequencies(const string &sentence)  { 
	// Cria o hashmap para armazenar palavra, frequência
    unordered_map<char, int> histogram;
    
    for(int i = 0; i < sentence.length(); i++){
    	histogram[sentence[i]]++;
	}
  
    unordered_map<char, int>::iterator histogramIterator;
    
    for (histogramIterator = histogram.begin(); histogramIterator != histogram.end(); histogramIterator++)
    	cout << "(" << histogramIterator->first << ", " << histogramIterator->second << ")\n";
    
    return;
}

string lowerSentence(string sentence) {
	for(int i = 0; i < sentence.length(); i++)
		sentence[i] = tolower(sentence[i]);
		
	return sentence;
}
