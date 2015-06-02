#include "../header/processo.hpp"

void despachante(processo_t p){
	p.show();
	return;
}

// TODO: BRANCO VAI FAZER MAIS FODA
void processo_t:: show(){
	cout << "\tPID: " << pid << endl;
	return;
}

processo_t* processo_init(int id,int pr, int mem, int bl, bool i, bool s, bool d, bool m)
{
	processo_t *p = new processo_t;
	p->pid = id;
   	p->prioridade = pr;
	p->mem_offset = mem;
	p->quant_blocos = bl;
	p->uso_impressora = i;
	p->uso_scanner = s;
	p->uso_disco = d;
	p->uso_modem = m;	

	return p;	
}
