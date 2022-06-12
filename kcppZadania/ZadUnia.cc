#include <iostream>

using namespace std;

union basicUnion{
    int a;
    int b[2];
    double c;
    double d[2];
};

int main(){
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
