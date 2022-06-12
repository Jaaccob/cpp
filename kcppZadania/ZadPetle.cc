#include <iostream>

using namespace std;

void funA(int num){
	int i = 0;
	cout << "while i++" << endl;
	while(i++ < num){
		if (i == num){
			cout << "i==num, break";
			break;
		}
		cout << i << " ";
	}
	cout << endl << "while ++i" << endl;
	i = 0;
	while(++i < num){
		if (i == num){
			cout << "i==num, break";
			break;
		}
		cout << i << " ";
	}
	cout << endl << endl;
}

void funB(int num){
	int i = 0;
	cout << "do-while i++" <<endl;
	do{
		if (i == 3) continue;
		cout << i << " ";
	}while(i++ < num);
	cout << endl << "do-while ++i" << endl;
	i = 0;
	do{
		if (i == 3) continue;
		cout << i << " ";
	}while(++i < num);
	cout << endl << endl;
}

void funC(int num){
	cout << "for" << endl;
	for(int i = 0; i < num; i++){
		if (i == 3){
			cout << "i==3, return funC(" << num-1 <<")" << endl;
			return funC(num-1);
		}
		cout << i << " ";
	}
	cout << endl << endl;
}



int main(){
	
	return 1;
}

