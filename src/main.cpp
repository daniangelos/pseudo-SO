#include<iostream>
#include<fstream>
#include "../header/processo.hpp"
#include "../header/escalonador.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	if(argc != 2) {
		cerr << "\tNumero de argumentos invalidos!" << endl;
		cerr << "\tModo de uso: ./simulador <input.txt>" << endl;
		return -1;
	}

	char* input;
	input = argv[1];

	
	//processo_t p(1, 0, 2, 0, 3, 64, false, false, false, false);
	escalonador e;
	//e.despachante(p);
	e.utils_tomem(input);


	return 0;
}
	
