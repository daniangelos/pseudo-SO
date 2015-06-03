#ifndef PROCESSO_HPP
#define PROCESSO_HPP

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

class processo_t
{
	public:
		processo_t(){}
		processo_t(const int _pid, const int _pr, const int _mem, const int _bl, const bool _i, const bool _s, const bool _d, const bool _m):
			pid(_pid),prioridade(_pr),mem_offset(_mem),qtd_blocos(_bl),uso_impressora(_i),uso_scanner(_s),uso_disco(_d),uso_modem(_m){}
		friend ostream& operator<<(ostream& os,const processo_t& it);
		int get_pid();
		void set_pid();
		int get_prioridade();
		void set_prioridade();
		int get_memoffset();
		void set_memoffset();
		int get_qtdblocos();
		void set_qtdblocos();
		bool get_impressora();
		void set_impressora();
		bool get_scanner();
		void set_scanner();
		bool get_disco();
		void set_disco();
		bool get_modem();
		void set_modem();
	private:
		int pid;
		int prioridade;
		int mem_offset;
		int qtd_blocos;
		bool uso_impressora;
		bool uso_scanner;
		bool uso_disco;
		bool uso_modem;
};

#endif // PROCESSO_HPP
