CC=g++
CFG= -c -g -Wall -std=c++11 -I ../include

all: pong++

pong++: main.o 
	g++ main.o -o pong++ -lncurses

main.o: ../src/main.cpp
	$(CC) $(CFG) ../src/main.cpp

clean:
	rm *.o hearth
