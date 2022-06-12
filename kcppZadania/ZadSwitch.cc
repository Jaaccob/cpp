#include <iostream>

void orEven1(int number){
        if (number & 1 == 1){
                std::cout << "Liczba nie jest parzysta" << std::endl;
        }
        else {
                std::cout << "Liczba jest parzysta" << std::endl;
        }
}

void orEven2(int number){
        if (number %2 == 0){
                std::cout << "Liczba jest parzysta" << std::endl;
        }
        else {
                std::cout << "Liczba nie jest parzysta" << std::endl;
        }
}


void orEven3(int number){
        number % 2 != 0 ? std::cout << "Liczba nie jest parzysta" << std::endl : std::cout << "Liczba jest parzysta" << std::endl;
}

int main(){
    std::cout << "Podaj liczbę" << std::endl;
    int num;
    std::cin >> num;
    std::cout << "Wybierz funkcje" << std::endl;
    std::string choose;
    std::cin >> choose;
    if(choose.length() < 4){
        std::cout << "Za krótka nazwa";
        return 1;
    }
    
    switch(choose[0]){
    case 'f':
        switch(choose[1]){
            case 'u':
                switch(choose[2]){
                    case 'n':
                        switch(choose[3]){
                            case 'a':
                                orEven1(num);
                                break;
                            case 'b':
                                orEven2(num);
                                break;
                            case 'c':
                                orEven3(num);
                                break;
                            default:
                                std::cout << "Nie znaleziono funkcji." << std::endl;
                                return 1;
                            }
                            break;
                        default:
                            std::cout << "Nie znaleziono funkcji." << std::endl;
                            return 1;
                }
                break;
            default:
                std::cout << "Nie znaleziono funkcji." << std::endl;
                return 1;
        }
        break;
    default:
        std::cout << "Nie znaleziono funkcji." << std::endl;
        return 1;
	}
	return 0;
}