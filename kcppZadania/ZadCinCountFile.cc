#include <iostream>
#include <fstream>

using namespace std;

int main(){
	cout << "Podaj liczbe ";
	int number;
	cin >> number;
	fstream fileW("cpp.txt", ios::out);

	if(fileW.good()){
		cout << "Udalo sie otworzyc plik" << endl;
		cout << "Zapis liczny: " << number << endl;
		fileW << number;
		fileW.close();
	}
	else {
		cerr << "Nie udalo sie otworzyc pliku" << endl;
	}
	cout << endl << endl << "Odczyt z pliku ! "<< endl;
	fstream fileR("cpp.txt", ios::in);
	if(fileR.good()){
		string line;
		cout << "Plik otwarty i zawiera: " << endl;
		while( !fileR.eof()){
			getline(fileR, line);
			cout << line << endl;
		}
		fileR.close();
	}
	else {
		cerr << "Nie udalo sie otworzyc pliku" << endl;
	}
	return 1;
}
