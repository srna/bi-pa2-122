all: citac.out

citac.out: main.o citac.o
	g++ main.o citac.o -o citac.out

main.o: main.cpp
	g++ -Wall -pedantic -c main.cpp -o main.o

citac.o: citac.cpp
	g++ -Wall -pedantic -c citac.cpp -o citac.o

clean:
	rm *.o*
