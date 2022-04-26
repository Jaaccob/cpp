#include <iostream>

using namespace std;

void Funkcja1(){
	cout << "Funcka 1: deklaracja zmiennych \n\n\n\n";
	int a = 1;
	int b = 10;
	int c = 20;
 	int d = 30;
 	int e = 40;
 	int f = 50;
	int g = 60;
	int h = 70;
	int j = 80;
	int *p = &a;

	cout << "*p: " << *p << endl;
	p++;
	cout << "p: " << *p << endl;
	++p;
	cout << "p: " << *p << endl;
	++*p;
	cout << "p: " << *p << endl;
	++(*p);
	cout << "p: " << *p << endl;
	*p++;
	cout << "p: " << *p << endl;
	(*p)++;
	cout << "p: " << *p << endl;
	*(p)++;
	cout << "p: " << *p << endl;
	*++p;
	cout << "p: " << *p << endl;
	*(++p);
	cout << "p: " << *p << endl;
}

void Funkcja2(){
	cout << endl << "Funkcja 2: delkaracja tablicy " << endl << endl << endl << endl;
	int tab[] = {1,2,3,4,5,6,7,8,9,10};
	int *p = tab;
	cout << "*p: " << *p << endl;
        p++;
        cout << "p: " << *p << endl;
        ++p;
        cout << "p: " << *p << endl;
        ++*p;
        cout << "p: " << *p << endl;
        ++(*p);
        cout << "p: " << *p << endl;
	++*(p);
	cout << "p: " << *p << endl;
        *p++;
        cout << "p: " << *p << endl;
        (*p)++;
        cout << "p: " << *p << endl;
        *(p)++;
        cout << "p: " << *p << endl;
        *++p;
        cout << "p: " << *p << endl;
        *(++p);
        cout << "p: " << *p << endl;
}

void Funkcja3(){
	cout << endl << "Funkcja 2: delkaracja tablicy " << endl << endl << endl << endl;
	int a = 0, b = 0, c = 0;
	int *p = &b;
	*p += 10;
	cout << "A, B, C: " << a << " " << b << " " << c << endl;
	*(p+(&b-&a)) = *p*2;
	cout << "A, B, C: " << a << " " << b << " " << c << endl;
	*p += *(p+(&b-&a));
	cout << "A, B, C: " << a << " " << b << " " << c << endl;
	*(p-(&b-&a)) = 2**(p+(&b-&a));
	cout << "A, B, C: " << a << " " << b << " " << c << endl;
	*p += *(p+(&b-&a));
	cout << "A, B, C: " << a << " " << b << " " << c << endl;
	*(p+(&b-&a)) += *(p-(&b-&a));
	cout << "A, B, C: " << a << " " << b << " " << c << endl;
	*p += *(p+(&b-&a)) - *(p-(&b-&a));
	cout << "A, B, C: " << a << " " << b << " " << c << endl;
	*(p-(&b-&a)) *= 2;
	cout << "A, B, C: " << a << " " << b << " " << c << endl;
	*p += *(p-(&b-&a)) - *(p+(&b-&a));
	cout << "A, B, C: " << a << " " << b << " " << c << endl;

}



int main(){
	Funkcja1();
	Funkcja2();
	Funkcja3();
	return 1;
}
