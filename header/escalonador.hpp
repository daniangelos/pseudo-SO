#ifndef ESCALONADOR_HPP
#define ESCALONADOR_HPP

#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include "processo.hpp"

class escalonador
{
	private:
		vector<processo_t> processos;
		queue<processo_t> f_usuario_p1;
		queue<processo_t> f_usuario_p2;
		queue<processo_t> f_usuario_p3;
		queue<processo_t> f_temporeal;
	public:
		void show_allp();
		void despachante (processo_t p);
		void utils_tomem(string nome_arq);
		void order_process();
};

#endif //ESCALONADOR_HPP
