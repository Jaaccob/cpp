#include <iostream>

using namespace std;


int main(){
	short s = 1;
	int i = 1;
	long l = 1;
	long long ll = 1;
	unsigned short us = 1;
	unsigned int ui = 1;
	unsigned long ul = 1;
	unsigned long long ull = 1;
	float f = 1;
	double d = 1;
	long double ld = 1;
	char c = '1';
	unsigned char uc = '1';
	bool b = '1';

	
	cout
	<< "short:			" << &s << " ," << endl
	<< "int:			" << &i << " ," << endl
	<< "long:			" << &l << " ," << endl
	<< "long long:		" << &ll << " ," << endl
	<< "unsigned short:		" << &us << " ," << endl
	<< "unsigned int:		" << &ui << " ," << endl
	<< "unsigned long:		" << &ul << " ," << endl
	<< "unsigned long long:	" << &ull << " ," << endl
	<< "float: 			" << &f << " ," << endl
	<< "double: 		" << &d << " ," << endl
	<< "long double: 		" << &ld << " ," << endl
	<< "char: 			" << &c << " ," << endl
	<< "unsigned char: 		" << &uc << " ," << endl
	<< "bool: 			" << &b << endl;

	
	//Adresy są kolejnymi adresami pamięci RAM oddalonych od siebie o deklarowany typ zmiennej

	return 1;
}
