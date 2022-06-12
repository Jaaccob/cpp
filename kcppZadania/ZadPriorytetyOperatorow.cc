#include <iostream>

int main(){
	int x=1;
	int y=2;
	int z=3;
	int result[]={4,4,4,4};
	result[0] *= -++x*x--+-y--%++z;
	result[1] *= -(++x)*(x--)+-(y--)%(++z);
	result[2] *= (-(++x))*(x--)+(-(y--))%(++z);
	result[3] *= ((-(++x))*(x--))+((-(y--))%(++z));
	std::cout << result[0] << std::endl;
	std::cout << result[1] << std::endl;
	std::cout << result[2] << std::endl;
	std::cout << result[3] << std::endl;
	return 0;
}