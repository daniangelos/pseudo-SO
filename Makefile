.PHONY: all
all: simulacao clean

F = -g -std=c++11 -pthread 

simulacao: main.o processo.o memoria.o recurso.o
	@g++ main.o processo.o memoria.o recurso.o $F -o simulador

main.o: src/main.cpp 
	@g++ src/main.cpp $F -c 

processo.o: src/processo.cpp header/processo.hpp
	@g++ src/processo.cpp $F -c

memoria.o: src/memoria.cpp header/memoria.hpp
	@g++ src/memoria.cpp $F -c

recurso.o: src/recurso.o header/recurso.hpp
	@g++ src/recurso.cpp $F -c

run: simulador
	./simulador input/casoteste1.txt

clean:
	@rm *.o
