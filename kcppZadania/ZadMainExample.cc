/**
*Zadanie 1.1
*--------------------------------------
*Napisać program który zawiera:
*- funkcję main
*- 5 innych funkcji, z czego dwie zadeklarowane jako: extern "C"
*- wywołując program decydujemy, które z funkcji mają zostać wykonane przez podanie tego w liście argumentów przekazanych do funkcji main
*- nazwać program: ZadMainExample.cc 
*/
#include<iostream>

using namespace std;

extern "C" int suma(int iOneNumber, int iTwoNumber){
	return iOneNumber + iTwoNumber;
}

extern "C" int roznica(int iOneNumber, int iTwoNumber){
	return iOneNumber - iTwoNumber;
}

int mnozenie(int iOneNumber, int iTwoNumber){
	return iOneNumber * iTwoNumber;
}

float dzielenie(int iOneNumber, int iTwoNumber){
	if(iTwoNumber == 0){
		cout << "Nie dzielimy przez 0" << endl;
		return 0;
	}
	return iOneNumber/iTwoNumber;
}

void wyswietlPrzywitanie(int iOneNumber, int iTwoNumber){
	cout << "Czesc, jestem prostym kalkulatorem, twoja pierwsza liczba to: " << iOneNumber << " a twoja druga liczba to: " << iTwoNumber << endl;
}



int main(int argc, char *argv[]){
	string sFun = argv[1];
	string sNumberOne = argv[2];
	string sNumberTwo = argv[3];
	int iNumberOne = stoi(sNumberOne);
	int iNumberTwo = stoi(sNumberTwo);
	int iFun = stoi(sFun);
	switch(iFun){
		case 0: 
			cout << suma(iNumberOne, iNumberTwo) << endl; 
			break;
		case 1: 
			cout << roznica(iNumberOne, iNumberTwo) << endl;
			break;
		case 2:
			cout << mnozenie(iNumberOne, iNumberTwo) << endl;
			break;
		case 3:
			cout << dzielenie(iNumberOne, iNumberTwo) << endl;
			break;
		case 4:
			wyswietlPrzywitanie(iNumberOne, iNumberTwo);
			break;
		default:
			cout << "Bledna operacja" << endl;
			break;
	}
	return 1;
}




