#include <iostream>

using namespace std;

struct basicStruct
{
    int a;
    int b = 12;
    basicStruct(){a = 8; b = 33;}
};

int main(){
    basicStruct bs;
    bs.a = 7;
    bs.b ++;
    cout << "a: " << bs.a << ", b: " << bs.b << endl;
    return 1;
}
