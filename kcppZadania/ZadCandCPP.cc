#include <iostream>
#include <iomanip>

using namespace std;


int main(){
	cout << setw(14) << "C" << setw(25) << "C++" << "\n" << endl;

	cout << setw(35) << "printf(\"bleee!!!\") " << "\t" << "std::cout << bleeee!!! << endl" << endl <<endl;

	cout << setw(35) << "printf(\"%i\", 19) " << "\t" << "cout << 19" << endl << endl;

	cout << setw(35) << "scanf(%i, &varInt) " << "\t" << "std::cin >> varInt" << endl  << endl;

	cout << setw(35) << "fprintf(stderr, \"Kom. o bledzie\") " << "\t" << "cerr << \"Komunikat o bledzie\" "<< endl << endl; 

	cout << setw(35) << "#include <stdio.h>" << "\t" << "#include <iostream>" << "\n" << endl;

	cout << setw(35) << "-" << "\t" << "using namespace NAME" << endl << endl;

	return 1;

}
