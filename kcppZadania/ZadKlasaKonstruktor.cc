#include <iostream>

using namespace std;

class basicClass
{
    private:
        int a;
        int b;
    
    public:
        basicClass(){}

        basicClass(int intA, int intB){
            a = intA;
            b = intB;
        }

        basicClass(int intA) : a(intA){}

        ~basicClass(){
            cout << "Destroy basicClass" << endl;
        }

        int getA(){
            return a;
        }

        int getB(){
            return b;
        }

};

int main(){
    basicClass bc(7,14);
    cout << "a: " << bc.getA() << endl;
    cout << "b: " << bc.getB() << endl;

    basicClass bci(bc);
    cout << "a: " << bci.getA() << endl;
    cout << "b: " << bci.getB() << endl;

    basicClass *pbc = new basicClass();
    cout << "a: " << pbc->getA() << endl;
    cout << "b: " << pbc->getB() << endl;
    delete pbc;
}

