#include <iostream>
#include <Class.h>
#include <conio.h>

using namespace std;

union basicUnion{
    int a;
    int b[2];
    double c;
    double d[2];
};

class kcpp{
    private:
        void funA(int num);
        
        void funB(int num);
        
        void funC(int num);
        
        void funWar(int a){
	        a = a*2;
        }

        void funRef(int &a){
            a = a*2;
        }

        void funWsk(int *a){
            *a = *a*2;
        }
    
		void funClass(){
			Car* panda = new Car("Fiat","Panda");
			panda->setHorsepower(75);
			Car* pPanda = panda->setMaxSpeed(180);
			pPanda->setHorsepower(76);
			panda->show();
			pPanda->show();
			if(panda->equals(*pPanda)){
				cout << endl << "Same car" << endl;
			}
			delete panda;
			Car* fabia = new Car("Skoda", "Fabia", 150, 220);
			fabia->show();

			Car* fabia2 = fabia;
			fabia2->show();
			delete fabia;


			Car a3("Audi","a3",120,240);
			a3.setMaxSpeed2(245).show();
		}

		void funUnia(){
			    basicUnion bu;
				bu.a = 7;
				bu.b[0] = 1;
				bu.b[1] = 2;
				cout << "a: " << bu.a << endl;
				cout << "b[0]: " << bu.b[0] << endl;
				cout << "b[1]: " << bu.b[1] << endl;

				bu.c = 3.14;
				bu.d[0] = 3.1415;
				bu.d[1] = 3.14159;
				cout << "a: " << bu.a << endl;
				cout << "b[0]: " << bu.b[0] << endl;
				cout << "b[1]: " << bu.b[1] << endl;
				cout << "c: " << bu.c << endl;
				cout << "d[0]: " << bu.d[0] << endl;
				cout << "d[1]: " << bu.d[1] << endl;
				cout << "Zmiana typów liczb na double" << endl;
		}

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
    
		void funParzysteCase(){
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
		}

	public:
        void ZadZwracanie(){
            int a = 2;
            int *wska = &a;
            cout  << "Wartosc a: " << a << endl;
            funWar(a);
            cout  << "Wartosc a: " << a << endl; 
            funRef(a);
            cout  << "Wartosc a: " << a << endl;
            funWsk(wska);
            cout  << "Wartosc a: " << a << endl;
        }

        void ZadPetle(){
        int num = 5;
        funA(num);
        funB(num);
        funC(num);
    }

		void ZadClass(){
			funClass();
		}

		void ZadUnia(){
			funUnia();
		}

		void ZadParzysteCase(){
			funParzysteCase();
		}
};

void kcpp::funA(int num){
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

void kcpp::funB(int num){
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

void kcpp::funC(int num){
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
    kcpp *classCpp = new kcpp();

	unsigned char znak;
	std::cout << "klawisz [ESC] wychodzi z programu." << std::endl;
	do
	{	
		while (kbhit())
		{
			znak = getch();
		}
		std::cout << "Który program chcesz wybrać?" << std::endl;
		std::cout << "0: ZadZwracanie.cc" << std::endl;
		std::cout << "1: ZadPetle.cc" << std::endl;
		std::cout << "2: ZadClass.cc" << std::endl;
		std::cout << "3: ZadUnia.cc" << std::endl;
		std::cout << "4: ZadParzysteCase.cc" << std::endl;
		znak = getch();
		if('0' == znak){
			classCpp->ZadZwracanie();
		}else if('1' == znak){
			classCpp->ZadPetle();
		}else if('2' ==znak){
			classCpp->ZadClass();
		}else if('3' == znak){
			classCpp->ZadUnia();
		}else if('4' == znak){
			classCpp->ZadParzysteCase();
		}else if ( 27 != znak){
			std::cout << "Niepoprawny numer" << std::endl;
		}
	} while (znak != 27);
    return 0;
}