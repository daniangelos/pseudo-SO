#ifndef MEMORIA_HPP
#define MEMORIA_HPP

#include <iostream>
#include <list>
#include<algorithm>

#define MAX_MEM 1024
#define MAX_REAL 64
#define MAX_USUARIO 960
using namespace std;

struct Space{
    int posicao;
	int tamanho;
};
 
class memoria
{
	private:
		/*atributo estático da Instância da classe para garantir unicidade do objeto*/
		static memoria *instance = 0;
		/*Memoria Total*/
		array<int, MAX_MEM> mem;
		list<Space> userSpace;
		list<Space> realSpace;
		/*Contador de usuário*/
		int userMem;
		/*Contador de tempo real*/
		int realMem;
		memoria();
		
	public:
		
		static memoria& getInstance();
		int allocateMem(const int priority, const int quantity);
};

#endif //MEMORIA_HPP
