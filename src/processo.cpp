#include "../header/processo.hpp"
ostream& operator<<(ostream& os,const processo_t& it)
{
	os << "dispatcher =>" << '\n';
	os << "\tPID: " << it.pid << '\n';
	os << "\toffset: " << it.mem_offset << '\n';
	os << "\tblocks: " << it.qtd_blocos << '\n';
	os << "\tpriority: " << it.prioridade << '\n';
	os << "\ttime: " << '\n';
	os << "\tprinters: " << it.uso_impressora << '\n';
	os << "\tscanners: " << it.uso_scanner << '\n';
	os << "\tmodems: " << it.uso_modem << '\n';
	os << "\tdrives: " << it.uso_disco;
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
