all: simulacao clean

F = -g -std=c++11 

simulacao: main.o processo.o
	@g++ main.o processo.o $F -o simulador

main.o: src/main.cpp 
	@g++ src/main.cpp $F -c 

processo.o: src/processo.cpp header/processo.hpp
	@g++ src/processo.cpp $F -c

run: simulador
	./simulador input/casoteste1.txt

clean:
	@rm *.o
