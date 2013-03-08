OPTS = -Wall -pedantic -g

all: complex.out

complex.out: main.o complex.o
	g++ main.o complex.o -o complex.out

main.o: main.cpp
	g++ $(OPTS) -c main.cpp -o main.o

complex.o: complex.cpp
	g++ $(OPTS) -c complex.cpp -o complex.o

clean:
	rm *.o*
