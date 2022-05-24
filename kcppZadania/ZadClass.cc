#include <iostream>

using namespace std;

class basicClass{
    private:
        int a;

    protected:
        int b;

    public:
        int c;
        void setA(int intA){
            a = intA;
        }

        int getA();

        void setB(int intB){
            b = intB;
        }

        void setC(int intC){
            c = intC;
        }
        
        inline int getAplusB(){
            return a+b;
        }

};

int basicClass::getA(){
    return a;
}

int main(){

    basicClass bc;
    bc.setA(5);
    bc.setB(2);
    bc.setC(8);
    cout << "a: " << bc.getA() << endl;
    cout << "a + b: " << bc.getAplusB() << endl;
    return 1;
}