#include <iostream>
/*
* Zadanie 2.1
* --------------------------------------
* Zadanie: Napisać program z czterema funkcjami z których każda zwraca inaczej:
* 1. Przez wartość
* 2. Przez referencje
* 3. Przez wskaźnik
* 4. Tablice (proszę się zastanowić o co tak naprawę chodzi)
* - nazwać program: ZadZwracanie.cc
*/
using namespace std;

void funWar(int a){
	a = a*2;
}

void funRef(int &a){
	a = a*2;
}

void funWsk(int *a){
	*a = *a*2;
}

void funTab(int tab[]){
	for(int i=0; i <3; i++){
		tab[i] = tab[i]*2;
	}
}



int main(){
	int a = 2;
	int *wska = &a;
	cout  << "Wartosc a: " << a << endl;
	funWar(a);
	cout  << "Wartosc a: " << a << endl; 
	funRef(a);
	cout  << "Wartosc a: " << a << endl;
	funWsk(wska);
	cout  << "Wartosc a: " << a << endl;
	

	int tab[] = {2,2,2};
	funTab(tab);
	for(int i = 0; i < 3; i++){
		cout << tab[i] << ",";
	}
	cout << endl;
	return 1;
}
