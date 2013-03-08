OPTS = -Wall -pedantic -ggdb

all: parser.out

parser.out: parser.cpp
	g++ ${OPTS} parser.cpp -o parser.out

clean:
	rm -f *.out
	rm -rf *.out.*
