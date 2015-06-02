#include<iostream>
#include<fstream>
#include "../header/processo.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	if(argc != 2) {
		cerr << "\tNumero de argumentos invalidos!" << endl;
		cerr << "\tModo de uso: ./simulador <input.txt>" << endl;
		return -1;
	}

	char* input;
	input = argv[1];

	
	processo_t *p = processo_init(1, 2, 3, 4, true, true, false, false);
	despachante(*p);
	delete p;


	return 0;
}
	
