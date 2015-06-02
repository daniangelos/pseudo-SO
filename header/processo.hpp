#ifndef PROCESSO_HPP
#define PROCESSO_HPP

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

typedef struct {
	int pid;
	int prioridade;
	int mem_offset;
	int quant_blocos;
	bool uso_impressora;
	bool uso_scanner;
	bool uso_disco;
	bool uso_modem;
	void show();
}processo_t;


processo_t* processo_init(int id,int pr, int mem, int bl, bool i, bool s, bool d, bool m);

extern vector<processo_t> processos;
extern queue<processo_t> f_usuario_p1;
extern queue<processo_t> f_usuario_p2;
extern queue<processo_t> f_usuario_p3;
extern queue<processo_t> f_temporeal;

void despachante (processo_t p);

#endif // PROCESSO_HPP
