#ifndef Class_h
#define Class_h 1

#include <iostream>
#include <string.h>

using namespace std;

class Car{
	public:
        Car() {};

        Car(string brand, string model);

        Car(string brand, string model, int horsepower, int maxSpeed);

        void setHorsepower(int horsepower);

        Car* setMaxSpeed(int maxSpeed);

        Car& setMaxSpeed2(int maxSpeed);

        Car(Car &var);

        ~Car();

        void show();

        bool equals(Car &var);

	protected:

    private:
        static int carCounter;
        string brand;
        string model;
        int horsepower;
        int maxSpeed;
};

#endif