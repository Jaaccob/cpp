#include <iostream>
#include <string>

using namespace std;

#define INT_A 23
#define concat(a, b) a ## b << #a << #b << " " << a << " " << b << endl;

void fun1(){
    int a = 0;
    #ifdef INT_A
        a += INT_A;
    #endif

    #ifndef INT_A
        num += 100;
    #endif
        std::cout << a << std::endl;
}

void fun2(){
	int co = 0;
	int ut = 1;
	concat(co, ut);
}

void fun3(){
    int a = 0;
    int b = 1;
    std::cout << a << " " << b << std::endl;
}

void fun4(){
    int a = 0;
    int b = 1;
    if(b) a += b;
    if(!b) a += 1;
    std::cout << a << std::endl;
}

int main(){
    fun1();
    fun2();
    fun3();
    fun4();
    return 0;
}