#include <iostream>
#include <fstream>
#include <string>

int main(){
	std::string text;
	int num;
	std::cout << "Podaj liczbę: ";
	std::cin >> num;

	std::ofstream fileA("cin.txt");
	std::cerr << "Koniec odczytu od użytkownika" << std::endl;

	if (fileA.good()){
		fileA << num;
		fileA.close();
	}
	else 
        std::cerr << "Błędny zapis" << std::endl;

	std::ifstream fileB;
	fileB.open("cin.txt");

	if (fileB.is_open()){
		while(getline(fileB,text)){
			std::cout << text << std::endl;
		}
		fileB.close();
	}else 
        std::clog << "Błędny odczyt" << std::endl;
	return 0;
}