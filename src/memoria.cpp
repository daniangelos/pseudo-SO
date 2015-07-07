#include "../header/memoria.hpp"
#include <iostream>

memoria::memoria()
{
	for(int i=0;i<MAX_MEM;i++)
	{
		mem[i] = 0;
	}
}
unsigned int memoria::aloca(unsigned int qtd, int tipo_p)
{
	unsigned int offset = MAX_MEM;
	switch(tipo_p)
	{
		case TEMPO_REAL:
			if(qtd > MAX_REAL)
			{
				offset = 1026;
				return offset;
			}
			offset = verifica(qtd,START,MAX_REAL);
		   break;
	   	default:
			if(qtd > MAX_USUARIO)
			{
				offset = 1026;
				return offset;
			}
			offset = verifica(qtd,MAX_REAL,MAX_MEM);
			break;	   
	}
	if(offset!=MAX_MEM)
		for(int i=offset;i<qtd + offset;i++)
		{
			mem[i] = 1;
		}
	return offset;
}

void memoria::desaloca(unsigned int offset,unsigned int qtd)
{
	for(int i=offset;i<qtd+offset;i++)
	{
		mem[i] = 0;
	}	
}

void memoria::show()
{
	for(int i=0;i<MAX_MEM;i++)
	{
		cout << mem[i];
	}
	cout << endl;
}
unsigned int memoria::verifica(unsigned int qtd, unsigned int start, unsigned int end)
{
	unsigned int offset = MAX_MEM;
	int j;

	for(int i=start; i<end; i++)
	{
		j = i;

		while (mem[j] == 0 && j < qtd + i)
			j++;

		if (j == qtd + i)
		{
			offset = i;
			break;
		}
		else i = j;
	}

	return offset;
}
