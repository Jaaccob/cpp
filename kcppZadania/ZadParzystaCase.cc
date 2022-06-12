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
	
	cout << "Podaj program, ktory chcesz wybrac: " << endl;
	cout << "1. OPERACJE BITOWE" << endl;
	cout << "2. MODULO" << endl;
	cout << "3. OPERATOR WARUNKOWY" << endl;
	
	char choose;
	cin >> choose;
	switch(choose){
		case '1':
		        orEven1(number);
			break;
		case '2':
		        orEven2(number);
			break;
		case '3':
		        orEven3(number);
			break;
		default: 
			cout << "Niepoprawny number" << endl;
		}
        return 1;
}

