all: pong

pong: FORCE ball.o paddle.o game.o
	g++ -g -Wall -std=c++14 -lncurses ball.o paddle.o game.o pong.cpp -o pong

ball.o: ball.h ball.cpp
	g++ -g -Wall -std=c++14 -c ball.cpp -o ball.o

paddle.o: paddle.h paddle.cpp
	g++ -g -Wall -std=c++14 -c paddle.cpp -o paddle.o

game.o: game.h game.cpp
	g++ -g -Wall -std=c++14 -lncurses -c game.cpp -o game.o

FORCE: ;

.phony: clean pong

clean:
	-@rm -rf *.o	