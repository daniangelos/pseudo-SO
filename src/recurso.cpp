#include "../header/recurso.hpp"

sem_t scanner;
sem_t impressora;
sem_t modem;
sem_t disco;

void inicializarSemaforos()
{
	sem_init(&scanner, 0, 1);
	sem_init(&impressora, 0, 2);
	sem_init(&modem, 0, 1);
	sem_init(&disco, 0, 2);
	return;
}	

int bloquear_recurso(int recurso) 
{
	int sucesso = 0;
	switch(recurso)
	{
		case IMPRESSORA:
			if(sem_trywait(&impressora)==0)
				sucesso = 1;
			break;
		case SCANNER:
			if(sem_trywait(&scanner)==0)
				sucesso = 1;
			break;
		case MODEM:
			if(sem_trywait(&modem)==0)
				sucesso  = 1;
			break;
		case DISCO:
			if(sem_trywait(&disco)==0)
				sucesso = 1;
			break;
		default:
			break;
	}
	return sucesso;
}

void liberar_recurso(int recurso)
{
	switch(recurso)
	{
		case IMPRESSORA:
			sem_post(&impressora);
			break;
		case SCANNER:
			sem_post(&scanner);
			break;
		case MODEM:
			sem_post(&modem);
			break;
		case DISCO:
			sem_post(&disco);
			break;
		default:
			break;
	}
}
