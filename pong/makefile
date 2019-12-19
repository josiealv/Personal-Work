all: pong

pong: FORCE ball.o
	g++ -g -Wall -std=c++11 ball.o pong.cpp -o pong

ball.o: ball.h ball.cpp
	g++ -g -Wall -std=c++11 -c ball.cpp -o ball.o

FORCE: ;

.phony: clean pong

clean:
	-@rm -rf *.o	