#include<iostream>

using namespace std;

enum typ_wyliczeniowy{
	zero,
	jeden = 1,
	dwa = 1,
	trzy,
	cztery,
	piec,
	szesc,
	siedem,
	osiem,
	dziewiec
};

int main(){
	typ_wyliczeniowy a = jeden;
	cout << a << endl;
	cout << dwa << endl;
	float c = 3.14;
	cout << int (c) << endl;
	return 1;
}
