#ifndef RECURSO_HPP
#define RECURSO_HPP

#include<semaphore.h>
#include<pthread.h>

enum Recursos{ SEM_RECURSO = 0, IMPRESSORA, SCANNER, DISCO, MODEM, TEM_RECURSO = 1};

extern sem_t scanner;
extern sem_t impressora;
extern sem_t modem;
extern sem_t disco;

void inicializarSemaforos();
int bloquear_recurso(int recurso);
void liberar_recurso(int recurso);

#endif //RECURSO_HPP
