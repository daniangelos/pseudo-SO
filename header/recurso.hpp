#ifndef RECURSO_HPP
#define RECURSO_HPP

#include<semaphore.h>
#include<pthread.h>

sem_t scanner;
sem_t impressora;
sem_t modem;
sem_t disco;

#endif //RECURSO_HPP
