#include<iostream>
#include "../header/escalonador.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	if(argc < 2) {
		cerr << "\tNumero de argumentos invalidos!" << endl;
		cerr << "\tModo de uso: ./simulador <input.txt>" << endl;
		return -1;
	}

	char* input;
	input = argv[1];

	escalonador e;
	inicializarSemaforos();
	e.utils_tomem(input);
	e.simulacao();

	return 0;
}
	
