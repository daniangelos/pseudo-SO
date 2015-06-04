.PHONY: all clean
all: simulacao clean

F = -g -std=c++11 -pthread 

simulacao: main.o processo.o memoria.o recurso.o escalonador.o
	@echo "Linkando simulador ..."
	@g++ main.o processo.o memoria.o recurso.o escalonador.o $F -o simulador

main.o: src/main.cpp 
	@echo "Criando objeto de main ..."
	@g++ src/main.cpp $F -c 

processo.o: src/processo.cpp header/processo.hpp
	@echo "Criando objeto de processo ..."
	@g++ src/processo.cpp $F -c

memoria.o: src/memoria.cpp header/memoria.hpp
	@echo "Criando objeto de memoria ..."
	@g++ src/memoria.cpp $F -c

recurso.o: src/recurso.cpp header/recurso.hpp
	@echo "Criando objeto de recurso ..."
	@g++ src/recurso.cpp $F -c

escalonador.o: src/escalonador.cpp header/escalonador.hpp
	@echo "Criando objeto de escalonador ..."
	@g++ src/escalonador.cpp $F -c


run: simulador
	./simulador input/casoteste1.txt

clean:
	@rm -f *.o

fclean:
	@rm -f *.o
	@rm -f simulador
	@rm -f *.gch
