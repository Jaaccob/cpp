#include <iostream>
#include <math.h>

using namespace std;

class Shape{
    public:
        virtual double circuit() = 0;
        virtual double area() = 0;
};

class Triangle: public Shape{
    private:
        double a;
        double b;
        double c;

    public: 
        Triangle(double x0, double x1, double x2){
            if(x0 + x1 > x2 && x0 + x2 > x1 && x1 + x2 > x0){
                a = x0;
                b = x1;
                c = x2;
            }
            else{
                cout << "Bad values for triangle" << endl;
            }
        }

        double circuit(){
            return a + b + c;
        }

        double area(){
            double p = (a + b + c)/2;
            return sqrt(p*(p-a)*(p-b)*(p-c));
        }
};

class Rectangle : public Shape{
    private:
        double a;
        double b;
    
    public: 
        Rectangle(double x0, double x1){
            a = x0;
            b = x1;
        }

        double circuit(){
            return 2*a + 2 * b;
        }

        double area(){
            return a * b;
        }
};

class Square: public Shape{
    private:
        double a;

    public:
        Square(double x){
            a = x;
        }
        double circuit(){
            return 4* a;
        }

        double area(){
            return pow(a,2);
        }
};

class Circle: public Shape{
    private:
        double r;

    public:
        Circle(double x){
            r = x;
        }

        double circuit(){
            return 2 * M_PI * pow(r, 2);
        }

        double area(){
            return M_PI * pow(r, 2);
        }

        double distance(double p){
            return sqrt(p / M_PI);
        }
};


int main(){
    Triangle *t = new Triangle(3,4,5);
    Rectangle *r = new Rectangle(3,5);
    Square *s = new Square(3);
    Circle *c = new Circle(3);

    cout << "Obwód: " << endl;
    cout << "Trójkąt: " << t->circuit() << endl;
    cout << "Prostokąt: " << r->circuit() << endl;
    cout << "Kwadrat: " << s->circuit() << endl;
    cout << "Koło: " << c->circuit() << endl;

    cout << "Pole: " << endl;
    cout << "Trójkąt: " << t->area() << endl;
    cout << "Prostokąt: " << r->area() << endl;
    cout << "Kwadrat: " << s->area() << endl;
    cout << "Koło: " << c->area() << endl;

    cout << "Dystans: " << endl;
    cout << c->distance(5) << endl;

}