#include "../header/escalonador.hpp"
void escalonador::despachante(processo_t p){
	cout << p << endl;
	return;
}

void escalonador::utils_tomem(string nome_arq)
{
	fstream sc;
	sc.open(nome_arq.c_str());
	string s;
	processo_t p;
	int _ti,_pr,_tp,_qb,_i,_s,_m,_d;
	while(getline(sc,s))
	{
		if(s!="")
		{
			cout << s << endl;
			p.set_timeinit(_ti);
			p.set_prioridade(_pr);
			p.set_timeexec(_tp);
			p.set_qtdblocos(_qb);
			p.set_impressora(_i);
			p.set_scanner(_s);
			p.set_modem(_m);
			p.set_disco(_d);
			processos.push_back(p);	
		}
	}		
}
