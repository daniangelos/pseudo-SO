#ifndef PROCESSO_HPP
#define PROCESSO_HPP

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "../header/recurso.hpp"
#define PORCENTAGEM 101
#define QUANTUM 1

using namespace std;

enum Prioridades{ TEMPO_REAL = 0, USUARIO_P1, USUARIO_P2, USUARIO_P3 };

class processo_t
{
	public:
		processo_t(){}
		processo_t(const int _pid,const int _mo,const int _ti, const int _pr, const int _tp,
			   	const int _qb, const bool _i, const bool _s, const bool _m, const bool _d, int _rb):
			// Construtor:
			pid(_pid), mem_offset(_mo), time_init(_ti), prioridade(_pr), time_proc(_tp),
			 qtd_blocos(_qb), uso_impressora(_i), uso_scanner(_s), uso_modem(_m), 
			 uso_disco(_d),recurso_bloqueado(_rb) { }
		friend ostream& operator<<(ostream& os,const processo_t& it);
		int get_pid();
		void set_pid(const int _id);
		int get_prioridade();
		void set_prioridade(const int _pr);
		int get_memoffset();
		void set_memoffset(const int _mo);
		int get_qtdblocos();
		void set_qtdblocos(const int _qb);
		int get_timeexec();
		void set_timeexec(const int _te);
		int get_timeinit();
		void set_timeinit(const int _ti);
		bool get_impressora();
		void set_impressora(const bool _i);
		bool get_scanner();
		void set_scanner(const bool _s);
		bool get_disco();
		void set_disco(const bool _d);
		bool get_modem();
		void set_modem(const bool _m);
		int get_recursobloqueado();
		void set_recursobloqueado(const int _rb);
		bool in_mem();
		void liberar_recursos();
		void check();
	private:
		int pid;
		int time_init;
		int prioridade;
		int time_proc;
		int mem_offset;
		int qtd_blocos;
		bool uso_impressora;
		bool uso_scanner;
		bool uso_modem;
		bool uso_disco;
		int recurso_bloqueado;
		int has_recurso();
		int use_recurso();
};

bool first_executed(processo_t p1, processo_t p2);

#endif // PROCESSO_HPP
