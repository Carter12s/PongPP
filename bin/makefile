CC=g++
CFG= -c -g -Wall -std=c++11 -I ../include

all: pong++

pong++: main.o ball.o scenegraph.o object.o collisionobject.o pong.o
	g++ main.o ball.o scenegraph.o object.o collisionobject.o pong.o -o pong++ -lncurses

main.o: ../src/main.cpp
	$(CC) $(CFG) ../src/main.cpp

ball.o: ../src/ball.cpp
	$(CC) $(CFG) ../src/ball.cpp

scenegraph.o: ../src/scenegraph.cpp
	$(CC) $(CFG) ../src/scenegraph.cpp

object.o: ../src/object.cpp
	$(CC) $(CFG) ../src/object.cpp

collisionobject.o: ../src/collisionobject.cpp
	$(CC) $(CFG) ../src/collisionobject.cpp

pong.o: ../src/pong.cpp
	$(CC) $(CFG) ../src/pong.cpp
clean:
	rm *.o pong 
