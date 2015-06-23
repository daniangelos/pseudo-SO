#include<iostream>
#include "../header/processo.hpp"
#include "../header/escalonador.hpp"
#include "../header/memoria.hpp"

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

	memoria m;
	cout << m.aloca(20,2) << endl;
	m.show();
	cin.get();
	cout << m.aloca(40,1) << endl;
	m.show();
	cin.get();
	m.desaloca(64,20);
	m.show();
	cin.get();
	cout << m.aloca(22,2) << endl;
	m.show();
	cin.get();

	//e.utils_tomem(input);
	//e.order_process();
	//e.start_time();
	//e.simulacao();

	return 0;
}
	
