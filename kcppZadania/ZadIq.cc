#include <iostream>

using namespace std;

int main(){
	int tab[] = {1,2,3,4,5,6,7,8,9};
	int i = 0;
	int *p = tab;

	cout << "tab[0]: " << tab[i] << endl;
	cout << "p[0]: " << p[i] << endl;
	cout << "0[q]: " << i[p] << endl;
	cout << 0[p] << endl;

	//i[p] oraz p[i] jest analigoczne i traktowane w taki sam sposób
	//zwiazane jest to z arytmetyka wskaźników
	//p[i] == *(p+i)
	return 1;
}
