#include <iostream>
#include <conio.h>

void funA(){
    std::cout << "Funkcja a" << std::endl;
}

void funB(){
    std::cout << "Funkcja b" << std::endl;
}

int main(){
    unsigned char znak;

    std::cout << "Który sposób chcesz wybrać ?" << std::endl;
    std::cout << "0: Switch" << std::endl;
    std::cout << "1: If" << std::endl;
    znak = getch();

    if(znak == '0'){
        std::cout << "Który program chcesz wybrać ?" << std::endl;
        std::cout << "0: funA" << std::endl;
        std::cout << "1: funB" << std::endl;
        znak = getch();

        switch (znak)
        {
        case '0':
            funA();
            break;
        case '1':
            funB();
            break;
        default:
            std::cout << "Niepoprawny numer!" << std::endl;
            break;
        }
    }else if(znak == '1'){
        std::cout << "Który program chcesz wybrać ?" << std::endl;
        std::cout << "0: funA" << std::endl;
        std::cout << "1: funB" << std::endl;
        znak = getch();

        if(znak == '0'){
            funA();
        }else if (znak == '1'){
            funB();
        }else{
            std::cout << "Niepoporawny numer!" << std::endl;
        }
        
    }else {
        std::cout << "Niepoprawny numer!" << std::endl;
    }
    return 0;
}