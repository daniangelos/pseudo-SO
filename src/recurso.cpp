#include "../header/recurso.hpp"

void inicializarSemaforos()
{
	sem_init(&scanner, 0, 1);
	sem_init(&impressora, 0, 2);
	sem_init(&modem, 0, 1);
	sem_init(&disco, 0, 2);
	return;
}	
