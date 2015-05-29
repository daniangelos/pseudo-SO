#ifndef PROCESSO_HPP
#define PROCESSO_HPP

#include <fstream>

typedef struct processo {
	int pid;
	int prioridade;
	int mem_offset;
	int quant_blocos;
	bool uso_impressora;
	bool uso_scanner;
	bool uso_drivers;
}processo;

void despachante (char *input);

#endif // PROCESSO_HPP
