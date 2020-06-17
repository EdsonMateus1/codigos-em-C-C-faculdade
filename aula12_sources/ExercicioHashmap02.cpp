#include <iostream>
#include <locale>
#include <unordered_map>
#include <sstream>
#include <cctype>
#include <iomanip>

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
    
    unsigned int length = sentence.length();
    
    cout << "OLHA AQUI " << length << length*100 << endl;
    
    for(int i = 0; i < length; i++){
    	histogram[sentence[i]]++;
	}
  
    unordered_map<char, int>::iterator histogramIterator;
    
    cout << "HISTOGRAM" << endl;
    cout << endl;
    
    cout << "CHAR " << " # " << "  % FREQ" << endl; 
    
    for (histogramIterator = histogram.begin(); histogramIterator != histogram.end(); histogramIterator++) {
    	cout << right << setw(2) << histogramIterator->first << "    ";
		cout << right << setw(2) << histogramIterator->second << "  ";
		cout << setprecision(4) << setw(6) << float(histogramIterator->second)/length*100;
		cout << endl;
	}
    
    return;
}

string lowerSentence(string sentence) {
	for(int i = 0; i < sentence.length(); i++)
		sentence[i] = tolower(sentence[i]);
		
	return sentence;
}
