#include "../header/processo.hpp"
ostream& operator<<(ostream& os,const processo_t& it)
{
	os << it.pid << ' ';
	os << it.prioridade << ' ';
	os << it.mem_offset << ' ';
	os << it.qtd_blocos << ' ';
	os << it.uso_impressora << ' ';
	os << it.uso_scanner << ' ';
	os << it.uso_disco << ' ';
	os << it.uso_modem;
	return os;
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
