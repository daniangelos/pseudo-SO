#include "../header/memoria.hpp"


/*Get instance*/
static memoria& memoria::getInstance()
{
	if(!instance) instance = new memoria();
	return *instance;
}

void memoria::memoria():userMem (0), realMem(0)
{
	/*Inicializa a lista de espaços livres para Usuario*/
	Node userNo;
	userNo.posicao = 64;
	userNo.tam = 960;
	userNo.next = NULL;
	this.userSpace.push(userNo);
	
	/*Inicializa a lista de espaços livres par tempo real*/
	Node realNo;
	realNo.tam = 64;
	realNo.posicao = 0;
	realNo.next = NULL;
	this.realSpace.push(realNo);
	
	
	
}


/*Alocar Memória*/
/*Retorno é 0 se conseguiu alocar blocos de memória, caso não consiga, retorna 1*/
/*Entrada é o valor da prioridade que define o tipo de processo e a quantidade de blocos*/
/*não tratei a questão de ser bloco contiguo de memória ainda.*/
int memoria::allocateMem(const int priority, const int quantity)
{
	if(priority == 0)
	{
		if( (this.realMem + quantity) <= MAX_REAL)
		{
			/*Caso onde há memória de tempo real livre*/
			this.realMem += quantity;
			/*TODO validar espacos contiguos*/
			
			return 0;
		}else
		{
			/*Caso de erro onde não foi possível alocar memoria de tempo real*/
			return 1;
		}
	}else
	{
		if( (this.userMem + quantity) <= MAX_USUARIO)
		{
			/*Caso onde há memória de usuário livre*/
			this.userMem+=quantity;
			/*TODO validar espacos contiguos*/
			
			return 0;
		}else
		{
			/*Caso de erro onde não foi possível alocar memoria de tempo real*/
			return 1;
		}
	}
}


