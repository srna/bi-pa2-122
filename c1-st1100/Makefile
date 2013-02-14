all: pole.out

pole.out: pole.o func.o
	g++ pole.o func.o -o pole.out

pole.o: pole.cpp
	g++ -c -Wall -pedantic pole.cpp -o pole.o

func.o: func.cpp
	g++ -c -Wall -pedantic func.cpp -o func.o

clean:
	rm *.out
	rm *.o
