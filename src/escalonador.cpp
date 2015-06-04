#include "../header/escalonador.hpp"
void escalonador::show_allp()
{
	for(processo_t p : processos)
		despachante(p);
}
void escalonador::despachante(processo_t p){
	cout << p << endl;
	return;
}

void escalonador::utils_tomem(string nome_arq)
{
	fstream sc;
	sc.open(nome_arq.c_str());
	string s;
	vector<int> aux;
	char *pch;
	processo_t p;
	int id = 0;
	int _ti, _pr, _tp, _qb, _i, _s, _m, _d;

	while(getline(sc,s))
	{
		if(s!="")
		{
			pch = strtok((char*)s.c_str(),"\t ,");
			while(pch!=NULL)
			{
				aux.push_back(atoi(pch));
				pch = strtok(NULL,"\t ,");
			}
		}
	}		
	for(int i=0;i<aux.size();i+=8)
	{
		p.set_pid(id);
		p.set_memoffset(-1);
		p.set_timeinit(aux[i]);
		p.set_prioridade(aux[i+1]);
		p.set_timeexec(aux[i+2]);
		p.set_qtdblocos(aux[i+3]);
		p.set_impressora(aux[i+4]);
		p.set_scanner(aux[i+5]);
		p.set_modem(aux[i+6]);
		p.set_disco(aux[i+7]);
		processos.push_back(p);	
		id++;
	}
}

void escalonador::order_process()
{
	int pr;

	sort(processos.begin(), processos.end(), first_executed);

	for(processo_t p : processos)
	{
		pr = p.get_prioridade();
		switch(pr){
			case 0:
				f_temporeal.push(p);
				break;
			case 1:
				f_usuario_p1.push(p);
				break;
			case 2:
				f_usuario_p2.push(p);
				break;
			case 3:
				f_usuario_p3.push(p);
				break;
		}
	}

}
