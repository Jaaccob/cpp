#include <iostream>

/*Zadanie 2.2
* --------------------------------------
* Napisz program przekazujący tablice z zachowaniem rozmiaru
* Czy się da?
* Jeśli tak to proszę wykonać zadanie:
* - nazwać program: ZadPrzekazywanieTablic.cc
* Jeśli się nie da to proszę wykonać zadanie:
* - zdefiniować ogólną funkcję w której nie jest na sztywno ustawiony rozmiar tablicy, która przekazujemy:
* - nazwać program: ZadPrzekazywanieTablicZpodaniemRozmiaru.cc
*/

using namespace std;

const int SIZE = 3;

void fun(int tab[]){
	for(int i=0; i < SIZE; i++){
		tab[i] *= 2;
	}
}

int main(){
	int tab[] = {1,2,3};
	fun(tab);

	for(int i=0; i < SIZE; i++){
               cout <<  tab[i] << ",";
        }
	cout << endl;
	return 1;
}
