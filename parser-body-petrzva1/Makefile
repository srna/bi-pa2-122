OPTS = -Wall -pedantic -g


all:Body.out			

Body.out:main.o students.o 		
	g++ main.o students.o -o Body.out		
	

main.o: main.cpp
	g++ $(OPTS) -c main.cpp -o main.o

students.o: students.cpp
	g++ $(OPTS) -c students.cpp -o students.o

clean: 
	rm *.out
	rm *.o 
