#include <iostream> 

using namespace std;


void orEven1(int number){
	if (number & 1 == 1){
		cout << "Liczba nie jest parzysta" << endl;
	}
	else {
		cout << "Liczba jest parzysta" << endl;
	}
}

void orEven2(int number){
	if (number %2 == 0){
		cout << "Liczba jest parzysta" << endl;
	}
	else {
		cout << "Liczba nie jest parzysta" << endl;
	}
}


void orEven3(int number){
	number % 2 != 0 ? cout << "Liczba nie jest parzysta" << endl : cout << "Liczba jest parzysta" << endl;
}

int main(){
	int number;
	cout << "Podaj liczbe: ";
	cin >> number;
	orEven1(number);
	orEven2(number);
	orEven3(number); 
	return 1;
}
