#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

float fun1(int a, int b){
	return ((a+b)/18) *34.12;
}

float fun2(int a, int b) {
	float tem = 0;
	for(int i=0; i < 5; i++){
		tem += (a * b)/2 + 7/14;
	}
	return tem*3.141526;
}

float fun3(int a, int b){
	float tem = 0;
	while (tem < 10){
		tem += (b-a)*4;
	}
	return tem * 8.12461;
}



int main(){
	float a = 14.1231;
	float b = 20.3213;

	float o0 = fun1(a,b);
	float o1 = fun2(a,b);
	float o2 = fun3(a,b);

	cout << o0 << "," << o1 << "," << o2 << endl << endl << endl;


	cout << setfill ('=') << setw(40) << "=" << endl;
	cout << "Wynik naszego dzialania: " << (a+b)/17 << " jest niepoprawny ale: " << endl;
	cout << setfill (' ') << setw(4) << "output: " << setw(4) << setprecision(5) << o0  << setw(4) << "T: " << setprecision(4) << o0 << endl;
	cout << setfill (' ') << setw(4) << "output1: " << setw(4) << setprecision(5) << o1 << setw(4) << "T: " << setprecision(4) << o1 << endl;
	cout << setfill (' ') << setw(4) << "output2: " << setw(4) << setprecision(5) << o2 << setw(4) << "T: " << setprecision(4) << o2 << endl;
	cout << setfill ('-') << setw(30) << "-" << endl;
	cout << setfill (' ') << setw(4) << "avarage: " << setw(4) << a << setw(4) << "T: " << a << endl;
	cout << setfill ('=') << setw(40) << "=" << endl;
	return 1;
}
