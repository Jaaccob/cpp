#include "Class.h"
#include <iostream>
#include <string.h>

using namespace std;

Car::Car(string brand, string model){
    this->brand = brand;
    this->model = model;
    horsepower = 0;
    maxSpeed = 0;
    carCounter++;
}

Car::Car(string brand, string model, int horsepower, int maxSpeed){
    this->brand = brand;
    this->model = model;
    carCounter++;
};

void Car::setHorsepower(int horsepower){
    this->horsepower = horsepower;
    cout << "Ustawiłem ilość koni na: " << this->horsepower << endl;
};

Car* Car::setMaxSpeed(int maxSpeed){
    this->maxSpeed = maxSpeed;
    cout << "set maxSpeed on: " << this->maxSpeed << endl;
    return this;
};

Car& Car::setMaxSpeed2(int maxSpeed){
    this->maxSpeed = maxSpeed;
    cout << "set maxSpeed on: " << this->maxSpeed << endl;
    return *this;
};

Car::Car(Car &var){
    brand = var.brand;
    model = var.model;
    horsepower = var.horsepower;
    maxSpeed = var.maxSpeed;
    carCounter++;
    cout << "Wszystkie zmienne zostaly skopiowane" << endl;
};

Car::~Car(){
    cout << "Obiekt: " << this << " jest zniszczony" << endl;
};

void Car::show(){
    cout << endl << "Parametry auta: " << endl;
    cout << "Marka: " << brand << endl;
    cout << "Model: " << model << endl;
    cout << "Konie mechaniczne: " << horsepower << endl;
    cout << "Maksymalna predkosc: " << maxSpeed << endl;
    cout << "Jest to: "<< carCounter << " obiekt typu Car" << endl;
};

int Car::carCounter = 0;

bool Car::equals(Car &var){
	if(this == &var){
		return true;
	}
	else{
		return false;

	}
};

// Car::Car(string sBrand, string sModel, int iHorsepower, int iMaxSpeed) :
//  brand(sBrand), model(sModel), horsepower(iHorsepower), maxSpeed(iMaxSpeed) {carCounter++;};

// int main(){
// 	Car* panda = new Car("Fiat","Panda");
// 	panda->setHorsepower(75);
// 	Car* pPanda = panda->setMaxSpeed(180);
// 	pPanda->setHorsepower(76);
// 	panda->show();
// 	pPanda->show();
// 	if(panda->equals(*pPanda)){
// 		cout << endl << "Same car" << endl;
// 	}
// 	delete panda;
// 	Car* fabia = new Car("Skoda", "Fabia", 150, 220);
// 	fabia->show();

// 	Car* fabia2 = fabia;
// 	fabia2->show();
// 	delete fabia;


// 	Car a3("Audi","a3",120,240);
// 	a3.setMaxSpeed2(245).show();
// 	return 1;
// }
