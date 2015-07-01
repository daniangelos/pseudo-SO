#include "../header/escalonador.hpp"
void escalonador::show_allp()
{
	processo_t q;

	//cout << "Todos os processos: " << endl;
	//for(processo_t p : processos)
		//despachante(p);

	cout << "\nTodos os processos de tempo real: " << endl;
	for(int i=0; i<(int)f_temporeal.size(); i++)
	{
		q = f_temporeal.front();
		despachante(q);
		f_temporeal.pop();
		f_temporeal.push(q);
	}

	cout << "\nTodos os processos de usuario com prioridade 1: "<< endl;
	for(int i=0; i<(int)f_usuario_p1.size(); i++)
	{
		q = f_usuario_p1.front();
		despachante(q);
		f_usuario_p1.pop();
		f_usuario_p1.push(q);
	}

	cout << "\nTodos os processos de usuario com prioridade 2: "<< endl;
	for(int i=0; i<(int)f_usuario_p2.size(); i++)
	{
		q = f_usuario_p2.front();
		despachante(q);
		f_usuario_p2.pop();
		f_usuario_p2.push(q);
	}

	cout << "\nTodos os processos de usuario com prioridade 3: "<< endl;
	for(int i=0; i<(int)f_usuario_p3.size(); i++)
	{
		q = f_usuario_p3.front();
		despachante(q);
		f_usuario_p3.pop();
		f_usuario_p3.push(q);
	}
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
	for(int i=0;i<(int)aux.size();i+=8)
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
		p.set_recursobloqueado(SEM_RECURSO);
		processos.push_back(p);
		id++;
	}
}

void escalonador::order_process()
{
	sort(processos.begin(), processos.end(), first_executed);
}

void escalonador::start_time()
{
	seconds_passed = 0;
}

int escalonador::get_time_passed()
{
	return seconds_passed;
}

bool escalonador::ainda_existe_processo()
{
	return (
		!f_temporeal.empty() ||
		!f_usuario_p1.empty() ||
		!f_usuario_p2.empty() ||
		!f_usuario_p3.empty() || !processos.empty());
}

// ## Verifica se existe algum processo nas filas que ja pode ser executado ## //
bool escalonador::prox_processo(processo_t *p)
{
	if(!f_temporeal.empty() && 
			f_temporeal.front().get_timeinit() <= seconds_passed)
	{
		*p = f_temporeal.front();
		f_temporeal.pop();
		return true;
	}
	if(!f_usuario_p1.empty() &&
			f_usuario_p1.front().get_timeinit() <= seconds_passed)
	{
		*p = f_usuario_p1.front();
		f_usuario_p1.pop();
		return true;
	}
	if(!f_usuario_p2.empty() && 
			f_usuario_p2.front().get_timeinit() <= seconds_passed)
	{
		*p = f_usuario_p2.front();
		f_usuario_p2.pop();
		return true;
	}
	if(!f_usuario_p3.empty() && 
			f_usuario_p3.front().get_timeinit() <= seconds_passed)
	{
		*p = f_usuario_p3.front();
		f_usuario_p3.pop();
		return true;
	}

	// ## Nao chegaram processos ainda ## //
	return false;
	
}

void escalonador::popula()
{
	int i = 0;
	processo_t p;
	while(i < (int)processos.size() && processos[i].get_timeinit() < seconds_passed + 1)
	{
		p = processos[i];
		vai_ffila(p);
		i++;
	}
	processos.erase(processos.begin(),processos.begin()+i);
}

void escalonador::simulacao()
{
	processo_t p;
	unsigned int offset;
	while(ainda_existe_processo())
	{
		popula();
		if(prox_processo(&p))
		{
			if(!p.in_mem())
			{
			  offset = m.aloca(p.get_qtdblocos(),p.get_prioridade());
			  if(offset==MAX_MEM)
			  {
				cout << "\a---ERROR : MEMORIA NAO ALOCADA PROCESSO " << p.get_pid() << " ---" << endl;
				vai_ffila(p);
				seconds_passed++;
				continue;
			  }
			  else
				p.set_memoffset(offset);
			}
			despachante(p);
			p.executar(seconds_passed);
			if(p.get_timeexec() > 0)
			  vai_ffila(p);
			else
			{
			  m.desaloca(p.get_memoffset(),p.get_qtdblocos());
			  p.liberar_recursos();
			}
		}
		else
		  seconds_passed++;

	}	
}


void escalonador::vai_ffila(processo_t _p)
{
  switch(_p.get_prioridade())
  {
    case TEMPO_REAL:
	    f_temporeal.push(_p);
	    break;
    case USUARIO_P1:
	    f_usuario_p1.push(_p);
	    break;
    case USUARIO_P2:
	    f_usuario_p2.push(_p);
	    break;
    case USUARIO_P3:
	    f_usuario_p3.push(_p);
	    break;
     
  }
}
