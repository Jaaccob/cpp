#include <iostream>

using namespace std;

struct basicStruct{
    int a;
    int b;
    basicStruct(){
        a = 1;
        b = 2;
    };
    basicStruct(int intA){
        a = intA;
    };
    basicStruct(int intA, int intB) : a(intA), b(intB){
    };
    ~basicStruct(){
        cout << "Destroy basicStruct" << endl;
    };
};

int main(){
    basicStruct *pbs = new basicStruct;
    pbs->a = 7;
    pbs->b ++;
    cout << "a: " << pbs->a << ", b: " << pbs->b << endl;
    delete pbs;

    basicStruct bs(1,2);
    cout << "a: " << bs.a << ", b: " << bs.b << endl;
    return 1;
}