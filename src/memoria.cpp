#include "../header/memoria.hpp"


/*Get instance*/
static memoria& memoria::getInstance()
{
	if(!instance) instance = new memoria();
	return *instance;
}

memoria::memoria():userMem (0), realMem(0)
{
	/*Inicializa a lista de espaços livres para Usuario*/
	Space userNo;
	userNo.posicao = 64;
	userNo.tam = 960;
	this->userSpace.push_back(userNo);
	
	/*Inicializa a lista de espaços livres par tempo real*/
	Space realNo;
	realNo.tam = 64;
	realNo.posicao = 0;
	this->realSpace.push_back(realNo);
	
	mem.fill(0);
	
	
}



/*Alocar Memória*/
/*Retorno é 0 se conseguiu alocar blocos de memória, caso não consiga, retorna 1*/
/*Entrada é o valor da prioridade que define o tipo de processo e a quantidade de blocos*/
/*não tratei a questão de ser bloco contiguo de memória ainda.*/
int memoria::allocateMem(const int priority, const int quantity)
{	
	auto find_space = [quantity](list<Space>::iterator &begin, list<Space>::iterator &end){
		return find_if(begin, end, [quantity](Space const &espaco){ return espaco.tamanho >= quantity; });
	};
	
	if(priority == 0)
	{
		if( (this.realMem + quantity) <= MAX_REAL)
		{
			/*Caso onde há memória de tempo real livre*/
			realMem += quantity;
			/*TODO validar espacos contiguos*/
			list<Space>::iterator freeSpace = find_space(realSpace.begin(),realSpace.end());
			if(freeSpace != realSpace.end()) /*achou algo*/
			{
				Space usedNo;
				usedNo.tam = quantity;
				usedNo.posicao = freeSpace->posicao;
				this->usedSpace.push_back(usedNo);
				for(int i=0; i<quantity; i++)
				{
					mem[freeSpace->posicacao+i]=1;
				}
				if(quantity < freeSpace->tamanho)
				{
					freeSpace->tamanho -= quantity;
					freeSpace->posicao += quantity;
				}else
				{
					realSpace.erase(freeSpace);
				}
				return 1;
			}
		}
	}else
	{
		if( (this.userMem + quantity) <= MAX_USUARIO)
		{
			/*Caso onde há memória de usuário livre*/
			userMem+=quantity;
			/*TODO validar espacos contiguos*/
			list<Space>::iterator freeSpace = find_space(userSpace.begin(),userSpace.end());
			if(freeSpace != userSpace.end()) /*achou algo*/
			{
				Space usedNo;
				usedNo.tam = quantity;
				usedNo.posicao = freeSpace->posicao;
				this->usedSpace.push_back(usedNo);
				for(int i=0; i<quantity; i++)
				{
					mem[freeSpace->posicacao+i]=1;
				}
				if(quantity < freeSpace->tamanho)
				{
					freeSpace->tamanho -= quantity;
					freeSpace->posicao += quantity;
				}else
				{
					userSpace.erase(freeSpace);
				}
				return 1;
			}
		}
	}
	return 0;
}


