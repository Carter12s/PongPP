CC=g++
CFG= -c -g -Wall -std=c++11 -I ../include

all: hearth

hearth: main.o action.o card.o cardlibrary.o deck.o engine.o jsoncpp.o player.o playerinfo.o cinplayer.o terminalrender.o termplayer.o
	g++ main.o action.o card.o cardlibrary.o deck.o engine.o jsoncpp.o player.o playerinfo.o cinplayer.o terminalrender.o termplayer.o -o hearth -lncurses

main.o: ../src/main.cpp
	$(CC) $(CFG) ../src/main.cpp

engine.o: ../src/engine.cpp
	$(CC) $(CFG) ../src/engine.cpp 

action.o: ../src/action.cpp
	$(CC) $(CFG) ../src/action.cpp

card.o: ../src/card.cpp
	$(CC) $(CFG) ../src/card.cpp

cardlibrary.o: ../src/cardlibrary.cpp 
	$(CC) $(CFG) ../src/cardlibrary.cpp 

deck.o: ../src/deck.cpp
	$(CC) $(CFG) ../src/deck.cpp

jsoncpp.o: ../src/jsoncpp.cpp
	$(CC) $(CFG) ../src/jsoncpp.cpp

player.o: ../src/player.cpp
	$(CC) $(CFG) ../src/player.cpp

playerinfo.o: ../src/playerinfo.cpp
	$(CC) $(CFG) ../src/playerinfo.cpp

cinplayer.o: ../src/cinplayer.cpp
	$(CC) $(CFG) ../src/cinplayer.cpp

terminalrender.o: ../src/terminalrender.cpp
	$(CC) $(CFG) ../src/terminalrender.cpp -lncurses

termplayer.o: ../src/termplayer.cpp
	$(CC) $(CFG) ../src/termplayer.cpp

clean:
	rm *.o hearth
