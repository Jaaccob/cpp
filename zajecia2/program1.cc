#include<iostream>

using namespace std;

typedef unsigned int znak;
typedef float przecinek;

int funkcja (int a);

/*int funkcja(int a){
*	int b = 77;
*	cout << b << endl;
*	return a;
*}
*/

int zmiana1(){
	static int a = 0;
	a ++;
	cout << a << endl;
	return a;
}

int zmiana2(){
	return zmiana1();
}

int main(){
	int a = 5;
	//funkcja(a);
	a = zmiana1();
	a += zmiana2();
	znak w = 5;
	przecinek zmienna = 3.14;
	for(int i =0; i < 3; i++){
		a += zmiana2();
	}
	cout << a << endl;;
	cout << "Zmienna predefiniowana: " << w << endl;
	cout << "Zmienna predefiniowana: "<< zmienna << endl;
	return 1;
}

int funkcja(int a){
	int b = 77;
	cout << b << endl;
	return a;
}
