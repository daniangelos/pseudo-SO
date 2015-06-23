#ifndef MEMORIA_HPP
#define MEMORIA_HPP

#include <bitset>
#include "processo.hpp"

#define MAX_MEM 1024
#define MAX_REAL 64
#define MAX_USUARIO MAX_MEM-MAX_REAL
#define START 0

using namespace std;

class memoria
{
	private:
		bitset<MAX_MEM> mem;
	public:
		memoria();
		void show();
		unsigned int aloca(unsigned int qtd,int tipo_p);
		void desaloca(unsigned int offset, unsigned int qtd);
		unsigned int verifica(unsigned int qtd,unsigned int start, unsigned int end);
};

#endif //MEMORIA_HPP
