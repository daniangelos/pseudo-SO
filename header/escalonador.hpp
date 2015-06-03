#ifndef ESCALONADOR_HPP
#define ESCALONADOR_HPP
#include <vector>
#include <queue>
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
		void despachante (processo_t p);
};

#endif //ESCALONADOR_HPP
