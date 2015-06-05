#include "../header/processo.hpp"
ostream& operator<<(ostream& os,const processo_t& it)
{
	os << "dispatcher =>" << '\n';
	os << "\tPID: " << it.pid << '\n';
	os << "\tpriority: " << it.prioridade << '\n';
	os << "\ttime_init: " << it.time_init << '\n';
	os << "\ttime_exec: " << it.time_proc << '\n';
	os << "\toffset: " << it.mem_offset << '\n';
	os << "\tblocks: " << it.qtd_blocos << '\n';
	os << "\tprinters: " << it.uso_impressora << '\n';
	os << "\tscanners: " << it.uso_scanner << '\n';
	os << "\tmodems: " << it.uso_modem << '\n';
	os << "\tdrives: " << it.uso_disco;
	return os;
}

//GETS FUNCTIONS
int processo_t::get_timeexec()
{
	return this->time_proc;
}

int processo_t::get_timeinit()
{
	return this->time_init;
}

int processo_t::get_pid()
{
	return this->pid;
}

int processo_t::get_prioridade()
{
	return this->prioridade;
}

int processo_t::get_memoffset()
{
	return this->mem_offset;
}

int processo_t::get_qtdblocos()
{
	return this->qtd_blocos;
}

bool processo_t::get_impressora()
{
	return this->uso_impressora;
}

bool processo_t::get_scanner()
{
	return this->uso_scanner;
}

bool processo_t::get_disco()
{
	return this->uso_disco;
}

bool processo_t::get_modem()
{
	return this->uso_modem;
}

//SETS FUNCTIONS

void processo_t::set_pid(const int _pid)
{
	this->pid = _pid;
}

void processo_t::set_prioridade(const int _pr)
{
	this->prioridade = _pr;
}

void processo_t::set_memoffset(const int _mo)
{
	this->mem_offset = _mo;
}

void processo_t::set_qtdblocos(const int _qb)
{
	this->qtd_blocos = _qb;
}

void processo_t::set_timeexec(const int _tp)
{
	this->time_proc = _tp;
}

void processo_t::set_timeinit(const int _ti)
{
	this->time_init = _ti;
}

void processo_t::set_impressora(const bool _i)
{
	this->uso_impressora = _i;
}

void processo_t::set_scanner(const bool _s)
{
	this->uso_scanner = _s;
}

void processo_t::set_modem(const bool _m)
{
	this->uso_modem = _m;
}

void processo_t::set_disco(const bool _d)
{
	this->uso_disco = _d;
}

void processo_t::executar(int *tempo)
{
	return;
}

// ## Funcao utilizada na funcao de ordenacao ## //
bool first_executed(processo_t p1, processo_t p2)
{
	return p1.get_timeinit() < p2.get_timeinit();
}

